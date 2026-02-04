from collections import Counter

a = "aaavbbssfs"

b = Counter(a)

for c in a:
    print(c,b[c])
