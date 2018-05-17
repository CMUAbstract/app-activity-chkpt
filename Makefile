export BOARD ?= msp-exp430fr5994
#export BOARD ?= wisp

TOOLS = \
	mementos \
	dino \

TOOLCHAINS = \
	gcc \
	clang \
	mementos \
	dino \

include ext/maker/Makefile

# Not clear why export from maker/Makefile.env does not propagate
export LLVM_ROOT

# Paths to toolchains here if not in or different from defaults in Makefile.env

export MEMENTOS_ROOT ?= $(LIB_ROOT)/mementos
export DINO_ROOT ?= $(LIB_ROOT)/dino
