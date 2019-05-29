/******************************************************************************

                   Remove Duplicate characters from string in-place

*******************************************************************************/

#include <stdio.h>
//1234
int main()
{
    int i, cur=0;
    char arr[] = {0,0,1,2};
    
    for(i=0;i<sizeof(arr)-1;i++) {
        if(arr[i] != arr[i+1])
            cur++;
        arr[cur] = arr[i];
    }
    
    for(i=0; i<cur+1; i++) {
        printf("%d|", arr[i]);
    }

    return 0;
}


