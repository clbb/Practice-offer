SRC=3.cpp
OBJ=main

${OBJ}:${SRC}
	g++ -o $@ $^ -g
.PHONY:clean
clean:
	rm -rf ${OBJ} ${OBJ}.d*
