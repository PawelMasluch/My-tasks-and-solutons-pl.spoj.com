#include<iostream> // 100 pkt
#include<cstdio>
#include<string>


using namespace std;


const double A = 3.78541178, B = 1.609344;


string s;

double X;


int main()
{
	cin >> X >> s;
	
	printf( "%.2lf ", 100. * A / X / B );
	
	if( s == "l/100km" )
	{
		cout << "mpg\n";
	}
	else // s == "mpg"
	{
		cout << "l/100km\n";
	}
	
	return 0;
}
