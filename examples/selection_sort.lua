-- {int} -> ()
local function selection_sort(xs)
    local N = #xs
    for i=1,N do

        -- Find minimum
        local min_i = i
        local min_x = xs[i]
        for j = i+1, N do
            local y = xs[j]
            if y < min_x then
                min_i = j
                min_x = y
            end
        end

        -- Move it to the front
        xs[i], xs[min_i] = xs[min_i], xs[i]
    end
end

return selection_sort
