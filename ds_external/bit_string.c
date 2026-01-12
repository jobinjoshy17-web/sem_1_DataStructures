#include <stdio.h>
#include <stdlib.h>

int max = 10;

int is_duplicate(int arr[], int v, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == v){
            printf("Element already exists!\n");
            return 1;
        }
    }
    return 0;
}

int isUniversal(int U[], int v, int n){
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(U[i] == v){
            flag = 1;
            return 1;
        }
    }

    if(flag == 0){
        printf("Element not present in the universal set"); //Done upto here
    }
}

int main(){
    printf("Size of universal set: ");
    scanf("%d", &max);

    int U[max],v;
    printf("\n***Universal set creation***\n");
    for(int i = 0; i < max; i++){
        printf("U[%d] : ", i + 1);
        scanf("%d", &v);

        if(is_duplicate(U, v, i) == 0){
            U[i] = v;
        }
        else{
            i--;
        }
    }

    printf("\n***Universal set display***\n");
    for(int i = 0; i < max; i++){
        printf("%d ", U[i]);
    }
    printf("\n");
    return 0;
}