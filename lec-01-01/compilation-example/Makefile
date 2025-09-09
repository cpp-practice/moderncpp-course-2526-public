
CXX = clang++
CXXFLAGS = -Wall -Wextra -g
LDFLAGS =

linking: main.out

main.out: assembly
	$(CXX) $(CXXFLAGS) main.o hello.o -o main.out

assembly: main.o hello.o

main.o: main.s
	$(CXX) $(CXXFLAGS) -c main.s -o main.o

hello.o: hello.s
	$(CXX) $(CXXFLAGS) -c hello.s -o hello.o

compile: main.s hello.s

main.s: main.ii
	$(CXX) $(CXXFLAGS) -S main.ii -o main.s
	$(CXX) $(CXXFLAGS) -emit-llvm -S main.ii -o main.ll

hello.s: hello.ii
	$(CXX) $(CXXFLAGS) -S hello.ii -o hello.s
	$(CXX) $(CXXFLAGS) -emit-llvm -S hello.ii -o hello.ll

preprocess: main.ii hello.ii

main.ii: main.cpp hello.ii
	$(CXX) $(CXXFLAGS) -E main.cpp -o main.ii
	$(CXX) $(CXXFLAGS) -E -P main.cpp -o beauty-main.ii

hello.ii: hello.cpp hello.hpp
	$(CXX) $(CXXFLAGS) -E hello.cpp -o hello.ii
	$(CXX) $(CXXFLAGS) -E -P hello.cpp -o beauty-hello.ii

clean:
	rm -rf *.ii *.s *.o *.out *.ll

