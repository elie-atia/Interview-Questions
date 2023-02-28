import math

def findNumberInArrayByPercentage(arr,percentage):
    index = (percentage/100) * (len(arr)-1)

    if(index % 1 == 0 ):
        return arr[int(index)]

    lowerIndex = math.floor(index)
    upperIndex = math.ceil(index)
    lowerValue = arr[lowerIndex]
    upperValue = arr[upperIndex]
    fraction = index - lowerIndex

    return lowerValue + (upperValue - lowerValue)*fraction

arr = [10,20,30,50]
percentage = 87.44
result = findNumberInArrayByPercentage(arr, percentage)
print(result)