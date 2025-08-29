function toma_de_medidas(duracion)
    for i ∈ 1:duracion
        datos = String(read(info_serial))
        push!(historial,datos)
        sleep(5)
    end
end

function tratamiento_de_datos(x)
    datos_2 = []
    matrices = []
    datos = split(x,"\r\n",keepempty=false)
    for i ∈ 2:length(datos)-1
        lista_1 = split(datos[i],", ",keepempty=false)
        lista_1 = parse.(Float32,lista_1)
        push!(datos_2,lista_1)
    end
    for i ∈ datos_2
        matriz_i = reverse(reshape(i,10,20)',dims=1)
        push!(matrices,matriz_i)
    end
    return matrices
end