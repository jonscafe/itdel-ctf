import os

def xor(message, key):
    data1 = message
    data2 = (key*(len(message)//len(key)+1))[:len(message)]
    return bytes([b1 ^ b2 for b1, b2 in zip(data1, data2)])
    

FLAG = b'ITDEL{4m4z1ngg_r3u533_##v1g3n334r35##}'
# print(len(FLAG))

assert len(FLAG) == 38

secret = os.urandom(5)

enc = xor(FLAG, secret)
with open("output.txt", "w") as f:
    f.write(enc.hex())
