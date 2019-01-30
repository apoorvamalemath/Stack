
#include<stdio.h>

struct stack
{
    int item[10];
    int top;
};

typedef struct stack stack;

void push(stack *s,int num)
{

    s->item[++s->top]=num;
}

int peek(stack *s)
{
    int num;
    num=s->item[s->top];
    return num;

}

void pop(stack *s)
{
    s->top--;
}


int Postfix(stack s,char post[20])
{
    int x1, x2,res,i;
    for(i=0;post[i];i++)
    {
        if(isdigit(post[i]))
        {
            push(&s,post[i]-'0');
        }
        else
        {
            x1=peek(&s);
            pop(&s);
            x2=peek(&s);
            pop(&s);
            switch(post[i])
            {
                case '+':res=x2+x1;
                         break;
                case '-':res=x2-x1;
                         break;
                case '*':res=x2*x1;
                          break;
            }
            push(&s,res);
        }

    }
    res=peek(&s);
    return res;
}

main()
{
    stack s;
    s.top=-1;
    int res;
    int postfix[10];
    printf("Enter the postfix exp:\n");
    scanf("%s",postfix);
    res=Postfix(s,postfix);
    printf("ANS :%d\n",res);
}




