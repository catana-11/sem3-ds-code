/*Program to : 
1.Create sparse Matrix
2.Display sparse Matrix
3.Create Compact Form
4.Display Compact Form
5.Simple Tranpose matrix
6. Fast transpose matrix
*/
#include <stdio.h>

void input_matrix(int r, int c, int sp[r][c]) //Function to get sparse matrix
{
    printf("\nEnter matrix elements : \n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Enter element (%d, %d) : ",i, j);
            scanf("%d", &sp[i][j]);
        }
    }
}

void show_matrix(int r, int c, int sp[r][c]) //Function to display sparse matrix
{
    printf("\nEntered matrix is : \n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d\t", sp[i][j]);
        }
        printf("\n");
    }
}

int compact(int r, int c, int sp[r][c], int cp[20][3]) //Function to create compact form matrix
{
    int k = 1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(sp[i][j] != 0)
            {
                cp[k][0] = i;
                cp[k][1] = j;
                cp[k][2] = sp[i][j];
                k++;
            }
        }
    }

    cp[0][0] = r;    //For 0th row
    cp[0][1] = c;
    cp[0][2] = k - 1;

    return k;
}


void simple_transpose(int r, int c, int cp[20][3], int tp[20][3]) //Function to create simple transpose matrix 
{
    int k = 1;
    for(int i = 0; i < cp[0][1]; i++)
    {
        for(int j = 1; j <= cp[0][2]; j++)
        {
            if(cp[j][1] == i)
            {
                tp[k][0] = cp[j][1];
                tp[k][1] = cp[j][0];
                tp[k][2] = cp[j][2];
                k++;
            }
        }
    }
    tp[0][0] = c;  //For 0th row
    tp[0][1] = r;
    tp[0][2] = k - 1;
}



void fast_transpose(int cp[20][3], int tp[20][3]) //Function to find fast transpose
{
    int rTerm[20]; //to store no of non zero elements
    int rPos[20]; 
    int loc = 0; //location index of transposed matrix

    for(int i = 0; i < cp[0][1]; i++)
    rTerm [i] = 0;

    for(int i = 1; i <= cp[0][2]; i++)
    {
        rTerm[cp[i][1]]++;
    }
    rPos[0] = 1;

    for(int i = 1; i < cp[0][1]; i++)
    rPos[i] = rPos[i - 1] + rTerm[i - 1];

    for(int i = 1; i <= cp[0][2]; i++)
    {
        loc = rPos[cp[i][1]];
        tp[loc][0] = cp[i][1];
        tp[loc][1] = cp[i][0];
        tp[loc][2] = cp[i][2];
        rPos[cp[i][1]]++;
    }

    tp[0][0] = cp[0][1];
    tp[0][1] = cp[0][0];
    tp[0][2] = cp[0][2];
}

int main()
{
    int r = 0, c = 0, k = 0, count1 = 0, count2 = 0, choice = 0;
    char cont = '\0';

    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);

    int sparseMatrix[r][c];
    int CompactForm[20][3];
    int SimpleTranspose[20][3];

    input_matrix(r, c, sparseMatrix);
    show_matrix(r, c, sparseMatrix);
    count1 = compact(r, c, sparseMatrix, CompactForm);
    show_matrix(count1, c, CompactForm);

    do
    {
        printf("Menu\n1.Simple Transpose\n2.Fast Transpose\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                    printf("\nSimple Transpose Matrix is : \n");
                    simple_transpose(r, c, CompactForm, SimpleTranspose);
                    show_matrix(count1, c, SimpleTranspose);
                    break;

            case 2:
                    printf("\nFast Transpose Matrix is : \n");
                    fast_transpose(CompactForm, SimpleTranspose);
                    show_matrix(count1, c, SimpleTranspose); 
                    break;

            default:
                    printf("Enter a valid choice !!!");

        }

        printf("Do you want to continue ? (y / n) : ");
        scanf(" %c", &cont);
    } 
    
    while (cont == 'Y' || cont == 'y');
    


    return 0;
}