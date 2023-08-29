SOURCE_DIR = source
OBJ_DIR = obj
INCLUDE_DIR = include
CFLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
PROGRAM_NAME = solver.out

all: obj $(PROGRAM_NAME)

obj:
	@mkdir obj

$(PROGRAM_NAME): $(OBJ_DIR)/main.o $(OBJ_DIR)/solve.o $(OBJ_DIR)/tests.o $(OBJ_DIR)/user.o $(OBJ_DIR)/args_check.o
	@g++ $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/solve.o $(OBJ_DIR)/tests.o $(OBJ_DIR)/user.o $(OBJ_DIR)/args_check.o -o $(PROGRAM_NAME)
	@echo "Linking object files into $(PROGRAM_NAME)"

$(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cpp $(INCLUDE_DIR)/args_check.h $(INCLUDE_DIR)/tests.h $(INCLUDE_DIR)/user.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	@echo "Compiling main.cpp"

$(OBJ_DIR)/solve.o: $(SOURCE_DIR)/solve.cpp $(INCLUDE_DIR)/solve.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/solve.cpp -o $(OBJ_DIR)/solve.o
	@echo "Compiling solve.cpp"

$(OBJ_DIR)/tests.o: $(SOURCE_DIR)/tests.cpp $(INCLUDE_DIR)/tests.h $(INCLUDE_DIR)/solve.h $(INCLUDE_DIR)/colors.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/tests.cpp -o $(OBJ_DIR)/tests.o
	@echo "Compiling tests.cpp"

$(OBJ_DIR)/user.o: $(SOURCE_DIR)/user.cpp $(INCLUDE_DIR)/user.h $(INCLUDE_DIR)/solve.h $(INCLUDE_DIR)/colors.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/user.cpp -o $(OBJ_DIR)/user.o
	@echo "Compiling user.cpp"

$(OBJ_DIR)/args_check.o: $(SOURCE_DIR)/args_check.cpp $(INCLUDE_DIR)/args_check.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/args_check.cpp -o $(OBJ_DIR)/args_check.o
	@echo "Compiling args_check.cpp"
