EXECUTABLE_QUERY_USERDATA := query_userdata
EXECUTABLE_INSERT_USERDATA := insert_userdata

SLIBS := url_cloud64 curl ssl crypto
DLIBS := m dl rt pthread z
INCS := ../../include 
LIBPATHS := ../../lib

USER_MARCOS := _POSIX_THREADS _LINUX_OS_ _FILE_OFFSET_BITS=64
CFLAGS = -Wall --no-strict-aliasing -g
CC = gcc -std=gnu99

QUERY_SOURCE := query_userdata.c 
INSERT_SOURCE := insert_userdata.c

QUERY_OBJS := $(patsubst %.c,%.o,$(QUERY_SOURCE))
INSERT_OBJS := $(patsubst %.c,%.o,$(INSERT_SOURCE))

%.o:%.c
	$(CC) $(CFLAGS) $(addprefix -D,$(USER_MARCOS)) $(addprefix -I,$(INCS)) -c $< -o $@

all: $(EXECUTABLE_QUERY_USERDATA) $(EXECUTABLE_INSERT_USERDATA)

$(EXECUTABLE_QUERY_USERDATA): $(QUERY_OBJS)
	$(CC) $(CFLAGS) $(addprefix -L,$(LIBPATHS))  -o $(EXECUTABLE_QUERY_USERDATA) $(QUERY_OBJS) -Wl,-Bstatic $(addprefix -l,$(SLIBS)) -Wl,-Bdynamic $(addprefix -l,$(DLIBS))

$(EXECUTABLE_INSERT_USERDATA): $(INSERT_OBJS)
	$(CC) $(CFLAGS) $(addprefix -L,$(LIBPATHS))  -o $(EXECUTABLE_INSERT_USERDATA) $(INSERT_OBJS) -Wl,-Bstatic $(addprefix -l,$(SLIBS)) -Wl,-Bdynamic $(addprefix -l,$(DLIBS))

clean :
	rm -rf *.d *.o *.lo $(EXECUTABLE_QUERY_USERDATA) $(EXECUTABLE_INSERT_USERDATA)
# DO NOT DELETE
