#include<iostream> // 100 pkt

using namespace std;

int main()
{
	char a,b;
	cin>>a>>b;
	int wyn = (16*((int)(a)-48)) + (int)(b) - 48;
	if((int)(b) >= 65)
	{
		wyn -= 7;
	}
	
	cout<<wyn<<endl<<(char)(wyn)<<endl;
	
	return 0;
}