#include <stdio.h>
#include <string.h>


void xor_enc(char *text, const char *key){
    int text_len = strlen(text);
    int key_len = strlen(key);
    for(int i = 0; i < text_len; i++){
        text[i] ^= key[i % key_len];
    }
}


int main(){
    char text[] = "ITDEL{ezr3v_x0r_3ncrypt}";
    char key[] = "itdelj0ss";
    printf("Text: %s\n", text);

    xor_enc(text, key);
    for (int i = 0; i < strlen(text); i++){
        printf("%02X", text[i]);
    }
    printf("\n");
}


// encrypted: 2020202020115509015A023B1D5C186F401D0A061D15185B