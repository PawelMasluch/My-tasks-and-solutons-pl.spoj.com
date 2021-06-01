#include<iostream> // 100 pkt
#include<map>
#include<string>


using namespace std;


typedef map < int, string > MIS;


#define UB upper_bound

#define ST first

#define ND second


MIS M;

MIS::iterator it;

int n;


void preprocessing()
{
	M[1] = "I";
	
	M[4] = "IV";
	
	M[5] = "V";
	
	M[9] = "IX";
	
	M[10] = "X";
	
	M[40] = "XL";
	
	M[50] = "L";
	
	M[90] = "XC";
	
	M[100] = "C";
	
	M[400] = "CD";
	
	M[500] = "D";
	
	M[900] = "CM";
	
	M[1000] = "M";
}


void f()
{
	while( n > 0 )
	{
		it = M.UB( n );
		
		--it;
		
		cout << it->ND;
		
		n -= it->ST;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	preprocessing();
	
	cin >> n;
	
	f();
	
	return 0;
}
