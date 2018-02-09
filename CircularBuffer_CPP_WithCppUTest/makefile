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

CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wfatal-errors
CPPUTEST_CXXFLAGS += -Wno-reserved-id-macro
CPPUTEST_CXXFLAGS += -Wno-keyword-macro
CPPUTEST_CXXFLAGS += -Wno-unused-variable
CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ./MyMemoryLeakDetectorNewMacrosFile.h

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
