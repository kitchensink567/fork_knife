#run make to run the first recipe aka run, you can also run the first recipe by doing make run
SRCS = main.cpp TileDef.cpp #add source cpp files here
HEADERS = include/Tiledef.h #add header files here
WARNING = -Wall -Wshadow --pedantic #g++ warning flags
ERROR = -Werror -Wvla #g++ error flags
INCLUDE = -Iinclude #flag for include directory
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --show-leak-kinds=all --track-origins=yes #memchecker 
EXE = testing #executable name
CPP = g++ -std=c++11 -g $(WARNING) $(ERROR) $(INCLUDE) #compilation variable
OBJS = $(SRCS:%.cpp=%.o) #object files
run: $(EXE) #runs executable
	./$(EXE)
$(EXE): $(OBJS)  #builds executable using object files
	$(CPP) $(OBJS) -o $(EXE) 
.cpp.o: $(HEADERS) #compiles sources to object files
	$(CPP) -c $*.cpp  
gdb: $(EXE) #runs executable in gdb
	gdb ./$(EXE)
memory: $(EXE) #runs executable in valgrind which checks for memory leaks
	$(VAL) ./$(EXE)
	vim memcheck.txt
clean: #cleans all computer generated files including file containing map info
	rm -rf memcheck.txt TileInfo.txt $(OBJS) $(EXE)
