#include<iostream> // 100 pkt
#include<string>
using namespace std;
int main()
{
    string a,b,c;
    cin>>a>>b;
    int A=a.size(),B=b.size(),i,rest=0,sum=0;
    if(A>B)
    {
           for(i=0; i<A-B; i++)
           {
                   b="0"+b;
           }
    }
    else
    {
           for(i=0; i<B-A; i++)
           {
                   a="0"+a;
           }
    }
    A=max(A,B);
    B=A;
    for(i=A-1; i>=0; i--)
    {
                       sum=sum+(int)(a[i])+(int)(b[i])-96;
                       rest=sum%10;
                       c=(char)(rest+48)+c;
                       sum/=10;
                       rest=0;
    }
    if(sum>0)
    {
             c=(char)(sum+48)+c;
    }
    cout<<c<<endl;
    //system("pause");
    return 0;
}
