SOURCE_DIR = src/cpp
OBJ_DIR = src/obj

solver.out: $(OBJ_DIR)/main.o $(OBJ_DIR)/solve.o $(OBJ_DIR)/tests.o $(OBJ_DIR)/user.o $(OBJ_DIR)/args_check.o
	g++ $(OBJ_DIR)/main.o $(OBJ_DIR)/solve.o $(OBJ_DIR)/tests.o $(OBJ_DIR)/user.o $(OBJ_DIR)/args_check.o -o solver.out

$(OBJ_DIR)/main.o $(SOURCE_DIR)/main.cpp:
	g++ -c $(SOURCE_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/solve.o $(SOURCE_DIR)/solve.cpp:
	g++ -c $(SOURCE_DIR)/solve.cpp -o $(OBJ_DIR)/solve.o

$(OBJ_DIR)/tests.o $(SOURCE_DIR)/tests.cpp:
	g++ -c $(SOURCE_DIR)/tests.cpp -o $(OBJ_DIR)/tests.o

$(OBJ_DIR)/user.o $(SOURCE_DIR)/user.cpp:
	g++ -c $(SOURCE_DIR)/user.cpp -o $(OBJ_DIR)/user.o

$(OBJ_DIR)/args_check.o $(SOURCE_DIR)/args_check.cpp:
	g++ -c $(SOURCE_DIR)/args_check.cpp -o $(OBJ_DIR)/args_check.o
