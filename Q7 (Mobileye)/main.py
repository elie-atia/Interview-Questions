# sliding window approach:

import numpy as np

def min_of_3x3(matrix):
    result = np.zeros((14, 14))
    for i in range(14):
        for j in range(14):
            result[i, j] = np.min(matrix[i:i+3, j:j+3])
    return result

matrix = np.zeros((16,16))
for i in range(16):
    for j in range(16):
        matrix[i][j] = i + j

print(matrix)
print(min_of_3x3(matrix))


# This approach has a time complexity of O(n^2), where n is the size of the input matrix. 