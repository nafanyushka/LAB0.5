#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//                          STRUCTURES
typedef struct Node Node;
struct Node{
    char data;
    Node* next;
};
//                          STRUCTURES
char* get_String();
void print(Node*);
//void factoring(Node* a, Node* chet, Node* nechet);
Node* strict(char*);

int main(){
    Node * list = NULL;
//    char* a = get_String();
    printf("Your string: ");
    list = strict(get_String());
    printf("Only digits: ");
    print(list);
    system("pause");
    return 0;
}

void print(Node* first){
    for(Node * p = first; p->next != NULL; p = p->next) {
        printf("%c", p->data);
    }
    printf("\n");
}

//void factoring(Node* a, Node* chet, Node* nechet){
//    for(Node* p = a; p != NULL; p = p->next){
//
//    }
//}

Node* strict(char* a){
    Node* list = (Node*)malloc(sizeof(Node));
    Node* p = list;
    int i = *a;
    while(*a != '\0'){
        if(48 <= i && i <= 57)
//        if(*a == '0'|| *a == '1' || *a == '2' || *a == '3' || *a == '4' || *a == '5' || *a == '6' || *a == '7' || *a == '8' || *a == '9')
        {
            list->data = *a;
            list->next = (Node *) malloc(sizeof(Node));
//        printf("%c\n", list->data);
            list = list->next;
        }
        a++;
        i = *a;
    }
    list->next = NULL;
//    printf("END OF HYPE!\n");
    free(a);
    return p;
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