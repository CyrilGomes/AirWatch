.PHONY: clean force debug

# Compiler configuration (default)
G++ = g++
G++FLAGS = -std=c++17

# Essentials
ECHO = @echo
RM = @rm
RMFLAGS = -f

# Rules for the executable targets
UnitTests.exe: UnitTests.o 
	$(G++) -o UnitTests.exe $(G++FLAGS) UnitTests.o
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
