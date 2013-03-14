//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
#define MAXLINE 1000

void unescape(char s[], char t[]);
void escape(char s[], char t[]);

int main()
{
    char t[]  = "cadena\n \tde";
    char s[MAXLINE];
    unescape(s, t);
    escape(s, t);
    
    printf("Text1:  %s\n", s);
    printf("Text2:  %s\n", t);

    return 0;
}

//converts visibles characters like new line. tab in real characters
void unescape(char s[], char t[]){
    int i, j = 0;
    
    for (i = 0; t[i] != '\0'; i++)
    {
        switch (t[i]) {
            case '\n':
                s[j++]  = '\\';s[j++] = 'n';
                break;
            case '\t':
                s[j++]  = '\\';s[j++] = 't';
                break;
            case '\b':
                s[j++]  = '\\';s[j++] = 'b';
                break;
            default:
                s[j++]    = t[i];
                break;
        }
    }
    
    s[j] = '\0';
    
}

//converts characters like new line, tab in visibles characters
void escape(char s[], char t[]){
    
    int i, j = 0;
    
    for (i = 0; t[i] != '\0'; i++)
    {
        if (t[i] == '\\')
        {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case 'b':
                    s[j++] = '\b';
                    break;
                    
                default:
                    i--;
                    s[j++] = t[i];
                    break;
            }
            
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

