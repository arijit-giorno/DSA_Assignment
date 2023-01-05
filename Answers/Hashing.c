#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int main(){
    long int key,hash[MAX];
    int i,j,prime;
    for(i=0;i<MAX;i++){
        hash[i]=-9999;
    }
    printf("Enter a prime number ");
    scanf("%d",&prime);
    i=0;
    printf("enter element ");
    scanf("%d",&key);
    while (key!=-1 &&i<MAX){
        j=key%prime;
        if (hash[j]==-9999)
        {
            hash[j]=key;
            printf("element allocated\n");
        }
        else{
            j++;
            while (hash[j]!=-9999)
            {
                j++;
            }
            hash[j]=key;
            printf("element allocated after collition\n");

        }
        i++;
        printf("enter element ");
        scanf("%d",&key);
    }
    for ( i = 0; i < MAX; i++)
    {
        printf("%d---->%d\n",i,hash[i]);
    }
    
    
}