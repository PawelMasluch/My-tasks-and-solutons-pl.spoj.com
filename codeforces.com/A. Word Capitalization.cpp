#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int pom;
	
	string s;
	
	cin >> s;
	
	pom = (int)( s[0] );
	
	if( 97 <= pom  &&  pom <= 122 )
	{
		s[0] = (char)( pom - 32 );
	}
	
	cout << s << endl;
	
	return 0;
}
