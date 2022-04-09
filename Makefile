OUT = cellula
INSTALL_DIR = /usr/local/bin


SRC := $(shell find $(SOURCE) -name *.cpp)
OBJ := $(SRC:%=$(OBJECT)/%.o)
DEPS := $(OBJ:.o=.d)

CC = g++-11
CFLAGS = -std=c++20 -Wall -fmodules-ts -pthread

all: cellula

cellula: src/main.cpp src/Core/Layer.cpp src/Core/Application.cpp 
	$(CC) $(CFLAGS) -c src/Core/Layer.cpp 
	$(CC) $(CFLAGS) -c src/Core/Application.cpp -lsfml-graphics -lsfml-window -lsfml-system
	$(CC) $(CFLAGS) -c src/main.cpp
	$(CC) $(CFLAGS) main.o Application.o Layer.o -o cellula -lsfml-graphics -lsfml-window -lsfml-system

#install: $(OUT)
#	@cp $(OUT) $(INSTALL_DIR)

#uninstall:
#	@rm $(INSTALL_DIR)/$(OUT)

clean:
	rm -rf gcm.cache/
#	rm -rf $(OBJECT) $(OUT)

