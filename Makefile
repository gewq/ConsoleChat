BIN = chat

CXX = g++
CXXFLAGS = -std=gnu++17 -Wall -Wextra


source_dirs := . Chat/States/AddresseeIsMissing Chat/States/EnteringAddressee Chat/States/LoginIncorrect Chat/States/LoginInputState Chat/States/LoginNonunique Chat/States/LoginUnique Chat/States/NameCorrectState Chat/States/PasswordIncorrect Chat/States/PasswordInputState Chat/States/Registration Chat/States/StartState Chat/States/UserInChat Chat DataBase Message SHA_1 State User
search_wildcards := $(addsuffix /*.cpp,$(source_dirs)) 

$(BIN): $(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards))))
	$(CXX) $^ $(CXXFLAGS) -o $@ 

VPATH := $(source_dirs)
 
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -MD $(addprefix -I,$(source_dirs)) $<

include $(wildcard *.d)

clean:
	rm *.o *.d