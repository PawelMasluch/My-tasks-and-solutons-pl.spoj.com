#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	
	cin>>s;
	
	int rok,wyn;
	
	cin>>rok;
	
	wyn = (int)(s[8]) - 48;
	
	wyn *= 2;
	
	wyn += 5;
	
	wyn *= 50;
	
	wyn += 1764;
	
	wyn -= rok;
	
	cout << wyn << endl;
	
	return 0;
}