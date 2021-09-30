arr = [-1, 2, -3, 4, 5, 6, -7, 8, 9]

p1,p2=0,len(arr)-1

while(p1<=p2):
    if(arr[p1]<0 and arr[p2]<0):
        p1+=1
    elif(arr[p1]>=0 and arr[p2]<0):
        arr[p1],arr[p2]=arr[p2],arr[p1]
        p1+=1
        p2-=1
    elif(arr[p1]>=0 and arr[p2]>=0):
        p2-=1
    else:
        p1+=1
        p2-=1

print(arr)
