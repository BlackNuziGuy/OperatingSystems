#include <stdio.h>
#include <stdlib.h>


typedef struct nd{
    int val;
    struct nd * next;
} node;
node *new(int val){
    node* new = malloc(sizeof(node));
    new->next = NULL;
    new->val = val;
    return new;
}


void insert_node( node *neighbour, node *to_insert ){
    node *dummy;
    to_insert->next = neighbour->next;
    neighbour->next = to_insert;
}

void delete_node( node* to_delete , node *head){

    node *prev = NULL;
    while( head != to_delete){
        prev = head;
        head = head->next;
    }

    prev->next = head->next;
    free(head);
}

void print_list(node *head){

    while( head != NULL){
        printf("%d%s", head->val,(head->next==NULL)?"\n":" ");
        head = head->next;
    }


}


int main(){

    node *head = new(0), *new_node = new(20) ,*current;

    //Initialize
    for(int i=1; i<10; i++)
    {
        current = new(i);
        insert_node(head,current);
    }
    print_list(head);

    //Check insertion and deletion
    insert_node(head,new_node);
    print_list(head);
    delete_node(new_node,head);
    print_list(head);

    //Even more testing
    while (head->next != NULL)
        delete_node(head->next,head);
    print_list(head);
    //It works!

    return 0;
}