EXEC = ar.out

OBJECTS = \
	main.o \

include $(MAKER_ROOT)/Makefile.dino
include $(MAKER_ROOT)/Makefile.board
include $(MAKER_ROOT)/Makefile.console
include $(MAKER_ROOT)/Makefile.edb

CFLAGS += \
	-I$(LIBMSP_ROOT)/src/include \
	-I$(LIBMSPMATH_ROOT)/src/include \
	-I$(LIBMSPBUILTINS_ROOT)/src/include \
	-I$(LIBIO_ROOT)/src/include \

LLVM_LIBS += \
	$(LIBMSPMATH_ROOT)/bld/clang/libmspmath.a.bc \
	$(LIBMSP_ROOT)/bld/clang/libmsp.a.bc \

LFLAGS += \
	-L$(LIBMSPBUILTINS_ROOT)/bld/gcc \

LIBS += \
	-lmspbuiltins \

VPATH = ../../src
