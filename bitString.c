#include <stdio.h>

int main()
{
    int U_size, A_size, B_size;
    printf("enter universal set size: "); // Universal set
    scanf("%d", &U_size);

    int U[U_size];
    for (int i = 0; i < U_size; i++)
    {
        printf("U[%d] = ", i);
        scanf("%d", &U[i]);
    }
    printf("***** Universal set *****\n");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d  ", U[i]);
    }
    printf("\n");

    printf("enter set A size: "); // Set A
    scanf("%d", &A_size);
    int A[A_size];
    for (int i = 0; i < A_size; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    printf("***** set A *****\n");
    for (int i = 0; i < A_size; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");

    printf("enter set B size: "); // Set B
    scanf("%d", &B_size);
    int B[B_size];
    for (int i = 0; i < B_size; i++)
    {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }
    printf("***** set B *****\n");
    for (int i = 0; i < B_size; i++)
    {
        printf("%d  ", B[i]);
    }
    printf("\n");

    int bitA[U_size], bitB[U_size];
    for (int i = 0; i < U_size; i++)
    { // Initialize all bits to 0
        bitA[i] = 0;
        bitB[i] = 0;
    }

    for (int i = 0; i < A_size; i++)
    { // Create bit string for A
        for (int j = 0; j < U_size; j++)
        {
            if (A[i] == U[j])
            {
                bitA[j] = 1;
            }
        }
    }

    for (int i = 0; i < B_size; i++)
    { // Create bit string for A
        for (int j = 0; j < U_size; j++)
        {
            if (B[i] == U[j])
            {
                bitB[j] = 1;
            }
        }
    }

    // Displaying bit strings

    printf("Bit string of A : ");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d", bitA[i]);
    }
    printf("\n");

    printf("Bit string of B : ");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d", bitB[i]);
    }
    printf("\n");

    // bit string operations
    printf("\n\nAUB : \n");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d", bitA[i] | bitB[i]);
    }
    printf("\n");

    // bit string operations
    printf("\n\nA∩B : \n");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d", bitA[i] & bitB[i]);
    }
    printf("\n");

    // bit string operations
    printf("\n\nA-B : \n");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d", bitA[i] & !(bitB[i]));
    }
    printf("\n");

    // bit string operations
    printf("\n\nB-A : \n");
    for (int i = 0; i < U_size; i++)
    {
        printf("%d", bitB[i] & !(bitA[i]));
    }
    printf("\n");
    return 0;
}