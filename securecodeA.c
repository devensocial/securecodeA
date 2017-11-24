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

int match() {
  char* pattern = "abacab";					//input req string here
  char* text = "bbacbabcbabcbabbabcbabcbacbbbacbacbacbacbacbabacab";	//getline comes here

  int match = kmp(text, pattern);

  printf("Match at: %d\n", match);

  return 0;
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
	char word1[255];
	char word2[10];
	char ch;
	int choice;
	int i=0,j,index;
	FILE *co;						//for fetching chars
	//FILE *sr;
	const char EOL = "/0";
	printf("What file type you want to scan for analysis?\n1.C\n2.PHP");
	scanf("%d",&choice);
	if (choice == 1)
	{
		co = FILE fopen("code.c","r");  //code file
		if (co==NULL)
		{
			perror("Error opening file");
			return(-1);/* code */                            
		}
	}
	else
	{
		co = FILE fopen("code.php","r");  //code file
		if (co==NULL)
		{
			perror("Error opening file");
			return(-1);/* code */
		}
	}
	FILE *fp;
   char str[60];

   /* opening file for reading */
   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
      puts(str);
   }
	
	while(!feof(co))
	{
		i=0;
		while (ch!=" "|| ch!="("){
		ch=getc(co);
		word1[i]=ch;
			i++;
		}
		
		
		if(word1 == "String" || word1 == "Query" || word1 == "1'='1" )
		{
			printf("\n");
			printf("Your file contains SQL injection vulnerability and may pose threat in later stages of testing, fex fixes can be done by implementing few fixes.");
		}
		else if(strcmp(word1,"gets()")==1)		//sessionid exposed
		{
			printf("\nThis function is vulnerable to BufferOverflow error as in the input, if it recives the input as a pointer, then it couldn't estimate the size of it.\n");
		}
		else if(strstr(word1,"preg_replace ")==1)
		{
			printf("\n0");
		}
		else if(strcmp(word1,"sprintf()")==1)
		{
			printf("\n");
		}
		else if( strcmp(word1,"strcpy()")==1 || strcmp(word1,"strcpy")==1 || strcmp(word1,"strcpy(")==1)
		{
			printf("\nYour code might have some vulnerablities and this can better be heal;ed by replacing this function by strncpy().\n");
		}
		else if( strcmp(word1,"vsprintf()")==1)
		{
			printf("\n");
		}
		else if( strcmp(word1,"strcpyA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"strcpyW")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"StrCpyNA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"StrCpyNW")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"StrNCpyA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"StrNCpyW")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"StrNCpy")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"strcpynA")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"strcpyn")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( strcmp(word1,"strcpyn(")==1)
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
	}
}
