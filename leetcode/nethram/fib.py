a,b=0,1
n=int(input("enter the number: "))

for _ in range(n):
    print(a,end=" ")
    a,b=b,a+b
print(a,"",b)
