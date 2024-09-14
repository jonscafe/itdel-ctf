import random
from secret import FLAG

# equation a, b, c, d
loop = 2
while loop>1:
    print("Hello:")
    a = random.getrandbits(512)
    b = random.getrandbits(512)
    c = random.getrandbits(512)
    d = random.getrandbits(512)
    
    eq = []
    for i in range(4):
        mult = [random.getrandbits(512) for _ in range(4)]
        ret = a*mult[0] + b*mult[1] + c*mult[2] + d*mult[3]
        temp = f'{mult[0]}a + {mult[1]}b + {mult[2]}c + {mult[3]}d = {ret}'
        eq.append(temp)
    
    print("YOUR EQUAtion:",eq)
    print("your ans:")
    aa = input("a:")
    bb = input("b:")
    cc = input("c:")
    dd = input("d:")
    if int(aa)==a and int(bb)==b and int(cc)==c and int(dd)==d:
        print("Your right")
        loop-=1
    else:
        print("wrong answer")

print(FLAG)