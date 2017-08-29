#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"
#include "lvm.h"

#include <stdio.h>
#include <stdlib.h>

#include "libtitan.h"

// Constants

static TValue constants[1];
static TValue *const_0 = &constants[0];
static TValue *const_1 = &constants[1];

static void sum_1_N_dynamic_titancall(lua_State *L)
{
    // Allocate stack
    // param N   -> 1
    // local res -> 2
    // local i   -> 3
    // out[1]    -> 3
    
    // 1 -> param[1] N
    // 2 -> local res
    // 3 -> local i
    // 4 -> return[1]
    
    titan_grow_stack(L, 1, 3);

    // Function parameters

    // Function body
    
    {
        TValue *to = L->ci->func + 2;
        TValue *fr = const_0;
        setobj(L, to, fr);
    }
    
    {
        {
            TValue *to = L->ci->func + 3;
            TValue *fr = const_1;
            setobj(L, to, fr);
        }
        
        while(1){
            
            int tmp_1;
            {
                TValue *rb = L->ci->func + 3;
                TValue *rc = L->ci->func + 1;
                tmp_1 = luaV_lessequal(L, rb, rc);
            }
            
            if (!tmp_1) break;
            
            { 
                TValue *ra = L->ci->func + 2;
                TValue *rb = L->ci->func + 2;
                TValue *rc = L->ci->func + 3;
                
                lua_Number nb; lua_Number nc;
                if (ttisinteger(rb) && ttisinteger(rc)) {
                    lua_Integer ib = ivalue(rb); lua_Integer ic = ivalue(rc);
                    setivalue(ra, intop(+, ib, ic));
                }
                else if (tonumber(rb, &nb) && tonumber(rc, &nc)) {
                    setfltvalue(ra, luai_numadd(L, nb, nc));
                }
                else {
                    luaT_trybinTM(L, rb, rc, ra, TM_ADD);
                }
            }
            
            { 
                TValue *ra = L->ci->func + 3;
                TValue *rb = L->ci->func + 3;
                TValue *rc = const_1;
                
                lua_Number nb; lua_Number nc;
                if (ttisinteger(rb) && ttisinteger(rc)) {
                    lua_Integer ib = ivalue(rb); lua_Integer ic = ivalue(rc);
                    setivalue(ra, intop(+, ib, ic));
                }
                else if (tonumber(rb, &nb) && tonumber(rc, &nc)) {
                    setfltvalue(ra, luai_numadd(L, nb, nc));
                }
                else {
                    luaT_trybinTM(L, rb, rc, ra, TM_ADD);
                }
            }
        }
    }

    // Return results

    {
        TValue out1;
        setobj(L, &out1, L->ci->func + 2);
    
        setobj(L, L->ci->func + 3, &out1);
    }
}

static int sum_1_N_dynamic_luacall(lua_State *L)
{
    // Get parameters
    
    {
        int nargs = lua_gettop(L);
    
        if (nargs > 1) {
            titan_shrink_stack(L, nargs, 1);
        }
    
        if (nargs < 1) {
            titan_grow_stack(L, nargs, 1);
        }
    }
    
    // Call internal representation and return
    
    sum_1_N_dynamic_titancall(L);

    return 1;
}

int luaopen_sum_1_N_dynamic_titan(lua_State *L)
{
    setivalue(const_0, 0);
    setivalue(const_1, 1);
    
    lua_pushcfunction(L, sum_1_N_dynamic_luacall);
    return 1;
}
