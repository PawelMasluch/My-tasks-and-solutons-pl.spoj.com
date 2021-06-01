#include<iostream> // 100 pkt

using namespace std;

typedef long long LL;

LL NWD(LL a, LL b)
{
	LL temp;
	
	while(b)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	
	return a;
}

LL NWW(LL a, LL b)
{
	return (a/NWD(a,b))*b;
}

int main()
{
	LL n,t[3],wyn=0,i,nww=1;
	
	cin >> n >> t[0] >> t[1] >> t[2];
	
	wyn += ((n/t[0]) + (n/t[1]) + (n/t[2]));
	
	wyn -= ((n/NWW(t[0],t[1])) + (n/NWW(t[1],t[2])) + (n/NWW(t[2],t[0])));
	
	for(i=0; i<=2; i++)
	{
		nww = nww/NWD(nww,t[i]);
		
		if(nww>1000000000)
		{
			cout << wyn << endl;
			return 0;
		}
		
		nww *= t[i];
	}
	
	wyn += (n/nww);
	
	cout << wyn << endl;
	
	return 0;
	
}
