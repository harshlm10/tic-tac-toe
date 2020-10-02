#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
char p1[10],p2[10];int arr[3][3]={{-10,-10,-10},{-10,-10,-10},{-10,-10,-10}};
display()
{
	printf("___%3d___|___%3d___|___%3d___\n",arr[0][0],arr[0][1],arr[0][2]);
	printf("___%3d___|___%3d___|___%3d___\n",arr[1][0],arr[1][1],arr[1][2]);
	printf("___%3d___|___%3d___|___%3d___\n",arr[2][0],arr[2][1],arr[2][2]);
	printf("--> "); 
	fflush(stdout);
    sleep(1);
}
int loc(int address)
{
	int x,y;
	if(address>=1&&address<=3)
	{
		x=0;
		y=address-1;	
	}
	else if(address>=4&&address<=6)
	{
		x=1;
		y=address-4;	
	}
	else if(address>=7&&address<=9)
	{
		x=2;
		y=address-7;	
	}
	return (x*10+y);
}
int check()
{
	int x=-10,i;
	for(i=0; i<3; i++)
	{
		if((arr[i][0]+arr[i][1]+arr[i][2]==3)||(arr[i][0]+arr[i][1]+arr[i][2]==0))
		{x=arr[i][0];/*printf("\n%d%d,%d%d,%d%d\n",i,0,i,1,i,2);*/return x;}
	}
	for(i=0; i<3; i++)
	{
		if((arr[0][i]+arr[1][i]+arr[2][i]==3)||(arr[0][i]+arr[1][i]+arr[2][i]==0))
		{x=arr[0][i];/*printf("\n%d%d,%d%d,%d%d\n",0,i,1,i,2,i);*/return x;}
	}
	if((arr[0][0]+arr[1][1]+arr[2][2]==3)||(arr[0][0]+arr[1][1]+arr[2][2]==0))
		{x=arr[0][0];/*printf("\n%d%d,%d%d,%d%d\n",0,0,1,1,2,2);*/return x;}
	else if((arr[0][2]+arr[1][1]+arr[2][0]==3)||(arr[0][2]+arr[1][1]+arr[2][0]==0))
		{x=arr[0][2];/*printf("\n%d%d,%d%d,%d%d\n",0,2,1,1,2,0);*/return x;}	
	
}
void move(int cos)
{
	int count=0,location,arr_addr,x,y,result,inc;
	printf("Enter location (1-9):\n");
	for(;;)
{	while(1){
	printf("--> ");
	scanf("%d",&location);
	arr_addr = loc(location);
	y = arr_addr%10; x = arr_addr/10;
	if(arr[x][y]!=-10)
	printf("Invalid Move !!!\n--> ");
	else break;}
	if(cos==0 && count==0) inc=0;
	else if(cos==1 && count==0) inc = 1;
	if(inc%2==0){
		{
			arr[x][y]=0;
			inc++;}
		}
	else
	{{
		arr[x][y]=1;
		inc++;}
	}
	display();
	count++;
	result = check();
	if(result==0)
	{
	printf("%s Wins",p1);count=0;break;}
	else if(result==1)
	{printf("%s Wins",p2);count=0;break;}
	if(count>=9)
	{printf("Match Drawn !!!");count=0;break;}				
}
}
void firstplayer()
{
	printf("Enter First player(O) name : ");
	scanf("%s",p1);
	printf("Enter Second player(1) name : ");
	scanf("%s",p2);
}
int firstchance()
{
	srand(time(0));
	int random = rand();
	if((random%2)==0)
	{
		printf("This is %s's turn\n\n",p1);
		return 0;	
	}
	else
	printf("This is %s's turn\n\n",p2);
	return 1;
}
int main()
{
	int chance;
	firstplayer();
	int x=1,y=2,z=3;
	printf("\n-------------------------------------------\nPLAY USING NUMBER KEYS\n\n");
		printf("\n");
		for(int i=1; i<=3; i++)
		{
			printf("___%d___|___%d___|___%d___\n",x,y,z);
			x=x+3;y=y+3;z=z+3;
		}
		printf("       |       |       \n");
		printf("\n---------------------------------------------------------------------------\n\n");
	/*	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3 ;j++)
			printf(" %d ",arr[i][j]);
		}*/
		chance = firstchance();
		move(chance);
		return 0;
}
