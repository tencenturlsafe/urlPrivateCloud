EXECUTABLE := matchServer

SLIBS := uv url_cloud64 curl ssl crypto
DLIBS := m dl rt pthread z
INCS := ./include ../../include ../common 
LIBPATHS := ./lib ../../lib

USER_MARCOS := _POSIX_THREADS _LINUX_OS_ _FILE_OFFSET_BITS=64
CFLAGS = -Wall --no-strict-aliasing -g
CC = gcc -std=gnu99

SOURCE := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SOURCE))

%.o:%.c
	$(CC) $(CFLAGS) $(addprefix -D,$(USER_MARCOS)) $(addprefix -I,$(INCS)) -c $< -o $@

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(addprefix -L,$(LIBPATHS))  -o $(EXECUTABLE) $(OBJS) -Wl,-Bstatic $(addprefix -l,$(SLIBS)) -Wl,-Bdynamic $(addprefix -l,$(DLIBS))

clean :
	rm -rf *.d *.o *.lo $(EXECUTABLE)
# DO NOT DELETE
