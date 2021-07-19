#include<bits/stdc++.h>


typedef long long LL;

typedef std::vector <int> VI;

typedef std::vector <VI> VVI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


void calculate_auxiliary_values(VI &t, int n, VI &IDsOfCycles, VI &positionsInCycles, VVI &Cycles){
	
	IDsOfCycles.resize(n);
	positionsInCycles.resize(n);
	
	
	VI visited(n, false);
	
	
	
	VI current_cycle;
	int current_cycle_number = 0;
	
	REP(i,0,n-1){
		if( visited[i] == false ){
			
			int position_in_current_cycle = 0;
			int j = i;
			
			do{
				current_cycle.push_back(j);
				
				IDsOfCycles[j] = current_cycle_number;
				
				positionsInCycles[j] = position_in_current_cycle;
				++position_in_current_cycle;
				
				visited[j] = true;
				j = t[j];
			}
			while( visited[j] == false );
			
			++current_cycle_number;
			
			Cycles.push_back( current_cycle );
			current_cycle.clear();
		}
	}
	
	
	visited.clear();
}


/* k-th power of permutation t, in O(n) time */
VI k_th_permutation_power(VI &t, int n, LL k){
	
	VI res(n);
	
	
	
	VI IDsOfCycles;
	VI positionsInCycles;
	VVI Cycles;
	
	
	
	calculate_auxiliary_values(t, n, IDsOfCycles, positionsInCycles, Cycles);
	
	
	
	REP(i,0,n-1){
		
		int cycle_number = IDsOfCycles[i];
		int position_in_cycle = positionsInCycles[i];
		int cycle_length = Cycles[ cycle_number ].size();
		int destination_position_in_cycle = (position_in_cycle + k - 1) % cycle_length;
		int destination_index = Cycles[cycle_number][destination_position_in_cycle];
		
		res[destination_index] = t[i];
	}
	
	
	REP(i,0,n-1){
		++res[i];
	}
	
	
	IDsOfCycles.clear();
	positionsInCycles.clear();
	Cycles.clear();
	
	
	return res;
}


int main(){
	
	int n; // permutation's length (1000000 >= n >= 1)
	LL k; // exponent (9*10^18 >= k >= 0)
	VI t; // permutation (for user, of {1..n} set; for calculations, of {0..n-1} set)
	
	/* Read data from standard input - permutation of {1..n} set */
	std::cin >> n >> k;
	
	int val;
	REP(i,0,n-1){
		std::cin >> val;
		--val;
		t.push_back( val );
	}
	
	
	/* Compute result -> k-th permutation's power of {1..n} set */
	VI res = k_th_permutation_power( t, n, k );
	
	
	/* Write result to standard output - k-th permutation's power of {1..n} set */
	REP(i,0,n-1){
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	
	
	return 0;
}


/*


Test 1:
In:
6 2
3 1 2 6 4 5
Out:
1 2 3 4 5 6


Test 2:
In:
5 3
5 3 4 1 2
Out:
4 5 2 3 1


Test 3:
In:
5 4
5 3 4 1 2
Out:
3 1 5 2 4

*/
