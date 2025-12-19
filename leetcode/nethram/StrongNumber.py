def factorial(n):
    sum = 1
    for i in range(1,n+1):
        sum*=i
    return sum

number = 534
temp = number
sum1=0
while(temp > 0):
    digit = temp % 10
    sum1= sum1 + factorial(digit)
    temp = temp // 10

if sum1 == number :
    print("strong")
else:
    print("not strong")
