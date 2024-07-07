#include <stdio.h>

struct frame_LFU
{
    int content;
    int frequency;
    int count;
} frames_LFU[10];

int main()
{
    int i, j, n, m, pages[50];
    printf("enter the no of pages");
    scanf("%d", &n);
    printf("enter the reference string");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("enter the size of frame");
    scanf("%d", &m);

    lfu(pages, n, m);
}


void lfu(int pages[],int n,int f){

    int i,j,id=0,k,cnt=1,min,pf=0;
    
    for(i=0;i<n;i++){
        frames_LFU[i].content=-1;
        frames_LFU[i].count=0;
        frames_LFU[i].freq=0;
    }

    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(frames_LFU[j].content==pages[i]){
                printf("hit");
                frames_LFU[j].freq++;
                frames_LFU[j].count=cnt++;
                break;
            }
        }
        if(j==f){
            printf("miss");
            if(id<f){
                frames_LFU[id].content=pages[i];
                frames_LFU[id].count=cnt++;
                frames_LFU[id].freq=1;
                id++;
            }
            else{
                min=0;
                for(k=0;k<f;k++){
                    if(frames_LFU[k].freq<frames_LFU[min].freq){
                        min=k;
                    }

                    else if(frames_LFU[k].freq==frames_LFU[min].freq && frames_LFU[k].count<frames_LFU[min].count){
                            min=k;
                    }
                }
                frames_LFU[min].content=pages[i];
                frames_LFU[min].freq=1;
                frames_LFU[min].count=cnt++;
            }
            pf++;
        }
         for (j = 0; j < f; j++)
        {
            if (frames_LFU[j].content != -1)
                printf("%d ", frames_LFU[j].content);
        }
        printf("\n");
    }
    printf("page fault:%d",pf);
}
