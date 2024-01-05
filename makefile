CC=gcc
libraries=-lgdi32 -lopengl32 -lpthread -lglew32 -lglfw3dll -lcglm
extra=-DGLEW_STATIC
progname=projectN

all:
	$(CC) src/*.c -Iinclude $(libraries) -o $(progname) -Wall

release:
	$(CC) src/*.c -Iinclude $(libraries) -o $(progname) -Wall -O3 -mwindows
	strip $(progname).exe
	
	
tiny:
	$(CC) src/*.c -Iinclude $(libraries) -o $(progname) -Wall -Os -mwindows
	strip $(progname).exe
