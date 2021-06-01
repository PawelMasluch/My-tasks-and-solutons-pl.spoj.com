#include<iostream> // 100 pkt
using namespace std;
int f(long long n)
{
	if(n==0)
	{
		return 1;
	}
	switch(n%4)
	{
		case 0 : return 6; 
		case 1 : return 2;
		case 2 : return 4;
		case 3 : return 8;
	}
}
int main()
{
	long long n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}