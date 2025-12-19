n = int(input("enter the number: "));
count =0
x = n
sum = 0;
while(x!=0):
    x=x//10
    count=count+1
x = n
while(x!=0):
    digit=x%10
    sum = sum + digit**count
    x=x//10

if(n==sum):
    print("armstrong")
else:
    print("not armstrong")
