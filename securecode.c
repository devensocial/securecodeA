#include<stdio.h>
#include<string.h>
#include<stiod.h> //for fgets()
int main()
{
	char word1[10];
	char word2[10];
	int i=0,j;
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
		j=0;
		while(getch(ch2)=="%")
		{
			while(ch2!=" ")
			{
				word2[j]=getch(sr);
				j++;
			}
		}
	}
}
