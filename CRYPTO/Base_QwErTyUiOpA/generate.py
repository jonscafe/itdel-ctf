FLAG = b'ITDEL{G4m1f1c4t10n_0N_b453_p0w3rr}'

flagint = int.from_bytes(FLAG, byteorder='big')

len('QwErTyUiOpA') == len('0123456789a')

qwer = 'QwErTyUiOpA'
# qwer = '0123456789a'

def changes(n):
    if n == 0:
        return '0'
    
    digits = []
    while n > 0:
        digits.append(qwer[n % 11])
        n //= 11
    
    # Join the digits in reverse order
    return ''.join(digits[::-1])

temp = changes(flagint)

with open("output.txt", "w") as f:
    f.write(temp)
