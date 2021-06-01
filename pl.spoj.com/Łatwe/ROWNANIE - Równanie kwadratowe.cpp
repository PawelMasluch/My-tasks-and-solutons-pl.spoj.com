#include<iostream> // AC
using namespace std;
int main()
{
    float a,b,c;
    while(cin>>a>>b>>c)
    {
                       if(b*b>4*a*c)
                       {
                                    cout<<"2"<<endl;
                       }
                       else
                       {
                            if(b*b==4*a*c)
                       {
                                    cout<<"1"<<endl;
                       }
                       else
                       {
                            if(b*b<4*a*c)
                       {
                                    cout<<"0"<<endl;
                       }
                       }
                       }
    }
    getchar();
    //system("pause");
    return 0;
}
                           
                       

