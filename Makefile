CC=gcc
AR=ar
STRIP=strip
RM=rm -rf
CFLAGS=
LDFLAGS=
INCLUDE_DIR=-I./ -I./inc
TARGET=libjson_al.a

OBJECTS=./arraylist.o ./json_object.o ./linkhash.o ./debug.o \
			./json_tokener.o ./printbuf.o ./json_api.o ./json_util.o

all:$(OBJECTS)
	$(AR) rc  $(TARGET) $(OBJECTS)
#	$(STRIP) $(TARGET)

$(OBJECTS):%.o:%.c
	$(CC) $(CFLAGS) -c $(INCLUDE_DIR) $< -o $@

demo:
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -o test test.c -L./ -lkpf -ljson_al

clean:
	$(RM) -rf $(OBJECTS)
	$(RM) -rf $(TARGET)
	$(RM) -rf test
