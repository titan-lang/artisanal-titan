local mode = arg[1] and string.lower(arg[1])
local N    = arg[2] and tonumber(arg[2]) or 1000

local f
if mode == "lua" then
    f = require 'fill_table'
elseif mode == "typed" then
    f = require 'fill_table_titan'
else
    print("usage: ../lua/src/lua thistest.lua (Lua|Typed)")
    os.exit(1)
end

print("N="..N)
local r = f(N)
print(type(r))

