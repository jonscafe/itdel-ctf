enc = bytes.fromhex(open("output.txt", "r").read().strip())

def xor(message, key):
    data1 = message
    data2 = (key*(len(message)//len(key)+1))[:len(message)]
    return bytes([b1 ^ b2 for b1, b2 in zip(data1, data2)])
    
key = xor(b'ITDEL', enc[:5])
flag = xor(enc, key)
print(flag)