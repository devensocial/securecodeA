#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>
//#include<stiod.h> //for fgets()

void failure(char* pattern, int* f);
int kmp(char* t, char* p);

int* init_array(int size) {
  int* arr = (int*)malloc(size * sizeof(int));
  int i;
  for(i = 0; i < size; i++) {
    arr[i] = 0;
  }

  return arr;
}

int match(char* text, char* pattern) {				//pattern is what to search and text is whole line.
  //char* pattern = "abacab";
  //char* text = "bbacbabcbabcbabbabcbabcbacbbbacbacbacbacbacbabacab";

  int match = kmp(text, pattern);

  //printf("Match at: %d\n", match);
  if (match>0)
  {
  	return 1;
  }
  else
  {
  	return 0;
  }
}

int kmp(char* t, char* p) {
  int m = strlen(p);
  int n = strlen(t);

  int* f = init_array(m); // Failure function values.
  int i = 0;
  int j = 0;

  while (i < n) {
    if (t[i] == p[j]) {
      if (j == m - 1) {
        return i - j;
      }
      else {
        i += 1;
        j += 1;
      }
    }
    else {
      if (j > 0) {
        j = f[j-1];
      }
      else {
        i += 1;
      }
    }
  }

  return -1;
}

void failure(char* p, int* f) {
  f[0] = 0;
  int i = 1;
  int j = 0;

  int m = strlen(p);

  while (i < m) {
    if (p[i] == p[j]) {
      f[i] = j + 1; // j+1 matches up to the current character.
      i += 1;
      j += 1;
    }
    else if (j > 0) {
      j = f[j - 1];
    }
    else {
      f[i] = 0;
      i += 1;
    }
  }
}

int main()
{
	printf("\nSeCode is an automated code security review tool that handles C and PHP. It has a few features that should hopefully \nmake it useful to anyone conducting code security reviews, particularly where time is at a premium:");
	printf("\n\n\t\t\t\tNOTE\n\n1. Please note that your code file should either be saved in .PHP or .C type.");
	printf("\n2. Your code file should be saved in same directory as this code file.");
	printf("\n3. Your code file should be named as code.c or code.php.");
	printf("\n4. This file will scan for 15 vulnerabilities that are compiled from various sources.\n\n");
	char* str[255];
	char ch;
	int choice;
	int i=0,j,index;
	FILE *co;						//for fetching chars
	//FILE *sr;
	const char EOL = "/0";
	printf("What file type you want to scan for analysis?\n1.C\n2.PHP\n");
	scanf("%d",&choice);
	if (choice == 1)
	{
		co = fopen("code.c","r");  //code file
		if (co == NULL)
		{
			perror("Error opening file");
			return(-1);/* code */                            
		}
	}
	else
	{
		co = fopen("code.php","r");  //code file
		if (co == NULL)
		{
			perror("Error opening file");
			return(-1);/* code */
		}
	}
   
	
	while(!feof(co))
	{
		if( fgets (str, 255, co)!=NULL ) {
      /* writing content to stdout */
      //puts(str);
   	
		
		
		//if(word1 == "String" || word1 == "Query" || word1 == "1'='1" )
		//{
		//	printf("\n");
		//	printf("Your file contains SQL injection vulnerability and may pose threat in later stages of testing, fex fixes can be done by implementing few fixes.");
		//}
		if(match(str,"gets()")==1)		//sessionid exposed
		{
			printf("\ngets() is vulnerable to BufferOverflow error as in the input, if it recives the input as a pointer, then it couldn't estimate the size of it.\n");
		}
		else if(match(str,"preg_replace")==1)
		{
			printf("\n0");
		}
		else if(match(str,"sprintf()")==1)
		{
			printf("\n");
		}
		else if(match(str,"strcpy()")==1 || match(str,"strcpy")==1 || match(str,"strcpy(")==1)
		{
			printf("\nYour code might have some vulnerablities and this can better be heal;ed by replacing this function by strncpy().\n");
		}
		else if(match(str,"vsprintf()")==1)
		{
			printf("\n");
		}
		else if(match(str,"strcpyA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"strcpyW")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"StrCpyNA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"StrCpyNW")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"StrNCpyA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"StrNCpyW")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"StrNCpy")==1)
		{
			printf("\nStrNCpyFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"strcpynA")==1)
		{
			printf("\nstrcpynA appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"strcpyn")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if(match(str,"strcpyn(")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
	}
}
}
