// 1. universal_set_creation
// 2. set A
// 3. set B

#include <stdio.h>
#include <stdlib.h>

int universal_set_creation(int max, int U[]){
    for(int i = 0; i < max; i++){
        printf("U[%d] : ", i);
        scanf("%d", &U[i]);
    }

    for(int i = 0; i < max; i++){
        printf("%d ", U[i]);
    }
}

int set_A_creation(int max, int set_A[]){
    int size;
    while(1){
        printf("\n\nSet A size : ");
        scanf("%d", &size);
        if(size > max){
            printf("ERROR : Size of set A cannot be greater than U");
        }
        else{
            break;
        }        
    }
    
    // int set_A[size];
    for(int i = 0; i < size; i++){
        printf("set_A[%d] : ", i);
        scanf("%d", &set_A[i]);
    }
    for(int i = 0; i < size; i++){
        printf("%d ", set_A[i]);
    }
}

int set_B_creation(int max, int set_B[]){
    int size;
    while(1){
        printf("\n\nSet B size : ");
        scanf("%d", &size);
        if(size > max){
            printf("ERROR : Size of set B cannot be greater than U");
        }
        else{
            break;
        }        
    }
    
    // int set_B[size];
    for(int i = 0; i < size; i++){
        printf("set_B[%d] : ", i);
        scanf("%d", &set_B[i]);
    }
    for(int i = 0; i < size; i++){
        printf("%d ", set_B[i]);
    }
}

int main(){
    int max;
    printf("Size of universal set: ");
    scanf("%d", &max);
    int U[max], set_A[max], set_B[max];
    universal_set_creation(max, U);
    set_A_creation(max, set_A);
    set_B_creation(max, set_B);
    return 0;
}