#include<cstdio> // do sprawdzenia
#include<vector>
#include<new>
#include<queue>
//#include<iostream>

using namespace std;

int min(int a, int b)
{
    return (a<b) ? a : b ;
}

int main()
{   
    int n, m, i, j, *rozm, a, b, my_number, *skladowa, num = 0, *odl, u, Z, l;
    
    bool *odw;
    
    vector <int> *G;
    
    queue <int> Q;
    
    scanf("%d", &Z);
    
    for(l=1; l<=Z; ++l)
    {
    
            scanf("%d%d", &n, &m);
            
            odw = new bool [n];
               
            rozm = new int [n];
            
            skladowa = new int [n];
            
            odl = new int [n];
            
            for(i=0; i<=n-1; ++i)
            {
                 rozm[i] = 0;
                 
                 odw[i] = false;
                 
                 odl[i] = 1000001;
            }
            
            G = new vector <int> [n];
            
            for(i=1; i<=m; ++i)
            {
                 scanf("%d%d", &a, &b);
                 
                 G[a-1].push_back(b-1);
                 ++rozm[a-1];
                 
                 G[b-1].push_back(a-1);
                 ++rozm[b-1];
            }
            
            scanf("%d", &my_number);
            
            
            
            /*** 1. faza - tabelka spójnych składowych + ich ilość ***/
            
            
            
            
            for(j=0; j<=n-1; ++j)
            {
                     if( odw[j] == false )
                     {   
                               odw[j] = true;
                               
                               skladowa[j] = num;
                               
                               Q.push(j);
                               
                               while(!Q.empty())
                               {
                                                u = Q.front();
                                 
                                                Q.pop();
                                 
                                                for(i=0; i<=rozm[u]-1; ++i)
                                                {
                                                         if( odw[ G[u][i] ] == false )
                                                         {
                                                             odw[ G[u][i] ] = true;
                                                             
                                                             Q.push( G[u][i] );
                                                             
                                                             skladowa[ G[u][i] ] = num;
                                                         }
                                                }
                                 }
                                 
                                 ++num;
                     }
                
            }
            
            
            
            /*** 2. faza - tabelka odleglości od wierzchołka my_number ***/
            
            
            
            for(i=0; i<=n-1; ++i)
            {
                 odw[i] = false;
            }
            
            
            Q.push(my_number-1);
            
            odw[my_number-1] = true;
            
            odl[my_number-1] = 0;
            
            
            while(!Q.empty())
            {
                   u = Q.front();
                   
                   Q.pop();
                   
                   for(i=0; i<=rozm[u]-1; ++i)
                   {
                            if( odw[ G[u][i] ] == false )
                            {
                                odw[ G[u][i] ] = true;
                                
                                Q.push(G[u][i]);
                            }
                            
                            odl[ G[u][i] ] = min( odl[ G[u][i] ], 1 + odl[u] );
                   }
            }
            
            
            /*** Wypisywanie wyników ***/
            
            
            
            printf("Znajomi numeru %d:\n", my_number);
            
            for(i=0; i<=n-1; ++i)
            {
                     if(  odl[i] != 1000001   &&   i  !=  my_number - 1  )
                     {
                         printf("%d: %d\n", i+1, odl[i]);
                     }
            }
            
            printf("Grup znajomych jest %d.\n", num);
            
            
            
            delete [] odw;
            delete [] odl;
            
            for(i=0; i<=n-1; ++i)
            {
                 G[i].clear();
            }
            
            delete [] G;
            delete [] skladowa;
            delete [] rozm;
            
            num = 0;
    
    }
    
    //system("pause");
    return 0;
}
