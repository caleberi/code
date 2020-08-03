#include <stdio.h>
#include <memory.h>


typedef struct node
{
        int key;
        struct node* next; // points to the next node element

}Node;

Node* head;
Node* tail;
Node* current;

void listInitializer(Node *n){
        head= (Node*)malloc(sizeof(*head));
        tail = (Node*)malloc(sizeof(*tail));
        head->next=current; // make the head and tail point to the same node
        tail->next = current;
}

void deleteNext(Node *n){
        n->next = n->next->next; // remember to free the memory 
}

Node* insertAfter(int v , Node* n){
        Node* x;
        x =(Node *)malloc(sizeof(*x));
        x->key = v;
        x->next = n->next;
        n->next=x;
        return x;

}


int main(int argc, char const *argv[])
{
        int i,N,M;
        
        return 0;
}

