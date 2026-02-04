from collections import Counter

a= "akshay"

freq = Counter(a)

for c in a :
    if(freq[c] == 1):
        print(c)
        break
