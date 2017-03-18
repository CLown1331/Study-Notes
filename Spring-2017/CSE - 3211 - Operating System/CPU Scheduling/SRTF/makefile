CC=g++
CCFLAG= -std=c++11 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fstack-protector 
sol: sol.cpp
	$(CC) $(CCFLAG) -o sol.exe sol.cpp
