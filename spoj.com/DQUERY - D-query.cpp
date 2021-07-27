/*
	Program to compute number of unique elements in different sequence's ranges.
	
	Based on: https://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
*/

#include <bits/stdc++.h> // AC



using namespace std;



#define REP(i,n) for(int i=0; i<n; ++i)



// Maximum possible value in sequence.
const int MAX_A = 1000000;



// Variable to represent block size. This is made global
// so compare1() of sort can use it.
int block;



// howMany[x] - number of occurences of value "x" in a sequence
int howMany[MAX_A+1];



// Structure to represent a query range
struct Query{
    
	int L, R; // range [L,R] of sequence
    int ID; // query's ID
    int ans; // number of unique elements in [L,R] range
};



// Function used to sort all queries so that all queries
// of the same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare1(Query x, Query y){
    
	// Different blocks, sort by block.
    if (x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
 
    // Same block, sort by R value
    return x.R < y.R;
}



// Function used to sort all queries increasing by ID.
bool compare2(Query x, Query y){
    return x.ID < y.ID;
}



// Driver program
int main(){
	
	// A length of sequence.
	int n;
	scanf( "%d", &n );
	
	// A sequence.
	int a[n];
	REP(i,n){
		scanf( "%d", &a[i] );
	}
	
	// A number of queries.
	int m;
	scanf( "%d", &m );
	
	// Queries.
    Query q[m];
    REP(i,m){
    	scanf( "%d %d", &q[i].L, &q[i].R );
    	--q[i].L;		--q[i].R;
    	q[i].ID = i;
	}
    
    // Find block size.
    block = (int)sqrt(n);
 
    // Sort all queries so that queries of same blocks
    // are arranged together.
    sort(q, q + m, compare1);
 
    // Initialize current L, current R and current number of unique elements.
    int currL = 0, currR = 0;
    int currUnique = 0;
 
    // Traverse through all queries
    REP(i,m){
        
		// L and R values of current range
        int L = q[i].L, R = q[i].R;
 
        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L){
        	
        	--howMany[ a[currL] ];
            
			if( howMany[ a[currL] ] == 0 ){
            	--currUnique;
			}
			
            ++currL;
        }
 
        // Add Elements of current Range
        while (currL > L){
        	++howMany[ a[currL-1] ];
            
			if( howMany[ a[currL-1] ] == 1 ){
            	++currUnique;
			}
			
            --currL;
        }
        while (currR <= R){
        	++howMany[ a[currR] ];
            
			if( howMany[ a[currR] ] == 1 ){
            	++currUnique;
			}
            ++currR;
        }
 
        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1){
        	
        	--howMany[ a[currR-1] ];
            
			if( howMany[ a[currR-1] ] == 0 ){
            	--currUnique;
			}
			
            --currR;
        }
 
        q[i].ans = currUnique;
    }
    
    // Sort all queries increasingly by ID.
    sort(q, q + m, compare2);
    
    // Printing answers
    REP(i,m){
    	printf( "%d\n", q[i].ans );
	}
    
    return 0;
}
