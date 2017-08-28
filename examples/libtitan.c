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

void titan_shrink_stack(lua_State *L, int old_size, int new_size)
{
    lua_pop(L, old_size - new_size);
}

void titan_grow_stack(lua_State *L, int old_size, int new_size)
{
    if (!lua_checkstack(L, new_size)) { titan_panic(); }
    for (int i=old_size+1; i <= new_size; i++) {
        lua_pushnil(L);
    }
}
