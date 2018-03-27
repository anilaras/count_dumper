#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
    int icont;
    
    FILE* fp;
    fp = fopen(argv[1],"r");
    if(fp == NULL)
        printf("olmamis bu anam bi daha ac");
    
    long arg2 = atoi(argv[2]);
    long arg3 = atoi(argv[3]);
    
    fseek(fp, arg2, SEEK_SET);
    
    for (int i = 0; i < arg3; i++) {
        int a = fgetc(fp);
        if(strcmp(argv[4],"-tam")== 0){
            long countbyte = ftell(fp);
            if (a == 10) {
                printf("BYTE counter : %.3ld | HEX : %.3X | DEC : %.3d | ASCII : %.3s | \n",countbyte,a,a,"nl");
            }
            else{
                printf("BYTE counter : %.3ld | HEX : %.3X | DEC : %.3d | ASCII : %.3c | \n",countbyte,a,a,a );
            }
        }
        if(strcmp(argv[4],"-hex") == 0){
        printf("%2X ",a);
        }
        icont++;
        if (icont >= 16) {
            printf("\n");
            icont = 0;
        }
    }
    printf("\n");
extag:
    return 0;
}
