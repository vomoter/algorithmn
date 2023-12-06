#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef struct  Process
{

 char ProcessName[50];  // 进程名字
 int ArriveTime; //进程到达系统的时间
 int Time;  //  进程需要时间
 int leval; //  进程优先级
 int LeftTime; // 进程运行一段时间后还需要的时间
}Pro; 

Pro Run_Now;    //正在运行的进程
int TimePice;	//进程时间片

void Init(struct Process pr[], int size);
void BubbleSort(struct Process pr[], int size);
void DisplayQueue(queue<Pro> &Que);			//打印队列元素
void Sort(Process pr[],int number);			//进程优先级排序从高到低
void FCFS(struct Process pr[], int num);    //先来先服务算法
void SSTF(struct Process pr[], int num);    // 短作业优先算法
void HighPro(struct Process pr[], int num);  // 高优先权算法
void HRN(struct Process pr[], int num);   //高响应比算法
void TimeTurn(struct Process pr[], int num);  //时间片轮转算法

void main()
{
	int type; //选择算法的类型
	int num;  //进程个数
	queue<Pro> Que;		//进程队列
	queue<Pro> Block;	//阻塞队列

    const int Size =30;
    struct Process   process[Size] ;
	
	cout<< "请输入进程个数(不超过30):"<<endl;
	cin>> num;
	cout<<"请输入进程时间片大小"<<endl;
	cin>>TimePice;
	cout<<"  选择调度算法："<<endl;
	cout<<"  1: FCFS  2: 时间片轮换 3: 优先级调度 4: 最短作业优先 5: 高响应比算法"<<endl;
    cin>>type; 

	Init(process,num);  //初始化

	

	cout<<"进程名:   进程到达系统时间:    进程执行时间:    优先权:"<<endl; 
	for (int i =0; i<num; i++)
	{
		cout<<process[i].ProcessName<<"  , "<<process[i].ArriveTime<<"  , "<<process[i].Time<<"  , "<<process[i].leval<<endl;  
		//Que.push(process[i]);
	}
	//DisplayQueue(Que);		
	for ( int k=0;k<num;k++)
	{
	  process[k].LeftTime=process[k].Time ;//对进程剩余时间初始化
	}
	  cout<<" ( 说明: 在本程序所列进程信息中，优先级一项是指进程运行后的优先级!! )";
	  cout<<endl;   cout<<endl;
	  cout<<"进程名字"<<"共需占用CPU时间 "<<" 还需要占用时间 "<<" 优先级"<<"   状态"<<endl;
	while(1)
	{
		switch(type)
		{
			case 0:break;
			case 1: FCFS(process,num); 
		
				break;
			case 2: SSTF(process,num);  break;
			case 3: HighPro(process,num);  break;
			case 4: HRN(process,num);  break;
			case 5: TimeTurn(process,num);  break;
			default: cout<<"输入算法类型错误!"<<endl;
		}
	}

	system("pause");
}

void Init(struct Process pr[], int size)
{

	cout<<endl;
	for(int i = 0; i<size; i++)
	{
		cout<<"请输入第"<<i+1<<"个进程的进程名,到达系统时间,执行时间,优先权"<<endl;
	    cin>> pr[i].ProcessName;
		cin>> pr[i].ArriveTime;
		cin>> pr[i].Time;
		cin>> pr[i].leval;
	}	
}
void DisplayQueue(queue<Pro> &Que)			//打印队列元素
{
	cout<<"dghdhdghde"<<endl;
	while(!Que.empty())
	{
		Pro process=Que.front();
		cout<<process.ArriveTime<<"  "<<process.Time<<" "<<process.leval<<endl;
		Que.pop();
	}
}


void Run(queue<Pro> &Que)
{
	Pro process=Que.front();
	Que.pop();
	process.LeftTime--;					//某一时间运行它的剩余时间减
	return;
}/*运行函数*/
void Wait()
{
	return ;
}
void Sort(Process pr[],int number)			//进程优先级排序从高到低
{
	 for( int i=1;i<number;i++)
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
 for( int d=number-1;d>number/2;d--)
 {
	  Process temp;
	  temp=pr [d];
	  pr [d] = pr [number-d-1];
	  pr [number-d-1]=temp;
}  // 此排序后按优先级从大到小排列

void BubbleSort(struct Process pr[], int size)    //冒泡排序算法对进程抵达时间先后排序
{
	int i, j, n = size;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (pr[j].ArriveTime > pr[j + 1].ArriveTime)
			{
				pr[n] = pr[j + 1];
				pr[j + 1] = pr[j];
				pr[j] = pr[n];
			}
		}
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

}
void FCFS(struct Process pr[], int num)    //先来先服务算法
{
	while(1)
	{
		if( num== 0)
		{
			cout<<" 所有进程都已经执行完毕!"<<endl;
			exit(1);
		}
		if(pr[0].LeftTime==0)
		{
			cout<<" 进程"<<pr[0].ProcessName<< " 已经执行完毕!"<<endl;
		for (int i=0;i<num;i++)
		 pr[i]=pr[i+1];
          num--;
		}
    else if(pr[num-1].LeftTime==0)
  {
     cout<<" 进程"<<pr[num-1].ProcessName<< " 已经执行完毕!"<<endl;
     num--;
  }
	 else
  {
          cout<<endl;  //输出正在运行的进程
          pr[0].LeftTime=pr[0].LeftTime- TimePice;
          pr[0].leval =pr[0].leval-1;
          cout<<" "<<pr[0].ProcessName <<"          "<<pr[0].Time <<"                 ";
          cout<<pr[0].LeftTime <<"                 "<<pr[0].leval<<"      运行"; 
          cout<<endl;  
    for(int s=1;s<num;s++)
     {
		 cout<<" "<<pr[s].ProcessName <<"          "<<pr[s].Time <<"                 ";
		 cout<<pr[s].LeftTime    <<"                 "<<pr[s].leval<<"      等待"<<endl; ;  
         }
  }  // else
  cout<<endl;
  system(" pause");
  cout<<endl;

	}
}
void sort_arriveTime(Process pr[],int size) //对所有进程按照到达时间进行排序
{
    int i,j;
    Process temp;
    for(i=0; i<N-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(pr[j].ArriveTime>pr[j+1].ArriveTime)
            {
                temp=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=temp;
            }
        }
    }
}
void SSTF(struct Process pr[], int num)    // 短作业优先算法
{

	while(1)
	{
		if(num==0)
		cout<<" 所有进程都已经执行完毕!"<<endl;
		



	}
}

void HighPro(struct Process pr[], int num)  // 高优先权算法
{
}

void HRN(struct Process pr[], int num)  //高响应比算法
{
}

void TimeTurn(struct Process pr[], int num)  //时间片轮转算法
{
}

