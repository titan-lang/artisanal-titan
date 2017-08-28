This repo is for experimenting with "hand-compiled" Titan programs so we can
decide how the code generation should look like before actually implementing 
the code generator.

It also includes a patched version of Lua.5.3.4 that has been modified to
expose the internal data structures and functions that we will need to access.


Included functions:

- sum_1_N

    This function is as simple as it gets, just a litle loop of integer
    arithmetic operations. I would expect this to be the highest speedup we
    will get.
    
    In addition to the plain Lua version and the typed Titan version I also
    made a dynamically-typed titan versino to check what speedup we get just
    removing the interpreter overhead.
