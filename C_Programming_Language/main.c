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
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("pos: %d", binsearch(10, v, 10));
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, hight, mid;
    low             = 0;
    hight           = n - 1;
    
    while (low <= hight) {
        mid = (low + hight)/2;

        if (x < v[mid])
            hight   = mid + 1;
        else if (x > v[mid])
            low     = mid + 1;
        else
            return mid;
    }
    return -1;
}