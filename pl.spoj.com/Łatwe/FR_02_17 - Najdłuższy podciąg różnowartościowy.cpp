#include<cstdio> // AC
#include<new>
//#include<iostream>

using namespace std;

int main()
{
    int n, i, *t, *ile = new int [1001], j, pocz, kon, wyn = 0, d, l;
    
    for(i=0; i<=1000; i++)
    {
         ile[i] = 0;
    }
    
    scanf("%d", &d);
    
    for(l=1; l<=d; l++)
    {
        
            scanf("%d", &n);
            
            t = new int [n];
            
            for(i=0; i<=n-1; i++)
            {
                 scanf("%d", &t[i]);
            }
            
            i = 0;
            j = i;
            
            while(i<=n-1)
            {
                         while(j<=n-1)
                         {
                                if(ile[t[j]] == 0)
                                {
                                             ile[t[j]]++;
                                             j++;
                                }
                                else
                                {
                                    break;
                                }
                         }
                         
                         if(wyn < j - i)
                         {
                             wyn = j - i;
                             pocz = i;
                             kon = j-1;
                         }
                         
                         ile[t[i]]--;
                         
                         i++;
            }
            
            printf("%d\n", wyn);
            
            for(i=pocz; i<=kon; i++)
            {
                 printf("%d ", t[i]);
            }
            printf("\n");
            
            wyn = 0;
            
            delete [] t;
    }
    
    //system("pause");
    return 0;
}

