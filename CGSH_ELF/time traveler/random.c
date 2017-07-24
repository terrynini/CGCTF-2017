#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    srand(time(NULL));

    char input[32] = {0};
    char output[32] = {0};
    scanf("%30s", input);

    for(int i = 0 ; i < strlen(input) ; i++){
        output[i] = input[i] ^ rand();
    } 
    printf("%s\n", output);


}
