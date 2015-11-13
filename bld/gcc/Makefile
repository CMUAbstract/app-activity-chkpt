EXEC = ar.out

OBJECTS = \
	main.o \

BOARD = mspts430
CONFIG_EDB = 0
CONFIG_PRINTF_LIB = libmspconsole
CONFIG_LIBEDB_PRINTF = eif

include $(MAKER_ROOT)/Makefile.gcc
include $(MAKER_ROOT)/Makefile.board
include $(MAKER_ROOT)/Makefile.console
include $(MAKER_ROOT)/Makefile.edb

CFLAGS += \
	-I$(LIBMSP_ROOT)/src/include \
	-I$(LIBMSPBUILTINS_ROOT)/src/include \
	-I$(LIBMSPMATH_ROOT)/src/include \
	-I$(LIBIO_ROOT)/src/include \

LFLAGS += \
	-L$(LIBMSPMATH_ROOT)/bld/gcc \

LIBS += \
	-lmspmath \

VPATH = ../../src
