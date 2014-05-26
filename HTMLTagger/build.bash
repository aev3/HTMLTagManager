#!/bin/bash
#
#g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -I./src -I/usr/local/include -I/usr/local/include/C++  -DPIC -fPIC -c src/HTMLTagManager.cpp -o src/HTMLTagManager.o
#g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -I./src -I/usr/local/include -I/usr/local/include/C++  -DPIC -fPIC -c src/REXConsts.cpp -o src/REXConsts.o
#g++ -shared -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -o build/lib/libHTMLTagManager-1.0.1.dylib \
#	./src/HTMLTagManager.o ./src/REXConsts.o 
#ar cru build/lib/libHTMLTagManager-1.0.1.a ./src/HTMLTagManager.o ./src/REXConsts.o 
#g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -I./src -I/usr/local/include -I/usr/local/include/C++  -DPIC -fPIC -c src/HTMLTagManagerApp.cpp -o src/HTMLTagManagerApp.o
#g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -o build/bin/HTMLTagManagerApp \
#	./src/HTMLTagManagerApp.o  ./src/HTMLTagManager.o ./src/REXConsts.o
#
# g++ -std=c++11 -c -o regex_test.o regex_test.cpp 
# g++ -std=c++11 -o rx_test regex_test.o -lm
#
###g++ -std=c++11 -Wall -c -o ./src/HTMLTagManager.o ./src/HTMLTagManager.cpp
###g++ -std=c++11 -Wall -c -o ./src/REXConsts.o ./src/REXConsts.cpp
###g++ -shared -std=c++11 -o build/lib/libHTMLTagManager-1.0.1.dylib ./src/HTMLTagManager.o ./src/REXConsts.o 
###g++ -std=c++11 -Wall -c -o ./src/HTMLTagManagerApp.o ./src/HTMLTagManagerApp.cpp
###g++ -std=c++11 -Wall -o build/bin/HTMLTagManagerApp ./src/HTMLTagManagerApp.o ./src/HTMLTagManager.o ./src/REXConsts.o -lm
#
mkdir -p build/lib;	
mkdir -p build/bin;
g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -I./src -I/usr/local/include -I/usr/local/include/C++  -DPIC -fPIC -c src/HTMLTagManager.cpp -o src/HTMLTagManager.o
g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -I./src -I/usr/local/include -I/usr/local/include/C++  -DPIC -fPIC -c src/REXConsts.cpp -o src/REXConsts.o
g++ -shared -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -o build/lib/libHTMLTagManager-1.0.1.dylib ./src/HTMLTagManager.o ./src/REXConsts.o 
ar cru build/lib/libHTMLTagManager-1.0.1.a ./src/HTMLTagManager.o ./src/REXConsts.o 
g++ -std=c++11 -Wall -c -o ./src/HTMLTagManagerApp.o ./src/HTMLTagManagerApp.cpp
g++ -std=c++11  -Wall -DPIC -fPIC -O2 -fpermissive  -o build/bin/HTMLTagManagerApp ./src/HTMLTagManagerApp.o  ./src/HTMLTagManager.o ./src/REXConsts.o 
#
#
# EoF

