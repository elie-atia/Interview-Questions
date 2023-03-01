import matplotlib.pyplot as plt
import time

def find_all_path_to_end_points(arr, path, end_points):
    all_path = []

    x, y = path[-1]

    # Generate all possible next points
    next_last_points = [        [x+i, y+j] for i in [-1, 0, 1] for j in [-1, 0, 1]
        if (abs(j+i) == 1
        and 0 <= x+i < len(arr)
        and 0 <= y+j < len(arr[0])
        and [x+i, y+j] not in path)
    ]

    # Generate all possible next paths
    next_paths = [path + [next_point] for next_point in next_last_points]

    # Recursively find all paths to end points
    for i in range(len(next_last_points)):
        if next_paths[i][-1] in end_points:
            all_path.append(next_paths[i])
        all_path.extend(find_all_path_to_end_points(arr, next_paths[i], end_points))

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

print([arr[idx[0]][idx[1]] for idx in all_path[5]])
# print(len(all_path))

print(all_path[5])
# Define the size of the grid
n_rows = 2
n_cols = 2



# Define the colors for the paths
colors = ['r']

# Loop through each path in the list
for i, path in enumerate(all_path):
    # Plot the grid
    plt.plot([0, n_cols], [n_rows, n_rows], 'k-')
    plt.plot([0, n_cols], [0, 0], 'k-')
    plt.plot([0, 0], [0, n_rows], 'k-')
    plt.plot([n_cols, n_cols], [0, n_rows], 'k-')

    for j in range(len(path)-1):

        x1, y1 = path[j]
        x2, y2 = path[j+1]
        plt.plot([x1, x2], [y1, y2], colors[i%len(colors)]+'-', linewidth=2)
        plt.plot([x1], [y1], colors[i%len(colors)]+'o')
        
    x1, y1 = path[j+1]
    plt.plot([x1], [y1], colors[i%len(colors)]+'o')
    plt.pause(0.1)
    plt.clf()


plt.show()


    
# Show the final plot

    