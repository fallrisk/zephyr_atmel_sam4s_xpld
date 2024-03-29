/*
 * Copyright (c) 2016 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>

#include <device.h>
#include <uart.h>
#include <zephyr.h>

static const char *banner1 = "Send any character to the UART device\n";
static const char *banner2 = "Character read:\n";

#ifdef CONFIG_BOARD_QUARK_SE_DEVBOARD
#define UART_DEVICE "UART_1"
#elif CONFIG_BOARD_QUARK_D2000_CRB
#define UART_DEVICE "UART_0"
#elif CONFIG_BOARD_ATMEL_SAM4S_XPLD
#define UART_DEVICE "UART_1"
#else
/* For any other board not specified above, we use UART_0 by default. */
#define UART_DEVICE "UART_0"
#endif

static volatile bool data_transmitted;
static volatile bool data_arrived;
static char new_data;

static void write_string(struct device *dev, const char *str, int len)
{
	for (int i = 0; i < len; i++)
		uart_poll_out(dev, str[i]);
}

static void test_by_polling(struct device *dev)
{
	unsigned char data;

	write_string(dev, banner1, strlen(banner1));

	/* Poll in the character */
	while (uart_poll_in(dev, &data) == -1)
		;

	write_string(dev, banner2, strlen(banner2));
	write_string(dev, &data, 1);
	write_string(dev, "\n", 1);
}

static void interrupt_handler(struct device *dev)
{
	uart_irq_update(dev);

	if (uart_irq_tx_ready(dev)) {
		data_transmitted = true;
	}

	if (uart_irq_rx_ready(dev)) {
		uart_fifo_read(dev, &new_data, 1);
		data_arrived = true;
	}
}

static void read_char_irq(struct device *dev, char *data)
{
	uart_irq_rx_enable(dev);

	data_arrived = false;
	while (data_arrived == false)
		;
	*data = new_data;

	uart_irq_rx_disable(dev);
}

static void write_buf_irq(struct device *dev, const char *buf, int len)
{
	int i;

	uart_irq_tx_enable(dev);

	for (i = 0; i < len; i++) {
		data_transmitted = false;
		while (uart_fifo_fill(dev, &buf[i], 1) == 0)
			;
		while (data_transmitted == false)
			;
	}

	uart_irq_tx_disable(dev);
}

static void test_by_irq(struct device *dev)
{
	char data;

	uart_irq_callback_set(dev, interrupt_handler);

	write_buf_irq(dev, banner1, strlen(banner1));
	read_char_irq(dev, &data);
	write_buf_irq(dev, banner2, strlen(banner2));
	write_buf_irq(dev, &data, sizeof(data));
	write_buf_irq(dev, "\n", 1);
}

void main(void)
{
	struct device *dev = device_get_binding(UART_DEVICE);

	test_by_polling(dev);
	test_by_irq(dev);
}
