#include <stdio.h>


int num = 100;

int myfunction(int a){
    return 200; 
}

int main(){
    num = myfunction(100);
    printf("%d\n", num);
    return 0;
}
