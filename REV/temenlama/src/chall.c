#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xor_operation(const char *str, const char *key, FILE *output) {
    size_t str_len = strlen(str);
    size_t key_len = strlen(key);
    
    for (size_t i = 0; i < str_len; i++) {
        // XOR each character of the string with the key (repeating key if shorter)
        char result = str[i] ^ key[i % key_len];
        fputc(result, output);  // write XOR result to the file
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string> <key>\n", argv[0]);
        return 1;
    }

    const char *str = argv[1];  // First argument: input string
    const char *key = argv[2];  // Second argument: key

    // Open output file
    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Failed to open output file");
        return 1;
    }

    xor_operation(str, key, output);

    fclose(output);
    printf("XOR operation completed and written to output.txt\n");
    return 0;
}
