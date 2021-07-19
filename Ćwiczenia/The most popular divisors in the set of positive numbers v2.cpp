/*

	Finding all positive (greater than 1) integers, dividing the most numbers of a given multiset of positive (greater than 1) integers.
	Computional complexity: O(   n  +  max(t_i) * log( max(t_i) )   )
	Space complexity:       O( n + max(t_i) )
	

*/

#include<bits/stdc++.h>


typedef std::vector <int> VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FOR(i,a,b,jump) for(int i=a; i<=b; i+=jump)
#define PB push_back


// 10^7 >= n >= 1
// 10^7 >= t[i] >= 0 for i=0,1,...,n-1
VI the_most_popular_divisors(VI &t, int n, int &max_count){
	
	// Finding the biggest element in a multiset.
	// O(n)
	int MAX_T = t[0];
	REP(i,1,n-1){
		MAX_T = std::max( MAX_T, t[i] );
	}
	
	/*REP(i,0,n-1){
		printf( "%d, ", t[i] );
	}*/
	
	// ---------------------------------
	
	VI histogram( MAX_T + 1, 0 );
	REP(i,0,n-1){ // O(n)
		++histogram[ t[i] ];
	}
	
	/*REP(i,1,MAX_T){
		printf( "%d, ", histogram[i] );
	}*/
	
	// ---------------------------------
	
	VI res;
	int tmp_count = 0;
	max_count = 0;
	
	// O( MAX_T * log(MAX_T) )
	REP(i,2,MAX_T){ // for each possible divisor
		
		FOR(j,i,MAX_T,i){ // for each multiple of divisor i
			tmp_count += histogram[j];	
		}
		
		if( tmp_count > max_count ){
			max_count = tmp_count;
			
			res.clear();
			res.PB(i);
		}
		else{
			if( tmp_count == max_count ){
				res.PB(i);
			}
		}
		
		/*printf( "d=%d: tmp_count=%d\nres:\n", i, tmp_count );
		
		REP(i,0,res.size()-1){
			printf( "%d, ", res[i] );
		}
		printf( "\n" );
		*/
		
		tmp_count = 0;
	}
	
	// ----------------------------------------
	
	histogram.clear();
	
	// ----------------------------------------
	
	return res;
}



int main(){
	
	int n;
	
	printf( "Data input\n" );
	
	printf( "Enter a number of elements in multiset:\nn = " );
	scanf( "%d", &n );
	
	// --------------------
	
	VI t;
	int x;
		
	printf( "Enter a multiset of numbers:\n" );
	REP(i,0,n-1){
		scanf( "%d", &x );
		t.PB(x);
	}
	
	// ---------------------
	
	int max_count;
	VI res = the_most_popular_divisors(t, n, max_count);
	
	
	/*printf( "%d\n", max_count );
	printf( "%d\n", res.size() );
	REP(i,0,res.size()-1){
		printf( "%d, ", res[i] );
	}*/
	
	// ----------------------
	
	printf( "\nResults:\n" );
	
	
	// The most popular divisors
	printf( "The most popular divisors in our multiset:\n" );
	REP(i,0,res.size()-1){
		printf( "%d ", res[i] );
	}
	
	// Maximum number of elements divisible by the most popular divisors
	printf( "\nMaximum number of elements divisible by the most popular divisors is:\n%d\n", max_count );
	
	// ---------------------
	
	t.clear();
	
	// ---------------------
	
	return 0;
}

/*

Test #1:
In:
6
56 2 4 8 6 16
Out:
2
6

Test #2:
In:
8
5 7 99 8 4 3 147 119
Out:
3 7
3

*/
