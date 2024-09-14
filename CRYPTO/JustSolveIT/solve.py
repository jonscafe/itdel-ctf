from pwn import *
from sage.all import matrix

io = process(["python3","chall.py"])

def gen():
    io.recvuntil(b'YOUR EQUAtion: ')
    arr = [i[1:-1].split("=") for i in io.recvline().decode().strip()[1:-1].replace(" ","").split(",")]
    ret = []
    for i,j in arr:
        temp1 = [int(k.strip()[:-1]) for k in i.split("+")]
        temp2 = int(j.strip())
        ret.append(temp1+[temp2])
    return ret

def solve():
    ret = gen()
    Mat = matrix(ret)
    ret = []
    for i in Mat.rref():
        ret.append(int(i[-1]))
    submit(ret)
    io.recvline()

def submit(val):
    io.recvuntil(b'a:')
    io.sendline(str(val[0]).encode())
    io.recvuntil(b'b:')
    io.sendline(str(val[1]).encode())
    io.recvuntil(b'c:')
    io.sendline(str(val[2]).encode())
    io.recvuntil(b'd:')
    io.sendline(str(val[3]).encode())

while True:
    ret = io.recvline()
    if(b'Hello' not in ret):
        print(ret)
        break
    solve()