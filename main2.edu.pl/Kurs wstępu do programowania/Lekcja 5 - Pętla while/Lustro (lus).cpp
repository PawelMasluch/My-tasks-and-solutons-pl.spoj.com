#include<iostream> // do sprawdzenia
#include<vector>

using namespace std;

typedef long long LL;

int main()
{
	vector <LL> v;
	
	LL n, r = 0, i = 0;
	
	cin >> n;
	
	while(n > 0)
	{
		v.push_back(n%10);
		n/=10;
		r++;
	}
	
	while(v[i] == 0)
	{
		i++;
	}
	
	while(i<=r-1)
	{
		cout << v[i];
		i++;
	}
	
	return 0;
}