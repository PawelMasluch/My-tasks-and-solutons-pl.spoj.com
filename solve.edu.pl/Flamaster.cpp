#include<iostream> // 100 pkt
#include<string>
#include<stack>

using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


bool otw(char x) // czy znak "x" to nawias otwierający
{
	return ( x == '('  ||  x == '['  ||  x == '{' ) ? true : false ;
}


char f(char x) // z nawiasu zamykającego tworzymy otwierający 
{
	if( x == ')' )
	{
		return '(';
	}
	
	if( x == ']' )
	{
		return '[';
	}
	
	return '{';
}


char g(char x) // z nawiasu otwierającego tworzymy zamykający
{
	if( x == '(' )
	{
		return ')';
	}
	
	if( x == '[' )
	{
		return ']';
	}
	
	return '}';
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	stack < char > S, P;
	
	string s;
	
	cin >> s;
	
	int r = s.size();
	
	REP(i,r)
	{
		if( otw( s[i] ) )
		{
			S.push( s[i] );
		}
		else
		{
			if( S.empty() )
			{
				P.push( f( s[i] ) );
			}
			else
			{
				if( f( s[i] ) != S.top() )
				{
					cout << "NIE\n";
					
					return 0;
				}
				else
				{
					S.pop();
				}
			}
		}
	}
	
	while( !P.empty() )
	{
		cout << P.top();
		
		P.pop();
	}
	
	cout << s;
	
	while( !S.empty() )
	{
		cout << g( S.top() );
		
		S.pop();
	}
	
	cout << endl;
	
	return 0;
}
