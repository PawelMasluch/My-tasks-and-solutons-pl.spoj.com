#include<iostream> // AC
using namespace std;
int main()
{
    int x,y,r,n;
    float x1,y1;
    cin>>x>>y>>r;
    cin>>n;
    for(int i=0; i<n; i++)
    {
            cin>>x1>>y1;
            if(((x-x1)*(x-x1))+((y-y1)*(y-y1))<(r*r))
            {
                                       cout<<"I"<<endl;
            }
            else
            {
                if(((x-x1)*(x-x1))+((y-y1)*(y-y1))==(r*r))
            {
                                       cout<<"E"<<endl;
            }
            else
            {
                if(((x-x1)*(x-x1))+((y-y1)*(y-y1))>(r*r))
            {
                                       cout<<"O"<<endl;
            }
            }
            }
    }         
    /*getchar();
    system("pause");*/
    return 0;
}

