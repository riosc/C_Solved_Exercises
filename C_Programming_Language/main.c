//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
void squeeze(char s[], char c[]);

int main(){
    
    char name[] = "mi nombre es carlos rios";
    char cdel[] = "ai";
    
    squeeze(name, cdel);
    
    printf("%s", name);
    
    return 0;
}

void squeeze(char s[], char c[]){
    int i, j, k, fnd;
    
    for (i = k = 0; s[i] != '\0'; i++){
        for (j = fnd = 0; c[j] != '\0' && !fnd; j++){
            if (s[i] == c[j]){
                fnd++;
            }
        }
        if (!fnd)
            s[k++] = s[i];
    }
    s[k] = '\0';
    
}

