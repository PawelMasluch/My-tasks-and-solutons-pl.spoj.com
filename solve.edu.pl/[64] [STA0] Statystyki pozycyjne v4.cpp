//#include<bits/stdc++.h>
#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>




using namespace std;




#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define MP make_pair

#define value first

#define howMany second

#define valueIndex second





typedef pair < int, int > PII;

typedef vector < PII > VPII;

typedef vector < int > VI;





// A class representing a node of a range tree
class Node{
	
	private:
		VPII histogram; // vector of pairs (element, number of occurences of this element in a sequence)
		
	
	public:
		
		// constructor
		Node() {}
		
		
		// destructor
		~Node(){
			this -> histogram.clear();	
		}
		
		// copy constructor
		Node(const Node &otherNode){
			
			this -> histogram.clear();
			
			int n = otherNode.histogram.size();
			
			REP(i,0,n-1){
				this -> histogram.PB( otherNode.histogram[i] );
			}
		}
		
		// get size of histogram 
		int getSize(){
			return this -> histogram.size();
		}
		
		
		// get the i-th element (pair of numbers) of histogram
		PII getHistogram(int i){
			return this -> histogram[i];
		}
		
		
		// insert a given pair into a node
		// only for leafs in a range tree!!!
		void insert(PII p){
			this -> histogram.PB( p );
		}
		
		
		// merge histograms from two nodes into a third one
		// only for internal nodes in a range tree!!!
		static void merge(Node &result, Node &u, Node &v){
			
			int Nu = u.histogram.size();
			int Nv = v.histogram.size();
			
			int uIndex = 0, vIndex = 0;
			
			
			while( uIndex < Nu  &&  vIndex < Nv ){
				
				if( u.histogram[uIndex].value < v.histogram[vIndex].value ){ // current value in histogram in node u < current value in histogram in node v
					result.histogram.PB( u.histogram[uIndex] );
					++uIndex;
				}
				else{
					if( v.histogram[vIndex].value < u.histogram[uIndex].value ){ // current value in histogram in node v < current value in histogram in node u
						result.histogram.PB( v.histogram[vIndex] );
						++vIndex;
					}
					else{ // current value in histogram in node u == current value in histogram in node v
						result.histogram.PB(   MP( u.histogram[uIndex].value, u.histogram[uIndex].howMany + v.histogram[vIndex].howMany )   ); // we sum the numbers of occurences
						++uIndex;
						++vIndex;
					}
				}
			}
			
			while( uIndex < Nu ){
				result.histogram.PB( u.histogram[uIndex] );
				++uIndex;
			}
			
			while( vIndex < Nv ){
				result.histogram.PB( v.histogram[vIndex] );
				++vIndex;
			}
		}
		
		// make prefix sums for a given node
		// only for internal nodes in a range tree!!!
		void makePrefixSums(){
			int n = this -> histogram.size();
			
			REP(i,1,n-1){
				this -> histogram[i].howMany += this -> histogram[i-1].howMany;
			}
		}
		
};


// Full binary tree (nodes are numbered from 1 to 2*n-1, up to down, left to right)
class RangeTree{
	
	
	private:
		int n; // number of leafs (all the tree has 2*n-1 nodes)
		Node *t; // range tree, hidden in a table of nodes
		
		VI valuesDictionary; // ValuesDictionary[x] = old value in sequeunce for new value x 
		
		VI V; // a vector useful for base ranges partition 
		
		
		// minimal power of 2 >= x
		int f(int x){
			
			int result = 1;
			
			while( result < x ){
				result *= 2;
			}
	
			return result;
		}
		
		
		// scale array (new values from 0) and create a dictionary (from new values to old values)
		void scaleArray(int *newValues, PII *oldValues, int N){
			sort( oldValues, oldValues + N );
			
			int currentNewValue = 0;
			
			newValues[ oldValues[0].valueIndex ] = currentNewValue;
			this -> valuesDictionary.PB( oldValues[0].value );
			
			REP(i,1,N-1){
				if( oldValues[i].value > oldValues[i-1].value ){
					++currentNewValue;
					this -> valuesDictionary.PB( oldValues[i].value );
				}
				
				newValues[ oldValues[i].valueIndex ] = currentNewValue;
			}
			
			
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
		
		
		// how many elements < x in a range tree's node nr nodeNr (using a binary search)
		int howManyLessInNode(int nodeNr, int x){
			
			int start = 0, end = this -> t[nodeNr].getSize() - 1, med, result = -1;
			
			while( start <= end ){
				med = (start + end) / 2;
				
				if( this -> t[nodeNr].getHistogram(med).value < x ){
					
					result = med;
					
					start = med + 1;
				}
				else{
					end = med - 1;
				}
			}
			
			if( result == -1 ){
				return 0; // no elements < x
			}
			else{
				return this -> t[nodeNr].getHistogram(result).howMany;
			}
		}
		
		
		// how many elements < x in all base ranges of our current query
		int howManyLess(int x){
			int nV = this -> V.size();
			
			int result = 0;
			
			REP(i,0,nV-1){
				result += howManyLessInNode(this -> V[i], x);
			}
			
			return result;
			
		}
		
		
		// lower bound for finding a k-th positional statistic
		int lowerBound(){
			
			int nV = V.size();
			int result = 1000000099;
			
			REP(i,0,nV-1){
				result = min( result, this -> t[ V[i] ].getHistogram(0).value ); // first elements of histograms have minimal values (in given histograms)
			}
			
			return result;
		}
		
		
		// upper bound for finding a k-th positional statistic
		int upperBound(){
			
			int nV = V.size();
			int result = 0;
			
			REP(i,0,nV-1){
				result = max( result, this -> t[ V[i] ].getHistogram( this -> t[ V[i] ].getSize() - 1 ).value ); // last elements of histograms have maximal values (in given histograms)
			}
			
			return result;
		}
		
		
		// serve a single query
		void KthPositionalStatistic(){
			
			// we find a K-th least value in an index range [S, E] of our sequence
			int S, E, K; // 1 <= K <= E - S + 1
			scanf( "%d %d %d", &S, &E, &K ); // 1 <= S <= Ei <= N (N is a length of our sequence)
			--S;    --E;
			
			
			// find base ranges for our range [S, E] (wider range is [0, n-1] and start vertex has nr 1)
			baseRanges( 1, S, E, 0, this -> n - 1 );
			
			
			
			// find a solution (using a binary search): a K-th least value in an index range [S, E] of our sequence
			
			int start = lowerBound(), end = upperBound(), med;
			
			while( start <= end ){
				med = (start + end) / 2;
				
				if( howManyLess(med) < K ){
					if( howManyLess(med+1) >= K ){
						
						this -> V.clear();
						printf( "%d\n", this -> valuesDictionary[med] );
						return;
					}
					else{
						start = med + 1;
					}
				}
				else{
					end = med - 1;
				}
			}
			
			this -> V.clear();
			printf( "-1\n" ); // no solution
			return;
			
		}
		
		
		// input data and prepare data structures
		void inputData(){
			
			int N; // a length of a sequence of numbers
			scanf( "%d", &N ); // 1 <= N <= 250000
			
			
			PII *oldValues = new PII [N];
			REP(i,0,N-1){
				scanf( "%d", &oldValues[i].value ); // 0 <= oldValues[i].value <= 10^9
				oldValues[i].valueIndex = i;
			}
			
			int *newValues = new int [N];
			
			// scale old values to new values and make a dictionary
			scaleArray( newValues, oldValues, N );
			
			
			
			this -> n = f(N);
			this -> t = new Node [2*n];
			
			// insert single pairs to range tree's leafs
			REP(i,0,N-1){
				
				this -> t[n+i].insert( MP(newValues[i],1) );
			}
			
			delete [] oldValues;
			delete [] newValues;
			
			// merge internal nodes' children to those internal nodes
			FORD(i,n-1,1){
				Node::merge( this -> t[i], this -> t[2*i], this -> t[2*i+1] );
			}
			
			// make prefix sums for histograms of internal nodes
			FORD(i,n-1,1){
				this -> t[i].makePrefixSums(); 
			}
		}
		
		
		// serve all the queries
		void serveQueries(){
			int Q; // number of queries;  1 <= Q <= 15000
			scanf( "%d", &Q );
			
			while( Q > 0 ){
				
				KthPositionalStatistic(); // serve a single query
				
				--Q;
			}
		}
	
	
	public:
		
		// construtor
		RangeTree(){
			this -> n = 0;
			this -> t = NULL;
		}
		
		
		// destructor
		~RangeTree(){
			delete [] this -> t;
			this -> valuesDictionary.clear();
			this -> V.clear();
		}
		
		
		// solve the problem
		void solve(){
			inputData(); // input data and prepare data structures
			serveQueries(); // serve queries
		}
};


int main(){
	
	RangeTree T; // declaration of a useful data structure
	T.solve(); // solve the problem
	
	return 0;
}
