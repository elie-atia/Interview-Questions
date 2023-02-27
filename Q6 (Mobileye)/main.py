import math
# To check if a point is inside a polygon described as a set of points, using the ray casting algorithm:
def is_point_in_polygon(point, polygon):
    n = len(polygon)
    inside = False
    p1x, p1y = polygon[0]
    for i in range(n+1):
        p2x, p2y = polygon[i % n]   
        if point[1] > min(p1y, p2y):
            if point[1] <= max(p1y, p2y):  
                if point[0] <= max(p1x, p2x):
                    if p1y != p2y:
                        xinters = (point[1] - p1y) * (p2x - p1x) / (p2y - p1y) + p1x
                        if p1x == p2x or point[0] <= xinters:
                            inside = not inside
        p1x, p1y = p2x, p2y
    return inside

polygon = [(0,0),(0,1),(1,1),(1,0)]
p1_inside = (0.5,0.5)
p1_outside = (-1,0.5)

print(is_point_in_polygon(p1_inside, polygon))

# Note that this implementation assumes that the polygon is non-self-intersecting and has no holes. 
# If the polygon is self-intersecting or has holes, you will need to use a more advanced algorithm, 
# such as the winding number algorithm or the even-odd rule algorithm.






# The ray casting algorithm can also be used to find the convex hull of a set of points. Here is an outline of the algorithm:
def ray_casting(points):
    # Find the point with the lowest y-coordinate (if there are ties, choose the one with the lowest x-coordinate)
    p0 = min(points, key=lambda p: (p[1], p[0]))

    # Sort the remaining points by the angle they make with the horizontal line passing through p0
    sorted_points = sorted(points, key=lambda p: (math.atan2(p[1] - p0[1], p[0] - p0[0]), p0[0]**2 + p0[1]**2))

    # Initialize an empty list hull
    hull = []

    # Process the sorted points
    for pi in sorted_points:
        while len(hull) >= 2 and (pi[0]-hull[-1][0])*(hull[-2][1]-hull[-1][1]) - (pi[1]-hull[-1][1])*(hull[-2][0]-hull[-1][0]) <= 0:
            hull.pop()
        hull.append(pi)

    # Repeat step 4a until the line passing through the last two points in hull is vertical
    while len(hull) >= 3 and (hull[-1][0]-hull[-2][0])*(hull[-2][1]-hull[-3][1]) - (hull[-1][1]-hull[-2][1])*(hull[-2][0]-hull[-3][0]) == 0:
        hull.pop()

    # Return the list hull as the convex hull of the input set of points
    return hull


print(ray_casting([(0,0),(0,1),(1,1),(1,0),(0.5,1.5),(0.5,0.5)]))



