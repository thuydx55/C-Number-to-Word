CC=gcc
CFLAGS=-I. 
# DEPS = hellomake.h
OBJ = main.o Number.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)