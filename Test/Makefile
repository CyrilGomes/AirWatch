.PHONY: clean force debug

# Compiler configuration (default)
G++ = g++
G++FLAGS = -std=c++17 -pthread

# Classes for Unit Tests 
DB_CLASSES = DBManager
MODEL_CLASSES = ApplicationData Cleaner Company Government Individual Measurement Reading Sensor User Date
SERV_CLASSES = ApplicationServices UserServices
DB = $(addprefix ../Database/, $(addsuffix .cpp, $(DB_CLASSES)))
MODEL = $(addprefix ../Model/, $(addsuffix .cpp, $(MODEL_CLASSES)))
SERV = $(addprefix ../Services/, $(addsuffix .cpp, $(SERV_CLASSES)))
SRC = $(DB) $(MODEL) $(SERV)
OBJ = $(SRC:%.cpp=%.o)

# Essentials
ECHO = @echo
RM = @rm
RMFLAGS = -f

# Rules for the executable targets
UnitTests.exe: $(OBJ) UnitTests.o
	$(G++) -o UnitTests.exe $(G++FLAGS) $(OBJ) UnitTests.o
IntegrationTests.exe: IntegrationTests.o 
	$(G++) -o IntegrationTests.exe $(G++FLAGS) IntegrationTests.o 

# Rule to create every .o files out of every declared .cpp files
%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	$(G++) -c -o $@ $(G++FLAGS) $<

# Cleaning rule to remove the executable and any .o file in the CWD
clean:
	$(ECHO) "Suppression des fichiers générés"
	$(RM) $(RMFLAGS) %.exe %.o
