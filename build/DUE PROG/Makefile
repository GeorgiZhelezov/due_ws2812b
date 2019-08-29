ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/due_main.cpp.o \

PLATFORM_CORE_OBJS = \
	core/WString.cpp.o \
	core/IPAddress.cpp.o \
	core/Reset.cpp.o \
	core/syscalls_sam3.c.o \
	core/itoa.c.o \
	core/new.cpp.o \
	core/watchdog.cpp.o \
	core/cortex_handlers.c.o \
	core/iar_calls_sam3.c.o \
	core/main.cpp.o \
	core/wiring_pulse.cpp.o \
	core/wiring_shift.c.o \
	core/USB/CDC.cpp.o \
	core/USB/USBCore.cpp.o \
	core/USB/PluggableUSB.cpp.o \
	core/Print.cpp.o \
	core/avr/dtostrf.c.o \
	core/hooks.c.o \
	core/WInterrupts.c.o \
	core/RingBuffer.cpp.o \
	core/abi.cpp.o \
	core/WMath.cpp.o \
	core/USARTClass.cpp.o \
	core/wiring.c.o \
	core/Stream.cpp.o \
	core/wiring_pulse_asm.S.o \
	core/wiring_digital.c.o \
	core/UARTClass.cpp.o \
	core/wiring_analog.c.o \

PLATFORM_VARIANT_OBJS = \
	variant/variant.cpp.o \

LIBRARIES_OBJS = \
	libraries/FastLED/3.3.2/platforms.cpp.o \
	libraries/FastLED/3.3.2/FastLED.cpp.o \
	libraries/FastLED/3.3.2/wiring.cpp.o \
	libraries/FastLED/3.3.2/lib8tion.cpp.o \
	libraries/FastLED/3.3.2/power_mgt.cpp.o \
	libraries/FastLED/3.3.2/hsv2rgb.cpp.o \
	libraries/FastLED/3.3.2/noise.cpp.o \
	libraries/FastLED/3.3.2/colorpalettes.cpp.o \
	libraries/FastLED/3.3.2/colorutils.cpp.o \
	libraries/FastLED/3.3.2/bitswap.cpp.o \

TARGETS = \
	due_ws2812b.bin \

all: $(TARGETS)

due_ws2812b.bin: due_ws2812b.elf
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-objcopy" -O binary  "./due_ws2812b.elf" "./due_ws2812b.bin"

due_ws2812b.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -mcpu=cortex-m3 -mthumb -Os -Wl,--gc-sections "-T/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x/linker_scripts/gcc/flash.ld" "-Wl,-Map,./due_ws2812b.map"  -o "./due_ws2812b.elf" "-L." -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(PROJECT_OBJS) $(LIBRARIES_OBJS) "/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a" "./core.a" -Wl,--end-group -lm -lgcc

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-size" -A "./due_ws2812b.elf"

project/due_main.cpp.o: ../../due_main.cpp project/due_main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

project/due_main.cpp.d: ;

-include project/due_main.cpp.d 


core/WString.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d

core/IPAddress.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/Reset.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/Reset.cpp core/Reset.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/Reset.cpp.d: ;

-include core/Reset.cpp.d

core/syscalls_sam3.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/syscalls_sam3.c core/syscalls_sam3.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/syscalls_sam3.c.d: ;

-include core/syscalls_sam3.c.d

core/itoa.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/itoa.c core/itoa.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/itoa.c.d: ;

-include core/itoa.c.d

core/new.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/watchdog.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/watchdog.cpp core/watchdog.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/watchdog.cpp.d: ;

-include core/watchdog.cpp.d

core/cortex_handlers.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/cortex_handlers.c core/cortex_handlers.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/cortex_handlers.c.d: ;

-include core/cortex_handlers.c.d

core/iar_calls_sam3.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/iar_calls_sam3.c core/iar_calls_sam3.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/iar_calls_sam3.c.d: ;

-include core/iar_calls_sam3.c.d

core/main.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/wiring_pulse.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/wiring_pulse.cpp core/wiring_pulse.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/wiring_pulse.cpp.d: ;

-include core/wiring_pulse.cpp.d

core/wiring_shift.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/USB/CDC.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/USB/CDC.cpp core/USB/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/USB/CDC.cpp.d: ;

-include core/USB/CDC.cpp.d

core/USB/USBCore.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/USB/USBCore.cpp core/USB/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/USB/USBCore.cpp.d: ;

-include core/USB/USBCore.cpp.d

core/USB/PluggableUSB.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/USB/PluggableUSB.cpp core/USB/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/USB/PluggableUSB.cpp.d: ;

-include core/USB/PluggableUSB.cpp.d

core/Print.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/avr/dtostrf.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/avr/dtostrf.c core/avr/dtostrf.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/avr/dtostrf.c.d: ;

-include core/avr/dtostrf.c.d

core/hooks.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/WInterrupts.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/RingBuffer.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/RingBuffer.cpp core/RingBuffer.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/RingBuffer.cpp.d: ;

-include core/RingBuffer.cpp.d

core/abi.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/WMath.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/USARTClass.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/USARTClass.cpp core/USARTClass.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/USARTClass.cpp.d: ;

-include core/USARTClass.cpp.d

core/wiring.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/Stream.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/wiring_pulse_asm.S.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/wiring_pulse_asm.S
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -x assembler-with-cpp -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/wiring_digital.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/UARTClass.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/UARTClass.cpp core/UARTClass.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

core/UARTClass.cpp.d: ;

-include core/UARTClass.cpp.d

core/wiring_analog.c.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d


variant/variant.cpp.o: /home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x/variant.cpp variant/variant.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "./core.a" "$@"

variant/variant.cpp.d: ;

-include variant/variant.cpp.d


libraries/FastLED/3.3.2/platforms.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/platforms.cpp libraries/FastLED/3.3.2/platforms.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/platforms.cpp.d: ;

-include libraries/FastLED/3.3.2/platforms.cpp.d

libraries/FastLED/3.3.2/FastLED.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/FastLED.cpp libraries/FastLED/3.3.2/FastLED.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/FastLED.cpp.d: ;

-include libraries/FastLED/3.3.2/FastLED.cpp.d

libraries/FastLED/3.3.2/wiring.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/wiring.cpp libraries/FastLED/3.3.2/wiring.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/wiring.cpp.d: ;

-include libraries/FastLED/3.3.2/wiring.cpp.d

libraries/FastLED/3.3.2/lib8tion.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/lib8tion.cpp libraries/FastLED/3.3.2/lib8tion.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/lib8tion.cpp.d: ;

-include libraries/FastLED/3.3.2/lib8tion.cpp.d

libraries/FastLED/3.3.2/power_mgt.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/power_mgt.cpp libraries/FastLED/3.3.2/power_mgt.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/power_mgt.cpp.d: ;

-include libraries/FastLED/3.3.2/power_mgt.cpp.d

libraries/FastLED/3.3.2/hsv2rgb.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/hsv2rgb.cpp libraries/FastLED/3.3.2/hsv2rgb.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/hsv2rgb.cpp.d: ;

-include libraries/FastLED/3.3.2/hsv2rgb.cpp.d

libraries/FastLED/3.3.2/noise.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/noise.cpp libraries/FastLED/3.3.2/noise.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/noise.cpp.d: ;

-include libraries/FastLED/3.3.2/noise.cpp.d

libraries/FastLED/3.3.2/colorpalettes.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/colorpalettes.cpp libraries/FastLED/3.3.2/colorpalettes.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/colorpalettes.cpp.d: ;

-include libraries/FastLED/3.3.2/colorpalettes.cpp.d

libraries/FastLED/3.3.2/colorutils.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/colorutils.cpp libraries/FastLED/3.3.2/colorutils.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/colorutils.cpp.d: ;

-include libraries/FastLED/3.3.2/colorutils.cpp.d

libraries/FastLED/3.3.2/bitswap.cpp.o: /home/g2/.arduinocdt/libraries/FastLED/3.3.2/bitswap.cpp libraries/FastLED/3.3.2/bitswap.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/g2/.arduinocdt/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -mcpu=cortex-m3 -mthumb -DF_CPU=84000000L -DARDUINO=10608 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Arduino LLC"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/libsam" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/CMSIS/Include/" "-I/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/system/CMSIS/Device/ATMEL/" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/cores/arduino" -I"/home/g2/.arduinocdt/packages/arduino/hardware/sam/1.6.12/variants/arduino_due_x" -I"/home/g2/.arduinocdt/libraries/FastLED/3.3.2" "$<" -o "$@"

libraries/FastLED/3.3.2/bitswap.cpp.d: ;

-include libraries/FastLED/3.3.2/bitswap.cpp.d

