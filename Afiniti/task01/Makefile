img_down: img_down.o 
	c++ img_down.o -o img_down -lpthread

img_down.o: img_down.cpp
	c++ -c img_down.cpp -pthread

clean:
	rm -R img_down.o
