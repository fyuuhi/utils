#EXENAME = main
#
#OBJS = main.o
#main.o: main.cxx AnaL2MuonSA.h EventDisplay.h
#
#AR = g++
#CXX = g++
#
#ROOTINCS      = $(shell root-config --cflags)
#ROOTLIBS      = $(shell root-config --glibs)
#
#CXXFLAGS      = -g -Wall -fPIC $(ROOTINCS)
#SOFLAGS       = -shared
#
#all: $(OBJS)
#	$(CXX) -o $(EXENAME) $(OBJS) $(ROOTLIBS)
#
#%.o:%.cxx
#	$(CXX) $(CXXFLAGS) -c $< -o $@
#
#%.o:%.C
#	$(CXX) $(CXXFLAGS) -c $< -o $@
#
#%.o:%.cc
#
#clean:
#	rm $(EXENAME) $(OBJS)

PROGRAM_NAME := main

# compiler
CXX := g++
ROOTINCS      = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --glibs)

CXXFLAGS      = -g -Wall -fPIC $(ROOTINCS)
SOFLAGS       = -shared

# directory
OUT_DIR := out
SOURCE_DIR := src
HEADER_DIR := include

SOURCES := $(wildcard $(SOURCE_DIR)/*.cxx)
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

PROGRAM_DIR := $(OUT_DIR)/bin
OBJ_DIR := $(OUT_DIR)/obj
DEPEND_DIR := $(OUT_DIR)/depend

PROGRAM := $(PROGRAM_DIR)/$(PROGRAM_NAME)
SOURCE_NAMES = $(notdir $(SOURCES))
OBJS := $(addprefix $(OBJ_DIR)/,$(SOURCE_NAMES:.cxx=.o))
DEPENDS := $(addprefix $(DEPEND_DIR)/,$(SOURCE_NAMES:.cxx=.depend))

.PHONY: all
all: $(DEPENDS) $(PROGRAM)
$(PROGRAM): $(OBJS)
	@mkdir -p $(PROGRAM_DIR)
	$(CXX) $(CXXFLAGS) $(LIBS) $^ -o $(PROGRAM)

$(DEPEND_DIR)/%.depend: $(SOURCE_DIR)/%.cxx $(HEADERS)
	@echo "generating $@"
	@mkdir -p $(DEPEND_DIR)
	@$(CXX) $(CXXFLAGS) $(LIBS) -I$(HEADER_DIR) -MM $< > $@

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cxx
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(LIBS) -I$(HEADER_DIR) -c $^ -o $@


ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEPENDS)
endif

.PHONY : clean
clean:
	$(RM) -r $(OUT_DIR)

