COMPILER=g++
TARGET=fbsim
all:
	$(COMPILER)  -I headers project.cpp -o $(TARGET)
