#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lgc.h"
#include "ltable.h"
#include "lvm.h"

#include "libtitan.h"

static void sieve_titancall(lua_State *L)
{
    // Allocate stack
    //  1 -> arg(1)
    //  2 -> local_is_prime
    //  3 -> local_primes
    //  4 -> ret(1)
    titan_grow_stack(L, 1, 4);
    
    // Function parameters

    lua_Integer local_maxn;
    {
        TValue *v = L->ci->func + 1;
        local_maxn = ivalue(v);
    }
    
    // Function body

    Table *local_is_prime;
    {
        TValue *v = L->ci->func + 2;

        Table *t = luaH_new(L);
        sethvalue(L, v, t);
        local_is_prime = t;
        
        luaC_checkGC(L);
    }
    
    {
        Table *t = local_is_prime;
        lua_Integer k = 1;
        int v = 0;
        const TValue *vt = L->ci->func + 2;
        
        unsigned int actual_i = l_castS2U(k) - 1;
        unsigned int asize = t->sizearray;
        
        if (actual_i < asize) {
            TValue *slot = &t->array[actual_i];
            setbvalue(slot, v);
        } else if (actual_i < 2*asize) {
            unsigned int hsize = sizenode(t);
            luaH_resize(L, t, 2*asize, hsize);
            TValue *slot = &t->array[actual_i];
            setbvalue(slot, v);
        } else {
            TValue *slot = (TValue *) luaH_getint(t, k);
            TValue vk; setivalue(&vk, k);
            TValue vv; setbvalue(&vv, v);
            luaV_finishset(L, vt, &vk, &vv, slot);
        }
    }
    
    
    for (lua_Integer local_n = 2; local_n <= local_maxn; local_n += 1) {
        {
            Table *t = local_is_prime;
            lua_Integer k = local_n;
            int v = 1;
            const TValue *vt = L->ci->func + 2;
            
            unsigned int actual_i = l_castS2U(k) - 1;
            unsigned int asize = t->sizearray;
            
            if (actual_i < asize) {
                TValue *slot = &t->array[actual_i];
                setbvalue(slot, v);
            } else if (actual_i < 2*asize) {
                unsigned int hsize = sizenode(t);
                luaH_resize(L, t, 2*asize, hsize);
                TValue *slot = &t->array[actual_i];
                setbvalue(slot, v);
            } else {
                TValue *slot = (TValue *) luaH_getint(t, k);
                TValue vk; setivalue(&vk, k);
                TValue vv; setbvalue(&vv, v);
                luaV_finishset(L, vt, &vk, &vv, slot);
            }
        }
        
    }

    lua_Integer local_nprimes;
    {
        local_nprimes = 0;
    }
    
    Table *local_primes;
    {
        TValue *v = L->ci->func + 3;

        Table *t = luaH_new(L);
        sethvalue(L, v, t);
        local_primes = t;

        luaC_checkGC(L);
    }

    for (lua_Integer local_n = 1; local_n <= local_maxn; local_n += 1) {
    
        int tmp_0;
        {
            Table *t = local_is_prime;
            lua_Integer k = local_n;
            
            unsigned int actual_i = l_castS2U(k) - 1;
            unsigned int asize = t->sizearray;
            
            TValue *slot = &t->array[actual_i];
            if (actual_i < asize) {
                slot = &t->array[actual_i];
            } else {
                slot = (TValue *) luaH_getint(local_is_prime, local_n);
            }
            
            if (!ttisboolean(slot)) { titan_type_error(L, __LINE__); }
            tmp_0 = bvalue(slot);
        }

        if (tmp_0) {
        
            local_nprimes = local_nprimes + 1;
            
            {
                Table *t = local_primes;
                lua_Integer k = local_nprimes;
                lua_Integer v = local_n;
                const TValue *vt = L->ci->func + 3;
                
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
            
            
            lua_Integer tmp_1;
            {
                tmp_1 = local_n + local_n;
            }
            
            for (lua_Integer local_m = tmp_1; local_m <= local_maxn; local_m += local_n) {
                
                {
                    Table *t = local_is_prime;
                    lua_Integer k = local_m;
                    int v = 0;
                    const TValue *vt = L->ci->func + 2;
                    
                    unsigned int actual_i = l_castS2U(k) - 1;
                    unsigned int asize = t->sizearray;
                    
                    if (actual_i < asize) {
                        TValue *slot = &t->array[actual_i];
                        setbvalue(slot, v);
                    } else if (actual_i < 2*asize) {
                        unsigned int hsize = sizenode(t);
                        luaH_resize(L, t, 2*asize, hsize);
                        TValue *slot = &t->array[actual_i];
                        setbvalue(slot, v);
                    } else {
                        TValue *slot = (TValue *) luaH_getint(t, k);
                        TValue vk; setivalue(&vk, k);
                        TValue vv; setbvalue(&vv, v);
                        luaV_finishset(L, vt, &vk, &vv, slot);
                    }
                }
                
            }
        }
    }

    // Return
    
    {
        TValue *to = L->ci->func + 4;
        TValue *fr = L->ci->func + 3;
        setobj(L, to, fr);
    }
}

static int sieve_luacall(lua_State *L)
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
        const TValue *v = L->ci->func + 1;
        if (!ttisinteger(v)) { titan_type_error(L, __LINE__); }
    }
    
    // Run function and return
    
    sieve_titancall(L);

    return 1;
}

int luaopen_sieve_titan(lua_State *L)
{
    lua_pushcfunction(L, sieve_luacall);
    return 1;
}
