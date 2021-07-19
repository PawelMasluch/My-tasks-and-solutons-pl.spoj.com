#include<iostream>
#include<new>

using namespace std;

int main()
{
	int n, i, *t, x, pocz = -2, kon = - 2;
	
	cin >> n >> x;
	
	t = new int [n];
	
	for(i=0; i<=n-1; i++)
	{
		cin >> t[i];
		
		if(t[i] == x)
		{
			kon = i;
		}
	}	
	
	for(i=n-1; i>=0; i--)
	{	
		if(t[i] == x)
		{
			pocz = i;
		}
	}	
	
	cout << pocz + 1 << " " << kon + 1 << endl;
	
	return 0;
}