#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE* create_node(int data);
void Print_node(NODE* h);
NODE * insert_at_begin(NODE* head, int data);
NODE * insert_at_end(NODE* head, int data);
NODE * insert_at_index(NODE* head, int data,int index);
NODE * insert_after_value(NODE* head, int data,int value);
NODE * delete_at_begin(NODE* head, int data);
NODE * delete_at_end(NODE* head, int data);
NODE * delete_at_index(NODE* head,int index);
NODE * delete_after_value(NODE* head, int data,int value);
int main(){
    
    struct node * head;
    head = create_node(1);
    head = insert_at_end(head , 3);
    head = insert_at_end(head , 5);
    head = insert_at_end(head , 4);
    head = insert_at_index(head,222,2);
    Print_node(head);
    
    
    
    return 0;
}


NODE* create_node(int data){
    struct node * n1 =  (struct node*)malloc(sizeof(struct node));
    n1->data=data;
    n1->next=NULL;
    return n1;
}
void Print_node(NODE* h){
    NODE* head= h;
    while(head !=NULL){
        printf("%d -->",head->data);
        head = head->next;
        
    }
    puts("NULL");
}
NODE * insert_at_begin(NODE* head, int data){
    NODE* p =create_node(data);
    p->next = head ; 
    head = p ;
    return head;
}
NODE * insert_at_end(NODE* head, int data){
    NODE* ptr= head;
    while(ptr->next !=NULL){
        ptr = ptr->next;
        
    }
    NODE* n = create_node(data);
    ptr->next = n ; 
    return head;
}
NODE * delete_at_begin(NODE* head, int data){
    NODE * temp = head; 
    head = head->next;
    free(temp);
    return head; 
}
NODE * delete_at_end(NODE* head, int data){
    NODE *temp=head;
    while( temp->next->next !=NULL){
        temp = temp->next;
    }
    NODE *ptr = temp->next;
    temp->next = NULL;
    free(ptr);
}
NODE * insert_at_index(NODE* head, int data,int index){
    NODE *temp=head;
    for(int i =0 ; i<index;i++){
        temp = temp->next;
    }
    NODE *new = create_node(data);
    new->next=temp->next;
    temp->next = new;
    return head; 
}
NODE * delete_at_index(NODE* head,int index){
    NODE *temp=head;
    for(int i =0 ; i<index-1;i++){
        temp = temp->next;
    }
    NODE *ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);
    return head;
}