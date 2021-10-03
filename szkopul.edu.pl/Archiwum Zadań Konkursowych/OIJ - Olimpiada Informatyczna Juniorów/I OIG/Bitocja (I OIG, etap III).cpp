// A solution using Dijkstra algorithm.

#include<cstdio> // 40/100 pkt
#include<queue>
#include<vector>


using namespace std;


typedef pair <int, int> PII;
typedef vector < PII > VPII;
typedef priority_queue < PII > PQ_PII;


// Loop definition.
#define REP(i,a,b) for(int i=a; i<=b; ++i)

// Vector definitions.
#define PB push_back
#define pb pop_back
#define S size

// Pair definition.
#define MP make_pair

// Graph structure definitions.
#define edge_cost first
#define target_vertex second

// Priority queue definitions.
#define E empty
#define P push
#define p pop
#define T top
#define min_total_cost first
#define min_total_cost_vertex second


// Maximum graph's number of vertices.
const int MAX_N = 100;

// Definition of +Infinity.
const int INF = -1;


// Graph structure.
// G[u] = (w, v), where:
// u - edge's source vertex
// v - edge's target vertex
// w - edge weight
VPII G[MAX_N];

bool was_vertex_considered_before[MAX_N];
int shortest_path[MAX_N];

int n; // (Constant) number of graph's vertices.
int k; // Number of initial graph's edges.
int m; // Number of potential new edges of graph.


// This function returns a minimal cost 
// of path from given start vertex 
// to given end vertex 
// via Dijkstra algorithm.
// Both variables start_vertex and end_vertex
// are from range [1,n],
// where n - number of graph's vertices. 
int Dijkstra(int start_vertex, int end_vertex){
	
	--start_vertex;
	--end_vertex;
	
	REP(u,0,n-1){
		was_vertex_considered_before[u] = false;
		shortest_path[u] = INF;
	}
	shortest_path[start_vertex] = 0;
	
	// Function's result - initially +Infinity.
	int min_cost = INF;
	
	int u, v, w;
	int r;
	
	PQ_PII PQ;
	PQ.P( MP( -shortest_path[start_vertex], start_vertex ) );
	
	while( !PQ.E() ){
		u = PQ.T().min_total_cost_vertex;
		
		PQ.p();
				
		if( was_vertex_considered_before[u] == false ){
			
			r = G[u].S();
			
			REP(i,0,r-1){
				v = G[u][i].target_vertex;
				w = G[u][i].edge_cost;
				
				if( (shortest_path[u] != INF  &&  
					 shortest_path[v] == INF) || 
				
					(shortest_path[u] + w < shortest_path[v]  && 
					 shortest_path[u] != INF  &&
					 shortest_path[v] != INF) ){
					
					
					shortest_path[v] = shortest_path[u] + w;
					
					PQ.P( MP( -shortest_path[v], v ) );
				}
			}
			
			was_vertex_considered_before[u] == true;
		}
	}
	
	min_cost = shortest_path[end_vertex];
	return min_cost;
} 


int main(){
	
	scanf( "%d %d %d", &n, &k, &m );
	
	// u - Current graph edge's source vertex.
	// v - Current graph edge's target vertex.
	// w - Current graph edge's weight.
	int u, v, w;
	REP(i,1,k){ // Input of initial graph's each edge.
		
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;	--v;
		
		G[u].PB( MP(w, v) );
		G[v].PB( MP(w, u) );
	}
	
	// Initially.
	int global_min_cost_from_vertex_1_to_n = Dijkstra(1, n);
	
	int current_min_cost_from_vertex_1_to_n;
	
	// Considering possible new edges to graph.
	REP(i,1,m){
		
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;	--v;
		
		G[u].PB( MP(w, v) );
		G[v].PB( MP(w, u) );
		
		current_min_cost_from_vertex_1_to_n = Dijkstra(1, n);
		
		if( (global_min_cost_from_vertex_1_to_n == INF  &&  
			 current_min_cost_from_vertex_1_to_n != INF)  || 
			 
			(current_min_cost_from_vertex_1_to_n < global_min_cost_from_vertex_1_to_n  &&  
			 current_min_cost_from_vertex_1_to_n != INF  &&  
			 global_min_cost_from_vertex_1_to_n != INF) ){
			
			printf( "1\n" );
			
			global_min_cost_from_vertex_1_to_n = current_min_cost_from_vertex_1_to_n;
		}
		else{
			
			printf( "0\n" );
			
			G[u].pb();
			G[v].pb();
		}
	}
	
	return 0;
}
