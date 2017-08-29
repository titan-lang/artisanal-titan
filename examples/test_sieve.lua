local mode = arg[1] and string.lower(arg[1])
local N    = arg[2] and tonumber(arg[2]) or 100

local f
if mode == "lua" then
    f = require 'sieve'
elseif mode == "typed" then
    f = require 'sieve_titan'
else
    print("usage: ../lua/src/lua test_sieve.lua (Lua|Typed)")
    os.exit(1)
end

local ps = f(N)
print(#ps)
