CC = gcc
CFLAGS = -g -O2
OBJECTS = crossingcli.o crossing.o
LIBS = -lcurl

cross : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o cross $(LIBS)

crossingcli.o : crossingcli.c
	$(CC) $(CFLAGS) -c crossingcli.c

crossing.o : lib/crossing.c
	$(CC) $(CFLAGS) -c lib/crossing.c
