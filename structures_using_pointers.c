#include<stdio.h>

typedef struct
{
    int roll;
    char name[20];
}stud;

void getdetails(stud *p,int n)
{
    int i;
    printf("Enter the details:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter details of student %d:\n",i+1);
        scanf("%d%s",&(p)->roll,(*p).name);
        p++;
    }
}

void display(stud *p,int n)
{
    int i;
    printf("\n================\n");
    for(i=0;i<n;i++)
    {
        printf("Roll no: %d \n Name: %s\n\n",(p+i)->roll,(p+i)->name);
    }
}

main()
{
    int n;
    stud s[10];
    //stud *p;
    //p=&a;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    getdetails(&s,n);
    display(&s,n);
}
