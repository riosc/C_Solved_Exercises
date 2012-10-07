//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>

#define IN   1
#define OUT   0

int main(){
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        //++nc;
        //if (c == '\n')
        //    ++nl;
        if (c == ' ' || c == '\n' || c== '\t'){
            if (state == IN) {
                state = OUT;
                printf("\n");
            }
        }
        else if (state == OUT){
            state = IN;
            ++nw;
        }
        //printf("%d %d %d\n", nl, nw, nc);
        
    }
    
}

