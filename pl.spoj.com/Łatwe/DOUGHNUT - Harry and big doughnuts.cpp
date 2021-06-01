#include<iostream> // AC
using namespace std;
int main()
{
    int c,k,w,t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
    cin>>c>>k>>w;
    if(c*w<=k)
    {
              cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    }
    getchar();
    //system("pause");
    return 0;
}

