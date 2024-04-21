#include<stdio.h>
main(){
    int item,i=0;
    int a[5]={34,56,32,78,12};
    printf("Enter searching item :");
    scanf("%d",&item);
    while(i<5)
    {
        if(a[i]=item){
            printf("item found at %d",i);
            exit(0);
        }
        i++;
    }
    if(i>=5){
        printf("Item not found");
        exit(0);
    }
    return 0;

}