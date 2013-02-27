//
//  main.c
//  C_Programming_Language
//
//  Created by Carlos Rios on 10/7/12.
//  Copyright (c) 2012 Ideaware Co. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int main(){
    
    //example 1
    enum months{
        ENE = 1,
        FEB,
        MAR,
        ABR,
        MAY,
        JUN,
        JUL,
        AGO,
        SEP,
        OCT,
        NOV,
        DEC
    };
    enum months mes;
    mes = JUL;
    
    /*MORE EXAMPLES
     ==============
     http://crasseux.com/books/ctutorial/enum.html
     
     */
    return 0;
}

