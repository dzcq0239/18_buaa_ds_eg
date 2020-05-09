#include <stdio.h>
int main()
{
	int map[39][39]; 
	int i,j;
	for(i=0;i<39;i++)
	for(j=0;j<39;j++)
	map[i][j]=-1;
	
	for(i=1;i<=19;i++)
	for(j=1;j<=19;j++)
	scanf("%d",&map[i+5][j+5]);
	
	for(i=1;i<=19;i++)
	{
		for(j=1;j<=19;j++)
		{
			if((map[i+5][j+5]==1||map[i+5][j+5]==2)&&(map[i+5][j+5]==map[i+5][j+6]&&map[i+5][j+5]==map[i+5][j+7]&&map[i+5][j+5]==map[i+5][j+8])&&(map[i+5][j+4]==0||map[i+5][j+9]==0))
			{
				printf("%d:%d,%d",map[i+5][j+5],i,j);
				return 0;
			}
			
			if((map[i+5][j+5]==1||map[i+5][j+5]==2)&&(map[i+5][j+5]==map[i+6][j+6]&&map[i+5][j+5]==map[i+7][j+7]&&map[i+5][j+5]==map[i+8][j+8])&&(map[i+4][j+4]==0||map[i+9][j+9]==0))
			{
				printf("%d:%d,%d",map[i+5][j+5],i,j);
				return 0;
			}
			
			if((map[i+5][j+5]==1||map[i+5][j+5]==2)&&(map[i+5][j+5]==map[i+6][j+5]&&map[i+5][j+5]==map[i+7][j+5]&&map[i+5][j+5]==map[i+8][j+5])&&(map[i+4][j+5]==0||map[i+9][j+5]==0))
			{
				printf("%d:%d,%d",map[i+5][j+5],i,j);
				return 0;
			}
			
			if((map[i+5][j+5]==1||map[i+5][j+5]==2)&&(map[i+5][j+5]==map[i+6][j+4]&&map[i+5][j+5]==map[i+7][j+3]&&map[i+5][j+5]==map[i+8][j+2])&&(map[i+9][j+1]==0||map[i+4][j+6]==0))
			{
				printf("%d:%d,%d",map[i+5][j+5],i,j);
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}



