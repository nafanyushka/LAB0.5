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
        printf("\nStart: %s\nFinal: %s\n\n", a, b);
        free(b);
    };
    system("pause");
    return 0;
}

char* reverse(char* a){
    char* string = a;
    char* b = (char*)malloc(10 + strlen(string) * sizeof(char));
    int k = 0, size = 0;
    if(b == NULL || string == NULL){
        printf("sosNULL");
        return "error!";
    }

    printf("Let's go!\n");

    while(*string != '\0'){
        if(*string == ' ') {
            string++;
            k = 0;
            printf("OBNULENIE!\n");
        }
        else{
            if(*(string + 1) == ' ' || *(string + 1) == '\0') {
                if (*(string + 1) == ' ') {
                    for (int i = 0; i <= k; i++, b++, size++) {
                        *b = *(string - i);
                        printf("\" \" HERE: %c\n", *b);
                    }
                    *b = ' ';
                    b++;
                    size++;
                    string++;
                }
                if (*(string + 1) == '\0') {
                    k++;
                    for (int i = 0; i <= k; i++, b++, size++) {
                        *b = *(string - i);
                        printf("\\0 number %d HERE: %c\n", k, *b);
                    }
                    *b = '\0';
                    b = b - size;
                    b = (char*)realloc(b, strlen(b));
                    return b;
                }
            }
            else{
                string++;
                k++;
            }
        }
    }
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
