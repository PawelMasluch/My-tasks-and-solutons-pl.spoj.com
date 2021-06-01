#include<iostream> // AC


using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	int t[10], ind = -1, a;
	
	while( cin >> zn )
	{
		if( zn == '-' )
		{
			if( ind == -1 )
			{
				cout << ":(\n";
			}
			else
			{
				cout << t[ ind ] << endl;
				
				--ind;
			}
		}
		else // zn == '+'
		{
			cin >> a;
			
			if( ind == 9 )
			{
				cout << ":(\n";
			}
			else
			{
				cout << ":)\n";
				
				++ind;
				
				t[ ind ] = a;
			}
		}
	}
	
	return 0;
}
