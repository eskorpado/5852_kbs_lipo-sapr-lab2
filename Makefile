CC=g++
CFLAGS=-c
OFLAG=-o
CPPUNIT_FLAGS=-I${CPPUNIT_HOME}/include -L${CPPUNIT_HOME}/lib -lcppunit
PCRE_FLAG=-lpcrecpp
OBJ=obj
TEST=test
SRC=src
OFILE=main
SFILE=main.sh
TESTFILE=test/test_find_source_file

all: $(OFILE)

$(OFILE): $(OBJ)/main.o $(OBJ)/SourceFileFinder.o $(OBJ)/SourceFileFinderTest.o
	$(CC) $(OBJ)/main.o $(OBJ)/SourceFileFinder.o $(OBJ)/SourceFileFinderTest.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(OFILE)
	./$(OFILE) -t < $(TESTFILE)
	
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/main.o
	
$(OBJ)/SourceFileFinder.o: $(SRC)/SourceFileFinder.cpp
	$(CC) $(CFLAGS) $(SRC)/SourceFileFinder.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/SourceFileFinder.o
	
$(OBJ)/SourceFileFinderTest.o: $(SRC)/SourceFileFinderTest.cpp
	$(CC) $(CFLAGS) $(SRC)/SourceFileFinderTest.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/SourceFileFinderTest.o
	
# Tests runs are already included inside output file!
test: $(OFILE)

compare: $(OFILE)
	./$(SFILE) < $(TESTFILE) > fsout
	./$(OFILE) < $(TESTFILE) | sort > fcout
	diff fsout fcout

clean:
	rm -rf $(OFILE) $(OBJ)/* fcout fsout