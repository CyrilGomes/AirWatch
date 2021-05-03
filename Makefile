.PHONY: clean force debug

# Compiler configuration (default)
G++ = g++
G++FLAGS = -std=c++17

# Assembling the list of sources in a single variable
SRC = $(EXE).cpp $(DB) $(DISP) $(MODEL) $(SERV)
DB = $(addprefix Database/, $(DB_CLASSES).cpp)
DISP = $(addprefix Display/, $(DISP_CLASSES).cpp)
MODEL = $(addprefix Model/, $(MODEL_CLASSES).cpp)
SERV = $(addprefix Services/, $(SERV_CLASSES).cpp)

# Declaring the sources
EXE = AirWatch
DB_CLASSES = DBManager
DISP_CLASSES = Console HmiManagement
MODEL_CLASSES = ApplicationData Cleaner Company Government Individual Measurement Reading Reading Sensor User
SERV_CLASSES = ApplicationServices UserManagement

# Essentials
OBJ = $(SRC:.cpp=.o)
ECHO = @echo
RM = @rm
RMFLAGS = -f

# Rule for the executable target
$(EXE): $(OBJ)
	$(ECHO) "EDL de <$(EXE)>"
	@ $(G++) $(G++FLAGS) -o $(EXE) $(OBJ)

# Rule to create every .o files out of every declared .cpp files
%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	@ $(G++) -c $(G++FLAGS) $< -o $@

# Debug : No tolerance for warnings and debug capabilities
debug: G++FLAGS += -g -Wall -Werror
debug : $(EXE)

# Cleaning rule to remove the executable and any .o file in the CWD
clean:
	$(ECHO) "Suppression des fichiers générés"
	$(RM) $(RMFLAGS) $(EXE) *.o