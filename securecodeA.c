#include<stdio.h>
#include<string.h>
#include<stiod.h> //for fgets()
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
	printf("What file type you want to scan for analysis?\n1.Java\n2.PHP");
	scanf("%d",&choice)
	if (choice == 1)
	{
		co = FILE fopen("code.java","r",stdin);  //code file
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
		co = FILE fopen("code.php","r",stdin);  //code file
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
		word1[] = co.getline(&buffer,&bufsize,stdin);
		if(word1 == "String query = "SELECT * FROM accounts WHERE custID='" + request.getParameter("id") + "'";" || word1 == "Query HQLQuery = session.createQuery("FROM accounts WHERE custID='" + request.getParameter("id") + "'");" || word1 == "http://example.com/app/accountView?id=' or '1'='1" )
		{
			printf("Your file contains SQL injection vulnerability and may pose threat in later stages of testing, fex fixes can be done by implementing few fixes.");
		}
		else if(word1 == "sessionid=")		//sessionid exposed
		{
			printf("You session has been leaked please check for this and this might cause probl;em later in coding.")
		}
		else if(word1 == "")
	}
}
