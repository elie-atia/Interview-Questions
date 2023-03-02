class Rect:
    def __init__(self,Xmin,Ymin,Xmax,Ymax):
        self.Xmin = Xmin
        self.Ymin = Ymin
        self.Xmax = Xmax
        self.Ymax = Ymax


def checkRectOverlapping(rect1,rect2):
    if(rect1.Xmin > rect2.Xmax 
    or rect1.Ymin > rect2.Ymax 
    or rect1.Xmax < rect2.Xmin 
    or rect1.Ymax < rect2.Ymin):
        return False
    return True

def findRectangeNonOverlapping(rectangles):
    overlappingRectIndex = []
    for i in range(len(rectangles)):
        for j in range(i+1,len(rectangles)):
            if(i not in overlappingRectIndex and j not in overlappingRectIndex):
                if(checkRectOverlapping(rectangles[i],rectangles[j])):
                    overlappingRectIndex.append(i)
                    overlappingRectIndex.append(j)

    return overlappingRectIndex

                

def main():
    rectangles = []
    for i in range(10):
        rectangles.append(Rect(i,i,i+2,i+2))
    rectangles.append(Rect(0,15,2,17))
    print(findRectangeNonOverlapping(rectangles))


if __name__ == '__main__':
  main()