CXX=g++
CXXFLAGS=-Wall -std=c++11 $(DEBUG)
OBJ = main.o Number.o Language.o LanguageEnglish.o LanguageVietnamese.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS)