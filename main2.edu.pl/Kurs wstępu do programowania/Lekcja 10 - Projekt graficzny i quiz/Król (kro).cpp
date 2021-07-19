#include<iostream> // do sprawdzenia

using namespace std;

int main()
{
	char column;
	
	int wiersz, kolumna, x[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, y[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, i, wyn = 0;
	
	cin >> column >> wiersz;
	
	kolumna = (int)(column) - 96;
	
	for(i=0; i<=7; ++i)
	{
		if( wiersz + x[i] >= 1  &&  wiersz + x[i] <= 8  &&  kolumna + y[i] >= 1  &&  kolumna + y[i] <= 8 )
		{
			++wyn;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}