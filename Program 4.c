void printList(NODE **pglava)
{
    NODE *p=*phead;
    int rb=1;

    printf("=== ==================== ====== ===== =====\n");
    printf("NB. NAME                 AMOUNT PRICE CODE\n");
    printf("=== ==================== ====== ===== =====\n");
    while(p)
    {
        printf("%d %-20s %5lf %5lf %05d\n", rb++, p->a.name, p->a.amount, p->a.price, p->a.code);
        p=p->right;
    }
    printf("=== ==================== ===== ===== =====\n");
}

NODE *search (NODE **phead, NODE **ptail, int code)
{
    NODE *p=*phead, *q=*ptail;

    if(p->a.code==code)
        return p;
    else if(q->a.code==code)
        return q;

    else
    {
        while(p->right->a.code!=code)
            p=p->right;
        if(p==q)
            return 0;
        else
            return p;
    }
}

int delete (NODE **phead, NODE **ptail, int code)
{
    NODE *p=*phead,*q=*ptail,*t=search(&p,&q, code);

    if(t==0)
        return 0;

    else
    {
        t->left->right=t->right;
        t->right->left=t->left;
        free(t);
        return 1;
    }
}
