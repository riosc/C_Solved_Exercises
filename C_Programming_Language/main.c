//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
    
    int x = 987, y = 525;
    
    printf("val: %d", setbits(x, 9, 10, y));
    return 0;
}

//setbits:set bits from y to x in pos p to n
unsigned setbits(unsigned x, int p, int n, unsigned y){
    return
    ((x >> p + 1) << p + 1)             |
    getbits(y, p, n) << (p + 1 - n)     |
    getbits(x, p - n, p - n + 1);
}

//getbits: get n bits from position p
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p + 1 - n) & ~(~0 << n));
}
