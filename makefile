CP=g++
OUTDIR=bin/
OBJDIR=obj/
CPFLAGS=-Wall -pedantic -std=c++14

main: src/main.cpp inc/graph.h graph
	$(CP) -o bin/proj_mst $(CPFLAGS) src/main.cpp $(OBJDIR)graph.o

graph: src/graph.cpp inc/graph.h
	$(CP) -c src/graph.cpp $(CPFLAGS) -o $(OBJDIR)graph.o

clean:
	$(RM) obj/*.o bin/proj_mst