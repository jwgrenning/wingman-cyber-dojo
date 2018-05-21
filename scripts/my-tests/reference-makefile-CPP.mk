#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = CircularBuffer

#--- Inputs ----#
PROJECT_HOME_DIR = .

SRC_FILES = CircularBuffer.cpp

TEST_SRC_FILES = AllTests.cpp CircularBufferTest-Ref.cpp

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\

CPPUTEST_WARNINGFLAGS += -Wall 
CPPUTEST_WARNINGFLAGS += -Werror
CPPUTEST_WARNINGFLAGS += -Wswitch-default
CPPUTEST_WARNINGFLAGS += -Wfatal-errors
CPPUTEST_WARNINGFLAGS += -Wno-shadow
CPPUTEST_WARNINGFLAGS += -Wno-missing-variable-declarations
CPPUTEST_WARNINGFLAGS += -Wno-reserved-id-macro
CPPUTEST_WARNINGFLAGS += -Wno-keyword-macro
#CPPUTEST_WARNINGFLAGS += 
#CPPUTEST_WARNINGFLAGS += 

CPPUTEST_CXXFLAGS += -Wno-c++98-compat-pedantic
CPPUTEST_CXXFLAGS += -std=c++11
CPPUTEST_CXXFLAGS += -Wno-c++14-compat

CPPUTEST_CFLAGS += -std=c99
CPPUTEST_CFLAGS += -Wno-unused-parameter
CPPUTEST_CFLAGS += -Wno-strict-prototypes
CPPUTEST_CFLAGS += -Wno-missing-prototypes




CPPUTEST_CXXFLAGS += $(CPPUTEST_PLATFORM_CXXFLAGS)

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
