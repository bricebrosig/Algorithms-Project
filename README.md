# 4110-Project
Brice Brosig and Jon Wendt
Algorithm that updates the minimum spanning tree of a graph when edges are are added or deleted.
The goal is to determine, emperically, wether the time to update the MST depends more-so on the action (add/delete)
or the size of the tree. Or even both.

# Compiling

Use the makefile. This will include all the flags and dependencies that you can't be bothered with. 
Compiles to a bin folder so check that out for running the program.

simply type "make" and it will compile.

This compiles the executable to the bin folder so be sure that when you run you do ./bin/proj_mst

# output

This program will print the mst to the terminal... all of them. That can get pretty big so you might want to redirect the output
to a file to have a better look at it.

The program runs three different tests. One on a large graph, another on a small graph, and a third on very small graphs that demonstrate the algorithms.

The first two will have timing data included in the output while the third will not.

# references
Kruskal code was got from geeks for geeks. Modified slightly to suit the nature of this program.

Got the BFS from the book (or from 3110 textbook... i dont remember)

# issues

IF you have any issues viewing, compiling, or running any of these files please do not hesitate to email brice or jon about them.

thanks and best.