def find_all_path(arr, first_point_idx, last_point_idx, path_val):
    all_path=[path_val]

    next_points = [[last_point_idx[0]+i,last_point_idx[1]+j] for i in [-1,0,1] for j in [-1,0,1] 
    if (abs(j+i) == 1 
    and (last_point_idx[0]+i)>=0 
    and (last_point_idx[1]+j)>=0 
    and i<len(arr) 
    and j<len(arr[0])
    and (arr[last_point_idx[0]+i][last_point_idx[1]+j] not in path_val)
    ) ]
    
    next_paths_val = [path_val + [arr[next_point[0]][next_point[1]]] for next_point in next_points]
    for i in range(len(next_paths_val)):
        if(next_paths_val[i][-1] != arr[start_point[0]][start_point[1]]):
            all_path.append(next_paths_val[i]) 
    
        all_path += find_all_path(arr,first_point_idx,next_points[i],next_paths_val[i])

    return all_path

    



start_point = [0,0]
arr = [[1,2,3],[4,5,6],[7,8,9]]
find_all_path(arr, start_point,start_point, [1])

print(all_path)

    