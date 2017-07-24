#include <stdio.h>
#include <string.h>

int main(){
    char input[20] = "";

    printf("Hello, input the password\n");
    fgets(input, sizeof(input), stdin);
    if(!strcmp(input,"CGCTF{static_analyz3_i5_c001}")){
        printf("Congratulation!!");
    }   
    return 0;
}
