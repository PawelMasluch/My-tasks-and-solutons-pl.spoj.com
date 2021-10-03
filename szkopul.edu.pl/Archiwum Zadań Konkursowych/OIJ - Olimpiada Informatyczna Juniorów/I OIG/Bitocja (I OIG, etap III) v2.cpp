// A solution using Floyd-Warshall algorithm.

#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


// Loop definition.
#define REP(i,a,b) for(int i=a; i<=b; ++i)


// Maximum graph's number of vertices.
const int MAX_N = 100;

// Definition of +Infinity.
const int INF = 1000000099;


// Shortest paths' table.
// shortest_path[u][v] = w, where:
// u - edge's source vertex
// v - edge's target vertex
// w - value of minimal cost path from u to v
int shortest_path[MAX_N][MAX_N];

int n; // (Constant) number of graph's vertices.
int k; // Number of initial graph's edges.
int m; // Number of potential new edges of graph.


// This function computes minimal paths' costs
// from arbitrary start vertex u
// to arbitrary end vertex v
// via Floyd-Warshall algorithm.

// n - number of graph's vertices. 
void Floyd_Warshall(){
	
	REP(k,0,n-1){
		REP(u,0,n-1){
			REP(v,0,n-1){
				
				if( shortest_path[u][k] + shortest_path[k][v] < shortest_path[u][v] ){
					 	
					shortest_path[u][v] = shortest_path[u][k] + shortest_path[k][v];
				}
			}
		}
	}
}


int main(){
	
	scanf( "%d %d %d", &n, &k, &m );
	
	// Initializing the shortest paths' table.
	REP(u,0,n-1){
		
		REP(v,0,n-1){
			shortest_path[u][v] = INF;
		}
		shortest_path[u][u] = 0;
	}
	
	// u - Current graph edge's source vertex.
	// v - Current graph edge's target vertex.
	// w - Current graph edge's weight.
	int u, v, w;
	REP(i,1,k){ // Input of initial graph's each edge.
		
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;	--v;
		
		shortest_path[u][v] = shortest_path[v][u] = min( shortest_path[u][v], w );
	}
	
	// Computing values of minimal paths costs
	// for all pairs of start vertex u 
	// and end vertex v.
	Floyd_Warshall();
	
	// Considering possible new edges for graph.
	int possibility1, possibility2;
	REP(i,1,m){
		
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;	--v;
		
		possibility1 = shortest_path[0][u] + w + shortest_path[v][n-1]; // path: 0 ---> (u - v) -> n-1
		possibility2 = shortest_path[n-1][u] + w + shortest_path[v][0]; // path: n-1 -> (u - v) -> 0
		
		if( possibility1 < shortest_path[0][n-1]  ||
			possibility2 < shortest_path[0][n-1] ){
			
			printf( "1\n" );
			
			REP(start,0,n-1){
				REP(end,0,n-1){
					
					possibility1 = shortest_path[start][u] + w + shortest_path[v][end]; // path: start ---> (u - v) -> end
					possibility2 = shortest_path[end][u] + w + shortest_path[v][start]; // path:   end ---> (u - v) -> start
					
					if( possibility1 < shortest_path[start][end]  ||
						possibility2 < shortest_path[start][end] ){
						
						shortest_path[start][end] = min( possibility1, possibility2 );
					}
					
				}
			}
			
		}
		else{
			
			printf( "0\n" );
		}
	}
	
	return 0;
}
