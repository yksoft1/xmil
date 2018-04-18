#
# Makefile
#

CXX = g++
CC = gcc
STRIP = strip

SDL2CONF = sdl2-config

TARGET_DEBUG = xmil_d
TARGET = xmil

ifdef DEBUG
OPT_FLAG = -O0 -g
OBJS_DIR = objs_debug
BUILD = $(TARGET_DEBUG)
else
OPT_FLAG = -O3
OBJS_DIR = objs
BUILD = $(TARGET)
endif

ifeq ($(OS),Windows_NT)
EXE_PREFIX = .exe
else
EXE_PREFIX =
endif

TARGET_FILE = $(BUILD)$(EXE_PREFIX)

DIR_OBJS = objs

DIR_ROOT = ../..
DIR_COMMON = common
DIR_EMBED = embed
DIR_MENU = embed/menu
DIR_MENUBASE = embed/menubase
DIR_FDD = fdd
DIR_FONT = font
DIR_IO = io
DIR_EXT = sdl2/ext
DIR_SOUND = sound
DIR_SDL2 = sdl2
DIR_C86CTL = sdl2/ext/c86ctl
DIR_SCCI = sdl2/ext/scci
DIR_MINGW = sdl2/mingw
DIR_MISC = sdl2/mingw/misc
DIR_VRAM = vram
DIR_Z80C = z80c
DIR_CODECNV = codecnv

DIRS = $(DIR_COMMON) $(DIR_EMBED) $(DIR_MENU) $(DIR_MENUBASE) $(DIR_FDD)
DIRS += $(DIR_FONT) $(DIR_IO) $(DIR_EXT) $(DIR_SOUND) $(DIR_SDL2) $(DIR_C86CTL)
DIRS += $(DIR_SCCI) $(DIR_MINGW) $(DIR_MISC) $(DIR_VRAM) $(DIR_Z80C) $(DIR_CODECNV)

INC_DIR  = $(DIR_COMMON)
INC_DIR += $(DIR_SDL2)
INC_DIR += $(DIR_Z80C)
INC_DIR += $(DIR_IO)
INC_DIR += $(DIR_SOUND)
INC_DIR += $(DIR_VRAM)
INC_DIR += $(DIR_FONT)
INC_DIR += $(DIR_FDD)
INC_DIR += $(DIR_EMBED)
INC_DIR += $(DIR_MENUBASE)

COMMON_FLAGS = $(OPT_FLAG) -I. -I$(DIR_ROOT) $(addprefix -I$(DIR_ROOT)/,$(INC_DIR))
COMMON_FLAGS += $(shell $(SDL2CONF) --cflags)

CXXFLAGS = $(COMMON_FLAGS) --std=c++11
CFLAGS = $(COMMON_FLAGS)

SRC_ROOT = calendar.c debugsub.c ievent.c keystat.c
SRC_ROOT += nevent.c pccore.c statsave.c timing.c

SRC_COMMON = _memory.c bmpdata.c lstarray.c milstr.c parts.c
SRC_COMMON += profile.c rect.c resize.c strres.c textfile.c wavefile.c

SRC_EMBED = vramhdl.c vrammix.c

SRC_MENU = dlgabout.c dlgcfg.c filesel.c menustr.c

SRC_MENUBASE = menubase.c menudlg.c menuicon.c menumbox.c menures.c menusys.c menuvram.c

SRC_FDD = diskdrv.c fdd_2d.c fdd_d88.c fdd_ini.c fdd_mtr.c fddfile.c newdisk.c

SRC_FONT = font.c fontdata.c fontmake.c fontx1.c

SRC_IO = cgrom.c cmt.c crtc.c ctc.c dipsw.c dmac.c
SRC_IO += fdc.c iocore.c memio.c pcg.c ppi.c
SRC_IO += sio.c sndboard.c subcpu.c vramio.c

# SRC_EXT = opm.cpp psg.cpp

SRC_SOUND = opmgenc.c opmgeng.c psggenc.c 
SRC_SOUND += psggeng.c sndcsec.c sndctrl.c sound.c x1f.c
SRC_SOUND += opm.c psg.c

SRC_SDL2 = dosio.c fontmng.c ini.c joymng.c mousemng.c
SRC_SDL2 += scrnmng.c sdlkbd.c sysmenu.c sysmng.c taskmng.c
SRC_SDL2 += timemng.c trace.c xmil.c soundmng.cpp

SRC_MINGW = compiler.c main.c

SRC_MISC = threadbase.cpp tty.cpp 
# SRC_MISC += usbdev.cpp

SRC_VRAM = make15.c make24.c makeatr.c makechr.c makemix.c 
SRC_VRAM += makescrn.c makesub.c maketxth.c maketxtl.c palettes.c
SRC_VRAM += scrndraw.c scrnsave.c sdraw.c sdrawq16.c vram.c

SRC_Z80C = z80c.c z80c_cb.c z80c_ix.c z80c_iy.c z80c_mn.c z80c_sb.c
SRC_Z80C += z80dmap.c z80mem.c

SRC_CODECNV = eucsjis.c eucucs2.c sjiseuc.c sjisucs2.c tcswap16.c
SRC_CODECNV += tcswap32.c textcnv.c ucs2sjis.c ucs2utf8.c utf8ucs2.c

LDLAGS = 
LIBS = $(shell $(SDL2CONF) --libs) -lSDL2_ttf

SRCS  = $(SRC_ROOT)
SRCS += $(addprefix $(DIR_COMMON)/,$(SRC_COMMON))
SRCS += $(addprefix $(DIR_EMBED)/,$(SRC_EMBED))
SRCS += $(addprefix $(DIR_MENU)/,$(SRC_MENU))
SRCS += $(addprefix $(DIR_MENUBASE)/,$(SRC_MENUBASE))
SRCS += $(addprefix $(DIR_FDD)/,$(SRC_FDD))
SRCS += $(addprefix $(DIR_FONT)/,$(SRC_FONT))
SRCS += $(addprefix $(DIR_IO)/,$(SRC_IO))
SRCS += $(addprefix $(DIR_EXT)/,$(SRC_EXT))
SRCS += $(addprefix $(DIR_SOUND)/,$(SRC_SOUND))
SRCS += $(addprefix $(DIR_SDL2)/,$(SRC_SDL2))
SRCS += $(addprefix $(DIR_C86CTL)/,$(SRC_C86CTL))
SRCS += $(addprefix $(DIR_SCCI)/,$(SRC_SCCI))
SRCS += $(addprefix $(DIR_MINGW)/,$(SRC_MINGW))
SRCS += $(addprefix $(DIR_MISC)/,$(SRC_MISC))
SRCS += $(addprefix $(DIR_VRAM)/,$(SRC_VRAM))
SRCS += $(addprefix $(DIR_Z80C)/,$(SRC_Z80C))
SRCS += $(addprefix $(DIR_CODECNV)/,$(SRC_CODECNV))


OBJS_FILE := $(patsubst %.c,%.o,$(SRCS))
OBJS_FILE := $(patsubst %.cpp,%.o,$(OBJS_FILE))

OBJS = $(addprefix $(DIR_OBJS)/,$(OBJS_FILE))

all : $(OBJS_DIR) $(BUILD)

clean : 
	rm -rf $(OBJS_DIR)
	rm -f $(TARGET_FILE)

$(OBJS_DIR) : 
	mkdir -p $(OBJS_DIR)
	mkdir -p $(addprefix $(DIR_OBJS)/,$(DIRS))

$(TARGET) : $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(STRIP) $(TARGET_FILE)

$(TARGET_DEBUG) : $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)


$(DIR_OBJS)/%.o : $(DIR_ROOT)/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(DIR_OBJS)/%.o : $(DIR_ROOT)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<
