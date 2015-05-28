#include <stdio.h>
#include <stdlib.h>
#define N 40
typedef struct NODE node;
typedef struct NODE{
    int data;
    node* next;
};
node* list(int ar[N], int size);
void main(){
    int arr[] = { 57, 6, 57, 74, 88, 57, 74, 88, 9, 57 };
    node* new_list = list(arr[10], 10);
    node* tempi = new_list;
    while (tempi->next != NULL){
        printf("%d ->", tempi->data);
    }
}

node* list(int ar[N], int size){
    int i;
    node*head = (node*)malloc(sizeof(node));
    head->data = ar[0];
    head->next = NULL;

    for (i = 1; i < size; i++){
        node*temp = head;
        while((temp->data != ar[i]) && (temp->next != NULL)){
            temp = temp->next;
        }
        if ((temp->next == NULL) && (temp->data != ar[i])){
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        temp->data = ar[i];
        temp->next = NULL;
        }
    }

    return head;

}
