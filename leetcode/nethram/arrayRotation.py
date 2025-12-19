def arrayRotation(arr,k):
    temp=[]
    for i in range(len(arr)):
        index=(k+i)%len(arr)
        temp.insert(index,arr[i])
    print(temp)

arrayRotation([1,2,3,4,5,6,7],4)
