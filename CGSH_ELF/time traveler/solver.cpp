#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>

using std::cout;

int main(int argc, char** argv){
    int deadline = 1500000000;
    int now = time(NULL);

    FILE *fp;
    fp = fopen("./Message","r");

    int message[30];
    char flag[30];
    int ch;
    int i = 0;

    while( (ch = fgetc(fp) ) != EOF){
        message[i] = ch;
        i += 1;
    }

    while(now > deadline){
        srand(now);
    
        for(int j = 0 ; j < i ; j ++){
            flag[j] = message[j]^rand();    
        }
        if( !strncmp("CGCTF{",flag,6)){
            printf("%s", flag);
            break;
        }
        now--;
    }
    return 0;
}
