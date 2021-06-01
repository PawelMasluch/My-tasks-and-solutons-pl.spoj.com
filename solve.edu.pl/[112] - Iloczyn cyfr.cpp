#include<iostream> // 100 pkt
using namespace std;
int main()
{
	long long n;
	cin>>n;
	if(n<=1)
	{
		cout<<n<<endl;
	}
	else
	{
		int ile2=0,ile3=0,ile5=0,ile7=0,i,temp;
		while(n%2==0)
		{
			ile2++;
			n/=2;
		}
		while(n%3==0)
		{
			ile3++;
			n/=3;
		}
		while(n%5==0)
		{
			ile5++;
			n/=5;
		}
		while(n%7==0)
		{
			ile7++;
			n/=7;
		}
		if(n>=11)
		{
			cout<<"NIE\n";
		}
		else
		{
			string s;
			
			
			for(i=1; i<=(ile3/2); i++)
			{
				s="9"+s;
			}
			ile3%=2;
			//cout<<"ile3 wynosi teraz "<<ile3<<endl;
			
			
			for(i=1; i<=(ile2/3); i++)
			{
				s="8"+s;
			}
			ile2%=3;
			//cout<<"ile2 wynosi teraz "<<ile2<<endl;
			
			
			for(i=1; i<=ile7; i++)
			{
				s="7"+s;
			}
			//ile7=0;
			//cout<<"ile7 wynosi teraz "<<ile7<<endl;
			
			
			for(i=1; i<=min(ile2,ile3); i++)
			{
				s="6"+s;
			}
			temp=ile2;
			ile2-=min(ile2,ile3);
			//cout<<"ile2 wynosi teraz "<<ile2<<endl;
			ile3-=min(temp,ile3);
			//cout<<"ile3 wynosi teraz "<<ile3<<endl;
			
			for(i=1; i<=ile5; i++)
			{
				s="5"+s;
			}
			//ile5=0;
			//cout<<"ile5 wynosi teraz "<<ile5<<endl;
			
			for(i=1; i<=(ile2/2); i++)
			{
				s="4"+s;
			}
			ile2%=2;
			//cout<<"ile2 wynosi teraz "<<ile2<<endl;
			
			for(i=1; i<=ile3; i++)
			{
				s="3"+s;
			}
			//ile3=0;
			//cout<<"ile3 wynosi teraz "<<ile3<<endl;
			
			for(i=1; i<=ile2; i++)
			{
				s="2"+s;
			}
			//ile2=0;
			//cout<<"ile2 wynosi teraz "<<ile2<<endl;
			
			
			cout<<s<<endl;
		}
	}
	return 0;
}
