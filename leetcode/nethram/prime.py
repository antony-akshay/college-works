a = int(input("enter the number:"))
if(a==0 or a==1):
    print("not prime")
else:
    flag=1;
    for i in range(2,a//2+1):
        if(a%i == 0):
            flag=0;

    if(flag):
        print("prime")
    else:
        print("not prime")
