#include<iostream> // AC
using namespace std;
int main()
{
    int t; 
    cin>>t;
    int n; 
    for(int y=0; y<t; y++)
    {
    cin>>n;
    int tab[n];
    for(int i=0; i<n; i++)
    {
            cin>>tab[i];
    }
    for(int k=0; k<n; k++)
    {
            if(k%2==1)
            {
                      cout<<tab[k]<<" ";
            }
    }
    for(int q=0; q<n; q++)
    {
            if(q%2==0)
            {
                      cout<<tab[q]<<" ";
            }
    }
    cout<<endl;
    }
    //getchar();
    //system("pause");
    return 0;
}
            

