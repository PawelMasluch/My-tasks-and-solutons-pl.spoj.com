//#include<bits/stdc++.h>
#include<cstdio> // 99/100 pkt;  zaliczylem wszystkie testy
#include<vector>




using namespace std;




#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define MP make_pair

#define value first

#define howMany second





typedef pair < int, int > PII;

typedef vector < PII > VPII;

typedef vector < int > VI;






class Node{
	
	private:
		VPII histogram; // vector of pairs (element, number of occurences of this element)
		
	public:
		Node() {}
		
		~Node(){
			this -> histogram.clear();	
		}
		
		Node(const Node &otherNode){
			
			this -> histogram.clear();
			
			int n = otherNode.histogram.size();
			
			REP(i,0,n-1){
				this -> histogram.PB( otherNode.histogram[i] );
			}
		}
		
		int getSize(){
			return this -> histogram.size();
		}
		
		PII getHistogram(int i){
			return this -> histogram[i];
		}
		
		
		// only for leafs in a range tree!!!
		void insert(PII p){
			this -> histogram.PB( p );
		}
		
		
		// only for internal nodes in a range tree!!!
		static void merge(Node &result, Node &u, Node &v){
			
			int Nu = u.histogram.size();
			int Nv = v.histogram.size();
			
			int uIndex = 0, vIndex = 0;
			
			while( uIndex < Nu  &&  vIndex < Nv ){
				if( u.histogram[uIndex].value < v.histogram[vIndex].value ){
					result.histogram.PB( u.histogram[uIndex] );
					++uIndex;
				}
				else{
					if( v.histogram[vIndex].value < u.histogram[uIndex].value ){
						result.histogram.PB( v.histogram[vIndex] );
						++vIndex;
					}
					else{ // equality case
						result.histogram.PB(   MP( u.histogram[uIndex].value, u.histogram[uIndex].howMany + v.histogram[vIndex].howMany )   );
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
		
		
		
		// only for internal nodes in a range tree!!!
		void makePrefixSums(){
			int n = this -> histogram.size();
			
			REP(i,1,n-1){
				this -> histogram[i].howMany += this -> histogram[i-1].howMany;
			}
		}
		
};


// Full binary tree (nodes are numbered from 1 to 2*n-1)
class RangeTree{
	
	
	private:
		int n; // number of leafs (all the tree has 2*n-1 nodes)
		Node *t; // range tree, hidden in a table of nodes
		
		VI V; // a vector useful for base ranges partition 
		
		// minimal power of 2 >= x
		int f(int x){
			
			int result = 1;
			
			while( result < x ){
				result *= 2;
			}
	
			return result;
		}
		
		
		// We find a partition of a range [L,R] (using a wider range [a,b]), starting from a node nr v
		void baseRanges(int v, int L, int R, int a, int b)
		{
			if( L == a  &&  R == b )
			{
				V.PB(v);
				
				return;
			}
			
			int med = ( a + b ) / 2;
			
			if( R <= med )
			{
				baseRanges( 2 * v, L, R, a, med );
			}
			else
			{
				if( L > med )
				{
					baseRanges( 2 * v + 1, L, R, med + 1, b );
				}
				else
				{
					baseRanges( 2 * v, L, med, a, med );
					
					baseRanges( 2 * v + 1, med + 1, R, med + 1, b );
				}
			}
		}
		
		
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
				return 0; // no elements less than x
			}
			else{
				return this -> t[nodeNr].getHistogram(result).howMany;
			}
		}
		
		
		int howManyLess(int x){
			int nV = this -> V.size();
			
			int result = 0;
			
			REP(i,0,nV-1){
				result += howManyLessInNode(this -> V[i], x);
			}
			
			return result;
			
		}
		
	
	
	
	
	public:
		RangeTree(){
			n = 0;
			t = NULL;
		}
		
		~RangeTree(){
			delete [] t;
		}
		
		void prepareTree(){
			
			int N; // a length of a sequence of numbers
			scanf( "%d", &N ); // 1 <= N <= 250000
			
			this -> n = f(N);
			this -> t = new Node [2*n];
			
			int a;
			
			REP(i,0,N-1){
				scanf( "%d", &a );
				
				this -> t[n+i].insert( MP(a,1) );
			}
			
			FORD(i,n-1,1){
				Node::merge( this -> t[i], this -> t[2*i], this -> t[2*i+1] );
			}
			
			FORD(i,n-1,1){
				this -> t[i].makePrefixSums(); 
			}
		}
		
		void serveQueries(){
			int Q; // number of queries;  1 <= Q <= 15000
			scanf( "%d", &Q );
			
			while( Q > 0 ){
				
				KthPositionalStatistic();
				
				--Q;
			}
		}
		
		void KthPositionalStatistic(){
			
			int S, E, K;
			scanf( "%d %d %d", &S, &E, &K );
			--S;    --E;
			
			
			
			baseRanges(1,S,E,0,n-1);
			
			
			int start = 0, end = 1000000000, med;
			
			while( start <= end ){
				med = (start + end) / 2;
				
				if( howManyLess(med) < K ){
					if( howManyLess(med+1) >= K ){
						
						this -> V.clear();
						printf( "%d\n", med );
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
	
};


void solve(){
	
	RangeTree T; // create an instance of helpful data structure
	
	T.prepareTree(); // prepare a data structure
	
	T.serveQueries(); // serve queries
}


int main(){
	
	solve();
	
	return 0;
}
