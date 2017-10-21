#include<stdio.h>
#include<string.h>
#include<stiod.h> //for fgets()
int substring(char a[100], char b["p","r","e","g","_","r","e","p","l","a","c","e"])
{
	char ss[20];
	ss = strstr(a,b);
	return strcmp(b,ss);
}
int main()
{
	char word1[100];
	char word2[10];
	int choice;
	int i=0,j,index;
	FILE *co;
	char ch1,ch2;
	ch1=NULL;						//for fetching chars
	FILE *sr;
	const char EOL = "//0";
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	buffer = (char *)malloc(bufsize * sizeof(char));		//dynamic allocation of char for getline
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
		word1[] = co.sgets(&buffer,&bufsize);
		if(word1 == "String" || word1 == "Query" || word1 == "1'='1" )
		{
			printf("\n");
			printf("Your file contains SQL injection vulnerability and may pose threat in later stages of testing, fex fixes can be done by implementing few fixes.");
		}
		else if(word1 == "gets()")		//sessionid exposed
		{
			printf("\nThis function is vulnerable to BufferOverflow error as in the input, if it recives the input as a pointer, then it couldn't estimate the size of it.\n")
		}
		else if(substring(word1,"preg_replace")==1)
		{
			printf("\n0");
		}
		else if(word1 == "sprintf()")
		{
			printf("\n");
		}
		else if( word1 == "strcpy()")
		{
			printf("\nYour code might have some vulnerablities and this can better be heal;ed by replacing this function by strncpy().\n");
		}
		else if( word1 == "vsprintf()")
		{
			printf("\n");
		}
		else if( word1 == "")
	}
	while(fscanf(co,"%s",a )
	{
		word1 = co.fgets()
		{	
		}
	}

}
