# rarely used in real life examples

def bubble_sort(arr):
    s = len(arr)
    for i in range(s):
        for j in range(s-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                count+=1
    print("Array is sorted in",count,"swaps.")
    print("First Element:",arr[0])
    print("Last Element:", arr[s-1])
    return arr

a = [37, 82, 49, 2, 13, 90, 56, 8, 63, 21]
print(bubble_sort(a))


