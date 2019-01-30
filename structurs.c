#include<stdio.h>

typedef struct
{
    int roll;
    char name[20];
}stud;

void getdetails(stud s[10],int n)
{
    int i;
    printf("Enter the details:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter details of student %d:\n",i+1);
        scanf("%d%s",&s[i].roll,s[i].name);
    }
}

void display(stud s[10],int n)
{
    int i;
    printf("\n================\n");
    for(i=0;i<n;i++)
    {
        printf("Roll no: %d \n Name: %s\n\n",s[i].roll,s[i].name);
    }
}

main()
{
    int n;
    stud s[10];
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    getdetails(s,n);
    display(s,n);
}
