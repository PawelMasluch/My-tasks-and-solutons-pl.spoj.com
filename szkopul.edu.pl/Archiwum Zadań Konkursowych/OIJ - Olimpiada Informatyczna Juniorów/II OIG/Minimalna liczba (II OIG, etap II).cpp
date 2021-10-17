#include<iostream> // 100 pkt
#include<vector>
#include<algorithm>


typedef long long LL;
typedef std::vector <LL> VLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)
#define PB push_back


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	LL n, k;
	std::cin >> n >> k;
	
	VLL v;
	LL x;
	REP(i,1,n){
		std::cin >> x;
		
		if( x % k == 0 ){
			v.PB( x / k );
		}
	}
	
	sort( v.begin(), v.end() );
	
	LL multiple_of_k = 0;
	REP(i,0,v.size()-1){
		
		if( v[i] >= multiple_of_k + 2 ){
			std::cout << (multiple_of_k + 1) * k << std::endl;
			return 0;
		}
		else{
			multiple_of_k = v[i];
		}
	}
	std::cout << (multiple_of_k + 1) * k << std::endl;
	
	return 0;
}
