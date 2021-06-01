#include<cstdio> // 91/100 pkt; rozwiazanie przeszlo wszystkie testy
#include<new>
#include<algorithm>


#define REP(i,a,b) for(i=a; i<=b; ++i)


using namespace std;


struct elem
{
	int ind;
	
	double val;
};


bool f1(elem a, elem b)
{
	return ( a.val < b.val );
}


bool f2(elem a, elem b)
{
	return ( a.ind < b.ind );
}


int main()
{
	elem *t;
	
	int n, i, j;
	
	double *pref;
	
	scanf("%d", &n);
	
	t = new elem [n];
	
	pref = new double [n+1];
	
	pref[0] = 0;
	
	REP(i,0,n-1)
	{
		scanf("%lf", &t[i].val);
		
		t[i].ind = i + 1;
	}
	
	sort(t,t+n,f1);
	
	REP(i,0,n-1)
	{
		pref[i+1] = pref[i] + t[i].val;
	}
	
	i = n - 2;
	
	while( i >= 0 )
	{
		if( t[i].val != t[i+1].val )
		{
			if( pref[i+1] < t[i+1].val )
			{
				break;
			}
		}
		
		--i;
	}
	
	++i;
	
	sort(t+i,t+n,f2);
	
	REP(j,i,n-1)
	{
		printf("%d ", t[j].ind);
	}
	
	printf("\n");
	
	return 0;
}
