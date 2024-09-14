#include <stdio.h>
#include <string.h>

// XOR encryption/decryption function
void xor_enc(char *text, const char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    for (int i = 0; i < text_len; i++) {
        text[i] ^= key[i % key_len];
    }
}

// Main function to check the flag
int main() {
    // Encrypted flag to check against
    char encrypted_flag[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x11, 0x55, 0x09, 0x01, 0x5A, 0x02, 0x3B, 0x1D, 0x5C, 0x18, 0x6F, 0x40, 0x1D, 0x0A, 0x06, 0x1D, 0x15, 0x18, 0x17}; // Raw bytes
    char key[] = "itdelj0ss";
    char input[50];  

    printf("Enter the flag: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

    // XOR the input with the key
    xor_enc(input, key);

    // Compare XORed input with the encrypted flag using memcmp
    if (memcmp(input, encrypted_flag, sizeof(encrypted_flag)) == 0) {
        printf("Correct flag!\n");
    } else {
        printf("Incorrect flag!\n");
    }

    return 0;
}
