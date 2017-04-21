CXX=g++
CXXFLAGS=-Wall -std=c++11 $(DEBUG)

SRCS = NumberRepresentation/Number.o \
		NumberRepresentation/Language.o \
		NumberRepresentation/LanguageEnglish.o \
		NumberRepresentation/LanguageVietnamese.o
MAIN = main.o $(SRCS)
TEST = test.o $(SRCS) 

# $(info $(SRCS))
# $(info $(MAIN))
# $(info $(TEST))

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(MAIN)
	$(CXX) -o $@ $^ $(CXXFLAGS)

test: $(TEST)
	$(CXX) -o $@ $^ $(CXXFLAGS)
