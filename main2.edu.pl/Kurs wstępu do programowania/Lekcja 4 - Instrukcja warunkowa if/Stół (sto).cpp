#include<iostream>

using namespace std;

typedef long long LL; 

LL oblicz(LL A, LL B, LL K)
{
	LL wyn = 0;
	
	if(B>=K)
	{
		wyn += (A/K);
	}
	
	if(B>=K && A>=K)
	{
		wyn += ((B-K)/K);
	}
	
	if(B>=2*K)
	{
		if(A>=K)
		{
			wyn += ((A-K)/K);
		}
	}
	
	if(A>=2*K)
	{
		if(B>=2*K)
		{
			wyn += ((B-(2*K))/K);	
		}
	}
	
	return wyn;
	
}

int main()
{
	LL A,B,K;
	cin>>A>>B>>K;
	cout<<max(oblicz(A,B,K),oblicz(B,A,K))<<endl;
	return 0;
}