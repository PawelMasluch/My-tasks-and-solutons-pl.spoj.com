#include<iostream> // 100 pkt
using namespace std;
typedef long long ll;
struct pt
{
       ll x;
       ll y;
};
inline ll f(ll x)
{
       return (x>0) ? x : -x ; 
}
ll NWD(ll a, ll b)
{
          ll temp;
          while(b)
          {
                  temp=a%b;
                  a=b;
                  b=temp;
          }
          return a;
}
ll wyn(pt A, pt B)
{
          ll dx=f(A.x-B.x);
          ll dy=f(A.y-B.y);   
          return NWD(dx,dy);     
}
int main()
{
    pt A,B,C;
    ll P,BB=0;
    //ll x1,y1,x2,y2,x3,y3,P;
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
    A.x+=1000000000;
    B.x+=1000000000;
    C.x+=1000000000;
    A.y+=1000000000;
    B.y+=1000000000;
    C.y+=1000000000;
    P=f(((C.x-A.x)*(B.y-A.y))-((C.y-A.y)*(B.x-A.x)))/2;
    BB+=wyn(A,B);
    BB+=wyn(A,C);
    BB+=wyn(B,C);
    cout<<BB<<endl<<P+1-(BB/2)<<endl;
    //system("pause");
    return 0;
}
