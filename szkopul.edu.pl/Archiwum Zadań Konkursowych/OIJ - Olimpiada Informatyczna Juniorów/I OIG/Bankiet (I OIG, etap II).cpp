#include<iostream> // 100 pkt
using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 30000;


int repr[MAX_N+1], howMany[MAX_N+1];
int N;
int res;


int find(int x){
	
	int result = x;
	
	while( repr[result] != result ){
		result = repr[result];
	}
	
	repr[x] = result;
	
	return result;
}


void Union(int x, int y){
	
	int repr_x = find(x);
	int repr_y = find(y);
	
	if( howMany[repr_x] >= howMany[repr_y] ){
		
		howMany[ repr_x ] += howMany[ repr_y ];
		repr[ repr_y ] = repr_x;
	}
	else{
		
		howMany[ repr_y ] += howMany[ repr_x ];
		repr[ repr_x ] = repr_y;
	}
}


int main(){
	
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	res = N;
	
	REP(i,1,N){
		repr[i] = i;
		howMany[i] = 1;
	}
	
	int nr;
	REP(i,1,N){
		cin >> nr;
		
		if( find(nr) != find(i) ){
			Union( nr, i );
			--res;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
