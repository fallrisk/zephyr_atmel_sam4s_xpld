#!/usr/bin/fish
#
# Copyright (c) 2015 Wind River Systems, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Check that we are running this script with the fish shell.
if test -z $FISH_VERSION
	echo "This script is only for the fish shell."
	exit 1
end

# Save the current directory so we can jump back to it after getting this
# script's directory to store in the variable ZEPHYR_BASE.
set current_dir (pwd)

# Test if this file was sourced or executed.
if test "$_" != source
  echo "Source this file (do NOT execute it!) to set the Zephyr Kernel environment."
  exit 1
end

# Identify OS source tree root directory
set --export ZEPHYR_BASE (cd (dirname (status -f)); and pwd)

set scripts_path $ZEPHYR_BASE/scripts
echo "$PATH" | grep -q "$scripts_path"
set --export PATH $scripts_path $PATH
set --erase scripts_path

# You can further customize your environment by creating a bash script called
# ~/.zephyrrc in your home directory. It will be automatically
# run (if it exists) by this script.
# enable custom environment settings
set zephyr_answer_file ~/zephyr-env_install.fish
if test -f $zephyr_answer_file 
	echo "Warning: Please rename ~/zephyr-env_install.bash to ~/.zephyrrc"
	./$zephyr_answer_file
end
set --erase zephyr_answer_file 
set zephyr_answer_file ~/.zephyrrc
if test -f $zephyr_answer_file
	./$zephyr_answer_file
end
set --erase zephyr_answer_file 

cd $current_dir
