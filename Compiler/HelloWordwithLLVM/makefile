hello: hello_llvm_part1.cpp
	clang++ hello_llvm_part1.cpp `llvm-config --libs --cxxflags --ldflags` -lpthread -lz -ldl -lcurses -o hello -std=c++11
clean:
	rm hello
myPass: myPass.cpp
	clang++ -c myPass.cpp -o myPass.o `llvm-config --cxxflags` -std=c++11 -I/home/guo/data/software/llvm/include
	clang++ -shared -o myPass.so myPass.o `llvm-config --libs --ldflags` -L/home/guo/data/software/llvm/lib
