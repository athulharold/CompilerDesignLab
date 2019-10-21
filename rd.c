
#include<stdio.h>
#include<ctype.h>
#include<string.h>
 
void Tdash();
void Edash();
void E();
void F(); 
void T();
 
 
char expression[10];
int count, error;
char production[3][20]={"E->E+T|T","T->T*F|F","F->(E)|id"};
char newproduction[10][60];
char alpha[20],beta[20],temp[40],a1,a2,a3;
int main()
{     
	count = 0;
	error = 0;
	int i,j,index,k2,k3,k1=0; 
	
        printf("The grammer is: \n");
        for(i=0;i<3;i++)
	{
         printf("%s\n",production[i]);
	}

	//REMOVING LEFT RECURSION
	for(i=0;i<3;i++)
	{k2=0,k3=0;
	 a1=production[i][0];
	 a2=production[i][3];
	 if(a1==a2)
	    {
	        for(j=0;j<strlen(production[i]);j++)
		{a3=production[i][j];
			if(a3=='|')
				break;
		}
		index=j;
	
		for(j=4;j<index;j++)
		{
			alpha[k2++]=production[i][j];
		}
		 for(j=index+1;j<strlen(production[i]);j++)
		{
			beta[k3++]=production[i][j];
		}
          
   		k1++;
		temp[0]=production[i][0];
		strcat(newproduction[k1],temp);
		strcat(newproduction[k1],"->");
		strcat(newproduction[k1],beta);
		
		strcat(newproduction[k1],temp);
		strcat(newproduction[k1],"'");
		k1++;
		strcat(newproduction[k1],temp);
		strcat(newproduction[k1],"'->");
		strcat(newproduction[k1],alpha);
		strcat(newproduction[k1],temp);
		strcat(newproduction[k1],"'");
		strcat(newproduction[k1],"|e");
			      
	    } 
 	 else
		{
	    	strcat(newproduction[k1++],production[i]);
		}
  	}
	printf("k1= %d\n",k1);
	printf("After removing left recurssion\n");
	for(i=0;i<k1;i++)
	 printf("%s\n",newproduction[i]);
	
	printf("\nInput an expression:\t");
        scanf("%s", expression);
        E();
        if((strlen(expression) == count) && (error == 0))
        {
            printf("\nThe expressionession %s is Valid\n", expression);
        }
        else 
        {
            printf("\nThe expressionession %s is Invalid\n", expression);
        }
	return 0;
}
       
void E()
{
	T();
	Edash();
}
 
void T()
{
	F();
	Tdash();
}
 
void Tdash()
{
	if(expression[count] == '*')
        {
            count++;
            F();
            Tdash();
        }
}
 
void F()
{
        if(isalnum(expression[count]))
        {
            count++;
        }
        else if(expression[count] == '(')
        {
            count++;
            E();
            if(expression[count] == ')')
            {
                  count++;
            }
            else
            {
                  error = 1; 
            }
        }         
        else
        {
            error = 1;
        }
}
 
void Edash()
{
        if(expression[count] == '+')
        {
            count++;
            T();
            Edash();
        }
}
