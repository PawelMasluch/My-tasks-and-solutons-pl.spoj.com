#include<iostream>

using namespace std;

int f(int x)
{
	return (x>=0) ? x : -x ;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a < b + c  &&  a > f(b-c))
	{
		cout<<"TAK\n";
	}
	else
	{
		cout<<"NIE\n";
	}
	return 0;
}