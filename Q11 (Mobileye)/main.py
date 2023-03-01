def sum_rectangle(rectangle,arr):
    x1, y1, x2, y2 = rectangle
    
    return sum([arr[i][j] for i in range(x1,x2+1) for j in range(y1,y2+1)])

def sum_rectangles(rectangles,arr):
    return sum([sum_rectangle(rect,arr) for rect in rectangles])

arr = [[1,2,3],[4,5,6],[7,8,9]]
rectangles = [[0,0,1,1],[0,0,2,2]]
print(sum_rectangles(rectangles, arr))