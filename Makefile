TARGET = switchmac
PREFIX = /usr/local/bin
CC = gcc
OBJECTS = switchmac.o setmac.o getmac.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)	
	
switchmac.o: switchmac.c
	$(CC) -c switchmac.c

setmac.o: setmac.c setmac.h
	$(CC) -c setmac.c
	
getmac.o: getmac.c getmac.h
	$(CC) -c getmac.c
	
clean:
	rm -rf *.o switchmac
	
install: 
	install $(TARGET) $(PREFIX)
	
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
	
