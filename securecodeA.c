#include<stdio.h>
#include<string.h>
#include<stiod.h> //for fgets()
int main()
{
	char word1[10];
	char word2[10];
	int i=0,j,index;
	FILE *co;
	co = FILE fopen("code.txt","r");  //code file
	if (co==NULL)
	{
		perror("Error opening file");
		return(-1);/* code */
	}
	char ch1,ch2;
	ch1=NULL;						//for fetching chars
	FILE *sr;
	sr = FILE fopen("source.txt","r");//our file with keywords
	if (sr==NULL)
	{
		perror("Error opening file");
		return(-1);/* code */
	}while(!feof(co))
	{
		i=0;
		while(ch1!=" ")
		{
			word1[i]=getch(co);
			i++;
		}
		j=word[0];						//calculate ASCII value of the first alphabet and then start the search accordingly
		while(getch(ch2)=="%")			//how the keywords alphabet list will end
		{
			j=0;
			while(ch2!=" ")
			{
				word2[j]=getch(sr);		//implement dictionary search here
				j++;
			}
		}
		if(word1==word2)
		{
			printf("Your code might have some vulnerability: \n");
			index=word2[0];				//for seekp to print the report
			fseek( sr, index, SEEK_SET );
			getch(co)					//implement seekp
		}
	}
}
