#include<iostream> // AC
#include<string>
using namespace std;
int main()
{
    int rozm,i,j,suma3=0;
    string s;
    do
    {
           cin>>s;
           if(!(s.size()==1 && s[0]=='0'))
           {
             rozm=s.size();
             if(!((int)(s[rozm-1])==48 || (int)(s[rozm-1])==53))
             {
                                        cout<<"NIE\n";
             }
             else
             {
                 for(j=0; j<rozm; j++)
                 {
                          suma3+=(int)(s[j])-48;
                 }
                 if(suma3%3==0)
                 {
                               cout<<"TAK\n";
                 }
                 else
                 {
                     cout<<"NIE\n";
                 }
                 suma3=0;
             }
           }
    }
    while(!(s.size()==1 && s[0]=='0'));
    return 0;
}

