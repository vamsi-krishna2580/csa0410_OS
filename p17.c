#include <stdio.h>

int main() {
    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[3] = {3,3,2};

    int need[5][3];
    int finish[5]={0};
    int safe[5];
    int count=0;

    for(int i=0;i<5;i++)
        for(int j=0;j<3;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    while(count<5){
        for(int i=0;i<5;i++){
            if(!finish[i]){
                int flag=1;

                for(int j=0;j<3;j++)
                    if(need[i][j]>avail[j])
                        flag=0;

                if(flag){
                    for(int j=0;j<3;j++)
                        avail[j]+=alloc[i][j];

                    safe[count++]=i;
                    finish[i]=1;
                }
            }
        }
    }

    printf("Safe Sequence:\n");

    for(int i=0;i<5;i++)
        printf("P%d ",safe[i]);

    return 0;
}