#include<iostream> // 100 pkt
#include<string>
#include<new>
#include<algorithm>

using namespace std;

struct elem
{
	int ASCII;
	int ile;
};

bool f(elem a, elem b)
{
	if(a.ile==b.ile)
	{
		return (a.ASCII < b.ASCII);
	}
	return (a.ile > b.ile);
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n,i,j;
	elem *t = new elem [26];
	for(i=0; i<=25; i++)
	{
		t[i].ASCII = 97 + i;
		t[i].ile = 0;
	}
	string s;
	cin>>s;
	n = s.size();
	for(i=0; i<=n-1; i++)
	{
		t[(int)(s[i]) - 97].ile++;	
	}
	sort(t,t+26,f);
	for(i=0; i<=25; i++)
	{
		for(j=1; j<=t[i].ile; j++)
		{
			cout<<(char)(t[i].ASCII);
		}
	}
	cout<<endl;
	return 0;
}
