#include<iostream> // AC
using namespace std;
int main()
{
    int t;
    cin>>t;
    unsigned long long int n,x,y;
    for(int r=0; r<t; r++)
    {
    cin>>n>>x>>y;
    for(unsigned long long int i=1; i<n; i++)
    {
                 if(i%x==0 && i%y!=0)
                 {
                           cout<<i<<" ";
                 }
    }
    cout<<endl;
    } 
    /*getchar();
    system("pause");*/
    return 0;
}

