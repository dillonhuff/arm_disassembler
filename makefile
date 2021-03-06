UNAME := $(shell uname)
DEP_CFLAGS := -O3 -g -Wall -Isrc/ -Itest/
CFLAGS := $(DEP_CFLAGS)
CFLAGS += -std=c++0x

ifeq ($(UNAME), Linux)
CC := g++
endif

ifeq ($(UNAME), Darwin)
CC := clang++
endif

LINKER := $(CC)

SOURCES :=  $(shell find ./ -type f -name '*.cpp')
OBJS := $(patsubst %.cpp, %.o, $(SOURCES))

all_tests: $(notdir $(OBJS))
	$(LINKER) $(CFLAGS) $(notdir $(OBJS)) -o $@

include $(OBJS:.o=.d)
include $(HEADERS:.h=.d)

%.d: %.cpp
	bash depends.sh $(DEP_CFLAGS) ./ $*.cpp > $@

clean:
	find . -type f -name '*~' -delete
	find . -type f -name '*.d' -delete
	find . -type f -name '*.o' -delete
	rm -f all_tests
