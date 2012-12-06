//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
#include "source.h"
#define MAXLINE 1000

int main(){
   int len, max;
   char line[MAXLINE];
   char temp[MAXLINE];
   char tabSpaces[MAXLINE];

   while((len = getLine(line, MAXLINE)) > 0){
	 copy(temp, line);
	 //delRepeatedChars(trimLine, temp);
	 replaceTabStops(tabSpaces, temp);
	 printf("%s", tabSpaces);
   }

   return 0;
}

