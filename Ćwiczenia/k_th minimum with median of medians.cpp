#include<bits/stdc++.h>


typedef long long LL;

typedef std::vector <LL> VLL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)



const LL INF = (LL)1000000099 * 1000000099;


// k-th minimum of sequence A[0..n-1] with use median of medians algoritm.

// Assumption 1: 10^6 >= n >= 1
// Assumption 2: k in {1..n}
// Assumption 3: |A[i]| <= 10^18 for i in {0..n-1}

// Sources:
// http://smurf.mimuw.edu.pl/node/327
// http://wazniak.mimuw.edu.pl/index.php?title=Algorytmy_i_struktury_danych/Selekcja
// https://pl.wikipedia.org/wiki/Algorytm_magicznych_pi%C4%85tek
// https://en.wikipedia.org/wiki/Median_of_medians
LL k_th_minimum(VLL &A, int k){
	
	int n = A.size();
	
	// For small problems, use straightforward method (sort sequence and return k-th minimum of sequence)
	if( n <= 10 ){
		sort( A.begin(), A.end() );
		return A[k-1];
	}
	
	// ----------------------------------------------------
	
	/* Computing a pivot m */
	
	VLL M; // sequence of medians
	VLL P; // current subsequence of 5 elements
	
	
	// Subsequences of 5 elements
	REP(i,1,n/5){
		REP(j, (i-1)*5, i*5-1){
				P.push_back( A[j] );
		}
		
		sort( P.begin(), P.end() );
		
		M.push_back( P[2] );
		
		P.clear();
	}
	
	// Last, incomplete subsequence (>=1, < 5 elements)
	if( n % 5 > 0 ){
		
		P.resize(5, INF);
		
		int alfa = (n+4)/5;
		REP(j, (alfa-1)*5, n-1){
				P[j % 5] = A[j];
		}
		
		sort( P.begin(), P.end() );
		
		M.push_back( P[2] );
		
		P.clear();
	}
	
	
	// Computing a pivot
	LL m = k_th_minimum( M,   (M.size() + 1) / 2 );
	M.clear();
	
	// ----------------------------------------------------------------
	
	// A_<
	VLL A_less;
	
	// A_=
	VLL A_equal;
	
	// A_>
	VLL A_greater;
	
	
	// Computing   A_<,   A_=,   A_>
	REP(i,0,n-1){
		if( A[i] < m ){
			A_less.push_back( A[i] );
		}
		else{
			if( A[i] == m ){
				A_equal.push_back( A[i] );
			}
			else{ // A[i] > m
				A_greater.push_back( A[i] );
			}
		}
	}
	
	// Making a decision
	if( A_less.size() >= k ){
		
		A_equal.clear();
		A_greater.clear();
		
		return k_th_minimum(A_less, k);
	}
	else{
		if( A_less.size() + A_equal.size() >= k ){
			
			A_less.clear();
			A_equal.clear();
			A_greater.clear();
			
			return m;
		}
		else{
			
			int A_less_size = A_less.size();
			int A_equal_size = A_equal.size();
			
			A_less.clear();
			A_equal.clear();
			
			return k_th_minimum( A_greater,   k - A_less_size - A_equal_size );
		}
	}
}


int main(){
	
	int n, k;
	std::cin >> n >> k;
	
	// ----------------
	
	VLL A(n);
	REP(i,0,n-1){
		std::cin >> A[i];
	}
	
	// ----------------
	
	std::cout << k_th_minimum(A, k) << std::endl;
	
	// ----------------
	
	return 0;
}

/*

Tests:

Test 1:
In:
18 4
1 2 3 4 5 6 7 8 1 2 3 4 5 6 7 1 2 3 4

Out:
2


*/
