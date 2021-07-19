#include<bits/stdc++.h>


typedef long long LL;

typedef std::vector <int> VI;

typedef std::vector <VI> VVI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000; // maximum permutation's length


int n; // permutation's length (MAX_N >= n >= 1)
LL k; // exponent (9*10^18 >= k >= 0)
int t[MAX_N]; // permutation (for user, of {1..n} set; for calculations, of {0..n-1} set)


int * IDs_of_cycles(int *t, int n){
	int *res = new int [n];
	
	
	bool * visited = new bool [n];
	REP(i,0,n-1){
		visited[i] = false;
	}
	
	
	int current_cycle_number = 0;
	
	REP(i,0,n-1){
		if( visited[i] == false ){
			
			int j = i;
			
			do{
				res[j] = current_cycle_number;
				visited[j] = true;
				j = t[j];
			}
			while( visited[j] == false );
			
			++current_cycle_number;
		}
	}
	
	
	delete [] visited;
	
	
	return res;
}


int * positions_in_cycles(int *t, int n){
	int *res = new int [n];
	
	
	bool * visited = new bool [n];
	REP(i,0,n-1){
		visited[i] = false;
	}
	
	
	REP(i,0,n-1){
		if( visited[i] == false ){
			
			int position_in_current_cycle = 0;
			int j = i;
			
			do{
				res[j] = position_in_current_cycle;
				++position_in_current_cycle;
				visited[j] = true;
				j = t[j];
			}
			while( visited[j] == false );
		}
	}
	
	
	delete [] visited;
	
	
	return res;
}


VVI cycles(int *t, int n){
	VVI res;
	
	
	
	
	bool * visited = new bool [n];
	REP(i,0,n-1){
		visited[i] = false;
	}
	
	
	VI current_cycle;
	
	REP(i,0,n-1){
		if( visited[i] == false ){
			
			int j = i;
			
			do{
				current_cycle.push_back(j);
				visited[j] = true;
				j = t[j];
			}
			while( visited[j] == false );
			
			res.push_back( current_cycle );
			current_cycle.clear();
		}
	}
	
	
	delete [] visited;
	
	
	
	
	
	return res;
}


/* k-th power of permutation t, in O(n) time */
int * k_th_permutation_power(int *t, int n, LL k){
	
	int *res = new int [n];
	
	
	
	int * IDsOfCycles = IDs_of_cycles(t, n);
	/*
	std::cout << "\nNumbers of cycles:\n";
	REP(i,0,n-1){
		std::cout << numbersOfCycles[i] << " ";
	}
	std::cout << std::endl;
	*/
	
	
	int * positionsInCycles = positions_in_cycles(t, n);
	/*
	std::cout << "\nPositions in cycles:\n";
	REP(i,0,n-1){
		std::cout << positionsInCycles[i] << " ";
	}
	std::cout << std::endl;
	*/
	
	
	
	VVI Cycles = cycles(t, n);
	/*std::cout << "\nCycles:\n";
	REP(i,0,Cycles.size()-1){
		std::cout << "Cycle nr " << i << ": ";
		REP(j,0,Cycles[i].size()-1){
			std::cout << Cycles[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
	
	
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
	
	
	delete [] IDsOfCycles;
	delete [] positionsInCycles;
	Cycles.clear();
	
	
	return res;
}


int main(){
	
	/* Read data from standard input - permutation of {1..n} set */
	std::cin >> n >> k;
	REP(i,0,n-1){
		std::cin >> t[i];
		--t[i];
	}
	
	
	/* Compute result -> k-th permutation's power of {1..n} set */
	int *res = k_th_permutation_power( t, n, k );
	
	
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
