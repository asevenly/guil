.PHONY: usage cmake ninja clean
# variables
BUILD := build
# commands
usage:
	@cat Makefile.usage.txt
cmake:
	@echo "configure project into build directory"
	@cmake -B $(BUILD) -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
ninja:
	@echo "generates project into build directory"
	@ninja -C $(BUILD)
clean:
	@echo "remove force recursive build directory"
	@rm -fr $(BUILD)
	@git restore $(BUILD)

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `guil` C90 Detached Process GUI Library
# Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ
