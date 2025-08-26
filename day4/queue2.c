/* Program to implement circular queue for job scheduling */
#include <stdio.h>
#define MaxSize 20

struct job
{
    int jobid;
    char jobname[20];
    int jobpriority;
};

struct job cq[MaxSize];
int front = 0, rear = 0;

int queue_full() //Function to check id queue is full
{
    if(rear == front && (rear + 1) % MaxSize == front)
    {return 1;  } //Queue is full

    else
    {return 0; }//Inserts a job in queue
}

int queue_empty() //Function to check if queue is empty
{
    if(front == rear)
    { return 1; }//Queue is empty

    else 
    { return 0; }//Deletes a job
}

void queue_insert() //Function to insert a job in the queue
{
    if(queue_full() == 0)
    {
        rear = (rear + 1) % MaxSize;
        printf("Enter Job Details : \n");
        printf("Enter Job Id : ");  scanf("%d", &cq[rear].jobid);
        printf("Enter Job Name : "); scanf("%s", cq[rear].jobname);
        printf("Enter Job Priorty : "); scanf("%d", &cq[rear].jobpriority);
    }
    
    else 
    { printf("Queue is Full !!!\n");}
}

void queue_delete() //Function to delete a job in queue
{
    if(queue_empty() == 0)
    {
        front = (front + 1) % MaxSize;
     
        printf("Deleted Job is : \n");
        printf("--------------------\n");
        printf("Job Id : %d\n", cq[front].jobid);
        printf("Job Name : %s\n", cq[front].jobname);
        printf("Job Priorty : %d\n", cq[front].jobpriority);
        printf("\n");

    }
    
    else 
    {  printf("Queue is Empty !!!\n"); }
}

void queue_display() //Function to display jobs in the queue
{
    printf("------------Job Details----------\n");

    if (queue_empty() == 0) {
    for(int i = (front + 1) % MaxSize; i != (rear+ 1) % MaxSize; i = (i + 1) % MaxSize)
    {
        printf("Job Id : %d\n", cq[i].jobid);
        printf("Job Name : %s\n", cq[i].jobname);
        printf("Job Priorty : %d\n", cq[i].jobpriority);
        printf("------------------------------------\n");
    }
}
    else printf("Queue empty!");
    printf("\n");

}

int main()
{
    int choice = 0;
    char cont = '\0';

    do
    {
        printf("Menu\n1.Insert Job\n2.Delete Job\n3.Display Job\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                    queue_insert();
                    break;

            case 2: 
                    queue_delete();
                    break;

            case 3:
                    queue_display();
                    break;

            default: 
                    printf("Invalid Choice !!!\n");

        }

        printf("Do you want to continue ? (y / n) : ");
        scanf(" %c", &cont);
    }

    while(cont == 'Y' || cont == 'y');


    return 0;
}