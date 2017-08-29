#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"

#include "libtitan.h"

static lua_Integer sum_1_N_typed_titancall(lua_State *L, lua_Integer local_N)
{
    (void) L;
    
    // Allocate stack

    // Function parameters
    
    // Function body
    
    lua_Integer local_res;
    {
        local_res = 0;
    }

    for (lua_Integer local_i = 1; local_i <= local_N; local_i = local_i + 1){

        local_res = local_res + local_i;
    }

    // Return results

    return local_res;
}

static int sum_1_N_typed_luacall(lua_State *L)
{
    // Get parameters
    
    {
        int nargs = lua_gettop(L);
        if (nargs != 1) {
            titan_arity_error(L, __LINE__);
        }
    }
    
    lua_Integer local_N; 
    {
        TValue *v = L->ci->func + 1;
        if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
        local_N = ivalue(v);
    }

    // Call internal implementation and return
    
    lua_Integer res;
    res = sum_1_N_typed_titancall(L, local_N);
    
    {
        int top = lua_gettop(L);
        if (!lua_checkstack(L, top+1)) { titan_panic(); }
        
        lua_pushinteger(L, res);
    }

    return 1;
}

int luaopen_sum_1_N_typed_titan(lua_State *L)
{
    lua_pushcfunction(L, sum_1_N_typed_luacall);
    return 1;
}
