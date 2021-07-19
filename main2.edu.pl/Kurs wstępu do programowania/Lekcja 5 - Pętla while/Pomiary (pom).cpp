#include<iostream> // do sprawdzenia
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

int main()
{
	vector <LL> v;
	
	LL n, r = 0, wyn = 1, i;
	
	cin>>n;
	
	while(n != -1)
	{
		if(n >= 1)
		{
			v.push_back(n);
			r++;
		}
		cin>>n;
	}
	
	if(r==0)
	{
		cout << "0\n";
	}
	else
	{
		sort(v.begin(), v.begin() +  r);
		for(i=1; i<=r-1; i++)
		{
			if(v[i] != v[i-1])
			{
				wyn++;
			}
		}
		cout << wyn << endl;
	}
	
	return 0;
}