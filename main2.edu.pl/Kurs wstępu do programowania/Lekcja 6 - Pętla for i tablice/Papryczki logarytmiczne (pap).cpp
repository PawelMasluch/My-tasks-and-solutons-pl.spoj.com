#include<iostream> 

using namespace std;

int main()
{
	int wyn = 1, i, k, p, pom = 1;
	
	cin >> k;
	
	for(i=0; i<=k; i++)
	{
		cin >> p;
		wyn += (p*pom);
		pom *= 2;
	}
	
	cout << wyn << endl;
	
	return 0;
}