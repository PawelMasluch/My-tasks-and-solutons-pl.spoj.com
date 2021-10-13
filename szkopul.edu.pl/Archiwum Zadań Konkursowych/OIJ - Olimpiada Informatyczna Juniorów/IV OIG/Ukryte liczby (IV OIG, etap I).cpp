#include<iostream> // 100 pkt
#include<string>


using namespace std;


typedef long long LL;


#define FORD(i,b,a) for(int i=b; i>=a; --i)


int main(){
	
	ios_base::sync_with_stdio(0);
	
	int n;
	string s;
	
	cin >> n >> s;
	
	LL power_of_10 = 1;
	LL res = 0;
	FORD( i, s.size()-1, 0 ){
		
		if( s[i] >= '0' and s[i] <= '9' ){
			res += ( s[i] - '0' ) * power_of_10;
			power_of_10 *= 10;
		}
		else{
			power_of_10 = 1;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
