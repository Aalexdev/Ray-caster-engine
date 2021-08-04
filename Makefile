CXX = g++
OUT = out\RC_engine_lib
SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJ = $(addprefix .obj/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
LIB = lib/
INCLUDE = include/
FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_GPU -lSDL2_ttf -lSDL2_mixer
STD_VERSION = c++17
DEFINE = RCE_BUILD_DLL


all : $(OUT)

test : $(OUT)
	@echo launch
	@$(OUT)

.obj/%.o : src/%.cpp
	@echo compiling $@ from $< ...
	@$(CXX) -std=$(STD_VERSION) -o $@ -c -D $(DEFINE) $< -I $(INCLUDE)

.obj/%.o : src/*/%.cpp
	@echo compiling $@ from $< ...
	@$(CXX) -std=$(STD_VERSION) -o $@ -c $< -I $(INCLUDE)

$(OUT) : $(OBJ)
	@echo building the executable ...
	@$(CXX) -std=$(STD_VERSION) -shared -o $(OUT).dll .obj/*.o -L $(LIB) $(FLAGS) -Wl,--out-implib,$(OUT).a
	@echo executable bluid, ready to launch

clean:
	@echo clear .obj folder
	@del .obj\*.o

info:
	@echo -----------------------------------------------------
	@echo compiling info :                
	@echo 	compiler                     : $(CXX)
	@echo 	compiler standart version    : $(STD_VERSION)
	@echo 	include path                 : $(INCLUDE)
	@echo 	flags                        : $(FLAGS)
	@echo 	defines                      : $(DEFINE)
	@echo 	libs directory               : $(LIB)
	@echo 	output                       : $(OUT)
	@echo -----------------------------------------------------
