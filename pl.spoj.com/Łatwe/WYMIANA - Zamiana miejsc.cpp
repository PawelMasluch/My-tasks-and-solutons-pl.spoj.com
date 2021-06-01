#include<stdio.h> // AC

int main()
{
	int x, y;
	scanf("%d %d",&x,&y);

	x += y;
	
	y = x - y;
	
	x -= y;

	printf("%d %d",x,y);
	return 0;
}
