appname := soem

XENO_CONFIG := /usr/xenomai/bin/xeno-config
CFLAGS := -I/usr/xenomai/include/trank -D__XENO_COMPAT__ -I/usr/xenomai/include/cobalt -I/usr/xenomai/include -D_GNU_SOURCE -D_REENTRANT -D__COBALT__ -I/usr/xenomai/include/alchemy -I/usr/xenomai/include/cobalt -I/usr/xenomai/include 
LDFLAGS := $(shell $(XENO_CONFIG) --native --ldflags)
CC := $(shell $(XENO_CONFIG) --cc)

srcfiles := $(shell find . -name "*.c")
objects := $(patsubst %.c, %.o, $(srcfiles))
headers := $(patsubst %.c, %.h, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CC) -o $(appname) $(objects) $(CFLAGS) $(LDFLAGS)
	ar -rv $(appname).a ethercatdc.o  osal.o  ethercatmain.o  ethercatconfig.o  ethercatfoe.o  nicdrv.o  ethercatbase.o  ethercatsoe.o ethercatcoe.o  ethercatprint.o  oshw.o
	mkdir install
	mkdir install/include
	mkdir install/lib
	cp $(appname).a install/lib
	cp $(headers) install/include

clean:
	rm -f $(objects)
	rm -f soem.a
	rm -f soem
	rm -rf install/
