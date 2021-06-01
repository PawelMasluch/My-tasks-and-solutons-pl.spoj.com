#include<iostream> // 95/100 pkt; program wywlaszcza sie na jednym tescie
#include<string>

using namespace std;

int porownaj(string &a, string &b) // por?wnanie 2 liczb dodatnich
{
	int ra=a.size(),rb=b.size(),i;
	if(ra>rb)
	{
		return 1;
	}
	if(rb>ra)
	{
		return 2;
	}
	for(i=0; i<=ra-1; i++)
	{
		if((int)(a[i])>(int)(b[i]))
		{
			return 1;
		}
		if((int)(a[i])<(int)(b[i]))
		{
			return 2;
		}
	}
	return 0;
}

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

string mnoz(string &a, int b) // a*b , gdzie b - jednocyfrowa
{
	string wyn="";
	if(b==0 || a=="0")
	{
		wyn="0"+wyn;
		return wyn;
	}
	else
	{
		int temp,i,p=0,ra=a.size();
		for(i=ra-1; i>=0; i--)
		{
			temp=(((int)(a[i])-48)*b)+p;
			wyn=(char)(48+(temp%10))+wyn;
			p=temp/10;
		}
		while(p>0)
		{
			wyn=(char)(48+(p%10))+wyn;
			p/=10;
		}
		return wyn;
	}
}

string mnoz1(string &a, string &b) // mno?enie 2 du?ych liczb
{
	string wyn="0",temp;
	int rb=b.size(),i,j,pom,ra=a.size();
	for(i=rb-1; i>=0; i--)
	{
		pom=(int)(b[i])-48;
		temp=mnoz(a,pom);
		for(j=1; j<=rb-1-i; j++)
		{
			temp=temp+"0";
		}
		wyn=dodaj1(wyn,temp);
	}
	temp.clear();
	return wyn;
}

string odejmij(string &a, string &b) //  (a>=b>=0)
{
	string wyn="";
	if(porownaj(a,b)==0)
	{
		wyn="0";
		return wyn;
	}
	int ra=a.size(),rb=b.size(),i,j;
	for(i=ra-1; i>=ra-rb; i--)
	{
		if((int)(a[i])<(int)(b[i-ra+rb]))
		{
			j=i-1;
			while(a[j]=='0')
			{
				a[j]='9';
				j--;
			}
			a[j]=(char)((int)(a[j])-1);
			wyn=(char)((int)(a[i])-(int)(b[i-ra+rb])+58)+wyn;
		}
		else
		{
			wyn=(char)((int)(a[i])-(int)(b[i-ra+rb])+48)+wyn;
		}
	}
	for(i=ra-rb-1; i>=0; i--)
	{
		wyn=a[i]+wyn;
	}
	i=0;
	while(wyn[i]=='0')
	{
		i++;
	}
	wyn.erase(wyn.begin(),wyn.begin()+i);
	return wyn;
}

string reszta(string &a, string &b) // a mod b ; a>=0, b>0
{	
	if(porownaj(a,b)==2)
	{
		return a;
	}
	
	int ra = a.size(), rb = b.size(), i, j, c = 9;
	
	string temp1 = a.substr(0,rb), wyjscie = mnoz(b,9), temp2;
	
	temp2 = wyjscie;
	
	i=rb-1;
	
	while(i<=ra-1)
	{
		if(porownaj(temp1,b)==2)
		{
			i++;
			
			if(i==ra)
			{
				j=0;
				
				while(temp1[j]=='0')
				{
					j++;
				}
				
				temp1.erase(temp1.begin(),temp1.begin()+j);
				
				wyjscie.clear();
				
				temp2.clear();
				
				return temp1;
			}
			
			temp1 = temp1 + a[i];
		}
		else
		{
			while(porownaj(temp1,temp2)==2)
			{
				temp2 = odejmij(temp2,b);
				c--;
			}
			
			temp1 = odejmij(temp1,temp2);
			
			c = 9;
			
			temp2 = wyjscie;
				
			i++;
			
			if(i==ra)
			{
				j=0;
				
				while(temp1[j]=='0')
				{
					j++;
				}
				
				temp1.erase(temp1.begin(),temp1.begin()+j);
				
				wyjscie.clear();
				
				temp2.clear();
				
				return temp1;
			}
			
			temp1 = temp1 + a[i];
		
		}
		
	}
	
	j=0;
	
	while(temp1[j]=='0')
	{
		j++;
	}
	
	temp1.erase(temp1.begin(),temp1.begin()+j);
	
	wyjscie.clear();
				
	temp2.clear();
	
	return temp1;
}

string NWD(string a, string b)
{
	string temp,zero="0";
	while(porownaj(b,zero)==1)
	{
		temp = reszta(a,b);
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	string a, b, jeden = "1", iloczyn, suma, gcd;
	
	cin>>a>>b;
	
	if(a == "1" || b == "1")
	{
		cout<<"ZADEN\n";
		return 0;
	}
	
	gcd = NWD(a,b);
	
	if(porownaj(gcd,jeden)==1)
	{
		cout<<"NIESKONCZONOSC\n";
		return 0;
	}
	
	iloczyn = mnoz1(a,b);
	suma = dodaj1(a,b);
	
	cout<<odejmij(iloczyn,suma)<<endl;
	
	return 0;
}
