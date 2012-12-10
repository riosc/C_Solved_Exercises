#define TABSIZE   8
#define WCOL      127
#define IN        1                    //inside a word
#define OUT       0                    //outside out of a word


int 	getLine             (char line[], int maxline);
void 	copy                (char to[], char from[]);
int 	isBlankSpace        (int c);
int 	delRepeatedChars    (char to[], char from[]);
void 	detab               (char to[], char from[]);
void    entab               (char to[], char from[]);

int delRepeatedChars(char to[], char from[]){
   int index, index2, c, prev;
   index2 = 0;
   prev = from[0];

   for (index = 0; from[index] != '\0'; index++){
      c = from[index];

      if (!(isBlankSpace(c) && isBlankSpace(prev)))
	 to[index2++] = c;
	 
      prev = c;
   }

   //if char array in composed by white spaces and tab
   if (index2 == 1 && isBlankSpace(to[0]))
      return 0;
  
  //if last character is blank space
   if (isBlankSpace(to[index2-1]))
      index2--;

   to[index2] = '\0';

   return 1;
	
}

int getLine(char s[], int lim){
   int c, i;

   for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;
   
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


int isBlankSpace(int c){
   if(c == '\t' || c == ' ')
      return 1;
   else
      return 0;
}

void detab(char to[], char from[]){
   int i,		 //inde array from
   i2, 			 //index array to
   aCol,		    //count tab spaces
   j;			    //iterate to complete space in tab stops
   
   //actual column start in 0
   aCol = i2 		= 0;

   for 	(i = 0; from[i] != '\0'; i++){			//global iteration
   	if (from[i] == '\t'){				         //if tab was found
   		for (j = 0; j < TABSIZE - aCol; j++)	      //complete tab with spaces	   		
   			to[i2++]	= ' ';
         
   		aCol 			= TABSIZE - 1;	               //set aCol to final tab stop
      }else{
   	   	
   		to[i2++]		= from[i];
	  }

      aCol++;						                 //column space counter
      
      if (aCol == TABSIZE)                         //if complete a tab stop, reset column counter
	     aCol		 = 0;
   }

   to[i2]		= '\0';	                       //final char array mark
}

void entab(char to[], char from[]){
   int i,                                      //index from array
      i2                   = 0,                //index to array
      aCol                 = 0,                //count tab stop column
      spacesCounter        = 0;                //count consecutive blank spaces

   for (i = 0; from[i] != '\0'; i++){          //iteration on from array
      
      if    (from[i] == ' ')                   //if current char is a blank space add +1 spaceCounter
            spacesCounter++;    
      else  spacesCounter  = 0;

      to[i2++]             = from[i];


      if (++aCol == TABSIZE){                   // if complete tab stop then verify is posible replace blanck spaces by tab
         if (spacesCounter > 1){
            i2             = i2 - spacesCounter;
            to[i2++]       = '\t';
            spacesCounter  = 0;
         }
         aCol              = 0;
      }
   }

   to[i2]                  = '\0';
}

void foldLine(char s[]){

   int i,                                             //index s array
      i2                      = 0,                    //index fl array
      lstTravWrd              = 0,                    //save position of last word traversed by the iteration
      eol                     = 0;                    //save pos of end of line of fl array

   int state                 = OUT;                   //state start out of a word
   char fl[WCOL + 1];                                 //short line array, +1 elem to save end line char for printing

   for (i = 0; s[i] != '\0'; ++i){

      if    (!(isBlankSpace(s[i]))){                   //change state where current char is inside or outside a word
            state                   = IN; 

      }else if(state == IN){                          //find a blank space so change the state to OUT outside a word
            state                   = OUT;
            lstTravWrd              = i;              //save index of last traversed word in s array
            eol                     = i2;             //save index of last traversed word in fl array
      }

      if    (i2 == WCOL){                             // a wrap line is complete, so restabish indexes to last seen word
            fl[eol]                 = '\0';           //put end of line in last traversed word
            i2                      = 0;              //reset new line index
            i                       = lstTravWrd - 1; //localize i in last traversed word of s array
            printf("%s\n", fl);

      }else if (!(isBlankSpace(s[i]) && i2 == 0) ){   //prevent save blanck spaces at begining of new wrap line
            fl[i2++]                = s[i];
      }
   }
   fl[i2]                     = '\0';

   printf("%s\n", fl);
}






