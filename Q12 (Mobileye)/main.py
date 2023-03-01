def find_all_path_to_end_points(arr, path, end_points):
    all_path= []

    next_last_points =  [ [path[-1][0]+i,path[-1][1]+j] for i in [-1,0,1] for j in [-1,0,1] 
    if (abs(j+i) == 1 
    and (path[-1][0]+i)>=0 
    and (path[-1][1]+j)>=0 
    and (path[-1][0]+i)<len(arr) 
    and (path[-1][1]+j)<len(arr[0])
    and ( [path[-1][0]+i,path[-1][1]+j] not in path)
    ) ]
    
    next_paths = [path + [[next_point[0],next_point[1]]] for next_point in next_last_points]

    

    for i in range(len(next_last_points)):
        if(next_paths[i][-1] in end_points):
            all_path += next_paths
        all_path +=  find_all_path_to_end_points(arr,next_paths[i], end_points)

    return all_path

def find_all_path(arr):
    all_path = []
    for x in range(len(arr)):
        for y in range(len(arr[0])):
            end_points = [ [i,j] for i in range(len(arr)) for j in range(len(arr[0])) if (i*len(arr[j])+j)>(x*len(arr[j])+y) ]
            all_path += find_all_path_to_end_points(arr, [[x,y]],end_points)

    return all_path



arr = [[1,2,3],[4,5,6],[7,8,9]]
all_path = find_all_path(arr)
# print(all_path)

print([arr[idx[0]][idx[1]] for idx in all_path[290]])
print(len(all_path))



    