#!/usr/bin/python3

def max_points(A, B):
    if len(A)==1:
        return 1
    final_pts = 0

    for i in range(len(A)-1):
        slopes={}
        slopeCount=0
        sameCount=0
        verticalCount=0
        x1, y1 = A[i], B[i]
        for j in range(i+1, len(A)):
            if i!=j:
                x2, y2 = A[j], B[j]
                if x1==x2 and y1==y2:
                    sameCount += 1
                elif x1==x2:
                    verticalCount += 1
                    slopeCount = max(slopeCount, verticalCount)
                else:
                    slope = ((y2-y1)*1.0)/(x2-x1)
                    if slope not in slopes:
                        slopes[slope] = 1
                        slopeCount = max(slopeCount, slopes[slope])
                    else:
                        slopes[slope] += 1
                        slopeCount = max(slopeCount, slopes[slope])
        final_pts = max((slopeCount+sameCount+1), final_pts)
        print(slopes)
    return final_pts


if __name__ == '__main__':
    A =[1,2,3,4,5,-1]
    B = [1,3,3,5,1,-1]
    print(max_points(A, B))
