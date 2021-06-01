#include<string> // AC
#include<iostream>
using namespace std;
int main()
{
    int tab[26],TAB[26],i,j,n,rozm;
    for(i=0; i<26; i++)
    {
             tab[i]=0;
             TAB[i]=0;
    }
    string s;
    cin>>n;
    for(i=0; i<=n; i++)
    {
             getline(cin,s);
             rozm=s.size();
             for(j=0; j<rozm; j++)
             {
                      if((int)(s[j])>=97 && (int)(s[j])<=122)
                      {
                                         tab[(int)(s[j])-97]++;
                      }
                      else
                      {
                          if((int)(s[j])>=65 && (int)(s[j])<=90)
                          {
                                             TAB[(int)(s[j])-65]++;
                          }
                      }
             }
    }
    for(i=0; i<26; i++)
    {
             if(tab[i]>0)
             {
                         cout<<(char)(97+i)<<" "<<tab[i]<<endl;
             }
    }
    for(i=0; i<26; i++)
    {
             if(TAB[i]>0)
             {
                         cout<<(char)(65+i)<<" "<<TAB[i]<<endl;
             }
    }
    //system("pause");
    return 0;
}
