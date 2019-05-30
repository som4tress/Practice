/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define MAX(x,y) ((x>y) ? x : y)
#define ABS(x) ((x<0) ? x*(-1) : x)

int largest_single_subarray(char *arr, int len, char *res) {
    int max_sum = 0, count;
    int i, j;
    for(i=0; i<len; i++) {
        int sum = arr[i];
        for(j=i+1; j<len; j++) {
            sum += arr[j];
            if(sum > max_sum) {
                max_sum = sum;
                memset(res, 0, len);
                for(count=i; count<=j; count++) {
                    res[count-i] = arr[count];
                }
            }
        }
    }
    return max_sum;
}

int main()
{
    char arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    char res[100] = {0};
    int max_sum;
    
    max_sum = largest_single_subarray(arr, sizeof(arr), res);
    
    printf("Max Sum = %d\n", max_sum);
    
    for(int i=0; i<sizeof(arr); i++) {
        printf("%d|", res[i]);
    }

    return 0;
}
