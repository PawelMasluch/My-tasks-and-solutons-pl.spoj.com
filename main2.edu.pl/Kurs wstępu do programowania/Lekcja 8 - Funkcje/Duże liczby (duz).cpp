#include<iostream> // 100 pkt
#include<string>

using namespace std;

int porownaj(string &a, string &b) // porównanie 2 liczb dodatnich
{
	int ra = a.size(), rb = b.size(), i;
	
	if(ra > rb)
	{
		return 1;
	}
	
	if(rb > ra)
	{
		return 2;
	}
	
	for(i=0; i<=ra-1; i++)
	{
		if( (int)(a[i]) > (int)(b[i]) )
		{
			return 1;
		}
		
		if( (int)(a[i]) < (int)(b[i]) )
		{
			return 2;
		}
	}
	
	return 0;
}

void f(string &a, string &zn, string &b)
{
	int wyn = porownaj(a,b);
	
	if(zn == "==")
	{
		if(wyn == 0)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
	
	if(zn == "!=")
	{
		if(wyn != 0)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
	
	if(zn == "<")
	{
		if(wyn == 2)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
	
	if(zn == ">")
	{
		if(wyn == 1)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
	
	if(zn == "<=")
	{
		if(wyn != 1)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
	
	if(zn == ">=")
	{
		if(wyn != 2)
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	string a, b, zn;
	
	cin >> a >> zn >> b; 
	
	f(a,zn,b);
	
	return 0;
}