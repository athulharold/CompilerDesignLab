#include<stdio.h>
struct nfa
{
	char inp;
	int i,j[10],start,final,count; //count keeps the count of transition from a state for the same input
	
};
struct dfa
{
	int i[10],j[10],start,final;
	char inp; 
};

void main()
{
 struct nfa a[100];
 struct dfa b[100];
 int i=0,k,n,j,temp;
 printf("\nEnter the elements of the NFA: ");
 printf("\nPress -1 for current element to exit: \n");
 //inputting the NFA
 do{

	printf("\nInitial state::");
	scanf("%d",&temp);	
	if(temp!=-1)
		a[i].i=temp;
	else
		break;
	printf("Is it the starting state?(0/1): ");
	scanf("\n%d",&(a[i].start));
	printf("Is it the final state?(0/1): ");
	scanf("\n%d",&(a[i].final)); 
	printf("Input: ");
	scanf("\n%c",&(a[i].inp));
	k=0;
	do
		{
			printf("\nEnter all the transitions for the given state and input\nPress -1 to exit: ");
			printf("\nTransitioned state: ");
			scanf("%d",&(a[i].j[k]));
			if(a[i].j[k]==-1)
				break;
			k++;
		}while(1);
	k--;
	a[i].count=k;
	i++;
  }while(1);
  n=i;
  //printing the NFA
  for(i=0;i<n;i++)
  {
  	printf("\nF(%d,%c) = ",a[i].i,a[i].inp);
  	for(j=0;j<=a[i].count;j++)
		printf("%d  ",a[i].j[j]);
 }
  //converting
  i=0;
  temp=a[0].i;
  do
  {
  	if(a[i].i!=temp)
  		break;
 	b[i].i[0]=a[i].i;
  	b[i].inp=a[i].inp;
  	for(j=0;j<=a[i].count;j++)
  		b[i].j[j]=a[i].j[j];
  	i++;
  }while(1);
  i--;
  printf("\n%d",i);
  //sample printing
  for(temp=0;temp<=i;temp++)
  {
 
  	printf("\nF(%d,%c)= %d",b[temp].i[0],b[temp].inp,b[temp].j[temp]);
  }
  
 


}
 
