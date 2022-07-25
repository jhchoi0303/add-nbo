#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){

    uint32_t a, b;


    if(argc != 3){                 //input two files
        printf("Input 2 files!");
        return 0;
    }


    FILE *file1 = fopen(argv[1],"r"); 
    if(file1==NULL){
        printf("error!");
        return 0;
    }
    fread(&a, 1, sizeof(a), file1);  //read one uint32_t from file1 to a
    fclose(file1);


    FILE *file2 = fopen(argv[2],"r");
    if(file2==NULL){
        printf("error!");
        return 0;
    }
    fread(&b, 1, sizeof(b), file2);  //read one uint32_t from file2 to b
    fclose(file2);

    uint32_t a_nbo = htonl(a);          // Host byte order to Network byte order
    uint32_t b_nbo = htonl(b);


    printf("%d(%#x) + %d(%#x) = %d(%#x)", a_nbo, a_nbo, b_nbo, b_nbo, 
    a_nbo + b_nbo, a_nbo + b_nbo);     // hash mark adds 0x to number



}