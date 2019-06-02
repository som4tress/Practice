/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define MAX(x,y) ((x>y) ? x : y)
#define ABS(x) ((x<0) ? x*(-1) : x)

int largest_single_subarray(char *arr, int len, char *res, int *res_len) {
    int max_sum = 0, res_count;
    for(int i=0; i<len; i++) {
        int sum = arr[i];
        max_sum = MAX(sum, max_sum);
        
        for(int j=i+1; j<len; j++) {
            sum += arr[j];
            max_sum = MAX(sum, max_sum);
        }
    }
    *res_len = res_count;
    return max_sum;
}

int main()
{
    char arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    char res[100] = {0};
    int max_sum, len;
    
    max_sum = largest_single_subarray(arr, sizeof(arr), res, &len);
    
    printf("Max Sum = %d\nContagious Array = ", max_sum);
    
    for(int i=0; i<len; i++) {
        printf("%d|", res[i]);
    }

    return 0;
}
