#define col 8

int 	getLine(char line[], int maxline);
void 	copy(char to[], char from[]);
int 	isRestrictedChar(int c);
int 	delRepeatedChars(char to[], char from[]);
void 	replaceTabStops(char to[], char from[]);


int delRepeatedChars(char to[], char from[]){
   int index, index2, c, prev;
   index2 = 0;
   prev = from[0];

   for (index = 0; from[index] != '\0'; index++){
      c = from[index];

      if (!(isRestrictedChar(c) && isRestrictedChar(prev)))
	 to[index2++] = c;
	 
      prev = c;
   }

   //if char array in composed by white spaces and tab
   if (index2 == 1 && isRestrictedChar(to[0]))
      return 0;
  
  //if last character is blank space
   if (isRestrictedChar(to[index2-1]))
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


int isRestrictedChar(int c){
   if(c == '\t' || c == ' ')
      return 1;
   else
      return 0;
}

void replaceTabStops(char to[], char from[]){
   int i,		//inde array from
   i2, 			//index array to
   aCol,		//count tab spaces
   j;			//iterate to complete space in tab stops
   
   //actual column start in 0
   aCol = i2 		= 0;

   for 	(i = 0; from[i] != '\0'; i++){			//global iteration
	if (from[i] == '\t'){				//if tab was found
		for (j = 0; j < col - aCol; j++)	//complete tab with spaces	   		
			to[i2++]	= ' ';

		aCol 			= col - 1;	//set aCol to final tab stop
      	}else{
	   	
		to[i2++]		= from[i];
	}

      aCol++;						//column space counter
      
      if (aCol == col)
	 aCol		 = 0;

   }
   to[i2]		= '\0';	

}

