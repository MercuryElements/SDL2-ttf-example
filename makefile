CC = gcc

CFLAGS = -Wall -std=c99 -g #Common flags

LIBS = -L./SDL2_ttf-2.0.14/.libs #Location of the library

LFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf #Library flags

INCLUDES = -I./SDL2_ttf-2.0.14 #Location of the header files

SRCS = main.c

OBJS = $(SRCS:.c=.o)

BIN = ex_SDL2-ttf

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BIN) $^ $(LIBS) $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBS) $(LFLAGS)

clean:
	$(RM) *.o *~ $(BIN)	
