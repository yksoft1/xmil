# makefile for emscripten
#   gcc version 4

CC		=	emcc
RM		=	rm -f

ifeq ($(EMSCRIPTEN_ROOT),)
#Set it yourself if EMSCRIPTEN_ROOT not there
	EMSCRIPTEN_ROOT=c:/emsdk/emscripten/1.38.12
endif

#WebAssembly seemed to be a bit faster than asm.js
WASM=1

#Set maximum RAM that Emscripten use (in bytes).
EMSCRIPTEN_TOTAL_MEMORY=67108864

SDL_CONFIG ?= $(EMSCRIPTEN_ROOT)/system/bin/sdl2-config 
SDL_CFLAGS := $(shell $(SDL_CONFIG) --cflags) 
SDL_LIBS := $(shell $(SDL_CONFIG) --libs)

XMIL_PATH	= ../..

CFLAGS	=	-Wall -O3 -Wstrict-overflow=0 -Wstrict-aliasing=0 -I. -I.. \
			-I$(XMIL_PATH) \
			-I$(XMIL_PATH)/codecnv \
			-I$(XMIL_PATH)/common \
			-I$(XMIL_PATH)/embed \
			-I$(XMIL_PATH)/embed/menu \
			-I$(XMIL_PATH)/embed/menubase \
			-I$(XMIL_PATH)/fdd \
			-I$(XMIL_PATH)/font \
			-I$(XMIL_PATH)/io \
			-I$(XMIL_PATH)/sound \
			-I$(XMIL_PATH)/vram \
			-I$(XMIL_PATH)/z80c

CFLAGS	+=	$(SDL_CFLAGS)
LFLAGS	= 	 

ifeq ($(EMULARITY), 1)
	CFLAGS	+= -DUSE_EMULARITY_NP2DIR
endif

TARGET	=	xmil.bc

CPPSRCS	=	./main.c \
			$(wildcard $(XMIL_PATH)/*.c) \
			$(wildcard $(XMIL_PATH)/codecnv/*.c) \
			$(wildcard $(XMIL_PATH)/common/*.c) \
			$(wildcard $(XMIL_PATH)/embed/*.c) \
			$(wildcard $(XMIL_PATH)/embed/menu/*.c) \
			$(wildcard $(XMIL_PATH)/embed/menubase/*.c) \
			$(wildcard $(XMIL_PATH)/fdd/*.c) \
			$(wildcard $(XMIL_PATH)/font/*.c) \
			$(wildcard $(XMIL_PATH)/io/*.c) \
			$(wildcard $(XMIL_PATH)/sound/*.c) \
			$(wildcard $(XMIL_PATH)/vram/*.c) \
			$(wildcard $(XMIL_PATH)/z80c/*.c) \
			$(wildcard $(XMIL_PATH)/sdl2/*.c) \
			$(wildcard $(XMIL_PATH)/sdl2/*.cpp)

OBJS = $(addsuffix .o,$(basename $(CPPSRCS)))
LIBS = -lm  $(SDL_LIBS) 

.SUFFIXES: .c.o
.SUFFIXES: .cpp.o

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(LFLAGS) -g -o $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

html: $(TARGET)
ifeq ($(PRELOAD), 1)
	$(CC) -O3 -s USE_SDL=2 -s WASM=$(WASM) -s TOTAL_MEMORY=$(EMSCRIPTEN_TOTAL_MEMORY)  -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 \
	-s EMTERPRETIFY_WHITELIST=@em.txt $(TARGET) \
	--preload-file $(PREFILE) -o $(basename $(TARGET)).html 
else
	$(CC) -O3 -s USE_SDL=2 -s WASM=$(WASM) -s TOTAL_MEMORY=$(EMSCRIPTEN_TOTAL_MEMORY)  -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 \
	-s EMTERPRETIFY_WHITELIST=@em.txt $(TARGET) -o $(basename $(TARGET)).html 
endif