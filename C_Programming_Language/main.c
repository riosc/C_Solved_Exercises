//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
int lower(int c);
int isLetter(int c);
int isDigit(int c);
int isResDig(int c);
int htoi(char h[]);

int main(){
    
    int test = 0xff24;
    char hnum[] = "ff24";
    
    printf("%d -- %d", test, htoi(hnum));
    
    return 0;
}
int htoi(char h[]){
    int n = 0, i, start = 0;
    
    if (h[0] == '0' && lower(h[1]) == 'x')
        start = 2;
    
    for (i = start; isDigit(h[i]) || isLetter(h[i]); i++) {
        int vd = isDigit(h[i]) ? h[i] - '0' : lower(h[i]) - 'a' + 10;
        n = 16 * n + vd;
    }
    
    return n;
}

int isResDig(int c){
    return (lower(c) == 'x');
}

int isDigit(int c){
    return (c >= '0' && c <= '9');
}

int isLetter(int c){
    
    int lc = lower(c);
    return (lc >= 'a' && lc<= 'f');
}

int lower(int c){
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

