#include "libtitan.h"

#include <stdlib.h>

/*
 * I would expect that Titan will need functions that look like this
 * but I would expect that the number and types of arguments would have
 * to be different. Right now it just points to the line of code in the
 * hand-written C file and does not attempt to describe the error at all. 
 */

void titan_panic(void)
{
    exit(127);
}

int titan_type_error(lua_State *L, int line)
{
    return luaL_error(L, "Titan type error in C line %d", line);
}

int titan_arity_error(lua_State *L, int line)
{
    return luaL_error(L, "Titan arity error in C line %d", line);
}
