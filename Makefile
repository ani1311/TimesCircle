all:
	g++ main.cpp Matrix.cpp -o a -lsfml-graphics -lsfml-window -lsfml-system
	./a
	make clean

clean:
	rm -rf *o a
