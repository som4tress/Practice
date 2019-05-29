/******************************************************************************
                           Rotate Array AntiClockwise
*******************************************************************************/

#include <stdio.h>

#define swap(x,y) { char __tmp = x; x = y; y = __tmp; }

void transpose_arr(int m, int n, char arr[m][n]) {
   for(int row=0;row<m;row++) {
        for(int col=row+1;col<n;col++) {
            swap(arr[col][row], arr[row][col]);
        }
    }
}

void reverse_arr_rows(int m, int n, char arr[m][n]) {
    for(int col=0;col<n/2;col++) {
        for(int row=0;row<m;row++) {
            swap(arr[row][col], arr[(m-1)-row][col]);
        }
    }
}

void reverse_arr_columns(int m, int n, char arr[m][n]) {
    for(int row=0;row<m/2;row++) {
        for(int col=0;col<n;col++) {
            swap(arr[row][col], arr[row][(n-1)-col]);
        }
    }
}

int main()
{
    #define row 3
    #define col 3
    
    char arr[row][col] = { 0,1,2,
                           3,4,5,
                           6,7,8
                         };
                      
    transpose_arr(row, col, arr);
    reverse_arr_columns(row, col, arr); // for clockwise rotate
    reverse_arr_rows(row, col, arr); // for anticlockwise rotate
    
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


