//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);

int main(){
    
    int n = 987;
    printf("val: %d", getbits(n, 4, 3));
    
    return 0;
}

//getbits: get n bits from position p
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p + 1 - n) & ~(~0 << n));
}
