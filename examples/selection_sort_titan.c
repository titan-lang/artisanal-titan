#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"
#include "ltable.h"

#include "libtitan.h"

static void selection_sort_titancall(lua_State *L)
{
    // Allocate stack
    // 1 -> arg(1)
    titan_grow_stack(L, 1, 1);

    // Function parameters
    
    Table *local_xs;
    {
        TValue *v = L->ci->func + 1;
        local_xs = hvalue(v);
    }

    // Function body

    lua_Integer local_N;
    {
        local_N = luaH_getn(local_xs);
    }
    
    for (lua_Integer local_i=1; local_i <= local_N; local_i += 1) {

        lua_Integer local_min_i;
        {
            local_min_i = local_i;
        }

        lua_Integer local_min_x;
        {
            const TValue *v = luaH_getint(local_xs, local_i);
            if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
            local_min_x = ivalue(v);
        }

        lua_Integer tmp_1;
        {
            tmp_1 = local_i + 1;
        }

        for (lua_Integer local_j = tmp_1; local_j <= local_N; local_j += 1) {

            lua_Integer local_y;
            {
                const TValue *v = luaH_getint(local_xs, local_j);
                if (!ttisinteger(v) ) { titan_type_error(L, __LINE__); }
                local_y = ivalue(v);
            }

            int tmp_2;
            {
                tmp_2 = (local_y < local_min_x);
            }

            if (tmp_2) {

                local_min_i = local_j;
                
                local_min_x = local_y;
            }
        }

        lua_Integer tmp_3;
        {
            const TValue *v = luaH_getint(local_xs, local_min_i);
            if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
            tmp_3 = ivalue(v);
        }

        lua_Integer tmp_4;
        {
            const TValue *v = luaH_getint(local_xs, local_i);
            if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
            tmp_4 = ivalue(v);
        }

        {
            TValue v; setivalue(&v, tmp_4);
            luaH_setint(L, local_xs, local_min_i, &v);
        }

        {
            TValue v; setivalue(&v, tmp_3);
            luaH_setint(L, local_xs, local_i, &v);
        }
    }
}


static int selection_sort_luacall(lua_State *L)
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
        if (!ttistable(v)) { titan_type_error(L, __LINE__); }
    }
    
    // Run function and return

    selection_sort_titancall(L);

    return 0;
}

int luaopen_selection_sort_titan(lua_State *L)
{   
    lua_pushcfunction(L, selection_sort_luacall);
    return 1;
}
