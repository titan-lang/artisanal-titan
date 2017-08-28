local mode = arg[1] and string.lower(arg[1])
local N    = arg[2] and tonumber(arg[2]) or 500000000

local f
if mode == "lua" then
    f = require 'sum_1_N'
elseif mode == "typed" then
    f = require 'sum_1_N_typed_titan'
elseif mode == "dynamic" then
    f = require 'sum_1_N_dynamic_titan'
else
    print("usage: ../lua/src/lua thistest.lua (Lua|Titan|Dynamic)")
    os.exit(1)
end

print("N="..N)
local r = f(N)
print(r)

