#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define plakidio 5

void emfanish_pinaka(int n,int m,int level,int **a,int score);  /*synarthsh gia emfanish tou pinaka*/
int hammer(int **a, int i, int j,int r,int pl,int m,int n);    /*syanrthsh gia thn ektelesh tou sfyriou*/
void gravity(int **a,int m,int n);							  /*synarthsh gia ta mode bomb,add kai hammer oste an kato apo ena plakidio */
															 /*yparxei keno,to plakidio peftei mexri na synanthsei kapoio allo*/		
int main(void)
{
int **a; 	   		    //o dynamikos disdiastatos pinakas opou tha briskontai apothikeumena ta xromata
int i,j,p;	  		    //metrhtes
int ch;					//o arithmos ton xromaton
int n,m;   				//gia th dynamikh diaxeirhsh tou pinaka
int level; 				//H pista,jekinontas apo to 0 
int score = 0;  		//Oi pontoi tou paikth jekinontas apo 0
int k,l; 	  	   	    //oi suntetagmenes gia to mode bomb
int fl;  				//ena flag pou xrhsimopoieitai gia to mode bomb oste na doume an oi suntetagmenes you xrhsth einai entos h ektos pinaka
int temp,temp2,temp3; 	//antimetathesi timon
int flag;				//ena flag to opoio elegxei ton pinaka a kai an periexei mono 0,tote termatizei h pista
int flag2;				//ena flag pou to xrhsimopoioume sto mode push gia na doume an uparxei kapoia kenh sthlh ston pinaka
int *f; 				//enas dynamikos monodiastatos pinakas isos me to megethos ton stilon pou xrhsimopoieitai gia na doume poies stiles exoun mono mhdenika stoixeia 
int C; 					//sto mode add einai to xroma pou dinei o xrhsths
int h1,h2,r,pl=0;	    //metablhtes gia to mode hammer
int pol;				//suntelesths gia aujhsh tou score analoga th pista
int pl2=0;				//oi pistes pou epeje o xrhsths
int pl3;				//xrhsimopoieitai sto mode add gia na doume an o pinakas einai gematos apo plakidia
double d;				//gia th paragogh tyxaion arithmon
char mv[100]; 			//h kinhsh tou xrhsth 



srand((int) time(NULL));
printf("Welcome to !!DEMOLITION MAN!!\n");
printf("Give the initial dimesnions,according to the following rules:\n");
printf("(1)Minimum dimensions:4x4\n");
printf("(2)Maximum dimensions:10x10\n");
printf("(3)The initial dimensions must have the same size\n");
printf("(4)Use 'Space' between your values\n");
do
{
	scanf("%d",&m);  /*sthlh*/
	scanf("%d",&n);  /*grammh*/
	if((m!=n) || ((m<4 || n<4) || (m>10 || n>10))) 
	{
		if(m!=n)
			printf("The dimensions must have the same size\n");
		if(m<4 || n<4)
			printf("Out of Minimum dimensions\n");
		if(m>10 || n>10)
			printf("Out of Maximum dimensions\n");
		printf("Try again!!!\n");
	}
}while ((m!=n) || ((m<4 || n<4) || (m>10 || n>10)));
m=m-1;
n=n-1;
level = 0;
for(i=4;i<=n;i++)
	level++;
printf("Give the number of the colours [1,9]\n");
do
{
	scanf("%d",&ch);
	if((ch < 1) || (ch > 9))
		printf("Try again!!!\n");
}while((ch < 1) || (ch > 9));

while((m * n) < 100)
{
	level = level+1;
	n = n + 1;
	m = m + 1;
	f = (int *)malloc (m* sizeof (int));
	a = (int **)malloc (n* sizeof(int*));
	for(i=0;i<n;i++)
	{
		a[i] = (int*) malloc ( m* sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			d =(double) rand() /((double)RAND_MAX + 1);
			d = d * ch + 1;
			a[i][j] = (int) d;
		}
	}
	emfanish_pinaka(n,m,level,a,score);
	while(flag != (m*n))
	{
		flag = 0;
		printf("\nMake your move:\n");
		scanf("%s",mv);
		if((mv[0] == 'b') || (mv[0] == 'B'))
		{
			fl = 0;
			scanf("%d,%d",&k,&l);/*k grammh kai l sthlh */
			if((k>n) || (l>m) || (k<=0) || (l<=0))
			{
				printf("You are out of the table!\n");
				fl++;
			}
			if(fl == 0)
			{
				k=k-1;
				l=l-1;
				while(a[k][l] == 0)
				{
					printf("It is empty,so you can't place a bomb there\n");
					do
					{
						printf("Give new coordinates:\n");
						scanf("%d,%d",&k,&l);
					}while((k>n) || (l>m) || (k<=0) || (l<=0));
					k=k-1;
					l=l-1;
				}
				a[k][l] = 0;
				score = score + plakidio;
				if((k+1) < m)
				{
					score = score + plakidio;
					a[k+1][l] = 0;
				}
				if((k-1) >=0)
				{
					score = score + plakidio;
					a[k-1][l] = 0;
				}
				if((l+1) < n)
				{
					score = score + plakidio;
					a[k][l+1] = 0;
				}
				if((l-1) >=0)
				{
					score = score + plakidio;
					a[k][l-1] = 0;
				}
				if(((l-1) >= 0) && ((k-1) >=0))
				{
					score = score + plakidio;
					a[k-1][l-1] = 0;
				}
				if(((l+1) < n) && ((k+1) < m))
				{
					score = score + plakidio;
					a[k+1][l+1] = 0;
				}
				if(((l+1) < n) && ((k-1) >= 0))
				{
					score = score + plakidio;
					a[k-1][l+1] = 0;
				}
				if(((l-1) >= 0) && ((k+1) < m))
				{
					score = score + plakidio;
					a[k+1][l-1] = 0;
				}
				gravity(a,m,n);
				emfanish_pinaka(n,m,level,a,score);
			}
		}
		else if(mv[0] == 'p')
		{
			for(i=0;i<m;i++)
			{
				f[i] = 0;
			}
			flag2=0;
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[j][i] == 0)
					{
						f[i]++;
					}
				}
				if(f[i] == n)
					flag2=1;
			}	
			if(flag2 == 0)
			{
				printf("There are not empty columns in the table\n");
			}	
			else
			{
				if(mv[1] == 'r')
				{
					for(i=m-1;i>=0;i--)
					{
						if(f[i] == n)
						{
							for(j=i;j>=0;j--)
							{
								if(f[j] < n)
								{
									for(p=0;p<n;p++)
									{
										temp2=a[p][i];
										a[p][i] = a[p][j];
										a[p][j] = temp2;
									}
									temp3 = f[i];
									f[i] = f[j];
									f[j] = temp3;
									break;
								}
							}
						}
					}
				}
				else if(mv[1] == 'l')
				{
					for(i=0;i<=m-1;i++)
					{
						if(f[i] == n)
						{
							for(j=i;j<=m-1;j++)
							{
								if(f[j] < n)
								{
									for(p=0;p<n;p++)
									{
										temp2=a[p][i];
										a[p][i] = a[p][j];
										a[p][j] = temp2;
									}
									temp3 = f[i];
									f[i] = f[j];
									f[j] = temp3;
									break;
								}
							}
						}
					}	
				}
				emfanish_pinaka(n,m,level,a,score);
			}			
		}
		else if((mv[0]=='h') || (mv[0] == 'H'))
		{
			fl=0;
			scanf("%d,%d",&h1,&h2);
			if((h1>n) || (h2>m) || (h1<=0) || (h2<=0))
			{
				printf("You are out of the table!\n");
				fl++;
			}
			if(fl == 0)
			{
				h1=h1-1;
				h2=h2-1;
				while(a[h1][h2] == 0)
				{
					printf("It is empty,so you can not use hammer there\n");
					do
					{
						printf("Give new coordinates:\n");
						scanf("%d,%d",&h1,&h2);
						if((h1>n) || (h2>m) || (h1<=0) || (h2<=0))
						{
							printf("You are out of the table!\n");
						}
					}while((h1>n) || (h2>m) || (h1<=0) || (h2<=0));
					h1=h1-1;
					h2=h2-1;
				}
				r=a[h1][h2];
				m--;
				n--;
				hammer(a,h1,h2,r,pl,m,n);
				pol = level + 3;
				for(i=0;i<=n;i++)
				{
					for(j=0;j<=n;j++)
					{
						if(a[i][j] == 11)
						{
							a[i][j] = 0;
							score = score + pol + plakidio;
							pol = pol + level;
						}
					}
				}
				m++;
				n++;
				gravity(a,m,n);
				emfanish_pinaka(n,m,level,a,score);
			}
		}
		else if((mv[0] == 'a') || (mv[0] == 'A'))
		{
			fl = 0;
			pl3=0;
			scanf("%d,%d %d",&k,&l,&C);/*k grammh kai l sthlh */
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(a[i][j] == 0)
						pl3++;
				}
			}
			if(pl3 == 0)
			{
				printf("The table is full of tablets!!!\n");
				fl++;
			}
			if((k>n) || (l>m) || (k<=0) || (l<=0))
			{
				printf("You are out of the table!\n");
				fl++;
			}
			if((C<1) || (C>ch))
			{
				printf("The colour you gave doesn't belong to[1,%d]\n",ch);
				fl++;
			}
			if(fl == 0)
			{
				k=k-1;
				l=l-1;
				while(a[k][l] != 0)
				{
					printf("There is already a tablet there\n");
					do
					{
						printf("Give new coordinates:\n");
						scanf("%d,%d",&k,&l);
					}while((k>n) || (l>m) || (k<=0) || (l<=0));
					k=k-1;
					l=l-1;
				}
				a[k][l] = C;
				gravity(a,m,n);
				emfanish_pinaka(n,m,level,a,score);
			}
		}
		else if((mv[0] == 'x') || (mv[0] == 'X'))
		{						/*O monos logos pou xrhsimopoihsame GOTO einai */
			goto END; 		   /*giati enalaktika tha eprepe na xrhsimopoihsoume break */
		}					  /*se 2 emfoleumenes for kai kati de mas leitourgouse kala*/
		else
			printf("Invalid move,read the rules please!!!\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j] == 0)
				{
					flag++;
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		free(a[i]);
	}
	free(a);
	free(f);
	pl2++;
}
END:
	if((mv[0] == 'x') || (mv[0] == 'X'))
	{
		printf("Why leave so soon??You need %d more levels to finish the game\n",8-level);
	}
	else
		printf("\n    !!!GAME OVER!!!\n");
	
	printf("Your score is: %d points\n",score);
	printf("You played %d levels\n",pl2);
return 0;
}



void emfanish_pinaka(int n,int m,int level,int **a,int score)
{
	int i,j;
printf("\nscore: %d\n",score);
printf("level: %d\n",level);
for(i=0;i<m;i++)
	if(i==0)
		printf("   %d ",i+1);
	else
			if(i<9)
				printf("%d ",i+1);
			else
				printf("%d",i+1);
printf("\n");
for(i=0;i<m;i++)
	if(i==0)
		printf("   --");
	else
		printf("--");
for(i=0;i<n;i++)
{
	printf("\n");
	if(i < 9)
		printf("%d |",i+1);
	else 
		printf("%d|",i+1);

	for(j=0;j<m;j++)
	{ 
			if(a[i][j] == 0)
				printf(". ");
			else
				printf("%d ",a[i][j]);
	}
}
}
void gravity(int **a,int m,int n)
{
int i,j,p,temp;

for(p = 0;p <= m-1;p++)
{				         /*p = sthlh*/
	for(i = n-1;i>=0;i--) /*i = grammh*/
	{
		if(a[i][p] == 0)
		{
			for(j=i;j>=0;j--)
			{
				if((a[i][p] + a[j][p]) == a[j][p])
				{
					temp = a[j][p];
					a[j][p] = a[i][p];
					a[i][p] = temp;
				}
			}
		}
	}
}
}













int hammer(int **a, int i, int j,int r,int pl,int m,int n)
{
	
	if((i<=m) && (i+1 <=m) && (i>=0) && (j<=n) && (j>=0) && (a[i+1][j]==r))
	{
		a[i][j] =10;
		a[i+1][j]=10;
		i++;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}
	else if((i<=m) && (i>=0) && (i-1 >=0) && (j<=n) && (j>=0) &&(a[i-1][j]==r))
	{
		a[i][j] = 10;
		a[i-1][j]=10;
		i--;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}	
	else if((i<=m) && (i>=0) && (j<=n) && (j+1<=n) && (j>=0) && (a[i][j+1]==r))
	{
		a[i][j] = 10;
		a[i][j+1] = 10;
		j++;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}		
	else if((i<=m) && (i>=0) && (j<=n) && (j>=0) && (j-1 >=0) && (a[i][j-1]==r))
	{
		a[i][j] = 10;
		a[i][j-1] = 10;
		j--;
		pl++;
		hammer(a,i,j,r,pl,m,n);
		
	}		
	if((i<=m) && (i+1 <= m) && (i>=0) && (j<=n) && (j>=0) && (a[i+1][j] == 10))
	{
		a[i][j] =11;
		a[i+1][j] = 11;
		i++;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}
	if((i<=m) && (i>=0) && (i-1 >= 0) && (j<=n) && (j>=0) && (a[i-1][j] == 10) )
	{
		a[i][j] = 11;
		a[i-1][j] = 11;
		i--;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}	
	if((i<=m) && (i>=0) && (j<=n) && (j+1<=n) && (j>=0) && (a[i][j+1] == 10) )
	{
		
		a[i][j] = 11;
		a[i][j+1] = 11;
		j++;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}
	if((i<=m) && (i>=0) && (j<=n) && (j>=0) && (j-1 >=0) && (a[i][j-1]==10))
	{
		a[i][j] = 11;
		a[i][j-1] = 11;
		j--;
		pl++;
		hammer(a,i,j,r,pl,m,n);
	}	
	if(pl==0)
	{
		printf("You can't brake a tablet that is not connected with other tablets of the same colour!!!\n");	
		printf("Check the table and try again!!!\n");
	}
}	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		









