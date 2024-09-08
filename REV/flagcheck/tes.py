flag = "ITDEL{kamulebihsukapakaighidraapaidapro}"
res = []

for i, x in enumerate(flag):
    # print(ord(x))
    if i % 3 == 1:
        res.append(ord(x) ^ 24)
        # print(ord(x), ord(x) ^ 24)
    elif i % 3 == 2:
        res.append(ord(x) ^ 51)
        # print(ord(x), ord(x) ^ 51)
    else:
        res.append(ord(x) ^ 32)
        # print(ord(x), ord(x) ^ 32)
    
print(res)