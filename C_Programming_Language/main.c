//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
int any(char s1[], char s2[]);

int main(){
    
    char s1[] = "carlos david rios vertel";
    char s2[] = "xz";
    
    printf("pos: %d", any(s1, s2));
    return 0;
}

int any(char s1[], char s2[]){

    int i, j;
    
    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    
    return -1;
}
