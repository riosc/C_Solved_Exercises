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
    int c, antChar = -1;
    while ((c = getchar()) != EOF) {
        if (!(antChar == ' ' && c == ' '))
            putchar(c);
        
        antChar = c;
    }
    
}
