#include<iostream> // 100 pkt
#include<vector>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	vector <int> v;
	int K, r = 0, i, n, wyn = 1000001;
	cin >> K >> s;
	
	if(K == 0)
	{
		cout<<"0\n";
		return 0;
	}
	
	n = s.size();
	
	for(i=0; i<=n-1; i++)
	{
		if(s[i] == 'D')
		{
			v.push_back(i+1);
			r++;
		}
	}
	
	if(r < K)
	{
		cout << "NIE\n";
		return 0;
	}
	
	for(i=0; i<= r - K; i++)
	{
		wyn = min(wyn, v[i + K - 1] - v[i] + 1 - K);
	}
	
	cout << wyn << endl;
	
	return 0;
	
}
