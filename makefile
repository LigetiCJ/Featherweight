CC=gcc
libraries=-lgdi32 -lopengl32 -lpthread -lglew32 -lglfw3dll -lcglm
extra=-DGLEW_STATIC
progname=projectN

all:
	$(CC) src/*.c -Iinclude $(libraries) -o $(progname) -Wall