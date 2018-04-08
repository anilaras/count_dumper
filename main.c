#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
    int icont = 0;
    if (argc < 1) {
        printf("yeterli arguman yok!");
    }
    FILE* fp;
    fp = fopen(argv[1],"r");
    if(fp == 0) {
        perror("fopen");
        exit(1);
    }
    
    long arg2 = atoi(argv[2]);
    long arg3 = atoi(argv[3]);
    
    fseek(fp, arg2, SEEK_SET);
    
    for (int i = 0; i < arg3; i++) {
        int a = fgetc(fp);
        if(strcmp(argv[4],"-tam")== 0){
            long countbyte = ftell(fp);
            if (a == 10) {
                printf("BYTE counter : %.3ld | HEX : %.3X | DEC : %.3d | ASCII : %s  \n",countbyte,a,a,"nl");
                if( feof(fp) ) {
                    break;
                }
            }
            else{
                printf("BYTE counter : %.3ld | HEX : %.3X | DEC : %.3d | ASCII : %c  \n",countbyte,a,a,a );
                if( feof(fp) ) {
                    break;
                }
            }
        }
        if(strcmp(argv[4],"-hex") == 0){
            printf("%2X ",a);
            if( feof(fp) ) {
                break;
            }
        }
        icont++;
        if (icont >= 16) {
            printf("\n");
            icont = 0;
        }
    }
    printf("\n");
    return 0;
}
