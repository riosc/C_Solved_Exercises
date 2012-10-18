//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>

int main(){
   int fahr;
   for (fahr = 0; fahr <= 300; fahr = fahr + 20){
      printf("%3d\t%6d\n", fahr, fahrToCelcius(fahr));
   }
}

int fahrToCelcius(int fahr){
   int celcius = 0;
   celcius = 5 * (fahr - 32)/9;

   return celcius;
}
