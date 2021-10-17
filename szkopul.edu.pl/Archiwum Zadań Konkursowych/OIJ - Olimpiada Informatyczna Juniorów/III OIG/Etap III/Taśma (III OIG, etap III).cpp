#include<iostream> // 100 pkt


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 100000;


int a[MAX_N]; // sequence of numbers to consider 


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	int m;
	std::cin >> m;
	
	int res;
	int n;
	while(m--){
		
		std::cin >> n;
		
		REP(i,0,n-1){
			std::cin >> a[i];
		}
		
		res = 0;
		
		// 1st case - 1st number with any other number
		REP(i,1,n-1){
			if( a[i] != a[0] ){
				res = i;
			}
		}
		
		// 2nd case - last number with any other number (apart from the 1st number)
		FORD(i,n-2,1){
			if( a[i] != a[n-1] ){
				res = std::max(res, n-1-i);
			}
		}
		
		if( res == 0 ){
			std::cout << "BRAK\n";
		}
		else{
			std::cout << res << std::endl;
		}
	}
	
	return 0;
}
