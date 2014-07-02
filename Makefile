INSTALLDIR= $(shell pwd)/modules
ifneq ($(KERNELRELEASE),)
	obj-m := char_scull.o
char_scull-objs := chardrvr.o charproc.o charopen.o charclose.o charwrite.o charread.o charlseek.o

else
	KERNDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
	rm -rf $(INSTALLDIR)

endif

