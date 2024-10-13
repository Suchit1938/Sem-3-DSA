#include<stdio.h>
#include<math.h>
void poly(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d",arr[i]);
        if(i!=0){
            printf("x^%d",i);
        }
        if(i!=size-1){
            printf(" + ");
        }

    }
    printf("\n");
}

int main(){
    int A[4]={1,-3,3,4};
    int B[3]={1,2,3};
    int max;
    int m = sizeof(A)/sizeof(A[0]) ;
    int n = sizeof(B)/sizeof(B[0]) ;
    if(m>n){
        max = m;
    }
    else{
        max= n;
    }
    int C[max];
    poly(A,m);
    poly(B,n);
    for (int i = 0; i < m; i++)
    {
        C[i]=A[i];
    }
    for (int i = 0; i < n; i++)
    {
        C[i] += B[i];
    }
    
    poly(C,max);
    
}