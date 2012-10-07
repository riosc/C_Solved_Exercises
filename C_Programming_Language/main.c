//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

int main(){
    int c, bs = 0, t = 0, nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++bs;
        else if (c == '\t')
            ++t;
        else if (c == '\n')
            ++nl;
        //putchar(c);
        printf("%c __ bs: %d t: %d nl: %d\n", c, bs, t, nl);
    }
    
}
