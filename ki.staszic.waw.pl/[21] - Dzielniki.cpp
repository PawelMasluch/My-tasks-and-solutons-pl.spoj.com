//n<=10^9
#include<iostream> // 100 pkt
using namespace std;
int main()
{
    int /*t,*/wynik=1,i,n,temp,wykladnik=0,j;
    //cin>>t;
    /*for(i=0; i<t; i++)
    {*/
             cin>>n;
             temp=n;
                 for(j=2; j*j<=n; j++)
                 {
                          while(temp%j==0)
                          {
                                       temp/=j;
                                       wykladnik++;
                          }
                          wynik*=(wykladnik+1);
                          wykladnik=0;
                 }
             if(temp>1)
             {
                       wynik*=2;
             }
             cout<<wynik<<endl;
             /*wynik=1;
    }
    system("pause");*/
    return 0;
}
