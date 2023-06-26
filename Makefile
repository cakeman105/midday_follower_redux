compile:
	time g++ -Wall -pedantic -std=c++17 -Werror -Wno-long-long -g -O2 -o midday_follower src/main.cpp src/graphics.cpp src/graphics.hpp src/files.cpp src/files.hpp -lncurses 

run:
	./midday_follower

clean:

doc:
	doxygen Doxyfile
