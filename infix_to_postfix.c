#include<stdio.h>

struct stack
{
    int item[20];
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
void push(stack *s,int num)
{

    s->item[++s->top]=num;
}

void pop(stack *s)
{
        s->top--;
}

int peek(stack *s)
{
     int num;
     num=s->item[s->top];
     return num;
}


int pre(char a)
{
    int p;
    switch(a)
    {
       case '+':
       case '-':p=1;
                break;
       case '/':
       case '*':p=2;
                break;
       default:p=-1;
    }
    return p;
}

int isoperand(char a)
{
    if(a>='a'&&a<='z')
        return 1;
    else
        return 0;
}
int isoperator(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/')
    return 1;
    else
        return 0;
}

void infix_post(stack s,char post[20],char in[20])
{
    int i;
    int j=0;
    for(i=0;in[i];i++)
    {
        if(isoperand(in[i]))
        {
            post[j++]=in[i];

        }
        else
        {
            if(isoperator(in[i]))
            {
                if(isempty(s))
                    push(&s,in[i]);
                else
                {
                    if(pre(in[i])>pre(peek(&s)))
                        push(&s,in[i]);
                    else
                    {
                        while(!isempty(s)&&pre(in[i])<=pre(peek(&s)))
                        {
                            post[j++]=peek(&s);
                            pop(&s);

                        }
                        push(&s,in[i]);
                    }
                }
            }
            else if(in[i]=='(')
                    push(&s,in[i]);
        else if(in[i]==')')
        {
            while(!isempty(s)&&peek(&s)!='(')
            {
                post[j++]=peek(&s);
                pop(&s);
            }

            if(!isempty(s))
              pop(&s);

        }

        }

    }
    while(!isempty(s))
    {

        post[j++]=peek(&s);
        pop(&s);
    }
    post[j]='\0';
}

main()
{
    stack s;
    s.top=-1;
    int post[20],in[20];
    printf("Enter the infix expression:\n");
    scanf("%s",in);
    infix_post(s,post,in);
    printf("Postfix expression is %s \n",post);
}
