 void delete_list (NODE **phead, NODE **ptail)
    {
        while(*phead)
        {
            NODE *d=(*phead)->right;
            free(*phead);
            *phead=d;
        }
    }


    void load_item(ITEM *a)
    {
        printf("Code:");scanf("%d",&a->code);
        printf("Name:");scanf("%s",a->name);
        printf("Amount:");scanf("%lf",&a->amount);
        printf("Price:");scanf("%lf", &a->price);
    }


int main()
{
    NODE *head=0, *tail=0;
    ITEM a;
    int code, b;
    char c;

    do
    {
        printf("Add-[A], Delete-[D], Search-[S], Print-[P], Stop-[0]:");
        scanf("%c", &c);

        if(c=='A')
        {
            load_item(&a);
            NODE *p=search(&head, &tail, a.code);
            if(p!=0)p->a=a;
            else
                add(&head, &tail, &a);
        }
        if(c=='D')
        {
            printf("Insert the code of the item you want to delete:");
            scanf("%d", &code);
            b=delete(&head, &tail, code);
            if(b==0)
                printf("There's no item with that code.");
            else
                printf("Item with code %d is deleted.", code);
        }
        if(c=='S')
        {
            printf("Insert the code of the item you are looking for:");
            scanf("%d", &code);
            NODE *d=search(&head, &tail, code);
            if(d==0)
                printf("There's no such item.");
            else
                printf("Item with code %d is %s.", d->a.code, d->a.name);
        }
        if(c=='P')printList(&head);
        else if(c!='0')
            printf("Unknown option.");

            }while(c!='0');


        delete_list(&head, &tail);


    return 0;
}
