#include<iostream> // 100 pkt
#include<cmath>
using namespace std;
int main()
{
	long long R,i,wyn;
	cin>>R;
	wyn=(4*R)+1;
	for(i=1; i<R; i++)
	{
		wyn+=(4*(long long)sqrt((R-i)*(R+i)));
	}
	cout<<wyn<<endl;
	return 0;
}