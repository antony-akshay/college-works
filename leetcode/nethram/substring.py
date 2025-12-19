a = "akshay"
b = "is there any one named akshay antony here ?"
l=len(b)
c = b.split()
print(l)
print(c[0])

index = b.find(a)

if a in b:
    print("present",index)
else:
    print("not present",index)
