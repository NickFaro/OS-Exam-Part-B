#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


//creates the node
struct node {
    int data;
     struct node * next;
};

//creates the head and tail nodes
struct node * front = NULL;
struct node * rear;

//inserts a node to the tail of the queue
void insert(struct node * ptr, int pcb) {

    ptr = (struct node * ) malloc(sizeof(struct node));
    //check for null pointer
    if (ptr == NULL) {
        printf("Null Pointer!");
        return;

    } else {
        //assign int pcb to node ptr
        ptr -> data = pcb;
        //if the queue is empty then assign ptr as the head and tail
        if (front == NULL) {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
            //if the queue is not empty then assign ptr to the tail
        } else {
            rear -> next = ptr;
            rear = ptr;
            rear -> next = NULL;
        }
    }
}

//inserts a node at the head of the queue
void insertHead(struct node * ptr, int pcb) {
    //allocate space for the new ndoe
    struct node *newNode = malloc(sizeof(struct node));
    //assign int pcb to the new node
    newNode->data = pcb;
    //attach the current head node to the end of the new node
    newNode->next = front;
    //set the new node as the head
    front = newNode;

}


int main() {
    //struct the node to be called
    struct node * head = NULL;
   //insert the two original nodes
    insert(head, 7);
    insert(head, 2);
    //create temporary node
     struct node * temp = front;

//print current nodes and their data
printf("Before Adding:\n");
     while(temp != NULL) {
        printf("PCB%d    PID = %d    State   Registers   ...\n", front -> data, front -> data);
     temp=temp->next;
    }

printf("After Adding:\n");

    insertHead(head, 4);
    insert(head, 9);
//print the queue after adding new PCBs
 while(front != NULL) {
       printf("PCB%d    PID = %d    State   Registers   ...\n", front -> data, front -> data);
        front=front->next;
    }

//free the queue
    while(front != NULL) {
        free(head);
       front=front->next;
    }

    return 0;


}