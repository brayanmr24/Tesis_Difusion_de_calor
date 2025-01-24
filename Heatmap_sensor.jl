 f2(x,y) = hist[y+(10*(x-1))]
 f(x,y) = historia[y+(10*(x-1))]

function Graficar_temp(min,max)
    data_2 = []
    data_3 = []
    data_4 = []
    data_5 = []
    n=0
    while true
        if bytesavailable(com) > 0
            comdata = String(read(com))
            data_2 = split(comdata,"\r\n",keepempty=false)[end-1]
            data_3 = split(data_2,", ",keepempty=false)
            data_4 = parse.(Float32,data_3)
            data_5 = reshape(data_4,1,10)
            plt = heatmap(1:10, [1], data_5, aspect_ratio = 1, title = "n = $(n)     t = $(n) s", ticks = false, axis = false, clim = (min,max))
            for i ∈ 1:10
                annotate!(i, 2, ("$(data_5[i])", 8, :center))
                push!(historia,data_5[i])
            end
            display(plt)
            sleep(1)
            n = n+1
        end
    end
end


function Graficar_tiemp(max)
    n=0
    while n<=max
        if bytesavailable(com) > 0
            comdata = String(read(com))
            data_2 = split(comdata,"\r\n",keepempty=false)[end-1]
            data_3 = split(data_2,", ",keepempty=false)
            data_4 = parse.(Float32,data_3)
            data_5 = reshape(data_4,1,10)
            for i ∈ 1:10
                push!(hist,data_5[i])
            end
            plt = surface(1:n+1,1:10,f2, title = "n = $(n)     t = $(2*n) s")
            display(plt)
            sleep(1)
            n=n+1
        end
    end
end