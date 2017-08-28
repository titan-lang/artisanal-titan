#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"
#include "ltable.h"

#include "libtitan.h"

static void fill_table_titancall(lua_State *L)
{
    // Allocate stack
    // 1 -> arg(1)
    // 2 -> xs
    // 3 -> ret(1)
    titan_grow_stack(L, 1, 3);

    // Function parameters
    
    lua_Integer local_N;
    {
        TValue *v = L->ci->func + 1;
        local_N = ivalue(v);
    }
    
    // Function body
    
    Table *local_xs;
    {
        TValue *v = L->ci->func + 2;
        
        Table *t = luaH_new(L);
        sethvalue(L, v, t);
        local_xs = t;
        
        luaC_checkGC(L); // TODO: this can be optimized?
    }
    
    for (lua_Integer local_i=1; local_i <= local_N; local_i += 1) {

        lua_Integer tmp_1;
        {
            tmp_1 = 10 * local_i;
        }
        
        {
            TValue v; setivalue(&v, tmp_1);
            luaH_setint(L, local_xs, local_i, &v);
        }
    }
    
    // Return

    {
        TValue *to = L->ci->func + 3;
        TValue *fr = L->ci->func + 2;
        setobj(L, to, fr);
    }
}


static int fill_table_luacall(lua_State *L)
{
    // Check and fix arity of parameters
    int nargs = lua_gettop(L);
    
    if (nargs > 1) {
        titan_arity_error(L, __LINE__);
    }
        
    if (nargs < 1) {
        titan_grow_stack(L, nargs, 1);
    }
    
    // Check parameter types
    
    {
        const TValue * v = L->ci->func + 1;
        if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
    }
    
    // Run function and return

    fill_table_titancall(L);

    return 1;
}

int luaopen_fill_table_titan(lua_State *L)
{   
    lua_pushcfunction(L, fill_table_luacall);
    return 1;
}
