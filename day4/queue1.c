/* Program to implement simple queue for job scheduling */
#include <stdio.h>

#define MaxSize 20

struct job
{
    int jobid;
    char jobname[20];
    int jobpriority;
};

struct job sq[MaxSize];
int front = -1, rear = -1;

int queue_full() //Function to check id queue is full
{
    if(rear == MaxSize - 1)
    {
        return 1; //Queue is full
    }

    else
    {
        return 0; //Inserts a job in queue
    }
}

int queue_empty() //Function to check if queue is empty
{
    if(front == rear)
    {
        return 1; //Queue is empty
    }

    else 
    {
        return 0; //Deletes a job
    }
}

void queue_insert() //Function to insert a job in the queue
{
    if(queue_full() == 0)
    {
        rear++;
        printf("Enter Job Details : \n");
        printf("Enter Job Id : "); scanf("%d", &sq[rear].jobid);
        printf("Enter Job Name : "); scanf("%s", sq[rear].jobname);
        printf("Enter Job Priorty : "); scanf("%d", &sq[rear].jobpriority);
    }
    
    else 
    {printf("Queue is Full !!!\n");}
}

void delete_queue() //Function to delete a job in queue
{
    if(queue_empty() == 0)
    {
        front++;
  
        printf("Deleted Job is : \n");
        printf("------------------------\n");
        printf("Job Id : %d\n", sq[front].jobid);
        printf("Job Name : %s\n", sq[front].jobname);
        printf("Job Priorty : %d\n", sq[front].jobpriority);
    

    }
    
    else 
    { printf("Queue is empty!\n");}
}

void display_queue() //Function to display jobs in the queue
{
    if(queue_empty() == 0)
    {
       
        printf("------------Job Details----------\n");

        for(int i = front + 1; i <= rear; i++)
        {
            printf("Job Id : %d\n", sq[i].jobid);
            printf("Job Name : %s\n", sq[i].jobname);
            printf("Job Priorty : %d\n", sq[i].jobpriority);
            printf("------------------------------------\n");
        }

    }

    else 
    {
        printf("Queue is empty!\n");
    }
}

int main()
{
    int choice = 0;
    char cont = '\0';

    do
    {
        printf("Menu\n1.Insert Job\n2.Delete Job\n3.Display Job\n");
        printf("Enter your choice : "); scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                    queue_insert();
                    break;
            case 2: 
                    delete_queue();
                    break;
            case 3:
                    display_queue();
                    break;
            default: 
                    printf("Invalid Choice\n");
        }

        printf("Do you want to continue ? (y / n) : "); scanf(" %c", &cont);
    } while(cont == 'Y' || cont == 'y');

    return 0;
}