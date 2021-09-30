arr=[1000,11,445,1,330,3000]


if(len(arr)==1):
    maxi=arr[0]
    mini=arr[0]

if(arr[0]>arr[1]):
    maxi=arr[0]
    mini=arr[1]
else:
    maxi=arr[1]
    mini=arr[0]

for _ in range(2,len(arr)):
    if(arr[_]>maxi):
        maxi=arr[_]
    elif(arr[_]<mini):
        mini=arr[_]

print('max is: ',maxi,'min is: ',mini)
