TARGET = switchmac
PREFIX = /usr/local/bin
CC = gcc

all: $(TARGET)

$(TARGET): switchmac.o setmac.o getmac.o 
	$(CC) switchmac.o setmac.o getmac.o -o switchmac
	
switchmac.o: switchmac.c
	$(CC) -c switchmac.c

setmac.o : setmac.c setmac.h
	$(CC) -c setmac.c
	
getmac.o : getmac.c getmac.h
	$(CC) -c getmac.c
	
clean:
	rm -rf *.o switchmac
	
install: 
	install $(TARGET) $(PREFIX)
	
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
	