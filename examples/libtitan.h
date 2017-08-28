#ifndef libtitan_h
#define libtitan_h

#include "lualib.h"
#include "lauxlib.h"

void titan_panic(void);
int titan_type_error(lua_State *L, int line);
int titan_arity_error(lua_State *L, int line);

#endif
