ID$@IR =../include
IDIR = ../include
CC= g++ 
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -lgtest -lgtest_main -fpermissive

ODIR=../obj
TEST_ODIR=../Test/obj
LDIR =../Source
DIR_TESTS=../Test

TEST_EXE= Reader_Test 
LIBS=

PROGRAM = Reader

_HEADERS = reader.hpp
HEADERS = $(patsubst %,$(IDIR)/%,$(_HEADERS))

_OBJECTS = reader.o Principal.o 
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

_TESTS = Test_reader.cpp 
TESTS = $(patsubst %,$(DIR_TESTS)/%,$(_TESTS))


$(ODIR)/%.o: %.cpp $(HEADERS) 
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

$(PROGRAM): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(TEST_EXE) : $(TESTS) reader.cpp
	$(CC) -o $@ --coverage $^ $(CFLAGS)

program: $(PROGRAM) test gcov project

test: $(TEST_EXE)
	mv $(LDIR)/*.gcno $(ODIR)

run: 
	./$(PROGRAM) 

run_test:
	./$(TEST_EXE)
.PHONY: clean

gcov:
	gcov $(TEST_DIR)/$(PROGRAM).gcda

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

clean_coverage:
	rm -f $(ODIR)/*.gcno $(ODIR)/*.gcda

clean_all:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ && rm -f $(ODIR)/*.gcno $(ODIR)/*.gcda
