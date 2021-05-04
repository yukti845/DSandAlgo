import math
import os
import random
import re
import sys

T = int(input())

for i in range(T):

    ND = input().split()
    N = int(ND[0])
    D = int(ND[1])

    a = list(map(int, input().split()))

    a.extend(a[:D])
    del (a[:D])

    for j in range(N):
        print(a[j])
    print('')
    
# Method 2
def rotLeft(a, d):
    for i in range(d):
        ele = a.pop(0)
        a.append(ele)
    return a

# Hourglass max sum problem
def hourglassSum(arr):
    sum_hour = []
    for i in range(4):
        for j in range(4):
            Sum = (arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + 
                    arr[i+2][j+1] + arr[i+2][j+2])
            sum_hour.append(Sum)
    return max(sum_hour)

# Minimum swaps
def minimumSwaps(arr):
    count=0
    for i in range(0,n):
        if(arr[i]==i+1):
            continue
