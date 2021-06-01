#include<iostream> // 100 pkt
using namespace std;
int main()
{
    int N,i,j,pom;
    cin>>N;
    for(i=1; i<=N; i++)
    {
             pom=i;
             for(j=1; j<=N; j++)
             {
                      cout<<pom<<" ";
                      pom+=i;
             }
             cout<<endl;
    }
    //system("pause");
    return 0;
}
