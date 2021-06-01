#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

void mnoz(LL **A, LL **B, LL p)
{
	LL a = (((A[0][0]*B[0][0])%p) + ((A[0][1]*B[1][0])%p))%p;
	LL b = (((A[0][0]*B[0][1])%p) + ((A[0][1]*B[1][1])%p))%p;
	LL c = (((A[1][0]*B[0][0])%p) + ((A[1][1]*B[1][0])%p))%p;
	LL d = (((A[1][0]*B[0][1])%p) + ((A[1][1]*B[1][1])%p))%p;
	
	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}

LL poteguj(LL **WYN, LL **F, LL n, LL p)
{
	while(n!=0)
	{
		if(n%2==1)
		{
			mnoz(WYN,F,p);
		}
		
		mnoz(F,F,p);
		
		n/=2;
	}
}

int main()
{
	LL **F = new LL *[2], **WYN = new LL *[2], i, n, p = 123456789;
	
	for(i=0; i<=1; i++)
	{
		F[i] = new LL [2];
		WYN[i] = new LL [2];
	}
	
	F[0][0] = 0;
	F[0][1] = 1;
	F[1][0] = 1;
	F[1][1] = 1;
	
	WYN[0][0] = 1;
	WYN[0][1] = 0;
	WYN[1][0] = 0;
	WYN[1][1] = 1;
	
	scanf("%lld", &n);
	
	poteguj(WYN,F,n,p);
	
	printf("%lld\n", WYN[0][1]);
	
	return 0;
}
