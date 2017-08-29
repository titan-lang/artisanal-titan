local mode = arg[1] and string.lower(arg[1])
local N    = arg[2] and tonumber(arg[2]) or 5000

local sort
if mode == "lua" then
    sort = require 'selection_sort'
elseif mode == "typed" then
    sort = require 'selection_sort_titan'
else
    print("usage: ../lua/src/lua thistest.lua (Lua|Typed)")
    os.exit(1)
end

local function make_input(N)
    local xs = {}
    for i=1,N do
        xs[i] = N - i + 1
    end
    return xs
end

local function print_array(xs)
    print( "{" .. table.concat(xs, ", ") .. "}" )
end

local function is_sorted(xs)
    for i=2,#xs do
        if xs[i-1] > xs[i] then
            return false
        end
    end
    return true
end

local xs = make_input(N)
print('before', is_sorted(xs))
sort(xs)
print('after', is_sorted(xs))
