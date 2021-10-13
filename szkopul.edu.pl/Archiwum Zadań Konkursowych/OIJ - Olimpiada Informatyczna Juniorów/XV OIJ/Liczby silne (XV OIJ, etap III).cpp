#include<iostream> // 100 pkt
#include<vector>
#include<algorithm>


using namespace std;


typedef long long LL;
typedef vector <LL> VLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)
#define PB push_back
#define S size


const LL MAX_N = 15; // MAX_N = max {n in N: n! <= 10^13}


LL factorial[MAX_N+1];
VLL strong_numbers;
VLL strong_numbers_preffix_sums;


void compute_factorials(){
	factorial[0] = 1;
	
	REP(n,1,MAX_N){
		factorial[n] = n * factorial[n-1];
	}
}


void generate_strong_numbers(){
	
	LL tmp;
	LL idx;
	LL strong_number;
	REP( bit_package, 1, (1<<MAX_N) - 1 ){
		
		tmp = bit_package;
		idx = 1;
		strong_number = 0;
		
		while( tmp > 0 ){
			
			if( tmp % 2 == 1 ){
				strong_number += factorial[ idx ];
			}
			
			tmp /= 2;
			++idx;
		}
		
		strong_numbers.PB( strong_number );
	}
	
}


void generate_strong_numbers_preffix_sums(){
	
	strong_numbers_preffix_sums.PB(0);
	
	REP(i,0,strong_numbers.size()-1){
		strong_numbers_preffix_sums.PB( strong_numbers_preffix_sums.back() + strong_numbers[i] );
	}
}


// min i (if exists): strong_numbers[i] >= x
LL find_idx_A(LL x){
	
	LL start = 0, end = strong_numbers.size()-1, med, res = -1;
	
	while( start <= end ){
		med = ( start + end ) / 2;
		
		if( strong_numbers[med] >= x ){
			res = med;
			
			end = med - 1;
		}
		else{
			start = med + 1;
		}
	}
	
	return res;
}


// max i (if exists): strong_numbers[i] <= x
LL find_idx_B(LL x){
	
	LL start = 0, end = strong_numbers.size()-1, med, res = -1;
	
	while( start <= end ){
		med = ( start + end ) / 2;
		
		if( strong_numbers[med] <= x ){
			res = med;
			
			start = med + 1;
		}
		else{
			end = med - 1;
		}
	}
	
	return res;
}


LL answer(LL A, LL B){
	
	LL res = 0;
	
	LL idx_A = find_idx_A( A );
	LL idx_B = find_idx_B( B );
	
	if( idx_A <= idx_B  &&  idx_A != -1  &&  idx_B != -1 ){
		return strong_numbers_preffix_sums[ (idx_B+1)     ] -
			   strong_numbers_preffix_sums[ (idx_A+1) - 1 ]; 
	}
	
	return res;
}


void serve_queries(){
	
	LL Q;
	cin >> Q;
	
	LL A, B;
	while(Q--){
		
		cin >> A >> B;
		
		cout << answer(A, B) << endl;
	}
}


int main(){
	
	ios_base::sync_with_stdio(0);
	
	
	compute_factorials();
	
	generate_strong_numbers();
	
	sort( strong_numbers.begin(), strong_numbers.end() );
	
	generate_strong_numbers_preffix_sums();
	
	serve_queries();
	
	
	return 0;
}
