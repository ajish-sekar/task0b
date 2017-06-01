#include<iostream>
#include<conio.h>

using namespace std;

struct customer{
       int id;
       int arrival, time_req, departure, turnaround;
       int priority, quanta;
       
       void input()
       {
            cout<<"Enter customer id, time of arrival, time required\n";
            cin>>id>>arrival>>time_req;
            }
            };
            
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
                                       
            
int main()
{
    customer c[1000];
    int i,no;
    cout<<"Enter number of customers ";
    cin>>no;
    for(i=0;i<no;i++)
    {
                     c[i].input();
                     }
    sort(c,no);
    fcfs(c,no);
    getch();
}
