def find_max_sum_subarray(arr):
    max_sum = float('-inf')
    for j in range(len(arr)):
        max_sum_j = arr[j]
        current_sum_j = arr[j]
        for i in range(j+1,len(arr)):
            current_sum_j += arr[i]
            max_sum_j = max(current_sum_j,max_sum_j)
            
        max_sum = max(max_sum,max_sum_j)

    return max_sum



arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
max_sum_subarray = find_max_sum_subarray(arr)
print(max_sum_subarray)
