#include<iostream>
#include<string>
using namespace std;

class Process
{
public:
string ProcessName;  // 进程名字
 int Time;  //  进程需要时间
 int leval; //  进程优先级
 int LeftTime; // 进程运行一段时间后还需要的时间
}; 

void Copy ( Process proc1, Process proc2); // 把proc2赋值给proc1
void Sort( Process  pr[], int size) ; // 此排序后按优先级从大到小排列
void sort1(Process  pr[], int size) ; //  此排序后按需要的cpu时间从小到大排列
void Fcfs( Process pr[], int num, int Timepice); // 先来先服务算法
void TimeTurn( Process process[], int num, int Timepice); // 时间片轮转算法
void Priority( Process process[], int num, int Timepice); // 优先级算法

int main()
{  
 int a;
 cout<<endl;
 cout<<"  选择调度算法："<<endl;
 cout<<"  1: FCFS  2: 时间片轮换 3: 优先级调度 4: 最短作业优先 5: 最短剩余时间优先"<<endl;
 cin>>a; 
const int Size =30;
 Process   process[Size] ;
 int num;
 int TimePice;  
cout<<" 输入进程个数:"<<endl;
 cin>>num;
 cout<<" 输入此进程时间片大小: "<<endl;
 cin>>TimePice;
for( int i=0; i< num; i++)
 {  
  string name;
  int CpuTime;
  int Leval;
  cout<<" 输入第"<< i+1<<" 个进程的名字、cpu时间和优先级:"<<endl;
  cin>>name;
  cin>> CpuTime>>Leval;
  process[i].ProcessName =name;
  process[i].Time =CpuTime;
  process[i].leval =Leval;
  cout<<endl;
}
for ( int k=0;k<num;k++)
  process[k].LeftTime=process[k].Time ;//对进程剩余时间初始化
  cout<<" ( 说明: 在本程序所列进程信息中，优先级一项是指进程运行后的优先级!! )";
  cout<<endl;   cout<<endl;
  cout<<"进程名字"<<"共需占用CPU时间 "<<" 还需要占用时间 "<<" 优先级"<<"   状态"<<endl;
if(a==1)
     Fcfs(process,num,TimePice);
else if(a==2)
  TimeTurn(  process,   num,   TimePice);
else if(a==3)
{
 Sort( process, num);
    Priority(   process ,  num,  TimePice);
}
 else   //  最短作业算法，先按时间从小到大排序，再调用Fcfs算法即可
 {
  sort1(process,num);
  Fcfs(process,num,TimePice);
 }
  system("pause");
  return 0;

}

void Copy ( Process proc1, Process proc2)
{
 proc1.leval =proc2.leval ;
 proc1.ProcessName =proc2.ProcessName ;
 proc1.Time =proc2.Time ;
}

void Sort( Process  pr[], int size)  //以进程优先级高低排序
{//  直接插入排序
 for( int i=1;i<size;i++)
 {
 Process temp;
     temp = pr[i];
     int j=i;  
     while(j>0 && temp.leval<pr[j-1].leval)
  {
       pr[j] = pr[j-1];
   j--;
  }
    pr[j] = temp;
} // 直接插入排序后进程按优先级从小到大排列
 for( int d=size-1;d>size/2;d--)
 {
  Process temp;
  temp=pr [d];
     pr [d] = pr [size-d-1];
  pr [size-d-1]=temp;
}  // 此排序后按优先级从大到小排列
}
/* 最短作业优先算法的实现*/
void sort1 ( Process  pr[], int size)  // 以进程时间从低到高排序
{//  直接插入排序
 for( int i=1;i<size;i++)
 {
 Process temp;
     temp = pr[i];
     int j=i;  
     while(j>0 && temp.Time < pr[j-1].Time )
  {
       pr[j] = pr[j-1];
   j--;
  }
    pr[j] = temp;
}  
}
/*  先来先服务算法的实现*/
void Fcfs( Process process[], int num, int Timepice)
{  // process[] 是输入的进程，num是进程的数目，Timepice是时间片大小
while(true)
 {
  if(num==0)
  {
   cout<<" 所有进程都已经执行完毕!"<<endl;
   exit(1);
  }
    if(process[0].LeftTime==0)
    {
  cout<<" 进程"<<process[0].ProcessName<< " 已经执行完毕!"<<endl;
     for (int i=0;i<num;i++)
     process[i]=process[i+1];
          num--;
    }
    else if(process[num-1].LeftTime==0)
  {
     cout<<" 进程"<<process[num-1].ProcessName<< " 已经执行完毕!"<<endl;
     num--;
  }
  else
  {
          cout<<endl;  //输出正在运行的进程
             process[0].LeftTime=process[0].LeftTime- Timepice;
             process[0].leval =process[0].leval-1;
             cout<<" "<<process[0].ProcessName <<"          "<<process[0].Time <<"                 ";
             cout<<process[0].LeftTime <<"                 "<<process[0].leval<<"      运行"; 
          cout<<endl;  
    for(int s=1;s<num;s++)
     {
      cout<<" "<<process[s].ProcessName <<"          "<<process[s].Time <<"                 ";
     cout<<process[s].LeftTime    <<"                 "<<process[s].leval<<"      等待"<<endl; ; 
         
         }
  }  // else
  cout<<endl;
  system(" pause");
  cout<<endl;
      
 } // while 
}
/* 时间片轮转调度算法实现*/
void TimeTurn( Process process[], int num, int Timepice)
{
while(true)
 {
  if(num==0)
  {
   cout<<" 所有进程都已经执行完毕!"<<endl;
   exit(1);
  }
    if(process[0].LeftTime==0)
    {
  cout<<" 进程"<<process[0].ProcessName<< " 已经执行完毕!"<<endl;
     for (int i=0;i<num;i++)
     process[i]=process[i+1];
          num--;
    }
     if( process[num-1].LeftTime ==0 )
  {
        cout<<" 进程" << process[num-1].ProcessName <<" 已经执行完毕! "<<endl;
         num--;
  }
  else if(process[0].LeftTime > 0)
    {
          cout<<endl;  //输出正在运行的进程
             process[0].LeftTime=process[0].LeftTime- Timepice;
             process[0].leval =process[0].leval-1;
             cout<<" "<<process[0].ProcessName <<"          "<<process[0].Time <<"                 ";
             cout<<process[0].LeftTime <<"                 "<<process[0].leval<<"      运行"; 
          cout<<endl;  
    for(int s=1;s<num;s++)
     {
      cout<<" "<<process[s].ProcessName <<"          "<<process[s].Time <<"                 ";
     cout<<process[s].LeftTime    <<"                 "<<process[s].leval; 
          if(s==1)
     cout<<"      就绪"<<endl;
    else
     cout<<"      等待"<<endl;
         
         }
  Process temp;
    temp = process[0];
    for( int j=0;j<num;j++)
     process[j] = process[j+1];
    process[num-1] = temp;
  } // else 
   
  cout<<endl;
  system(" pause");
  cout<<endl;
} // while 
}
/*  优先级调度算法的实现*/
void Priority( Process process[], int num, int Timepice)
{
 while( true)
 {
  if(num==0)
  {
   cout<< "所有进程都已经执行完毕!"<<endl;
      exit(1);
  }
if(process[0].LeftTime==0)
 {
  cout<<" 进程" << process[0].ProcessName <<" 已经执行完毕! "<<endl;
  for( int m=0;m<num;m++) 
    process[m] = process[m+1]; //一个进程执行完毕后从数组中删除
  num--; // 此时进程数目减少一个
 }
 if( num!=1 && process[num-1].LeftTime ==0 )
  {
   cout<<" 进程" << process[num-1].ProcessName <<" 已经执行完毕! "<<endl;
    num--;
 }
if(process[0].LeftTime > 0)
  {
    cout<<endl;  //输出正在运行的进程
 process[0].LeftTime=process[0].LeftTime- Timepice;
    process[0].leval =process[0].leval-1;
    cout<<" "<<process[0].ProcessName <<"          "<<process[0].Time <<"                 ";
    cout<<process[0].LeftTime <<"                 "<<process[0].leval<<"     运行"; 
cout<<endl;                  // 输出其他进程
   for(int s=1;s<num;s++)
  {
    cout<<" "<<process[s].ProcessName <<"          "<<process[s].Time <<"                 ";
    cout<<process[s].LeftTime    <<"                 "<<process[s].leval ; 
   if(s==1)
    cout<<"     就绪"<<endl;
   else
    cout<<"     等待 "<<endl;
   } 
} // else
  Sort(process, num);
  cout<<endl;
  system(" pause");
  cout<<endl;
} // while
}

