#include<stdio.h>
int main(){
    int A[5]={5,4,3,2,1};
        int swap;
  
    for (int i = 0; i < 5; i++)
    {
        int min = i;
        for (int j = i+1; j < 5; j++)
        {
            if(A[j]<A[min]){
                min = j;
            }
        }
        if(min!=0){
            swap=A[i];
            A[i]=A[min];                                                                
            A[min]=swap;

        }
        
    }
      for (int i = 0; i < 5; i++)
    {
        printf("%d,",A[i]);
    }
    
}