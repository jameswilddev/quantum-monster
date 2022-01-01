APPLICATION_DIRECTORIES = $(shell find src/software/applications/* -type d)
APPLICATION_NAMES = $(APPLICATION_DIRECTORIES:src/software/applications/%=%)
AVR_DISTRIBUTABLES = $(addsuffix .hex,$(addprefix dist/avr/,$(APPLICATION_NAMES)))

all:
	echo $(AVR_DISTRIBUTABLES)
