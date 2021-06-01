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
		int candidate; // 
		int howManyCandidate; // 
	
	
	public:
		
		// constructor
		Node() {
			this -> candidate = 0; // 
			this -> howManyCandidate = 0; // 
		}
		
		
		// destructor
		~Node() {}
		
		
		// copy constructor
		Node(const Node &otherNode){
			this -> candidate = otherNode.candidate;
			this -> howManyCandidate = otherNode.howManyCandidate;
		}
		
		
		// get 
		int getCandidate(){
			return this -> candidate;
		}
		
		
		// get 
		int getHowManyCandidate(){
			return this -> howManyCandidate;
		}
		
		
		// set 
		void setCandidate(int cand){
			this -> candidate = cand;
		}
		
		
		// set 
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
			if( u.candidate == v.candidate ){
				result.setNode( u.candidate, u.howManyCandidate + v.howManyCandidate );
			}
			else{
				if( u.howManyCandidate > v.howManyCandidate ){
					result.setNode( u.candidate, u.howManyCandidate - v.howManyCandidate );
				}
				else{
					if( v.howManyCandidate > u.howManyCandidate ){
						result.setNode( v.candidate, v.howManyCandidate - u.howManyCandidate );
					}
					else{
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
			
			this -> n = f(N);
			this -> t = new Node [2*n];
			
			
			
			scanf( "%d", &(this -> Q) ); // a number of queries; 1 <= Q <= 500000
			
			
			
			int a_i;
			
			REP(i,0,N-1){
				scanf( "%d", &a_i ); // 1 <= a_i <= N
				
				this -> t[n+i].setNode( a_i, 1 );	
			}
			
			
			// merge internal nodes' children to those internal nodes
			FORD(i,n-1,1){
				Node::merge( this -> t[i], this -> t[2*i], this -> t[2*i+1] );
			}
		}
		
		
		// find a candidate from a range [start,end] 
		int findCandidate(int start, int end){
			
			Node result;
			result.setNode( 0, 0 ); // 
			
			baseRanges( 1, start, end, 0, n-1 ); // 
			
			int nV = V.size();
			
			REP(i,0,nV-1){
				Node::merge( result, result, this -> t[ V[i] ] );
			}
			
			this -> V.clear();
			
			return result.getCandidate();
		}
		
		
		// serve all the queries
		void serveQueries(){
			
			/* 
				1. Declaration of useful structures 
			*/
			
			int howManyElementAlready[N+1]; // how many of a given number's copies we have already met (at the beginning, howManyElementAlready[x] = 0 for x in 0..N) 
			
			int rangeStart[Q];
			int rangeEnd[Q];
			int cand[Q];
			int howManyCandidateBeforeRangeStart[Q];
			
			VI whichQueriesStart[N];
			VI whichQueriesEnd[N];
			
			
			int answer[Q]; // answer[i] - i-th query's answer for i in 0..Q-1 (at the beginning, answer[i] = 0 - no leader assumed) 
			
			
			
			
			
			/*
				2. Initializing the structures
			*/
			
			
			REP(i,0,Q-1){
				scanf( "%d %d", &rangeStart[i], &rangeEnd[i] );
				
				--rangeStart[i];    --rangeEnd[i];
				
				whichQueriesStart[ rangeStart[i] ].PB( i );
				
				whichQueriesEnd[ rangeEnd[i] ].PB( i );
				
				cand[i] = findCandidate( rangeStart[i], rangeEnd[i] );
				
				howManyCandidateBeforeRangeStart[i] = 0;
				
				answer[i] = 0; // no leader
			}
			
			REP(i,0,N){
				howManyElementAlready[i] = 0;
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
