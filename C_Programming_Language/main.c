//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
   int len, max;
   char line[MAXLINE];
   char longest[MAXLINE];

   max = 0;
   while((len = getLine(line, MAXLINE)) > 0){
      if (len > 80){
     	 printf("Current Lines Is:%s With Lenght:%d", line, len);
      }

      /*if (len > max){
	 max = len;
	 copy(longest, line);
       }
       if (max > 0)
	  printf("Longest Line: %s", longest);
	*/

   }

   return 0;
}

int getLine(char s[], int lim){
   int c, i;

   for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
      s[i] = c;
   }
   if (c == '\n'){
      s[i] = c;
      ++i;
   }
   s[i] = '\0';

   return i;

}

void copy(char to[], char from[]){
   int i;
   i = 0;

   while (to[i] = from[i] != '\n')
      ++i;
}

