APPLICATION_DIRECTORIES = $(shell find src/software/applications/* -type d)
APPLICATION_NAMES = $(APPLICATION_DIRECTORIES:src/software/applications/%=%)
H_FILES = $(shell find src/software -name "*.h")
LIBRARY_C_FILES = $(shell find src/software/library -name "*.c")
APPLICATION_C_FILES = $(shell find src/software/applications -name "*.c")

AVR_CC = avr-gcc
AVR_CFLAGS = -Wall -O2 -mmcu=atmega328p -DQM_STATIC_DATA=PROGMEM
AVR_LDFLAGS =
AVR_DISTRIBUTABLES = $(addsuffix .hex,$(addprefix dist/avr/,$(APPLICATION_NAMES)))
AVR_C_FILES = $(shell find src/software/targets/avr -name "*.c")
AVR_TARGET_AND_LIBRARY_O_FILES = $(AVR_C_FILES:src/software/%.c=obj/avr/compiled/%.o) $(LIBRARY_C_FILES:src/software/%.c=obj/avr/compiled/%.o)
AVR_APPLICATION_O_FILES = $(APPLICATION_C_FILES:src/software/%.c=obj/avr/compiled/%.o)

all: $(AVR_DISTRIBUTABLES)

clean:
	rm -rf dist obj

obj/avr/compiled/%.o: src/software/%.c $(H_FILES) makefile
	mkdir -p $(dir $@)
	$(AVR_CC) -c $(AVR_CFLAGS) $< -o $@

obj/avr/linked/%.out: $(AVR_TARGET_AND_LIBRARY_O_FILES) $(AVR_APPLICATION_O_FILES)
	mkdir -p $(dir $@)
	$(AVR_CC) $(AVR_CFLAGS) $(AVR_TARGET_AND_LIBRARY_O_FILES) $(filter obj/avr/compiled/applications/$*/%,$(AVR_APPLICATION_O_FILES)) -o $@ $(AVR_LDFLAGS)

dist/avr/%.hex: obj/avr/linked/%.out
	mkdir -p $(dir $@)
	avr-objcopy -O ihex $< $@
