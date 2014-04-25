CXX=g++
CXXFLAGS=-Wall -std=c++11
SRCS=Transport.cpp DistanceBased.cpp Bus.cpp Railway.cpp FlatFare.cpp CableCar.cpp main_original.cpp
OBJS=$(SRCS:.cpp=.o)
LIBS=
TARGET=pa3

all: $(SRCS) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
