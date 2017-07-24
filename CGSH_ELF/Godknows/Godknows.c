#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
    
    char input[100] = "";
    printf("Only God knows what to input:\n");
    scanf("%100s",input);

    if(*( int32_t *)input == 0x47344c37){
        printf("you such a monster\n");
    }

    return 0;
}
