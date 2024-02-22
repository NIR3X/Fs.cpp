AR = ar
CXX = g++
CXXFLAGS = -std=c++2b -Wall -O2 -march=x86-64 -fno-rtti
LDFLAGS = -s -static

SRC = Fs.cpp
OBJ = $(SRC:.cpp=.o)
DEST = Fs.a
TEST_SRC = FsTest.cpp
TEST_DEST = FsTest.exe

build: $(OBJ)
	$(AR) r -o $(DEST) $^

build-test: build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(DEST) -o $(TEST_DEST) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DEST) $(TEST_DEST)
