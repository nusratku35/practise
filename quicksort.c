#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int partition(int* ara,int s,int e)
{
    int pivot=ara[e],t;
    int partition_index=s;
    int i;
    for(i=s;i<e;i++){
        if(ara[i]<=pivot){
            t=ara[i];
            ara[i]=ara[partition_index];
            ara[partition_index]=t;
            partition_index++;
        }
    }
    t=ara[partition_index];
    ara[partition_index]=ara[e];
    ara[e]=t;
    return partition_index;
}
void quick_sort(int* ara,int s,int e)
{
    int partition_index;
    if(s<e){
        partition_index=partition(ara,s,e);
        quick_sort(ara,s,partition_index-1);
        quick_sort(ara,partition_index+1,e);

    }
}

int main()
{
    int ara[1000];
    int n;///array size
    cin>>n;
    for(int i=0;i<n;i++)cin>>ara[i];

    quick_sort(ara,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",ara[i]);
    }
    return 0;
}
