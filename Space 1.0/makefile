TARGET = Space
OBJS = main.o space.o  

INCDIR = 
CFLAGS = -G4 -Wall -O2 
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
STDLIBS = -lstdc++ -losl -lpng -lz \
-lpspsdk -lpspctrl -lpspumd \
-lpsprtc -lpsppower -lpspgu \
-lpspaudiolib -lpspaudio -lm -lmikmod
LIBS=$(STDLIBS)$(YOURLIBS)


EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Space


PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak