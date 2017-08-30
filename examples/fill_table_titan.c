#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"
#include "ltable.h"
#include "lvm.h"

#include "lobject.h"

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
            Table *t = local_xs;
            lua_Integer k = local_i;
            lua_Integer v = tmp_1;
            const TValue *vt = L->ci->func + 2;
            
            unsigned int actual_i = l_castS2U(k) - 1;
            unsigned int asize = t->sizearray;
            
            if (actual_i < asize) {
                TValue *slot = &t->array[actual_i];
                setivalue(slot, v);
            } else if (actual_i < 2*asize) {
                unsigned int hsize = sizenode(t);
                luaH_resize(L, t, 2*asize, hsize);
                TValue *slot = &t->array[actual_i];
                setivalue(slot, v);
            } else {
                TValue *slot = (TValue *) luaH_getint(t, k);
                TValue vk; setivalue(&vk, k);
                TValue vv; setivalue(&vv, v);
                luaV_finishset(L, vt, &vk, &vv, slot);
            }
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
