#  Makefile

#-- Project variables -----------------------------------------#
PROJECT   = mythsnlegends
PREFIX    = /usr
SRC       = $(wildcard *.c)
OBJ       = $(SRC:.c=.o)
OBJDBG    = $(SRC:.c=.dbg.o)
#--------------------------------------------------------------#

#-- Compiler variables ----------------------------------------#
DBGFLAGS  = -g -O0 -DDEBUG
LDFLAGS   = `pkg-config --libs sdl` -lSDL_gfx
LIBSFLAGS = `pkg-config --cflags sdl`
CC        = gcc
CXX       = g++
CFLAGS    = -std=c99 -Wall -Wextra -Wwrite-strings -Wunreachable-code -include ./util.h $(LIBSFLAGS)
# CXXFLAGS  = $(CFLAGS)
#--------------------------------------------------------------#


#-- Targets ---------------------------------------------------#
all: $(OBJ)
	@echo "[**] Generating executable $(PROJECT)"
	@$(CC) $(CFLAGS) -o $(PROJECT) ./build/*.o $(LDFLAGS)
	@echo "[**] All done. Have fun."

debug: $(OBJDBG)
	@echo "[**] Generating debugging executable $(PROJECT)"
	@$(CC) $(CFLAGS) $(DBGFLAGS) -o $(PROJECT) ./debug/*.o $(LDFLAGS)
	@echo "[**] All done. May this reveal the annoying bug ;) ..."

%.o: %.c
	@echo "[CC] $< -> $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o ./build/$@

%.dbg.o: %.c
	@echo "[CC] $< -> $@"
	$(CC) $(CFLAGS) $(DBGFLAGS) $(INCLUDE) -c $< -o ./debug/$@

.PHONY: clean

clean:
	@echo "[**] Cleaning files."
	@rm -rf ./*/*.o ./*/*.obj
	@echo "[**] Cleaning executable."
	@rm $(PROJECT)
#--------------------------------------------------------------#
