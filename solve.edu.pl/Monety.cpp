#include<iostream> // 100 pkt
#include<string>
#include<new>

#define REP(i,a,b) for(i=a; i<=b; i++)
#define FORD(i,b,a) for(i=b; i>=a; i--)

using namespace std;

int main()
{
	string s;
	
	cin>>s;
	
	int r=s.size(),i,MIN_SUMA=0,MAX_SUMA=0,*pref,temp=0,*pom,wyn=0;
	
	pref = new int [r+1];
	pref[0]=0;
	
	REP(i,0,r-1)
	{
		if(s[i]=='A')
		{
			pref[i+1] = pref[i] + 1;
			MAX_SUMA = max(MAX_SUMA,pref[i+1]);
		}
		else // s[i]=='B'
		{
			pref[i+1] = pref[i] - 2;
			MIN_SUMA = min(MIN_SUMA,pref[i+1]);
		}
	}
	
	s.clear();
	
	pom = new int [MAX_SUMA-MIN_SUMA+1];
	
	REP(i,0,MAX_SUMA-MIN_SUMA)
	{
		pom[i] = -1; // nie ma takiej sumy prefiksowej
	}
	
	FORD(i,r,0)
	{
		pom[pref[i]-MIN_SUMA] = i;	
	}
	
	REP(i,0,r)
	{
		if(pom[pref[i]-MIN_SUMA]<i)
		{
			wyn = max(wyn,i-pom[pref[i]-MIN_SUMA]);
		}
	}
	
	delete [] pref;
	delete [] pom;
	
	cout<<wyn<<endl;
	
	return 0;
}
