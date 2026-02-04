from random import randint

a = [1,2,3,4,5,6,7,8]
l=len(a)
in_Sum = sum(a)
index = randint(1,l-1)
a[index]=0
new_Sum=sum(a)
print("new sum:",new_Sum,"in_Sum:",in_Sum)
print(in_Sum-new_Sum)
print("\n",a)
