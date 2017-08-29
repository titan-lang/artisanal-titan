#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"
#include "ltable.h"

#include "libtitan.h"

static void fill_table_titancall(lua_State *L, lua_Integer local_N)
{
    // Allocate stack
    // 1 -> xs, ret(1)
    titan_grow_stack(L, 0, 1);

    // Function parameters
    
    // Function body
    
    Table *local_xs;
    {
        TValue *v = L->ci->func + 2;
        
        Table *t = luaH_new(L);
        sethvalue(L, v, t);
        local_xs = t;
        
        luaC_checkGC(L);
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
    
        // resize stack 1 -> 1
        // stack[1] = stacl[1]
}


static int fill_table_luacall(lua_State *L)
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
        const TValue * v = L->ci->func + 1;
        if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
        local_N = ivalue(v);
    }
    
    // Call internal implementation and return

    fill_table_titancall(L, local_N);

    return 1;
}

int luaopen_fill_table_titan(lua_State *L)
{   
    lua_pushcfunction(L, fill_table_luacall);
    return 1;
}
