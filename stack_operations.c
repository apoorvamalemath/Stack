 #include<stdio.h>

struct stack
{
    int item[5];
    int top;
};

typedef struct stack stack;

int isempty(stack s)
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}

int isfull(stack s)
{
    if(s.top==4)
        return 1;
    else
        return 0;
}

void push(stack *s,int num)
{
    if(isfull(*s))
    {
        printf("Stack overflow\n");
        return;
    }
    else
    s->item[++s->top]=num;
}

void pop(stack *s)
{
    int num;
    if(isempty(*s))
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        num=s->item[s->top];
        printf("%d is popped \n",num);
        s->top--;
    }

}

int peek(stack *s)
{
    int num;
    if(isempty(*s))
    {
        printf("Stack is empty\n");
        return;
    }
    num=s->item[s->top];
    return num;
}

main()
{
    stack s;
    s.top=-1;
    int done=1,num;
    int ch,pele;
    while(done)
    {
        printf("1.Push\n2.Pop\n3.Peek\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number to be pushed:\n");
                   scanf("%d",&num);
                   push(&s,num);
                   break;
            case 2:pop(&s);
                   break;
            case 3:pele=peek(&s);
                   printf("Peek element is %d\n",pele);
                   break;
            default:done=0;
        }
    }
}
