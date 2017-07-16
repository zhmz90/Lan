hello: hello_llvm_part1.cpp
	clang++ hello_llvm_part1.cpp `llvm-config --libs --cxxflags --ldflags` -lpthread -lz -ldl -lcurses -o hello -std=c++11
clean:
	rm hello
myPass: myPass.cpp
	g++ -c myPass.cpp -o myPass.o `../../../llvm/build/bin/llvm-config --cxxflags` -std=c++11 -I../../../llvm/llvm/include
	g++ -shared -o myPass.so myPass.o `../../../llvm/build/bin/llvm-config --libs --ldflags` -L../../../llvm/llvm/lib

myPass2: myPass.cpp
	g++ -c myPass.cpp -o myPass.o -I/home/guo/data/software/llvm/include  -fPIC -fvisibility-inlines-hidden -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wmissing-field-initializers -pedantic -Wno-long-long -Wnon-virtual-dtor -Wdelete-non-virtual-dtor -std=c++11 -ffunction-sections -fdata-sections -O3 -DNDEBUG  -fno-exceptions -fno-rtti -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
	g++ -shared -o myPass.so myPass.o `llvm-config --libs --ldflags`
