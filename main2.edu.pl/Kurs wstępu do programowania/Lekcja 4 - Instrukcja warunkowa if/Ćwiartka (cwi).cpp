#include<iostream>

using namespace std;

int main()
{
	int x,y;
	cin>>x>>y;
	
	if(x==0)
	{
		if(y==0)
		{
			cout<<"0\n";
		}
		else
		{
			cout<<"OY\n";
		}
	}
	else
	{
		if(y==0)
		{
			cout<<"OX\n";
		}
		else
		{
			if(x>0)
			{
				if(y>0)
				{
					cout<<"I\n";
				}
				else
				{
					cout<<"IV\n";
				}
			}
			else
			{
				if(y>0)
				{
					cout<<"II\n";
				}
				else
				{
					cout<<"III\n";
				}
			}
			
		}
	}
	
	return 0;
}