def move(arr):
    index=0
    for i in range(len(arr)):
        if arr[i] != 0 :
            arr[index],arr[i]=arr[i],arr[index]
            index=index+1
    return  arr

arr1 = [1,0,8,0,5,0,0,3,6,8,0]
print(move(arr1))
