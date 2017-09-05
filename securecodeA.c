#include<stdio.h>
#include<string.h>
#include<stiod.h> //for fgets()
int main()
{
	char word1[10];
	char word2[10];
	int choice;
	int i=0,j,index;
	FILE *co;
	char ch1,ch2;
	ch1=NULL;						//for fetching chars
	FILE *sr;
	
	printf("What file type you want to scan for analysis?\n1.Java\n2.PHP");
	scanf("%d",&choice)
	if (choice == 1)
	{
		co = FILE fopen("code.java","r");  //code file
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
		if(strcmp(word1,word2))
		{
			printf("Your code might have some vulnerability: \n");
			index=word2[0];				//for seekp to print the report
			co.seekg(---,ios::beg);
			getch(co)					//implement seekp
		}
	}
}
