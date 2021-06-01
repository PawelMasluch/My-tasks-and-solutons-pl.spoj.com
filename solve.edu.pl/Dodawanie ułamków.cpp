#include<iostream> // 100 pkt

using namespace std;

typedef long long LL;

LL NWD(LL a, LL b)
{
	LL temp;
	
	while(b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	
	return a;
}

LL NWW(LL a, LL b)
{
	return ( a / NWD(a,b) ) * b;
}

int main()
{
	LL l1, m1, l2, m2, pom, l, m;
	
	cin >> l1 >> m1 >> l2 >> m2;
	
	pom = NWD(l1,m1);
	l1 /= pom;
	m1 /= pom;
	
	pom = NWD(l2,m2);
	l2 /= pom;
	m2 /= pom;
	
	m = NWW(m1,m2);
	l = (l1 * ( m / m1 ) ) + (l2 * ( m / m2 ) );
	
	pom = NWD(l,m);
	l /= pom;
	m /= pom;
	
	cout << l << " " << m << endl;
	
	return 0;
}
