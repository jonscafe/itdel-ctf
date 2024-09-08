#include<stdio.h>
#include<string.h>

int c[] = {105, 76, 119, 101, 84, 72, 75, 121, 94, 85, 116, 86, 66, 113, 91, 83, 109, 88, 65, 104, 82, 75, 121, 90, 71, 112, 90, 68, 106, 82, 65, 104, 82, 73, 124, 82, 80, 106, 92, 93};
char inp[100];

int main(int argc, char **argv){
    printf("apa flagnya\n");
    scanf("%s", inp);
    int len = strlen(inp);
    if(len != 40){
        printf("Salah\n");
        return 0;
    }
    for(int i=0; i<len; i++){
        if(i%3==1 && inp[i] != (c[i] ^ 24)){
            printf("Salah\n");
            return 0;
        } else if (i%3==2  && inp[i] != (c[i] ^ 51)){
            printf("Salah\n");
            return 0;
        } else if (i%3==0  && inp[i] != (c[i] ^ 32)){
            printf("Salah\n");
            return 0;
        }
    }
    printf("Benar\n");
    return 0;
}