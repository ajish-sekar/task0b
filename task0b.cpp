#include<iostream>
#include<conio.h>
 using namespace std;
int curtain[1000],s[1000],k[1000],j[1000], query, noc, noq;

void print(int a[1000])
{
     int i;
     for(i=0;i<noc;i++)
     cout<<a[i]<<" ";
     cout<<"\n";
     }
void cpy(int a[1000])
{
     int i;
     for(i=0;i<noc;i++)
     {
                       a[i]=curtain[i];
                       }
                       }
                       

void sobha(int q)
{
     int i=noc-1;
     for(i=noc-1; i>=0; i--)
     {
                  if(s[i]>=q)
                  {
                            s[i]=s[i]-q;
                            break;
                            }
                            }
                            if(i==-1)
                             {
                                     cout<<"Not available\n";
                                     return;
                                     }
                            print(s);
     
                            }
           
void kamal(int q)
{
     int i,min,j;
     min = abs(q-k[noc-1]);
     j=noc-1;
     
     for(i=noc-2;i>=0;i--)
     {
                          if((min>abs(q-k[i]))&&(k[i]>=q))
                          {
                                            min = abs(q-k[i]);
                                            j=i;
                                            }
      if(k[j]<q)
      {
                cout<<"Not available\n";
                return;
                }                                      }
      k[j] = k[j]- q; 
      print(k);
      }                            
void jasmine(int q)
{
     int i, max = j[noc-1], l = noc-1;
     for(i=noc-2;i>=0;i--)
     {
                          if((max<j[i])&&(j[i]>=q))
                          { 
                                                   max = j[i];
                                                   l=i;
                                                   }
                                                   }
     if(j[l]<q)
     {
               cout<<"Not available\n";
               return;
               }
     j[l] = j[l]-q;
     print(j);
     }

int main()
{
    int i, query;
    cout<<"Enter number of curtains ";
    cin>>noc;
    cout<<"Enter the stack from bottom to top\n";
    for(i=0;i<noc;i++)
    cin>>curtain[i];
    cpy(s);
    cpy(k);
    cpy(j);
    cout<<"Enter number of queries ";
    cin>>noq;
    cout<<"Enter query\n";
    for(i=0;i<noq;i++)
    {
          cin>>query;
          sobha(query);
          cout<<"\n";
          kamal(query);
          cout<<"\n";
          jasmine(query);
          cout<<"\n";
                      
                      
}
getch();
}
