#include<iostream>
#include<new>

using namespace std;

int main()
{
	int n, i, *t;
	
	cin >> n ;
	
	t = new int [n];
	
	for(i=0; i<=n-1; i++)
	{
		cin >> t[i];
	}	
	
	for(i=0; i<=n-1; i+=2)
	{
		cout << t[i] << " ";
	}
	
	cout << endl;
	
	for(i=1; i<=n-1; i+=2)
	{
		cout << t[i] << " ";
	}
	
	return 0;
}