#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_String();

int main(){

    int strings = 0;
    char* a = "!";
    while(*a != '\0'){
        a = get_String();
        printf("%s\n", a);
    };
    system("pause");
    return 0;
}

char* get_String(){
    char* a = (char*)malloc(1);
    char buf[11];
    int n, size = 0;
    *a = '\0';
    do{
        n = scanf("%10[^\n]", buf);
        if(n < 0){
            free(a);
            a = NULL;
            continue;
        }
        if(n == 0)
            scanf("%*c");
        else{
            size += (int)strlen(buf);
            a = (char*)realloc(a, size + 1);
            strcat(a, buf);
        }
    }while(n > 0);
    return a;
}
