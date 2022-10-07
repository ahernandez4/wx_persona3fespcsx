#old one was this 
#g++ P3fMem.cpp  wxbinaryresource.cpp wx_persona3fespcsx2.cpp `wx-config --cxxflags --libs`

TARGET_PROGRAM = wx_persona3fespcsx2

CXX = $(shell wx-config --cxx)

# wx-config --libs
WX_LIBS = $(shell wx-config --libs)

# wx-config -cxxflags
WX_CXXFLAGS = $(shell wx-config --cxxflags)

SRC = $(shell find -name "*.cpp")
_OBJS = $(patsubst %.cpp,%.o,$(SRC))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))
BUILD_DIR = build
OBJ_DIR = obj

all: makedir $(BUILD_DIR)/$(TARGET_PROGRAM)

makedir:
	mkdir -p build
	mkdir -p obj

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(WX_CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET_PROGRAM): $(OBJS)
	$(CXX) -o $(BUILD_DIR)/$(TARGET_PROGRAM) $(OBJS) $(WX_LIBS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm -r $(OBJ_DIR)

