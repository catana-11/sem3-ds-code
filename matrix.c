#include <stdio.h>

void display_matrix(int r, int c, int mat[r][c]){

    printf("\n--------------\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("[%d]    ", mat[i][j]); 
        }
        printf("\n");
    }
}

void display_compact(int cp[20][3]){

    printf("\n-----------------\n");
    for(int i=0; i<=cp[0][2]; i++){
        for(int j=0; j<3; j++){
            printf("[%d]    ", cp[i][j]); 
        }
        printf("\n");
    }
}

int compact(int r, int c, int mat[r][c], int cp[20][3]){

    int k = 1;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(mat[i][j] != 0){
                cp[k][0] = i;
                cp[k][1] = j;
                cp[k][2] = mat[i][j];
                k++;
            }
        }

    }

        cp[0][0] =r;
        cp[0][1] = c;
        cp[0][2] = k-1;

    return k;

}

void simple_transpose(int cp[20][3], int tp[20][3]){
    int l = 1;
    for(int i=0; i<cp[0][2]; i++){
        for(int j=0; j<=cp[0][2]; j++){
            if(cp[j][1] == i){
                tp[l][0] = cp[j][1];
                tp[l][1] = cp[j][0];
                tp[l][2] = cp[j][2];
                l++;
            }
        }

        tp[0][0] =cp[0][1];
        tp[0][1] = cp[0][0];
        tp[0][2] = cp[0][2];

    }
    printf("\nSimple tp:\n");
    display_matrix(l, 3, tp);


}

void fast_tranpose(int cp[20][3], int tp[20][3]){

    int rterm[20];
    int rpos[20];

    for(int i=0; i< cp[0][1]; i++) {rterm[i]=0;}
    for(int i=1; i<= cp[0][2]; i++) {rterm[cp[i][1]]++;}

    rpos[0] = 1;
    for(int i=1; i< cp[0][1]; i++) {rpos[i] = rpos[i-1]+rterm[i-1];}

    int loc;
    for(int i=1; i<= cp[0][2]; i++) {
        loc = rpos[cp[i][1]];
        tp[loc][0]= cp[i][1];
        tp[loc][1]= cp[i][0];
        tp[loc][2]= cp[i][2];
        rpos[cp[i][1]]++;
        
    } 
    
    
        tp[0][0] =cp[0][1];
        tp[0][1] = cp[0][0];
        tp[0][2] = cp[0][2];
    
        printf("\nFast tp-->\n");
        display_matrix(tp[0][2]+1, 3, tp);

}

int main(){

    int r; int c;

    printf("\nEnter rows: "); scanf("%d", &r);
    printf("\nEnter cols: "); scanf("%d", &c);

    int mat[r][c];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("\nEnter [%d][%d]: ", i, j); scanf("%d", &mat[i][j]);
        }
    }

    display_matrix(r, c, mat);

    // for compact:
    int cp[20][3];

    int count = compact(r,c, mat, cp);
    display_compact(cp);

    int choice = 0;

    printf("\nSimple or fast?: "); scanf("%d", &choice);

    if (choice==0){
    // simple tp:
    int stp[20][3];
    simple_transpose(cp, stp);
    }

    //fast tp:
    if (choice==1){
    int ftp[20][3];
    fast_tranpose(cp, ftp);
    }
 

    return 0;
}