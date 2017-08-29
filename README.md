#Artisanal Titan

This repo is for experimenting with "hand-compiled" Titan programs so
we can decide how the code generation should look like before actually
implementing the code generator.

It also includes a patched version of Lua.5.3.4 that has been modified
to expose the internal data structures and functions that we will need
to access.

##How to run

- Build the patched version of Lua in the "lua" folder.
- cd into the examples folder
- Run the makefile
- Run the test\_\*.lua scripts using the patched Lua.
  These scripts receive two arguments: the type of test to run ("Lua" or
  "Typed") and the size of the test instance.

##Included functions

###sum\_1\_N

This function is as simple as it gets, just a litle loop of integer
arithmetic operations. I would expect this to be the highest speedup we
will get.
    
In addition to the plain Lua version and the typed Titan version I also
made a dynamically-typed titan versino to check what speedup we get just
removing the interpreter overhead.

###fill\_table

I made this function to check if I wasn't doing anything really stupid regarding
the garbage collection.

### selection\_sort

This is a sligthly less trivial program that does lots of reading and writing
to a typed away. I think it is a good test for data structure performance in
Titan.

### sieve

Another nice little function that does a lot of reading and writing to typed
arrays.
