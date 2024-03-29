SUBMODULE_H_FILES = $(shell find submodules -name "*.h")

PREVIOUSLY_GENERATED_FILES = $(shell find src/software -name "*.*.h") $(shell find src/software -name "*.*.c") $(shell find src/software -name "*.ase.png") $(shell find src/software -name "*.aseprite.png")

TOOL_CC = $(CC)
TOOL_CFLAGS = -Wall -O2
TOOL_LDFLAGS = -lm
TOOL_C_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/tools -name "*.c"))
TOOL_NAMES = $(TOOL_C_FILES:src/software/tools/%.c=%)
TOOL_DISTRIBUTIBLES = $(TOOL_NAMES:%=dist/tools/%)

ASEPRITE_FILES = $(shell find src/software -name "*.ase") $(shell find src/software -name "*.aseprite")
CONVERTED_ASEPRITE_FILES = $(ASEPRITE_FILES:%=%.png)
IMAGE_FILES = $(shell find src/software -name "*.jpg") $(shell find src/software -name "*.jpeg") $(shell find src/software -name "*.png") $(shell find src/software -name "*.tga") $(shell find src/software -name "*.bmp") $(shell find src/software -name "*.psd") $(shell find src/software -name "*.psd") $(shell find src/software -name "*.gif") $(shell find src/software -name "*.hdr") $(shell find src/software -name "*.pic") $(shell find src/software -name "*.pnm")
NON_GENERATED_IMAGE_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(IMAGE_FILES))
IMAGE_FILES_TO_CONVERT = $(CONVERTED_ASEPRITE_FILES) $(NON_GENERATED_IMAGE_FILES)
CONVERTED_IMAGE_H_FILES = $(IMAGE_FILES_TO_CONVERT:%=%.h)
CONVERTED_IMAGE_C_FILES = $(IMAGE_FILES_TO_CONVERT:%=%.c)

APPLICATION_DIRECTORIES = $(shell find src/software/applications/* -type d)
APPLICATION_NAMES = $(APPLICATION_DIRECTORIES:src/software/applications/%=%)
APPLICATION_H_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/applications -name "*.h"))
APPLICATION_C_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/applications -name "*.c"))
LIBRARY_H_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/library -name "*.h"))
LIBRARY_C_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/library -name "*.c"))
TARGET_H_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/targets -name "*.h"))

AVR_CC = avr-gcc
AVR_CFLAGS = -Wall -O2 -mmcu=atmega328p -D'QM_STATIC_DATA=__attribute__((__progmem__))' -DQM_DISPLAY_WIDTH=48 -DQM_DISPLAY_HEIGHT=84 -DQM_STATIC_DATA_ADDRESS_TYPE='const void *'
AVR_LDFLAGS =
AVR_DISTRIBUTABLES = $(addsuffix .hex,$(addprefix dist/avr/,$(APPLICATION_NAMES)))
AVR_C_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/targets/avr -name "*.c"))
AVR_TARGET_O_FILES = $(AVR_C_FILES:src/software/%.c=obj/avr/compiled/%.o)
AVR_LIBRARY_O_FILES = $(LIBRARY_C_FILES:src/software/%.c=obj/avr/compiled/%.o)
AVR_APPLICATION_O_FILES = $(APPLICATION_C_FILES:src/software/%.c=obj/avr/compiled/%.o)
AVR_IMAGE_O_FILES = $(IMAGE_FILES_TO_CONVERT:src/software/%=obj/avr/compiled/%.o)

WINDOWS_CC = x86_64-w64-mingw32-gcc
WINDOWS_CFLAGS = -Wall -O2 -DQM_STATIC_DATA= -DQM_DISPLAY_WIDTH=48 -DQM_DISPLAY_HEIGHT=84 -DQM_STATIC_DATA_ADDRESS_TYPE='const void *'
WINDOWS_LDFLAGS = -lgdi32 -lwinmm -mwindows
WINDOWS_DISTRIBUTABLES = $(addsuffix .exe,$(addprefix dist/windows/,$(APPLICATION_NAMES)))
WINDOWS_C_FILES = $(filter-out $(PREVIOUSLY_GENERATED_FILES),$(shell find src/software/targets/windows -name "*.c"))
WINDOWS_TARGET_O_FILES = $(WINDOWS_C_FILES:src/software/%.c=obj/windows/%.o)
WINDOWS_LIBRARY_O_FILES = $(LIBRARY_C_FILES:src/software/%.c=obj/windows/%.o)
WINDOWS_APPLICATION_O_FILES = $(APPLICATION_C_FILES:src/software/%.c=obj/windows/%.o)
WINDOWS_IMAGE_O_FILES = $(IMAGE_FILES_TO_CONVERT:src/software/%=obj/windows/%.o)

all: $(TOOL_DISTRIBUTIBLES) $(AVR_DISTRIBUTABLES) $(AVR_TARGET_O_FILES) $(AVR_LIBRARY_O_FILES) $(AVR_APPLICATION_O_FILES) $(AVR_IMAGE_O_FILES) $(WINDOWS_DISTRIBUTABLES) $(WINDOWS_TARGET_O_FILES) $(WINDOWS_LIBRARY_O_FILES) $(WINDOWS_APPLICATION_O_FILES) $(WINDOWS_IMAGE_O_FILES) $(CONVERTED_IMAGE_H_FILES) $(CONVERTED_IMAGE_C_FILES)

clean:
	rm -rf dist obj $(PREVIOUSLY_GENERATED_FILES)

%.aseprite.png: %.aseprite makefile
	aseprite --batch $< --save-as $@

%.jpg.h: %.jpg dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.jpg.c: %.jpg.h
	echo

%.jpeg.h: %.jpeg dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.jpeg.c: %.jpeg.h
	echo

%.png.h: %.png dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.png.c: %.png.h
	echo

%.tga.h: %.tga dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.tga.c: %.tga.h
	echo

%.bmp.h: %.bmp dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.bmp.c: %.bmp.h
	echo

%.psd.h: %.psd dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.psd.c: %.psd.h
	echo

%.gif.h: %.gif dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.gif.c: %.gif.h
	echo

%.hdr.h: %.hdr dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.hdr.c: %.hdr.h
	echo

%.pic.h: %.pic dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.pic.c: %.pic.h
	echo

%.pnm.h: %.pnm dist/tools/image_to_sprite
	./dist/tools/image_to_sprite \
		$(shell realpath --relative-to $(dir $<) src/software/library/sprite.h) \
		$@ \
		$<.c \
		$(basename $(basename $(basename $(notdir $@)))) \
		`echo $(basename $(basename $(basename $(notdir $@)))) | tr a-z A-Z`_H \
		$(notdir $@) \
		< $<

%.pnm.c: %.pnm.h
	echo

dist/tools/%: src/software/tools/%.c $(SUBMODULE_H_FILES) makefile
	mkdir -p $(dir $@)
	rm -f $@
	$(TOOL_CC) $(TOOL_CFLAGS) $< -o $@ $(TOOL_LDFLAGS)

obj/avr/compiled/%.o: src/software/%.c $(APPLICATION_H_FILES) $(LIBRARY_H_FILES) $(TARGET_H_FILES) makefile
	mkdir -p $(dir $@)
	rm -f $@
	$(AVR_CC) -c $(AVR_CFLAGS) $< -o $@

obj/avr/linked/%.out: $(AVR_TARGET_O_FILES) $(AVR_LIBRARY_O_FILES) $(AVR_APPLICATION_O_FILES) $(AVR_IMAGE_O_FILES)
	mkdir -p $(dir $@)
	rm -f $@
	$(AVR_CC) $(AVR_CFLAGS) $(AVR_TARGET_O_FILES) $(AVR_LIBRARY_O_FILES) $(filter obj/avr/compiled/applications/$*/%,$(AVR_APPLICATION_O_FILES)) $(filter obj/avr/compiled/applications/$*/%,$(AVR_IMAGE_O_FILES)) -o $@ $(AVR_LDFLAGS)

dist/avr/%.hex: obj/avr/linked/%.out
	mkdir -p $(dir $@)
	rm -f $@
	avr-objcopy -O ihex $< $@

obj/windows/%.o: src/software/%.c $(APPLICATION_H_FILES) $(LIBRARY_H_FILES) $(TARGET_H_FILES) makefile
	mkdir -p $(dir $@)
	rm -f $@
	$(WINDOWS_CC) -c $(WINDOWS_CFLAGS) $< -o $@

dist/windows/%.exe: $(WINDOWS_TARGET_O_FILES) $(WINDOWS_LIBRARY_O_FILES) $(WINDOWS_APPLICATION_O_FILES) $(WINDOWS_IMAGE_O_FILES)
	mkdir -p $(dir $@)
	rm -f $@
	$(WINDOWS_CC) $(WINDOWS_CFLAGS) $(WINDOWS_TARGET_O_FILES) $(WINDOWS_LIBRARY_O_FILES) $(filter obj/windows/applications/$*/%,$(WINDOWS_APPLICATION_O_FILES)) $(filter obj/windows/applications/$*/%,$(WINDOWS_IMAGE_O_FILES)) -o $@ $(WINDOWS_LDFLAGS)
