#include<iostream> // do sprawdzenia

using namespace std; // 0<=n<=12

int main()
{
	int wyn = 1, i, n;
	
	cin >> n;
	
	for(i=1; i<=n; i++)
	{
		wyn *= i;
	}
	
	cout << wyn << endl;
	
	return 0;
}