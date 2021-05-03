.PHONY: clean force debug

# Compiler configuration (default)
G++ = g++
G++FLAGS = -std=c++17 -pthread

# Declaring the sources
EXE = AirWatch
DB_CLASSES = DBManager
DISP_CLASSES = Console DisplayManager
MODEL_CLASSES = ApplicationData Cleaner Company Government Individual Measurement Reading Sensor User Date
SERV_CLASSES = ApplicationServices UserManagement

# Assembling the list of sources in a single variable
SRC = $(EXE).cpp $(DB) $(DISP) $(MODEL) $(SERV)
DB = $(addprefix Database/, $(addsuffix .cpp, $(DB_CLASSES)))
DISP = $(addprefix Display/, $(addsuffix .cpp, $(DISP_CLASSES)))
MODEL = $(addprefix Model/, $(addsuffix .cpp, $(MODEL_CLASSES)))
SERV = $(addprefix Services/, $(addsuffix .cpp, $(SERV_CLASSES)))

# Essentials
OBJ = $(SRC:.cpp=.o)
ECHO = @echo
RM = @rm
RMFLAGS = -f

# Rule for the executable target
$(EXE): $(OBJ)
	$(ECHO) "EDL de <$(EXE)>"
	$(G++) -o $(EXE) $(G++FLAGS) $(OBJ)

# Rule to create every .o files out of every declared .cpp files
%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	$(G++) -c -o $@ $(G++FLAGS) $<

# Debug : No tolerance for warnings and debug capabilities
debug: G++FLAGS += -g -Wall -Werror
debug : $(EXE)

# Cleaning rule to remove the executable and any .o file in the CWD
clean:
	$(ECHO) "Suppression des fichiers générés"
	$(RM) $(RMFLAGS) $(EXE) *.o
