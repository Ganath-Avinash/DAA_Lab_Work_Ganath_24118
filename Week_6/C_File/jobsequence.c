#include <stdio.h>

struct Job{
    int id;
    int p;   
    int d;   
};

void sort(struct Job j[], int n){
    struct Job temp;
    for(int i = 0; i < n-1; i++){
        for(int k = 0; k < n-i-1; k++){
            if(j[k].p < j[k+1].p){
                temp = j[k];
                j[k] = j[k+1];
                j[k+1] = temp;
            }
        }
    }
}

int main(){

    int n = 0;
    printf("Enter no of Jobs:\n");
    scanf("%d", &n);

    struct Job j[n];

    for (int i = 0; i < n; i++){
        printf("Enter job %d profit and deadline:\n", i+1);
        j[i].id = i+1;
        scanf("%d %d", &j[i].p, &j[i].d);
    }

    sort(j, n);

    int max = 0;
    for(int i = 0; i < n; i++){
        if(j[i].d > max)
            max = j[i].d;
    }

    int slot[max+1];
    int totalProfit = 0;

    for(int i = 0; i <= max; i++)
        slot[i] = -1;

    for(int i = 0; i < n; i++){
        for(int k = j[i].d; k > 0; k--){
            if(slot[k] == -1){
                slot[k] = j[i].id;
                totalProfit += j[i].p;
                break;
            }
        }
    }

    printf("\nSelected Jobs:\n");
    for(int i = 1; i <= max; i++){
        if(slot[i] != -1)
            printf("Job %d\n", slot[i]);
        else{
            printf("-\n");
        }
    }

    printf("Total Profit = %d\n", totalProfit);

    return 0;
}
