#include<iostream> // 100 pkt
#include<new>
#include<algorithm>

using namespace std;

struct elem
{
	int value;
	int ktora;
};

bool f(elem a, elem b)
{
	return (a.value < b.value);
}

int main()
{
	elem *t = new elem [3];
	
	int i;
	
	for(i=0; i<=2; i++)
	{
		cin >> t[i].value;
		
		t[i].ktora = i + 1;
	}
	
	sort(t,t+3,f);
	
	switch(t[1].ktora)
	{
		case 1:
			cout << "PIERWSZA\n";
			break;
			
		case 2:
			cout << "DRUGA\n";
			break;
			
		case 3:
			cout << "TRZECIA\n";
			break;
	}
	
	return 0;
}
