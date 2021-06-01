#include<cstdio> // AC
#include<list> // u¿ycie listy

using namespace std;

int main()
{
	list <int> L;
	
	list <int> :: iterator it;
	
	int n, d;
	
	scanf("%d", &d);
	
	while( d > 0 )
	{
		scanf("%d", &n);
	
		L.push_front(n);
		
		n--;
		
		while( n > 0 )
		{	
			L.push_front( L.back() );
			
			L.pop_back();
			
			L.push_front(n);
			
			n--;
		}
		
		for(it=L.begin(); it!=L.end(); it++)
		{
			printf("%d ", *it);
		}
		printf("\n");
		
		L.clear();
		
		d--;
	}
	
	return 0;
}
