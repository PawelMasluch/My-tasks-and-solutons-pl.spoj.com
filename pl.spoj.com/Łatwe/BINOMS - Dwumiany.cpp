#include<iostream> // AC
#include<vector>
using namespace std;
int main()
{
    vector <int> pn,exp;
    int n,k,i,j,rozm=0,temp,wynik=1,N,q,a=1;
    bool t[1001];
    for(i=2; i<=1000; i++)
    {
             t[i]=true;
    }
    for(i=2; i<=31; i++)
    {
             if(t[i]==true)
             {
                           for(j=i*i; j<=1000; j+=i)
                           {
                                      t[j]=false;
                           }
             }
    }
    for(i=2; i<=997; i++)
    {
             if(t[i]==true)
             {
                           pn.push_back(i);
                           rozm++;
             }
    }
    cin>>N;
    for(q=0; q<N; q++)
    {
    cin>>n>>k;
    if(n<k)
    {
           cout<<"0\n";
    }
    else
    {
        if(k==0 && n>=0)
        {
                cout<<"1\n";
        }
        else
        {
            for(i=0; i<rozm; i++)
            {
                     exp.push_back(0);
                     a=pn[i];
                     while(a<=n)
                     {
                                exp[i]+=(n/a);
                                a*=pn[i];
                     }
                     a=pn[i];
                     while(a<=k)
                     {
                                exp[i]-=(k/a);
                                a*=pn[i];
                     }
                     a=pn[i];
                     while(a<=n-k)
                     {
                                exp[i]-=((n-k)/a);
                                a*=pn[i];
                     }
            }
            
            /*for(i=0; i<rozm; i++)
            {
                     cout<<exp[i]<<" ";
            }
            cout<<endl;*/
            
            for(i=0; i<rozm; i++)
            {
                     for(j=0; j<exp[i]; j++)
                     {
                              wynik=wynik*pn[i];
                     }
            }
            cout<<wynik<<endl;
            wynik=1;
            exp.clear();
            }
        }
    }
    //system("pause");
    return 0;
}
