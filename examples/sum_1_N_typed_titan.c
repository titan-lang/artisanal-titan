#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"

#include "libtitan.h"

static void sum_1_N_typed_titancall(lua_State *L)
{
    // Allocate stack
    // 1 -> arg(1)
    // 2 -> res(1)
    titan_grow_stack(L, 1, 2);

    // Function parameters
    
    lua_Integer local_N;
    {
        TValue *v = L->ci->func + 1;
        local_N = ivalue(v);
    }

    // Function body
    
    lua_Integer local_res;
    {
        local_res = 0;
    }

    for (lua_Integer local_i = 1; local_i <= local_N; local_i = local_i + 1){

        local_res = local_res + local_i;
    }

    // Return results

    {
        TValue *v = L->ci->func + 2;
        setivalue(v, local_res);
    }
}

static int sum_1_N_typed_luacall(lua_State *L)
{
    // Check and fix arity of parameters
    
    int nargs = lua_gettop(L);
    
    if (nargs > 1) {
        titan_arity_error(L, __LINE__);
    }
    
    if (nargs < 1) {
        titan_grow_stack(L, nargs, 1);
    }
    
    // Check types of parameters
    
    {
        TValue *v = L->ci->func + 1;
        if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
    }

    // Call internal implementation
    
    sum_1_N_typed_titancall(L);

    return 1;
}

int luaopen_sum_1_N_typed_titan(lua_State *L)
{
    lua_pushcfunction(L, sum_1_N_typed_luacall);
    return 1;
}
