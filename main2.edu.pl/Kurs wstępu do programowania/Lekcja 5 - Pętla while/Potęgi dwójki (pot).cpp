#include<iostream> // do sprawdzenia

using namespace std;

typedef long long LL;

int main()
{
	LL n, pom = 1;
	cin >> n;
	while(pom <= n)
	{
		cout << pom << endl;
		pom *= 2;
	}
	return 0;
}