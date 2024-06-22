#include<stdio.h>

int main(){
    int n,m,i,j,k,l,alloc[10][10],need[10][10],max[10][10];
    printf("enter the no of processes and resources:");
    scanf("%d %d",&n,&m);
    int avail[m];
    printf("enter the allocation matrix:");
    for(i=0;i<n;i++){
        for ( j = 0; j < m; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        
    }

    printf("enter the max matrix:");
    for(i=0;i<n;i++){
        for ( j = 0; j < m; j++)
        {
            scanf("%d",&max[i][j]);
        }
        
    }

    printf("enter the available matrix");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }



    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    printf("need matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d",need[i][j]);
        }
    }

    int finish[n],work[m],safesequence[n],in=0;

    for ( i = 0; i < n; i++)
    {
        finish[i]=0;
    }
    for ( i = 0; i < m; i++)
    {
        work[i]=avail[i];
    }
    

    for ( k = 0; k< n; k++)
    {
        for ( i = 0; i < n; i++)
        {
            if(finish[i]==0){
                int flag=0;
                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safesequence[in++]=i;
                    for(k=0;k<m;k++){
                        work[k]=work[k]+alloc[i][k];
                    }
                    finish[i]=1;
                }
            }
        }
        printf("safe sequence is :\n");
        for(i=0;i<n;i++){
            printf("P%d ->",safesequence[i]);
        }
        
    }
    


}