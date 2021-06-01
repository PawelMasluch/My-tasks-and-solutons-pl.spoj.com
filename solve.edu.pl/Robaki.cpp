#include<iostream> // 100 pkt

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	int N, L, wyn = 0, A;
	
	cin >> N >> L;
	
	while( N )
	{
		cin >> A >> zn;
		
		if( zn == 'L' )
		{
			wyn = max( wyn, A );
		}
		else
		{
			wyn = max( wyn, L - A );
		}
		
		--N;
	}
	
	cout << wyn << endl;
	
	return 0;
}
