enc = open("output.txt","r").read().strip()

qwer = 'QwErTyUiOpA'
yurs = '0123456789a'

def changes(mess):
    ret = ''
    for i in mess:
        for j in range(len(qwer)):
            if(i==qwer[j]):
                ret+=yurs[j]
                break
    return ret

flagint = int(changes(enc), 11)
flag = flagint.to_bytes(flagint.bit_length()//8+1, "big")
print(flag)