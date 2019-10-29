#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char stack[100];  //stack  for performing the parsing
void push(char item)
{
	if(top==100){
		printf("\nOverflow");
		exit(0);}
	top++;
	stack[top]=item;
}
void pop()
{
	if(top==-1){
		printf("\nUnderflow");
		exit(0);
		}
	top--;
}

void sparse(char production[10][10],char str[100],int n)  //parsing function
{
	int i,temp,j,l,k,m; //length stores the length of the string to parse
	char s,tempopro[10],tempo[10]; //temporary string to store the RHS of the productions and stack elements
	printf("\nEnter the start symbol :");
	scanf("%c",&s);
	//printf("\nTest: %d",strlen(str));
	for(i=0;i<strlen(str);i++) //traverses each element of the input string
	{
		 printf("\n%d",strlen(str));
		 push(str[i]);
		 printf("\nTest");
		 for(j=0;j<n;j++) //traverses each production
		 {
		 	strcpy(tempo," ");
		 	tempo[0]=stack[top];
		 	strcpy(tempopro," ");
		 	temp=top;
		 	l=strlen(production[j]);
		 	printf("\nTest: %d",l);
		 	for(k=3;k<l;k++)  
		 		{strncat(tempopro,production[j][k],1);}  //storing the RHS of the productions to tempopro
		 	printf("\n%s",tempopro);
		label: 	if(strcmp(tempo,tempopro)==0)
		 	{
		 		for(m=0;m<strlen(tempo);m++) 
		 			pop();
		 		push(production[j][0]);		
		 	}
		 	else
		 	{
		 		if(temp==0)
		 			{continue;
		 			} 
		 			
		 		else{
		 			temp--;
		 			strncat(tempo,stack[temp],1);	
		 			goto label;	}
		 	}	
		 	
		 }
		 
	}
	if(stack[top]==s && top==0)
		printf("\nParsed Succesfully");
	else
		printf("\nThe string doesn't belong to the given grammar");

}
void main()
{
	int n,i;
	char str[100],production[10][10];
	printf("\nEnter the number of productions: ");
	scanf("%d",&n);
	printf("\nEnter the production: ");
	for(i=0;i<n;i++)
		scanf("%s",production[i]);
	printf("\nThe productions entered are: ");
	for(i=0;i<n;i++)
	 	printf("\n%s",production[i]);
	printf("\nEnter the string to parse: ");
	scanf("%s",str);
	//printf("\n%s",str);
	sparse(production,str,n);
	
}

