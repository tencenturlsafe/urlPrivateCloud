EXECUTABLE_ONLINE_UPDATE := online_update
EXECUTABLE_SINGLE_MATCH := single_match
EXECUTABLE_MULTI_MATCH  := multi_match

SLIBS := url_cloud64 curl ssl crypto
DLIBS := m dl rt pthread z
INCS := ../../include 
LIBPATHS := ../../lib

USER_MARCOS := _POSIX_THREADS _LINUX_OS_ _FILE_OFFSET_BITS=64
CFLAGS = -Wall --no-strict-aliasing -g 
CC = gcc -std=gnu99

ONLINE_SOURCE := online_update.c
SINGLE_SOURCE := single_match.c 
MULTI_SOURCE := multi_match.c

ONLINE_OBJS := $(patsubst %.c,%.o,$(ONLINE_SOURCE))
SINGLE_OBJS := $(patsubst %.c,%.o,$(SINGLE_SOURCE))
MULTI_OBJS := $(patsubst %.c,%.o,$(MULTI_SOURCE))

%.o:%.c
	$(CC) $(CFLAGS) $(addprefix -D,$(USER_MARCOS)) $(addprefix -I,$(INCS)) -c $< -o $@

all: $(EXECUTABLE_ONLINE_UPDATE) $(EXECUTABLE_SINGLE_MATCH) $(EXECUTABLE_MULTI_MATCH)

$(EXECUTABLE_ONLINE_UPDATE): $(ONLINE_OBJS)
	$(CC) $(CFLAGS) $(addprefix -L,$(LIBPATHS))  -o $(EXECUTABLE_ONLINE_UPDATE) $(ONLINE_OBJS) -Wl,-Bstatic $(addprefix -l,$(SLIBS)) -Wl,-Bdynamic $(addprefix -l,$(DLIBS))

$(EXECUTABLE_SINGLE_MATCH): $(SINGLE_OBJS)
	$(CC) $(CFLAGS) $(addprefix -L,$(LIBPATHS))  -o $(EXECUTABLE_SINGLE_MATCH) $(SINGLE_OBJS) -Wl,-Bstatic $(addprefix -l,$(SLIBS)) -Wl,-Bdynamic $(addprefix -l,$(DLIBS))

$(EXECUTABLE_MULTI_MATCH): $(MULTI_OBJS)
	$(CC) $(CFLAGS) $(addprefix -L,$(LIBPATHS))  -o $(EXECUTABLE_MULTI_MATCH) $(MULTI_OBJS) -Wl,-Bstatic $(addprefix -l,$(SLIBS)) -Wl,-Bdynamic $(addprefix -l,$(DLIBS))

clean :
	rm -rf *.d *.o *.lo $(EXECUTABLE_ONLINE_UPDATE) $(EXECUTABLE_SINGLE_MATCH) $(EXECUTABLE_MULTI_MATCH)
# DO NOT DELETE
