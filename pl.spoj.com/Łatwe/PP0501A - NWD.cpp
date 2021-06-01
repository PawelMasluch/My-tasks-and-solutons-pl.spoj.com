#include<iostream> // AC
using namespace std;
int NWD(int a, int b)
{
    while (a!=b)
    {
          if(a>b)
          a=a-b;
          else
          b=b-a;
    }
    return a;
}
int main()
{
    int a,b,n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
            cin>>a>>b;
            if(a==0 || b==0)
            {
                    cout<<"1"<<endl;
            }
            else
            {
            cout<<NWD(a,b)<<endl;
            }
    }
    getchar();
    //system("pause");
    return 0;
}
    
    

