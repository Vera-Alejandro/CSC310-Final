INCLUDE_DIRS := /home/ale/CSC310-Final
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJECTS 	 := customErrorClass.o binaryFile.o Employee.o

excBinaryFile: main.cpp $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

customErrorClass.o: customErrorClass.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

binaryFile.o: binaryFile.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

Employee.o: Employee.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o excBinaryFile employee_info.dat