//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
#define MAXLINE 1000

int main(){
    int len, max;
    char line[MAXLINE];
    
    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        printf("%d", len);
    }
    
    return 0;
}

int getLine(char s[], int lim){
    int c, i;
    
//    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){

    for (i = 0; i < lim-1 ; ++i){
        if ((c = getchar()) != EOF)
            if (c != '\n')
                s[i] = c;
            else
                break;
        else
            break;
    }
    
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
    
}
