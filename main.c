#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_String();
char* reverse(char*);

int main(){

    int strings = 0;
    char* a = "!";
    while(*a != '\0'){
        a = get_String();
        char* b = reverse(a);
        printf("%s\n%s\n\n", a, b);
        free(b);
    };
    system("pause");
    return 0;
}

char* reverse(char* a){
    char* string = a;
    char* b = (char*)malloc(strlen(string) * sizeof(char));
    int k = 0, size = 0;
    if(b == NULL || string == NULL)
        printf("sosNULL");
    while(*string != '\0'){
        if(*string == ' ' && *(b-1) == ' ')
            string++;
        else{
            *b = *string;
            b++;
            string++;
            size++;
        }
    }
    *b = '\0';
    return b - size;
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
