#
# Makefile for a workspace of EV3 Platform.
#

# Configuration
SRCLANG := c
KERNEL := hrp2

#
# Functions
#
get_relpath = $(shell perl -MFile::Spec -e "print File::Spec->abs2rel(q($1),q($2))")

#
# Paths
#
KERNELDIR    := $(EV3_ROOT)/..
OBJDIR       := $(EV3_ROOT)/OBJ
LIBKERNELDIR := $(KERNELDIR)
TARGETDIR    := $(KERNELDIR)/target/ev3_gcc

# Object files
OBJFILENAME := $(KERNEL)
ifneq (, $(findstring CYGWIN, $(shell uname)))
    OBJFILENAME := $(OBJFILENAME).exe
endif
OBJBINARY := $(OBJDIR)/$(KERNEL).bin

#
# Target for an application module (dynamic)
#
APPLDIR := $(PWD)
MKFILENAME := Makefile.appmod

include $(APPLDIR)/Makefile.inc

appmod: clean $(APPLDIR)
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && \
	$(KERNELDIR)/configure -T ev3_gcc -A app \
		-a $(call get_relpath,$(APPLDIR),$(OBJDIR)) \
		-t $(call get_relpath,$(APPLDIR),$(OBJDIR)) \
		-D $(call get_relpath,$(KERNELDIR),$(OBJDIR)) \
		-l $(SRCLANG) \
		-m $(MKFILENAME) -o "-DBUILD_MODULE" \
		-U "$(APPLOBJS)" && \
	mv $(MKFILENAME) Makefile && \
	make clean && \
	make module_cfg.h && \
	make -j8 && \
	cp app $(PWD)
	mv $(PWD)/app $(PWD)/selab

clean:
	rm -rf $(OBJDIR)

realclean: clean
	rm -rf $(notdir $(OBJFILENAME)) uImage app $(LIBKERNELDIR)/libkernel.a


.PHONY: clean realclean app appmod

