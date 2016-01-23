CXX=clang++-3.5 -std=c++11 
CFLAGS=-W -Wall -pedantic
LDFLAGS=
GTK=`pkg-config gtkmm-3.0 --cflags --libs` 
TARGET_DIR=target
SRC_DIR=src

exec: main.o ihm.o saveReader.o
	$(CXX) -o main $(TARGET_DIR)/main.o $(TARGET_DIR)/ihm.o $(TARGET_DIR)/saveReader.o $(GTK) -v

ihm.o: $(SRC_DIR)/ihm.hpp $(SRC_DIR)/ihm.cpp
	$(CXX) -o $(TARGET_DIR)/ihm.o -c $(SRC_DIR)/ihm.cpp $(CFLAGS) $(GTK)

main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/ihm.hpp $(SRC_DIR)/saveReader.hpp 
	$(CXX) -o $(TARGET_DIR)/main.o -c $(SRC_DIR)/main.cpp $(CFLAGS) $(GTK)

saveReader.o: $(SRC_DIR)/saveReader.hpp $(SRC_DIR)/saveReader.cpp
	$(CXX) -o $(TARGET_DIR)/saveReader.o -c $(SRC_DIR)/saveReader.cpp $(CFLAGS) $(GTK)

clean:
	$(RM) $(TARGET_DIR)/*
