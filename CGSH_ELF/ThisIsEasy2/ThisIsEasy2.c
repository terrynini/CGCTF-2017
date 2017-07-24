#include <stdio.h>
#include <string.h>

int main(){
    
    char input[40] = "";
    printf("Warning: do not strings this program, just input something:\n");
    fgets(input, sizeof(input), stdin);
    
    for(int i = 6 ; i < strlen(input)-2 ; i++){
        input[i] = input[i] ^ 16;
    }
    if(!strcmp(input, "CGCTF{Th15_0ne_1s_N0t_th5_F14g}\n")){
        printf("You will dominate the world!!\n CGCTF{Y0u_sh0u1d_n3v3r_5u6mit_7hi5_0n3}");
    }

    return 0;
}
