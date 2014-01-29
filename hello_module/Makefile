# Define the source directory
dir-src := src

# Define the type of files that are temporary
files-tmp := *~ .tmp_versions .*.cmd *.mod.c core .depend

# Define build result files
files-result := *.o *.ko

# These files will be removed on a clean
files-rm-clean := $(files-tmp) $(files-result)


# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)
	obj-m := $(dir-src)/kernel_hello_module.o

# Otherwise we were called directly from the command
# line; invoke the kernel build system.
else

# Include the location of the kernel directory
include kernel_dir_loc.makefile

	PWD := $(shell pwd)
	KERNELDIR ?= $(PWD)/$(kernel-dir-loc)/

	# For my own sanity, define the architecture and cross compiler
	LOCAL_ARCH ?= arm
	LOCAL_CROSS_COMPILE ?= arm-none-linux-gnueabi-

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(LOCAL_ARCH) CROSS_COMPILE=$(LOCAL_CROSS_COMPILE) modules

install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(LOCAL_ARCH) CROSS_COMPILE=$(LOCAL_CROSS_COMPILE) INSTALL_MOD_PATH=$(PWD)/test_modules modules_install

clean:
	rm -rf $(files-rm-clean)
	cd $(dir-src) && rm -rf $(files-rm-clean)

.PHONY: modules install clean

endif