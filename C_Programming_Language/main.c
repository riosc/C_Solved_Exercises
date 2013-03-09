//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
int bitcount(unsigned x);

int main(){
    
    int x = 511;
    
    printf("num bits:%d", bitcount(x));
    return 0;
}

int bitcount(unsigned x){
    int b;
    
    for (b = 0; x != 0; x &= (x - 1))
            b++;

    return b;
}
