EXEC = ar.out

OBJECTS = \
	main.o \

BOARD = wisp
CONFIG_EDB = 1
CONFIG_PRINTF_LIB = libedb
CONFIG_LIBEDB_PRINTF = eif

MEMENTOS_MODE = timer+latch
MEMENTOS_VARIANT ?= V

include $(MAKER_ROOT)/Makefile.mementos
include $(MAKER_ROOT)/Makefile.board
include $(MAKER_ROOT)/Makefile.console
include $(MAKER_ROOT)/Makefile.edb

# TODO: for some reason using the type threeAxis_t_8 crashes LLVM/Clang
# NOTE: wisp-base lib must be compiled with same config
CFLAGS += -DACCEL_16BIT_TYPE

ifeq ($(MEMENTOS_VARIANT),NV)
CFLAGS += -DMEMENTOS_NONVOLATILE
else ifeq ($(MEMENTOS_VARIANT),V)
# nothing to set, that's by default
endif

CFLAGS += \
	-I$(LIBMSP_ROOT)/src/include \
	-I$(LIBMSPMATH_ROOT)/src/include \
	-I$(LIBMSPBUILTINS_ROOT)/src/include \
	-I$(LIBIO_ROOT)/src/include \

LLVM_NOOPT_LIBS += \
	$(LIBMSPMATH_ROOT)/bld/clang/libmspmath.a.bc \
	$(LIBMSP_ROOT)/bld/clang/libmsp.a.bc \

LFLAGS+= \
	-L$(LIBMSPBUILTINS_ROOT)/bld/gcc \

LIBS += \
	-lmspbuiltins \

VPATH = ../../src
