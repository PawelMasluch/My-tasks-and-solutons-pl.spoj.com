#include<iostream> // 100 pkt


typedef long long LL;


// 1 + 2 + ... + n
LL G(int n){
	return (LL)n * (n+1) / 2;
}


// a + (a+1) + ... + b
LL S(int a, int b){
	return G(b) - G(a-1);
}


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	// 1 <= n <= 10^9, 
	// 1 <= k <= n, 
	// 1 <= i <= j <= n
	int n, k, i, j;
	std::cin >> n >> k >> i >> j;
	
	// Sequence "a" of numbers to consider:
	// indices:    1      2   ... k k+1 k+2 ...  n
	//  values:  n-k+1  n-k+2 ... n  1   2  ... n-k
	
	// Thus, a_i = i+(n-k) for     1 <= i <= k 
	//    or a_i = i-k     for   k+1 <= i <= n
	
	if( i <= k ){
		if(j <= k){
			std::cout << S( i+(n-k), j+(n-k) ) << std::endl;
		}
		else{
			std::cout << S( i+(n-k), n ) + S(1, j-k) << std::endl;	
		}
	}
	else{
		std::cout << S(i-k, j-k) << std::endl;
	}
	
	return 0;
}
