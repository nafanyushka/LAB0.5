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
void factoring(Node* a, Node** chet, Node** ne_chet);
Node* strict(char*);
void freestrct(Node*);
//                          FUNCS

int main(){
    char* a = (char*)malloc(19);
    while(*a != EOF) {
        Node * list = NULL;
        Node * chet = (Node*)calloc(1, sizeof(Node));
        Node * ne_chet = (Node*)calloc(1, sizeof(Node));
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
        factoring(list, &chet, &ne_chet);
        print(chet);
        printf("Ne_chet: ");
        print(ne_chet);
        printf("\n");
//        freestrct(list);
        freestrct(chet);
        freestrct(ne_chet);
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

void factoring(Node* a, Node** chet, Node** ne_chet){
    Node* clspace = NULL;
    Node* List_chet = *chet;
    Node* List_ne_chet = *ne_chet;
    Node* flag_c = NULL,* flag_nc = NULL;
    char helper1 = ' ', helper = ' ';
    for(Node* p = a; p->next != NULL; p = p->next) {
        if(clspace != NULL){
            if (clspace->next->data == p->data && clspace->data == ' ') {
            free(clspace);
        }
    }
        if((((int)p->data)%2 == 1 && (48 <= (int)p->data && (int)p->data <= 57))){
            List_ne_chet->next = p;
            List_ne_chet = List_ne_chet->next;
            helper = List_ne_chet->data;
        }
        if((((int)p->data)%2 == 0) && (48 <= (int)p->data && (int)p->data <= 57)) {
            List_chet->next = p;
            List_chet = List_chet->next;
            helper1 = List_chet->data;
        }
        if(p->data == ' ' && helper1 != ' ') {
            List_chet->next = (Node *) malloc(sizeof(Node));
            flag_c = List_chet;
            List_chet = List_chet->next;
            List_chet->data = ' ';
            helper1 = ' ';
        }
        if(p->data == ' ' && helper != ' '){
            List_ne_chet->next = (Node *) malloc(sizeof(Node));
            flag_nc = List_ne_chet;
            List_ne_chet = List_ne_chet->next;
            List_ne_chet->data = ' ';
            helper = ' ';
        }
        if(p->data == ' '){
            clspace = p;
        }
    }
    List_ne_chet->next = malloc(sizeof (Node));
    List_chet->next = malloc(sizeof (Node));
    List_ne_chet = List_ne_chet->next;
    List_chet = List_chet->next;
    List_ne_chet->next = NULL;
    List_chet->next = NULL;
    List_chet = *chet;
    List_ne_chet = *ne_chet;
    *chet = (*chet)->next;
    *ne_chet = (*ne_chet)->next;
    free(List_chet);
    free(List_ne_chet);
    if(flag_nc != NULL){
        if(flag_nc->next->next->next == NULL){
            free(flag_nc->next->next);
            flag_nc->next->next = NULL;
        }
    }
    if(flag_c != NULL){
        if(flag_c->next->next->next == NULL){
            free(flag_c->next->next);
            flag_c->next->next = NULL;
        }
    }

}

Node* strict(char* a){
    Node* list = (Node*)malloc(sizeof(Node));
    Node* p = list;
    int i = (int)*a;
    char helper;
    while(*a != '\0'){
        if((48 <= i && i <= 57) || *a == ' ')
        {
            if(helper == ' ' && *a == ' ') {

            }
            else{
                list->data = *a;
                helper = list->data;
                list->next = (Node *) malloc(sizeof(Node));
                list = list->next;
            }
        }
        a++;
        i = (int)*a;
    }
    list->next = NULL;
    free(a);
    return p;
}

char* get_String(){
    char* a = (char*)malloc(1);
    if(a == NULL){
        printf("SOSNULL!!!!!!!!!!!!!!!!!!!!!!");
    }
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
    if(*(a + strlen(a) - 1) == ' '){
        for(int i = strlen(a) - 1; *(a + i) == ' '; i--)
            *(a+i) = '\0';
    }
    return a;
}

void freestrct(Node* a){
    Node* helper = NULL;
    while(a->next != NULL){
        helper = a;
        a = a->next;
        if(helper != NULL)
            free(helper);
    }
    free(a);
}