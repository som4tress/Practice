/******************************************************************************
                     https://leetcode.com/problems/binary-watch/
*******************************************************************************/

#include <stdio.h>

char HrLookup[12], MinLookup[60];

int CountSetBits(char val) {
    int count = 0;
    while(val) {
        count++;
        val = val & (val-1);
    }
    return count;
}

void PopulateLookup() {
    int i;
    
    for(i=0; i<12; i++) {
        HrLookup[i] = CountSetBits(i);
        MinLookup[i] = CountSetBits(i);
    }
    
    for(;i<60; i++) {
        MinLookup[i] = CountSetBits(i);
    }
}

void PossibleTimeRecursive(char HrTargetSetBits, char MinTargetSetBits) {
    int hr, min;
    
    if(!HrTargetSetBits) {
        // exit condition
        for(min=0; min<59; min++) {
            if(MinLookup[min] == MinTargetSetBits) {
                printf("%.02d:%.02d\n", 0, min);
            }
        }
        return;
    }
    
    if(HrTargetSetBits > 0 && !MinTargetSetBits) {
        for(hr=0; hr<11; hr++) {
            if(HrLookup[hr] == HrTargetSetBits) {
                printf("%.02d:%.02d\n", hr, 0);
            }
        }
    } else if(HrTargetSetBits > 0 && MinTargetSetBits) {
        for(hr=0; hr<11; hr++) {
            if(HrLookup[hr] == HrTargetSetBits) {
                for(min=0; min<59; min++) {
                    if(MinLookup[min] == MinTargetSetBits) {
                        printf("%.02d:%.02d\n", hr, min);
                    }
                }
            }
        }
    }
    
    PossibleTimeRecursive(--HrTargetSetBits, ++MinTargetSetBits);
}

void PossibleTime(char n) {
    if(n > 8) return;
    
    if(n <= 3)
        PossibleTimeRecursive(n, 0);
    else
        PossibleTimeRecursive(3, n-3);
}

int main()
{
    int i;
    PopulateLookup();
    PossibleTime(2);
}
