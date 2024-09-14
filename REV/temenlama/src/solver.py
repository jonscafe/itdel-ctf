def xor_decrypt(ciphertext, key):
    key_len = len(key)
    decrypted_text = ''

    for i in range(len(ciphertext)):
        # Reverse XOR by applying the same key
        decrypted_text += chr(ciphertext[i] ^ ord(key[i % key_len]))

    return decrypted_text

# Read the content from output.txt
with open("output.txt", "rb") as f:
    encrypted_data = f.read()

# Key used for decryption
key = "thekey"

# Perform XOR decryption
decrypted_message = xor_decrypt(encrypted_data, key)

# Print the decrypted result
print("Decrypted message:", decrypted_message)
