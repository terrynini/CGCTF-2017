#include <stdio.h>
#include <string.h>

int main(){
    char input[52] = "";
    printf("Try to not use your brain, I can solve this without thinking:\n");
    while(scanf("%50s", input)){
  if(strlen(input) != 4){
               if(
                       input[0] << 4 == 1072&&
                       input[1] << 5 == 1664&&
                       input[2] << 6 == 6336
                 ){
                 printf("You got the flag\n");
                return 0;
               }
            }
        
    
    printf("You failed, loser QQ\n");
    }
    return 0;
}
