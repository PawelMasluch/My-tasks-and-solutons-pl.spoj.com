#include<iostream> // AC
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x=0;
    int s;
    for(int i=0; i<t; i++)
    {
    cin>>s;
    while(s!=1)
    {
               if(s%2==1)
               {
                         s=(3*s)+1;
                         x++;
               }
               else
               {
                   s=s/2;
                   x++;
               }
    }
    cout<<x<<endl;
    x=0;
    }
    //getchar();
    //system("pause");
    return 0;
}

