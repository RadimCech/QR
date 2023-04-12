CFLAGS := -std=c++11


main : 
	g++ $(CFLAGS) $(PWD)/src/*.cpp -o main -I$(PWD)/include

clean : 
	rm main

