//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
int binsearch(int x, int v[], int n);

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    printf("pos: %d", binsearch(1, v, 20));
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, hight, mid;
    low             = 0;
    hight           = n - 1;
    
    while (low <= hight && v[mid] != x) {
        mid = (low + hight)/2;

        if (x < v[mid])
            hight   = mid - 1;
        else
            low     = mid + 1;
    }
/*
    if (v[hight] == x)
        return hight;
    else if (v[low] == x)
        return low;
    else if (v[mid] == x)
        return mid;
    else
        return -1;
*/
    return (v[mid] == x) ? mid : -1;
}