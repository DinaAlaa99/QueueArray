#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int top; // contain index of next empty place in the array
//int bottom; // contain index of next retrived data

struct student
{
    int id;
    char name[20];
    int grades[4];
};

struct student array[SIZE];

struct student fillStudent();
void checkchoice(int choice, struct student s1);
int printMenu();
void printStudent(struct student s);
int enQueue(struct student s);
struct student deQueue();

int main()
{
    struct student s;
    int choice;
    int flag=1;



    while (flag)
    {
        choice= printMenu();
        checkchoice(choice,s);
    }


    return 0;
}
int enQueue(struct student s)
{
    int retval=0;


    if ( top < SIZE )
    {
        array[top]=s;
        top++;
        retval=1;
    }
    return retval;
}
struct student deQueue()
{
    struct student st;
    st.id = -1;
    int i = 0;

    if (top != 0) // queue not empty

    {
        st = array[0];
        for (i=0; i<top; i++)
        {
            array[i]=array[i+1];
        }

        top--;

    }
    return st;
}
void checkchoice(int choice, struct student s1)
{

    int flag;

    switch(choice)

    {
    case 1:

    {
        s1 = fillStudent();
        flag = enQueue(s1);
        if (flag)
        {
            printf("\nStudent Added Succesfuly...\n");

        }
        else
        {
            printf("\nQueue is full\n");
        }
    }

    break;

    case 2:

    {

        s1 = deQueue();

        if (s1.id!=-1)
        {
            printStudent(s1);

        }
        else
        {
            printf("Queue is empyt");
        }
    }

    break;

    case 3:

        exit(0);

        break;



    }

}
struct student fillStudent()
{
    struct student s;
    int i;

    printf("Please Enter Student ID:\n");
    scanf("%d",&s.id);

    printf("Please Enter Studet Name:\n");
    scanf("%s",s.name);

    for (i=0; i<4; i++)
    {
        printf("Please Enter Studet Grade %d : ",i+1);
        scanf("%d",&s.grades[i]);
    }
    return s;

}
void printStudent(struct student s)
{
    int k, sum=0 ;
    printf("\nstudent id : %d \n",s.id);
    printf("student name : %s \n",s.name);

    for (k=0; k<4; k++)
    {
        printf("studet Grade %d = %d\n",k+1,s.grades[k]);
        sum+=s.grades[k];

    }
    printf("Total grades= %d\n",sum);
}
int printMenu()
{
    int choice;


    printf("\n****** MENU ******\n");
    printf("\n1.Enqueue\n");
    printf("\n2.Dequeue\n");
    printf("\n3.exit\n");
    printf("\nEnter your choice:\n");
    scanf("%d",&choice);

    if (choice <1 || choice > 3)
    {
        printf("\nPlease Enter Valid Number\n");
    }
    return choice;
}

