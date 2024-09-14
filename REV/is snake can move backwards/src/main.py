from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Util.Padding import unpad
from Crypto.Random import get_random_bytes
import base64


FLAG = "fbbeec1cb15337a8803665f7309bb3dc4b6f35bad236987de10c3b840e9aa776b7a7ebd1121fcf7a773afe420c5acd0e25b8c123891bb53df8b72979f9e6d7578e7922dc1787d98edcc4408ad222f3be88b241a7d298af697e02d728e1d852699c9c6c5253acc11b8183229bdb135ef4edf0d707d67851ecf56bbee8f74a2aa08a40cd874b056ab9864e5b8ed3d14088"

def showFlag(user, FLAG):
    iv = b'0000000000000000'
    key = user.encode()
    cipher = bytes.fromhex(FLAG)
    cipher_decrypt = AES.new(key, AES.MODE_CBC, iv)
    decrypted_padded_data = cipher_decrypt.decrypt(cipher)
    decrypted_data = unpad(decrypted_padded_data, AES.block_size)
    print(decrypted_data)
    flag = decrypted_data[::-1]
    flag = base64.b64decode(flag)
    flag = flag[::-1]


user = input("Input the key: ")

if user == "itdelctfitdelctf":
    #showFlag(user, FLAG)
    print("Have you read my code?")
else:
    print("Wrong, try again!")
    