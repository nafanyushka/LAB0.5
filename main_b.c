#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//                          STRUCTURES
typedef struct Node Node;
struct Node{
    char* data;
    Node* next;
};
//                          STRUCTURES
char* get_String();
void print(Node*);

int main(){
    Node * list = NULL;
    Node a, b, c;
    a.data = get_String();
    b.data = get_String();
    c.data = get_String();
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    list = &a;
    print(list);
    system("pause");
    return 0;
}

void print(Node* first){
    for(Node * p = first; p != NULL; p = p->next) {
        printf("%s\n", p->data);
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