import struct

# XOR encryption/decryption function
def xor_enc(text, key):
    text_len = len(text)
    key_len = len(key)
    decrypted = bytearray(text_len)
    
    # Perform XOR encryption/decryption
    for i in range(text_len):
        decrypted[i] = text[i] ^ key[i % key_len]
    
    return decrypted

# Convert the encrypted data from v7 into bytes
v7 = [0x955112020202020, 0x6F185C1D3B025A01, 0x5B18151D060A1D40]

# Convert the v7 values into a single byte string
encrypted = b''.join([struct.pack("<Q", x) for x in v7])  # "<Q" for 64-bit unsigned integer (little-endian)

# Define the key
key = b"itdelj0ss"


# Encrypt the input flag using the key
decflag = xor_enc(encrypted, key)

print(decflag)