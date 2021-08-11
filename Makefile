COMPILER=g++
TARGET=fbsim
all:
	$(COMPILER)  -I header project.cpp -o $(TARGET)
