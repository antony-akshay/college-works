
def isopening(a):
   return a in "({["

match = {
    ')': '(',
    '}': '{',
    ']': '['
}

a = "[{()}]"
l = []
for c in a:
    if (isopening(c)):
        l.append(c)
    else:
        if not l or l[-1] != match[c]:
            print("invalid")
            break
        l.pop()

if(len(l)==0):
    print("valid")
else:
    print("invalid")
