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
//                          FUNCS
char* get_String();
void print(Node*);
void factoring(Node* a, Node* chet, Node* ne_chet);
Node* strict(char*);
//                          FUNCS

int main(){
    Node * list = NULL;
    Node * chet = (Node*)malloc(sizeof(Node));
    Node * ne_chet = (Node*)malloc(sizeof(Node));
    char* a = (char*)malloc(19);
    while(*a != EOF) {
        printf("Your string: ");
        a = get_String();
        if(*a == '\0') {
            continue;
            free(a);
        }
        list = strict(a);
        free(a);
        printf("Only digits: ");
        print(list);
        printf("\nChet and Ne_chet: \nChet: ");
        factoring(list, chet, ne_chet);
        print(chet);
        printf("Ne_chet: ");
        print(ne_chet);
        printf("\n");
    }
    system("pause");
    return 0;
}

void print(Node* first){
    printf("\"");
    for(Node * p = first; p->next != NULL; p = p->next) {
        printf("%c", p->data);
    }
    printf("\"\n");
}

void factoring(Node* a, Node* chet, Node* ne_chet){
    Node* List_chet = chet;
    Node* List_ne_chet = ne_chet;
    Node* last_space;
    char helper1 = ' ', helper = ' ';
    for(Node* p = a; p->next != NULL; p = p->next){
        if((((int)p->data)%2 == 1)){
            List_ne_chet->data = p->data;
            helper = List_ne_chet->data;
            List_ne_chet->next = (Node*)malloc(sizeof(Node));
            List_ne_chet = List_ne_chet->next;
        }
        if((((int)p->data)%2 == 0) && (48 <= (int)p->data && (int)p->data <= 57)) {
            List_chet->data = p->data;
            helper1 = List_chet->data;
            List_chet->next = (Node*)malloc(sizeof(Node));
            List_chet = List_chet->next;
        }
        if(p->data == ' ' && helper1 != ' ') {
            List_chet->data = ' ';
            helper1 = List_chet->data;
            last_space = List_chet;
            List_chet->next = (Node *) malloc(sizeof(Node));
            List_chet = List_chet->next;
        }
        if(p->data == ' ' && helper != ' '){
            List_ne_chet->data = ' ';
            helper = List_ne_chet->data;
            last_space = List_ne_chet;
            List_ne_chet->next = (Node*)malloc(sizeof(Node));
            List_ne_chet = List_ne_chet->next;
        }
//        printf("%d", ((int)p->data)%2);
    }
    List_ne_chet->next = NULL;
    List_chet->next = NULL;
    if(last_space->next->next == NULL)
        last_space->next = NULL;

}

Node* strict(char* a){
    Node* list = (Node*)malloc(sizeof(Node));
    Node* p = list;
    int i = (int)*a;
    char helper;
    while(*a != '\0'){
        if((48 <= i && i <= 57) || *a == ' ')
//        if(*a == '0'|| *a == '1' || *a == '2' || *a == '3' || *a == '4' || *a == '5' || *a == '6' || *a == '7' || *a == '8' || *a == '9')
        {
//            printf("\nList data: %c; *a: %c", list -> data, *a);
            if(helper == ' ' && *a == ' ') {

            }
            else{
                list->data = *a;
                helper = list->data;
                list->next = (Node *) malloc(sizeof(Node));
//        printf("%c\n", list->data);
                list = list->next;
            }
        }
        a++;
        i = (int)*a;
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