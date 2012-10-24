//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
#define MAXLINE 1000
#define BLANK_LINE 1
#define NOBLANK_LINE 0

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int isCharNotRepeated(int c);

int main(){
   int len, max;
   char line[MAXLINE];
   char temp[MAXLINE];

   while((len = getLine(line, MAXLINE)) > 0){
	 copy(temp, line);
	 printf("line: %s \n", temp);
   }

   return 0;
}

int getLine(char s[], int lim){
   int c, i, prev;
   prev = -1;

   for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
      if (!(isCharNotRepeated(c) && isCharNotRepeated(prev)))
	 s[i] = c;
      else
	 i--;

      prev = c;
   }

   //if char array in composed by white spaces and tab
   if (i == 1 && isCharNotRepeated(s[0]))
      return -1;
   
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

   while ((to[i] = from[i]) != '\0')
      ++i;
}

int isCharNotRepeated(int c){
   if(c == '\t' || c == ' ')
      return 1;
   else
      return 0;
}


