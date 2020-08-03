#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define QUEUE_EMPTY INT16_MIN

typedef struct node
{
        int value;
        struct node *next;
} node;

typedef struct
{
        node *head;
        node *tail;
} queue;

void init_Queue(queue *q)
{
        q->head = NULL;
        q->tail = NULL;
        return;
}

bool enqueue(queue *q, int value)
{
        node * newnode = malloc(sizeof(node));
        if(newnode==NULL) return false;
        newnode->value = value;
        newnode->next = NULL;
        if (q->tail!=NULL){
                q->tail->next = newnode;
        }
        q->tail = newnode;
        if (q->head==NULL)
        {
               q->head = newnode;
        }
        return true;
}

int dequeue(queue *q, int value)
{
        if(q->head==NULL) return QUEUE_EMPTY;
        node* tmp = q->head;
        int result = tmp->value;
        q->head = q->head->next; // move  formard
        if (q->head ==NULL)
        {
                q->tail = NULL;
        }
        free(tmp);
        return result;
}

int main(int argc, char const *argv[])
{
        
        return 0;
}
