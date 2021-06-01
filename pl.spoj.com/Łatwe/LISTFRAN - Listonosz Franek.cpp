#include<cstdio> // AC
#include<new>
#include<vector>
#include<stack>

using namespace std;

struct edge
{
	int a, b;
};

int max(int a, int b)
{
	return (a>b) ? a : b ;
}

bool czy_spojny(vector <int> *G, int *rozm, int n)
{
	stack <int> S;
	
	int i, u;
	
	bool *odw = new bool [n];
	
	for(i=0; i<=n-1; ++i)
	{
		odw[i] = false;
	}
	
	S.push(0);
	
	odw[0] = true;
	
	while( !S.empty() )
	{
		u = S.top();
		
		S.pop();
		
		for(i=0; i<=rozm[u]-1; ++i)
		{
			if( !odw[ G[u][i] ] )
			{
				S.push( G[u][i] );
				odw[ G[u][i] ] = true;
			}
		}
	}
	
	for(i=0; i<=n-1; ++i)
	{
		if( !odw[i] )
		{
			delete [] odw;
			
			return false;
		}
	}
	
	delete [] odw;
	
	return true;
}

bool parzyste_stopnie(int *rozm, int n) // czy ka¿dy wierzcho³ek ma parzysty stopieñ (wiemy, ¿e graf jest spójny)
{
	int i;
	
	for(i=0; i<=n-1; ++i)
	{
		if( rozm[i] % 2 == 1 )
		{
			return false;
		}
	}
	
	return true;
}

bool f(vector <int> *G, int *rozm, int n) // czy w grafie istnieje cykl Eulera
{
	if( czy_spojny(G,rozm,n) == false ) // jesli niespójny
	{
		return false;
	}
	
	if( parzyste_stopnie(rozm,n) == false ) // jesli istnieje wierzcho³ek o nieparzystym stopniu
	{
		return false;
	}
	
	return true;
}

void czy_istnieje_cykl_Eulera(vector <int> *G, int *rozm, int n)
{
	if( f(G,rozm,n) == true )
	{
		printf("TAK\n");
	}
	else
	{
		printf("NIE\n");
	}
}

int main()
{
	edge *T;
	
	int n = 0, m, p, i, *rozm, a, b;
	
	scanf("%d%d", &m, &p);
	
	T = new edge [m];
	
	for(i=0; i<=m-1; ++i)
	{
		scanf("%d%d", &T[i].a, &T[i].b);
		
		n = max( n, max( T[i].a, T[i].b ) );
	}
	
	rozm = new int [n];
	
	for(i=0; i<=n-1; ++i)
	{
		rozm[i] = 0;
	}
	
	vector <int> *G = new vector <int> [n];
	
	for(i=0; i<=m-1; ++i)
	{	
		--T[i].a;
		--T[i].b;
		
		G[ T[i].a ].push_back( T[i].b );
		++rozm[ T[i].a ];
		
		G[ T[i].b ].push_back( T[i].a );
		++rozm[ T[i].b ];
	}
	
	delete [] T;
	
	czy_istnieje_cykl_Eulera(G,rozm,n);
	
	for(i=0; i<=n-1; ++i)
	{
		G[i].clear();
	}
	delete [] G;
	
	delete [] rozm;
	
	return 0;
}
