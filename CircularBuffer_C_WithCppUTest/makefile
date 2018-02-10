#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = CircularBuffer

#--- Inputs ----#
PROJECT_HOME_DIR = .

SRC_FILES = CircularBuffer.cpp

TEST_SRC_FILES = CircularBufferTest.cpp main.cpp

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\

CPPUTEST_CFLAGS += -std=c99
CPPUTEST_CXXFLAGS += -std=c++11
CPPUTEST_CFLAGS += -Wno-unused-parameter
CPPUTEST_WARNINGFLAGS += -Wall 
CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wfatal-errors
CPPUTEST_WARNINGFLAGS += -Wno-reserved-id-macro
CPPUTEST_WARNINGFLAGS += -Wno-keyword-macro
CPPUTEST_WARNINGFLAGS += -Wno-unused-variable
CPPUTEST_WARNINGFLAGS += -Wno-c++98-compat-pedantic
CPPUTEST_WARNINGFLAGS += -Wno-reserved-id-macro
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
