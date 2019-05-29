/******************************************************************************

                Find Minimum Cost Path in 2D array

*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define min(x,y) ((x<y) ? x : y)

int minCostArray(char *arr, int rowCount, int columnCount) {
    int i, row, cur_pos;
    
    char *result = malloc(rowCount * columnCount);
    if(!result) return -1;
    memset(result, 0, rowCount * columnCount);
    
    // Populate the columns and rows from arr[0]
    result[0] = arr[0];
    
    for(i=1; i<columnCount; i++)
        result[i] = result[i-1] + arr[i];
    
    for(i=columnCount; i<columnCount*rowCount; i+=columnCount)
        result[i] = result[i-columnCount] + arr[i];
    
    for(row=1; row<rowCount; row++) {
        for(cur_pos=((row*columnCount)+1); cur_pos<(row+1)*columnCount; cur_pos++) {
            result[cur_pos] = min(result[cur_pos-1], result[cur_pos-columnCount]) + arr[cur_pos];
            //printf("%d,%d\n", arr[cur_pos] + min(result[cur_pos-1], result[cur_pos-columnCount]),result[cur_pos]);
        }
    }
    
    // Just print out the result array
    for(int count=0; count<rowCount*columnCount; ) {
        printf("%.2d|", result[count++]);
        if(count%columnCount == 0) printf("\n");
    }
    
    return result[(rowCount * columnCount) - 1];
}

int main()
{
    char arr[] = { 0, 1, 2, 3,
                   4, 5, 6, 7,
                   8, 9, 10, 11,
                   12, 13, 14, 15
                 };
                
    int min_cost = minCostArray(arr, 4, 4);
    
    printf("\nMin cost path total = %d\n", min_cost);

    return 0;
}


