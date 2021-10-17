#include<iostream> // 100 pkt
#include<string>


typedef std::string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_LEN = 1000000;


int DP[MAX_LEN+1];


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	STR s;
	std::cin >> s;
	
	int len = s.length();
	
	s = '#' + s;
	
	int amount_of_pluses = 0;
	int amount_of_minuses = 0;
	int last_plus_index = 0;
	int res = 0;
	
	REP(i,1,len){
		
		if( s[i] == '+' ){
			
			last_plus_index = i;
			
			if( s[i-1] == '-' ){
				amount_of_pluses = 1;
			}
			else{
				++amount_of_pluses;
			}
			
			if( amount_of_minuses % 2 == 1 ){
				DP[i] = amount_of_pluses + (amount_of_minuses / 2);
			}
			else{
				DP[i] = 1 + DP[i-1];
			}
		}
		else{ // s[i] == '-'
			if( s[i-1] == '+' ){
				amount_of_minuses = 1;
			}
			else{
				++amount_of_minuses;
			}
			
			if( amount_of_minuses % 2 == 1 ){
				DP[i] = amount_of_minuses / 2;
			}
			else{
				DP[i] = (amount_of_minuses / 2) + DP[last_plus_index];
			}
		}
		
		res = std::max( res,  DP[i] );
	}
	
	std::cout << res << std::endl;
	
	return 0;
}
