CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: $(OBJS)
  $(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)
llrec.0: $(OBJS)
  $(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp  
llrec-test.0: $(OBJS)
  $(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 