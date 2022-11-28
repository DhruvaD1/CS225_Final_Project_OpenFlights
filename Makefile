EXENAME = main
OBJS = main.o create_graoh.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: ${EXENAME}

$(EXENAME): $(OBJS)
    $(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
    $(CXX) $< $(CXXFLAGS)

create_graoh.o: create_graoh.cpp
    $(CXX) $< $(CXXFLAGS)

clean:
    -rm -f *.o $(EXENAME)
