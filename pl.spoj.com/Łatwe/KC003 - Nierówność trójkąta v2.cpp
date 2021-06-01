#include<iostream> // AC
using namespace std;
int main()
{
    float a,b,c;
    while(cin>>a>>b>>c)
    {
                       if(a>0 && b>0 && c>0)
                       {
                              if(a<b+c && b<a+c && c<a+b)
                              {
                                       cout<<"1"<<endl;
                              }
                              else
                              {
                                  cout<<"0"<<endl;
                              }
                       }
                       else
                       {
                           cout<<"0"<<endl;
                       }
    }
    getchar();
    //system("pause");
    return 0;
}

