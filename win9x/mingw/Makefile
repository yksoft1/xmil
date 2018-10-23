# makefile for arm-linux
#   gcc version 4

CC		=	gcc
CXX		=	g++
WINDRES =   windres
STRIP	=	strip
RM		=	rm -f

XMIL_PATH	= ../..

CFLAGS	=	-O3 -Wstrict-overflow=0 -Wstrict-aliasing=0 -Wno-narrowing -DNDEBUG -I. -I.. \
			-I$(XMIL_PATH) \
			-I$(XMIL_PATH)/codecnv \
			-I$(XMIL_PATH)/common \
			-I$(XMIL_PATH)/fdd \
			-I$(XMIL_PATH)/font \
			-I$(XMIL_PATH)/io \
			-I$(XMIL_PATH)/sound \
			-I$(XMIL_PATH)/vram \
			-I$(XMIL_PATH)/z80c \
			-I$(XMIL_PATH)/win9x/dialog \
			-I$(XMIL_PATH)/win9x/misc \
			-I$(XMIL_PATH)/win9x/subwnd \
			-I$(XMIL_PATH)/win9x/ext \
			-I$(XMIL_PATH)/win9x/ext/c86cpl \
			-I$(XMIL_PATH)/win9x/ext/romeo \
			-I$(XMIL_PATH)/win9x/ext/scci 

CXXFLAGS = -std=gnu++0x $(CFLAGS)

#CFLAGS	+=	$(shell sdl2-config --cflags)
LFLAGS	= -static -mwindows

TARGET	=	xmil.exe

CPPSRCS	=	$(wildcard $(XMIL_PATH)/*.c) \
			$(wildcard $(XMIL_PATH)/codecnv/*.c) \
			$(XMIL_PATH)/common/_memory.c \
			$(XMIL_PATH)/common/bmpdata.c \
			$(XMIL_PATH)/common/milstr.c \
			$(XMIL_PATH)/common/parts.c \
			$(XMIL_PATH)/common/profile.c \
			$(XMIL_PATH)/common/strres.c \
			$(XMIL_PATH)/common/textfile.c \
			$(XMIL_PATH)/common/wavefile.c \
			$(XMIL_PATH)/generic/cmndraw.c \
			$(XMIL_PATH)/generic/keydisp.c \
			$(XMIL_PATH)/generic/softkbd.c \
			$(wildcard $(XMIL_PATH)/win9x/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/dialog/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/misc/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/subwnd/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/ext/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/ext/c86ctl/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/ext/romeo/*.cpp)\
			$(wildcard $(XMIL_PATH)/win9x/ext/scci/*.cpp)\
			$(wildcard $(XMIL_PATH)/fdd/*.c) \
			$(wildcard $(XMIL_PATH)/font/*.c) \
			$(wildcard $(XMIL_PATH)/io/*.c) \
			$(XMIL_PATH)/sound/opmgeng.c \
			$(XMIL_PATH)/sound/opmgenc.c \
			$(XMIL_PATH)/sound/psggeng.c \
			$(XMIL_PATH)/sound/psggenc.c \
			$(XMIL_PATH)/sound/sndctrl.c \
			$(XMIL_PATH)/sound/sound.c \
			$(XMIL_PATH)/sound/x1f.c \
			$(wildcard $(XMIL_PATH)/vram/*.c) \
			$(wildcard $(XMIL_PATH)/z80c/*.c) 

OBJS = $(addsuffix .o,$(basename $(CPPSRCS)))
LIBS =  -lstdc++ -lm -lcomctl32 -lcomdlg32 -lwinmm -ldxguid -lddraw -ldsound 

.SUFFIXES: .c.o
.SUFFIXES: .cpp.o
.SUFFIXES: .rc.o

all:	$(TARGET)

$(TARGET):	$(OBJS) $(XMIL_PATH)/win9x/xmil_mingw.o
	$(CC) $(LFLAGS) -g -o $@ $(OBJS) $(XMIL_PATH)/win9x/xmil_mingw.o $(LIBS) 
	$(STRIP) $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(XMIL_PATH)/win9x/xmil_mingw.o: $(XMIL_PATH)/win9x/xmil_mingw.rc
	$(WINDRES) -i $< -o $@
		
clean:
	rm -f $(TARGET) $(OBJS) $(XMIL_PATH)/win9x/xmil_mingw.o
