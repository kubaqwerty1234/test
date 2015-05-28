#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>


    typedef struct node {
        int num;
        struct node *next;
    } node;


    void push(int num, node **head);
    int pop(node **head);
    void display(node **head);
    int is_empty();
    int evaluatePostfix();



    int main()  {
        head = NULL;
        char exp[1000]; // = "5 1 2 + 4 * + 3 -";
        printf("Input expression:\t");
        fgets(exp, 1000, stdin);
        for(int i = 1; i <= strlen(exp); i++) {
            if(exp[i] == '\n') {
                exp[i] = '\0';
            }
            else if (exp[0] == '\n') {
                printf("stack is empty\n");
                exit(0);
            }
        }
        printf("%s = %d\n", exp, evaluatePostfix(exp));

        return 0;
}




    int evaluatePostfix(char* exp)  {
        char * token;
        int counter = 0;
        char temp[256][256];
        token = strtok(exp, " ");
        while(token != NULL)    {
            strcpy(temp[counter], token);
            token = strtok(NULL, " ");
            counter++;
        }

        for (int i = 0; i < counter; i++)    {
            if (isdigit(*(temp[i]))) {
                int val = atoi(temp[i]);
                push(val, &head);
            }
            else   {
                int val1 = pop(&head);
                int val2 = pop(&head);
                switch (exp[i]) {
                    case '+':    push(val2 + val1, &head);
                                 printf("%d\n", (*head).num);
                                 break;
                    case '-':    push(val2 - val1, &head);    break;
                    case '*':    push(val2 * val1, &head);    break;
                    case '/':    push(val1 / val2, &head);    break;
                }
            }
        }
        return pop(&head);
    }




    void push (int item, node **head) {
        node *temp;
        node * get_node(int);
        temp = get_node(item);
        temp->next = *head;
        *head = temp;
    }


    node *get_node(int item) {
        node *temp;
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL)
            printf("\nMemory cannot be allocated");
        temp->num = item;
        temp->next = NULL;
        return(temp);
    }




    int pop(node **head)    {
        int item;
        node *temp;
        item = (*head)->num;
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return(item);
    }

    int is_empty(node *temp) {
        if (temp == NULL)
            return 1;
        else
            return 0;
    }




    void display(node **head)   {
        node *temp;
        temp = *head;
        if(head == NULL)    {
            printf("stack is empty\n");
            return;
        }
        printf("\n");
        printf("=========\n");
        while(temp!=NULL)   {
            printf("%d\n", (*temp).num);
            temp = (*temp).next;
        }
        printf("=========\n");
    }
