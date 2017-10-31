#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stiod.h> //for fgets()
int main()
{
	char word1[100];
	char word2[10];
	int choice;
	int i=0,j,index;
	FILE *co;						//for fetching chars
	//FILE *sr;
	const char EOL = "/0";
	printf("What file type you want to scan for analysis?\n1.C\n2.PHP");
	scanf("%d",&choice)
	if (choice == 1)
	{
		co = FILE fopen("code.c","r");  //code file
		if (co==NULL)
		{
			perror("Error opening file");
			return(-1);/* code */                            
		}
		sr = FILE fopen("source1.txt","r");//our file with keywords
		if (sr==NULL)
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
		sr = FILE fopen("source2.txt","r");//our file with keywords
		if (sr==NULL)
		{
			perror("Error opening file");
			return(-1);/* code */
		}
	}
	
	while(!feof(co))
	{
		i=0;
		while (ch!=" "|| ch!="("){
		ch=getc(co);
		word1[i]=ch;
			i++
		}
		
		
		if(word1 == "String" || word1 == "Query" || word1 == "1'='1" )
		{
			printf("\n");
			printf("Your file contains SQL injection vulnerability and may pose threat in later stages of testing, fex fixes can be done by implementing few fixes.");
		}
		else if(word1 == "gets()")		//sessionid exposed
		{
			printf("\nThis function is vulnerable to BufferOverflow error as in the input, if it recives the input as a pointer, then it couldn't estimate the size of it.\n")
		}
		else if(strstr(word1,"preg_replace ")==1)
		{
			printf("\n0");
		}
		else if(word1 == "sprintf()")
		{
			printf("\n");
		}
		else if( word1 == "strcpy()" || word1 == "strcpy" ) || word1 == "strcpy(")
		{
			printf("\nYour code might have some vulnerablities and this can better be heal;ed by replacing this function by strncpy().\n");
		}
		else if( word1 == "vsprintf()")
		{
			printf("\n");
		}
		else if( word1 == "strcpyA")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "strcpyW")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "StrCpyNA")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "StrCpyNW")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "StrNCpyA")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "StrNCpyW")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "StrNCpy")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "strcpynA")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "strcpyn")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
		else if( word1 == "strcpyn(")
		{
			printf("\nFunction appears in Microsoft's banned function list. Can facilitate buffer overflow conditions.");
		}
	}
}
