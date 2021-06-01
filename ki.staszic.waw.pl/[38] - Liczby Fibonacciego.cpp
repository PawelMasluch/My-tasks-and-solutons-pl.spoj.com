#include<iostream> // 100 pkt
#include<string>

using namespace std;

string dodaj(string &a, string &b) // dodanie 2 liczb dodatnich (cyfry(a)>=cyfry(b))
{
	string wyn="";
	int i,ra=a.size(),rb=b.size(),p=0,temp;
	for(i=ra-1; i>=ra-rb; i--)
	{
		temp=(int)(a[i])+(int)(b[i-ra+rb])+p-96;
		p=temp/10;
		wyn=(char)(48+(temp%10))+wyn;
	}
	for(i=ra-rb-1; i>=0; i--)
	{
		temp=(int)(a[i])+p-48;
		p=temp/10;
		wyn=(char)(48+(temp%10))+wyn;
	}
	if(p==1)
	{
		wyn="1"+wyn;
	}
	return wyn;
}

string dodaj1(string &a, string &b) // dodanie 2 dowolnych liczb dodatnich
{
	int ra=a.size(),rb=b.size();
	if(ra>=rb)
	{
		return dodaj(a,b);
	}
	return dodaj(b,a);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n,i;
	
	cin>>n;
	
	string f0 = "0", f1 = "1", f2;
	
	if(n==0)
	{
		cout<<f0<<endl;
		return 0;
	}
	
	if(n==1)
	{
		cout<<f1<<endl;
		return 0;
	}
	
	for(i=2; i<=n; i++)
	{
		f2 = dodaj1(f0,f1);
		f0 = f1;
		f1 = f2;
	}
	
	cout<<f2<<endl;
	
	return 0;
	
}

