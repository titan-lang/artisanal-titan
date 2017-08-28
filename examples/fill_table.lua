local function fill_table(N)
    local xs = {}
    for i=1,N do
        xs[i] = 10*i
    end
    return xs
end

return fill_table
