#include<iostream> // 100 pkt

using namespace std;

typedef long long LL;

LL S(LL A, LL B)
{
	return (B+A)*(B-A+1)/2;
}

int main()
{
	LL A, B;
	
	cin >> A >> B;
	
	cout << S(A,B) << endl;
	
	return 0;
}
