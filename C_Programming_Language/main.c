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
unsigned invert(unsigned x, int p, int n);

int main(){
    
    int x = 827;
    
    printf("val: %d", invert(x, 4, 5));
    return 0;
}

//invert: invert n bit in x from p position
unsigned invert(unsigned x, int p, int n){
    return setbits(x, p, n, getbits(~x, p, n));
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
