CXX = g++
CXXSOURCE = main.cpp land.cpp lnot.cpp lor.cpp var.cpp expression.cpp
HEADERS = land.h lnot.h lor.h var.h expression.h
OBJECTS = ${CXXSOURCE:.cpp=.o}
DEPS= ${OBJECTS:.o=.d}
COMPILEOPS = -c
LINKOPS = -o
-include $(DEPS)

%.o:%.cpp %.d
	$(CXX) $(COMPILEOPS) $<

%.d:%.cpp
	$(CXX) -M $< > $@

build: a.out

a.out: main.cpp $(OBJECTS)
	$(CXX) $(OBJECTS) $(LINKOPS) a.out

#clean removes build output files and .o files
.PHONY: clean

clean:
	rm -rf *.out *.o *.d

#executes the executable file
run:
	./a.out
