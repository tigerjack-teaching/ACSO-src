obj-m := helloaxo.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
# KERNELDIR ?= /lib/modules/5.9.9-arch1-1/build
PWD       := $(shell pwd)
# EXTRAVERSION=-arch1-1

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

build:
	# $(MAKE) EXTRAVERSION=$(EXTRAVERSION) --debug=v -C $(KERNELDIR) M=$(PWD) modules
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
