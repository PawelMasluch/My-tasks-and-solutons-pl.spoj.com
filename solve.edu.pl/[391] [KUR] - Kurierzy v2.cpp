//#include<bits/stdc++.h>
#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>




using namespace std;




#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back





typedef vector < int > VI;





// A class representing a node of a range tree
class Node{
	
	private:
		int candidate; // candidate for a leader
		int howManyCandidate; // candidate's multiplicity (it can change during merging nodes)
	
	
	public:
		
		// constructor
		Node() {
			this -> candidate = 0; // initially, we have no candidate
			this -> howManyCandidate = 0; // initially, we have no candidate so the multiplicity is zero 
		}
		
		
		// destructor
		~Node() {}
		
		
		// copy constructor
		Node(const Node &otherNode){
			this -> candidate = otherNode.candidate;
			this -> howManyCandidate = otherNode.howManyCandidate;
		}
		
		
		// get candidate for a leader 
		int getCandidate(){
			return this -> candidate;
		}
		
		
		// get candidate's multiplicity
		int getHowManyCandidate(){
			return this -> howManyCandidate;
		}
		
		
		// set candidate for a leader 
		void setCandidate(int cand){
			this -> candidate = cand;
		}
		
		
		// set candidate's multiplicity
		void setHowManyCandidate(int howManyCand){
			this -> howManyCandidate = howManyCand;
		}
		
		
		// initialize a given node
		// only for leafs in a range tree!!!
		void setNode(int cand, int howManyCand){
			this -> setCandidate( cand );
			this -> setHowManyCandidate( howManyCand );
		}
		
		
		// merge two nodes into a third one (to compute a common candidate)
		// only for internal nodes in a range tree!!!
		static void merge(Node &result, Node &u, Node &v){
			
			if( u.candidate == v.candidate ){ // the same candidate
				result.setNode( u.candidate, u.howManyCandidate + v.howManyCandidate ); // a bigger multiplicity
			}
			else{
				
				if( u.howManyCandidate > v.howManyCandidate ){ // u is a common candidate
					result.setNode( u.candidate, u.howManyCandidate - v.howManyCandidate ); // we delete pairs of distinct candidates' elements
				}
				else{
					
					if( v.howManyCandidate > u.howManyCandidate ){ // v is a common candidate
						result.setNode( v.candidate, v.howManyCandidate - u.howManyCandidate ); // we delete pairs of distinct candidates' elements
					}
					else{ // no common candidate 
						
						// first zero: no common candidate 
						// second zero: we have zero copies of candidate because a common candidate doesn't exist
						result.setNode( 0, 0 );
					}
				}
			}
		}
		
};


// Full binary tree (nodes are numbered from 1 to 2*n-1, up to down, left to right)
class RangeTree{
	
	private:
		int n; // number of leafs (all the tree has 2*n-1 nodes)
		Node *t; // range tree, hidden in a table of nodes
		
		VI V; // a vector useful for base ranges partition 
		
		int N; // a length of a sequence of numbers; 1 <= N <= 500000
		int Q; // a number of queries; 1 <= Q <= 500000
		
		
		// minimal power of 2 >= x
		int f(int x){
			
			int result = 1;
			
			while( result < x ){
				result *= 2;
			}
	
			return result;
		}
		
		
		// We find a partition of a range [L,R] (using a wider base range [a,b]), starting from a node nr v
		void baseRanges(int v, int L, int R, int a, int b)
		{
			if( L == a  &&  R == b ) // if our range [L,R] is exactly a base range [a,b]
			{
				V.PB(v); // we save a vertex's number corresponding to a base range [a,b] 
				
				return; // we exit the function
			}
			
			int med = ( a + b ) / 2; // the end of a base range's left half
			
			if( R <= med ) // our range [L,R] is in the left half of a base range
			{
				baseRanges( 2 * v, L, R, a, med ); // recursive call for a base range's left half ( [a, med] )
			}
			else
			{
				if( L > med ) // our range [L,R] is in the right half of a base range
				{
					baseRanges( 2 * v + 1, L, R, med + 1, b ); // recursive call for a base range's right half ( [med+1, b] )
				}
				else
				{
					// we want a partition of a range [L, med] - recursive call for a base range's left half ( [a, med] )
					baseRanges( 2 * v, L, med, a, med );
					
					// we want a partition of a range [med+1, R] recursive call for a base range's right half ( [med+1, b] )
					baseRanges( 2 * v + 1, med + 1, R, med + 1, b );
				}
			}
		}
		
		
		// input data and prepare data structures
		void inputData(){
			
			scanf(   "%d", &( this -> N )   ); // a length of a sequence of numbers; 1 <= N <= 500000
			
			// creating a range tree, in memory
			this -> n = f(N);
			this -> t = new Node [2*n];
			
			
			
			scanf( "%d", &(this -> Q) ); // a number of queries; 1 <= Q <= 500000
			
			
			
			int a_i; // an element of sequence
			
			REP(i,0,N-1){
				
				scanf( "%d", &a_i ); // 1 <= a_i <= N
				
				this -> t[n+i].setNode( a_i, 1 ); // the i-th leaf of a range tree has a candidate a_i and multiplicity equal one	
			}
			
			
			// merge internal nodes' children to those internal nodes
			FORD(i,n-1,1){
				Node::merge( this -> t[i], this -> t[2*i], this -> t[2*i+1] );
			}
		}
		
		
		// find a candidate from a range [start,end] 
		int findCandidate(int start, int end){
			
			Node result;
			result.setNode( 0, 0 ); // initially, no candidate (1st zero) so the multiplicity is zero (2nd zero)
			
			baseRanges( 1, start, end, 0, n-1 ); // we make a partition of a range [start, end] as a subrange of [0, n-1] (we start a partition from a node nr 1)
			
			int nV = V.size(); // a number of nodes representing a partition of a range [start, end]
			
			REP(i,0,nV-1){ // for each node representing a base range
				Node::merge( result, result, this -> t[ V[i] ] ); // we merge a curent result with a next node
			}
			
			this -> V.clear();
			
			return result.getCandidate(); // we return a value of a candidate 
		}
		
		
		// serve all the queries
		void serveQueries(){
			
			/*
				Reminder.
				
				N - a length of a sequence of numbers; 1 <= N <= 500000
				Q - a number of queries; 1 <= Q <= 500000
			*/
			
			
			
			
			/* 
				1. Declaration of useful structures 
			*/
			
			int howManyElementAlready[N+1]; // how many of a given number's copies we have already met (at the beginning, howManyElementAlready[x] = 0 for x in 0..N) 
			
			int rangeStart[Q]; // rangeStart[i] - a range's begin of an i-th query 
			int rangeEnd[Q]; // rangeEnd[i] - a range's end of an i-th query
			int cand[Q]; // a candidate's value of an i-th query
			int howManyCandidateBeforeRangeStart[Q]; // how many occurences of a candidate (of an i-th query) was before a range's begin
			
			VI whichQueriesStart[N]; // for a given position i (in sequence) we remember which queries (we remember queries' IDs) begin from i-th position in sequence
			VI whichQueriesEnd[N]; // for a given position i (in sequence) we remember which queries (we remember queries' IDs) end on i-th position in sequence
			
			
			int answer[Q]; // answer[i] - i-th query's answer for i in 0..Q-1 (at the beginning, answer[i] = 0 - no leader assumed) 
			
			
			
			
			
			/*
				2. Initializing the structures
			*/
			
			
			// for each query
			REP(i,0,Q-1){
				scanf( "%d %d", &rangeStart[i], &rangeEnd[i] ); // we input a range for i-th query;  1 <= rangeStart[i] <= rangeEnd[i] <= N
				
				--rangeStart[i];    --rangeEnd[i]; // we subtract one because we want to have 0 <= rangeStart[i] <= rangeEnd[i] <= N-1
				
				whichQueriesStart[ rangeStart[i] ].PB( i ); // we add a new query to a set of queries beginning from the position i in our sequence
			    whichQueriesEnd[ rangeEnd[i] ].PB( i ); // we add a new query to a set of queries ending on the position i in our sequence
				
				cand[i] = findCandidate( rangeStart[i], rangeEnd[i] ); // find a candidate for an i-th query
				
				howManyCandidateBeforeRangeStart[i] = 0; // initially, no occurences of a candidate (of an i-th query) before a range's begin
				
				answer[i] = 0; // no leader
			}
			
			// for each possible value in our sequence
			REP(i,0,N){
				howManyElementAlready[i] = 0; // no occurence of element's value i in our sequence
			}
			
			
			
			
			
			
			/*
				3. Computing the answers	
			*/
			
			// for all positions in our sequence
			REP(i,0,N-1){
				
				// queries which start from the i-th position
				int r = whichQueriesStart[i].size();
				
				REP(j,0,r-1){
					int queryNr = whichQueriesStart[i][j];
					howManyCandidateBeforeRangeStart[ queryNr ] = howManyElementAlready[ cand[queryNr] ];
				}
				
				
				
				// update
				++howManyElementAlready[ this -> t[n+i].getCandidate() ];
				
				
				
				
				// queries which end on the i-th position
				r = whichQueriesEnd[i].size();
				
				REP(j,0,r-1){
					int queryNr = whichQueriesEnd[i][j];
					int howManyCandidateInRange = howManyElementAlready[ cand[queryNr] ] - howManyCandidateBeforeRangeStart[queryNr];
					int rangeLength = rangeEnd[ queryNr ] - rangeStart[ queryNr ] + 1;
					
					if( howManyCandidateInRange > rangeLength / 2 ){
						answer[queryNr] = cand[queryNr];
					}
					else{
						answer[queryNr] = 0; // no leader
					}
				}
			}
			
			
			
			
			/*
				4. Printing the answers
			*/
				
			REP(i,0,Q-1){
				printf( "%d\n", answer[i] );
			}
			
		}
	
	
	
	
	public:
		
		// constructor
		RangeTree(){
			this -> n = 0;
			this -> t = NULL;
			
			this -> N = 0;
			this -> Q = 0;
		}
		
		
		// destructor
		~RangeTree(){
			delete [] this -> t;
			this -> V.clear();
		}
		
		
		// solve the problem
		void solve(){
			inputData(); // input data and prepare data structures
			serveQueries(); // serve queries
		}
};


int main(){
	
	RangeTree T; // create an instance of helpful data structure
	T.solve(); // solve the problem
	
	return 0;
}
