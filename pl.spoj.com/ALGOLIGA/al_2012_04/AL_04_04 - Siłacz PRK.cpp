#include<iostream> // AC
using namespace std;
int main()
{
	int n,a,x=0,y=0,z=0;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a;
		if(a==0)
		{
			x++;
		}
		else
		{
			if(a==1)
			{
				y++;
		    }
			else
			{
				z++;
			}
	    }
	}
	if(x>y && x>z)
	{
		cout<<"bicek"<<endl;
	}
	else
	{
		if(y>x && y>z)
		{
			cout<<"klata"<<endl;
		}
		else
		{
			if(z>x && z>y)
			{
				cout<<"plecki"<<endl;
			}
			else
			{
				cout<<"Wszystko sie zlewa"<<endl;
			}
		}
	}
	return 0;
}
 
