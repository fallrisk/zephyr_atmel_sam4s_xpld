ccflags-$(CONFIG_UART_QMSI) +=-I$(CONFIG_QMSI_INSTALL_PATH)/include
ccflags-y +=-I$(srctree)/drivers

obj-$(CONFIG_UART_NS16550)	+= uart_ns16550.o
obj-$(CONFIG_UART_K20)		+= uart_k20.o
obj-$(CONFIG_UART_STELLARIS)	+= uart_stellaris.o
obj-$(CONFIG_UART_NSIM)		+= uart_nsim.o
obj-$(CONFIG_UART_ATMEL_SAM3)	+= uart_atmel_sam3.o
obj-$(CONFIG_UART_ATMEL_SAM4)	+= uart_atmel_sam4.o
obj-$(CONFIG_UART_QMSI)		+= uart_qmsi.o
obj-$(CONFIG_UART_STM32)	+= uart_stm32.o
obj-$(CONFIG_UART_NRF5)         += uart_nrf5.o
obj-$(CONFIG_UART_ALTERA_JTAG)  += uart_altera_jtag.o
