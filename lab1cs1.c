#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

    int * arr = (int *) malloc(5 * sizeof(int));

    

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {

        *(arr + i) = 1;

    }

    printf("%d", *arr); 


    return 0;
}