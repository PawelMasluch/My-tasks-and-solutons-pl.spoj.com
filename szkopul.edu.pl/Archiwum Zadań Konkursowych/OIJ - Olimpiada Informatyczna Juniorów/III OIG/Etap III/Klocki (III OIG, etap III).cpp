#include<iostream> // 100 pkt


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int INF = 1000099;


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	int n, k, s;
	std::cin >> n >> k >> s;
	
	int DP[s+1]; // DP[total_mass] - minimal number of boxes with total mass equal "total_mass"
	
	DP[0] = 0;
	REP(i,1,s){
		DP[i] = INF;
	}
	
	int m;
	REP(i,1,n){
		std::cin >> m;
		
		FORD(total_mass,s,m){
			DP[total_mass]  =  std::min( DP[total_mass],  DP[total_mass - m] + 1 );
		}
	}
	
	FORD(total_mass,s,0){
		
		if(DP[total_mass] <= k){
			std::cout << total_mass << std::endl;
			return 0;
		}
	}
	
	return 0;
}
