#include<iostream>
#include<conio.h>

using namespace std;

struct customer{
       int id;
       int arrival, time_req, departure, turnaround;
       int priority, quanta, waiting;
       
       void input()
       {
            cout<<"Enter customer id, time of arrival, time required, priority, time quanta\n";
            cin>>id>>arrival>>time_req>>priority>>quanta;
            waiting = arrival;
            }
            };
            
void cpy(customer a[1000], customer c[1000], int n)
{
     int i;
     for(i=0;i<n;i++)
     {
                     a[i]=c[i];
                     }
}
            
void sort(customer a[1000], int n)
{
     int i,j,min,index;
     customer temp;
     for(i=0;i<n;i++)
     {
                     min = a[i].arrival;
                     index = i;
                     for(j=i+1;j<n;j++)
                     {
                                       if(min>a[j].arrival)
                                       {
                                                          min=a[j].arrival;
                                                          index = j;
                                                          }
                                                          }
                                                          
                     temp = a[i];
                     a[i] = a[index];
                     a[index] = temp;
                     }
}

void fcfs(customer a[1000], int no)
{
     int i,time=0;
     for(i=0;i<no;i++)
     {
                      time+=a[i].time_req;
                      a[i].departure=time;
                      }
     for(i=0;i<no;i++)
     {
                      cout<<"Customer: "<<a[i].id<<" Departure: "<<a[i].departure<<" Turn around time: "<<a[i].departure-a[i].arrival<<"\n";
                      }
}

void priority(customer a[1000], int n)
{
     int i, time = 0, max,index,flag=0;
     for(time = 0; ; time++)
     {
              flag = 0;
              for(i=0;i<n;i++)
              {
                              if(a[i].time_req>0)
                                  flag=1;
                                  }
              if(flag==0)
                 break;
              max=a[0].priority;
              index = 0;
              for(i=1;i<n;i++)
              {
                              if((max<a[i].priority)&&(a[i].time_req>0)&&(time>=a[i].arrival))
                              {
                                                                         max = a[i].priority;
                                                                         index=i;
                                                                         }
                                                                         }
              a[index].time_req--;
             
              if(a[index].time_req == 0)
              {
                                   a[index].departure = time + 1;
                                   a[index].priority = 0;
                                   }
                                   }
      for(i=0;i<n;i++)
     {
                      cout<<"Customer: "<<a[i].id<<" Departure: "<<a[i].departure<<" Turn around time: "<<a[i].departure-a[i].arrival<<"\n";
                      }
}

void rrf(customer a[1000], int n)
{
     int i, time = 0;
     while(1)
     {
             int flag = 0;
              for(i=0;i<n;i++)
              {
                              if(a[i].time_req>0)
                                  flag=1;
                                  }
              if(flag==0)
                 break;
              int max =a[0].waiting - time, index = 0;
              for(i=0;i<n;i++)
              {
                              if((max<time-a[i].waiting)&&(a[i].waiting<time)&&(a[i].time_req>0))
                              {
                                                                                                 max=time-a[i].waiting;
                                                                                                 index=i;
                                                                                                 }
              }
              time+=a[index].quanta;
              a[index].waiting=time;
              a[index].time_req-=a[index].quanta;
              
               if(a[index].time_req <= 0)
              {
                                   a[index].departure = time;
                                   }
                                   }
     
        for(i=0;i<n;i++)
     {
                      cout<<"Customer: "<<a[i].id<<" Departure: "<<a[i].departure<<" Turn around time: "<<a[i].departure-a[i].arrival<<"\n";
                      }
}                                                                                
                                                                                                 
              
     
     
                                       
            
int main()
{
    customer c[1000], f[1000],p[1000],r[1000];
    int i,no;
    cout<<"Enter number of customers ";
    cin>>no;
    for(i=0;i<no;i++)
    {
                     c[i].input();
                     }
    sort(c,no);
    cpy(f,c,no);
    cpy(p,c,no);
    cpy(r,c,no);
    cout<<"\nFirst come first serve method\n";
    fcfs(f,no);

    cout<<"\nPriority method\n";
    priority(p,no);

    cout<<"\nRound robin method\n";
    rrf(r,no);
    getch();
}
