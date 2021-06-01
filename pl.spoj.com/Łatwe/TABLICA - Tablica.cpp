#include<cstdio> // AC
#include<stack>

using namespace std;

int main()
{
	stack <int> S;
	
	int x;
	
	while( scanf("%d", &x)  !=  EOF )
	{
		S.push(x);
	}
	
	while( !S.empty() )
	{
		printf("%d ", S.top() );
		S.pop();
	}
	printf("\n");
	
	return 0;
}
