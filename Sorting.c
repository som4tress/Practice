/******************************************************************************

                   Sort Characters in Array based on given order 

*******************************************************************************/

#include <stdio.h>

#define MAX_STR 100

void printStr(int len, char str[len][MAX_STR]) {
    for(int i=0; i<len; i++) {
        printf("%s ", str[i]);
    }
    printf("\n");
}

void swap(char *str1, char *str2) {
    char tmp[MAX_STR] = {0};
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}

int compare(char *str1, char *str2, char *sort_arr) {
    char sort_order[50];
    int i, max_len, len_1, len_2;
    
    if(!str1 || !str2) return 0;
    if(strcmp(str1, str2) == 0) return 0;
    
    // Form the hash of sort order
    for(i=0; i<strlen(sort_arr); i++) {
        char val = (sort_arr[i] - 'a');
        sort_order[val] = i;
    }
    
    // Iterate the string pairs and compare per the order in the hash
    len_1 = strlen(str1);
    len_2 = strlen(str2);
    if(len_1 > len_2)
        max_len = len_1;
    else
        max_len = len_2;
        
    for(i=0; i<max_len; i++) {
        if(i > (len_1 - 1))
            return -i;
        else if(i > (len_2 - 1))
            return i;
        else if(sort_order[str1[i]-'a'] > sort_order[str2[i]-'a'])
            return (i+1);
        else if(sort_order[str1[i]-'a'] < sort_order[str2[i]-'a'])
            return -(i+1);
    }
    
    return 0;
}

void sort(int len, char strArr[len][MAX_STR], char *sort_arr) {
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            if(compare(strArr[i], strArr[j], sort_arr) > 0) {
                swap(strArr[i], strArr[j]);
            }
        }
    }
}

int main()
{
    char str[] = {"fguecbdavwyxzhijklmnopqrst"};
    char strArr[7][MAX_STR] = {"geeksforgeeks", "is", "the", "best", "place", "for", "learning"};
    
    printf("Original Str : ");
    printStr(7, strArr);
    printf("Sorted Str : ");
    sort(7, strArr, str);
    printStr(7, strArr);
    //printf("%d\n", compare("geeksforgeeks", "for", str));
    
    return 0;
}


