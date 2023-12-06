#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef struct  Process
{

 char ProcessName[50];  // ��������
 int ArriveTime; //���̵���ϵͳ��ʱ��
 int Time;  //  ������Ҫʱ��
 int leval; //  �������ȼ�
 int LeftTime; // ��������һ��ʱ�����Ҫ��ʱ��
}Pro; 

Pro Run_Now;    //�������еĽ���
int TimePice;	//����ʱ��Ƭ

void Init(struct Process pr[], int size);
void BubbleSort(struct Process pr[], int size);
void DisplayQueue(queue<Pro> &Que);			//��ӡ����Ԫ��
void Sort(Process pr[],int number);			//�������ȼ�����Ӹߵ���
void FCFS(struct Process pr[], int num);    //�����ȷ����㷨
void SSTF(struct Process pr[], int num);    // ����ҵ�����㷨
void HighPro(struct Process pr[], int num);  // ������Ȩ�㷨
void HRN(struct Process pr[], int num);   //����Ӧ���㷨
void TimeTurn(struct Process pr[], int num);  //ʱ��Ƭ��ת�㷨

void main()
{
	int type; //ѡ���㷨������
	int num;  //���̸���
	queue<Pro> Que;		//���̶���
	queue<Pro> Block;	//��������

    const int Size =30;
    struct Process   process[Size] ;
	
	cout<< "��������̸���(������30):"<<endl;
	cin>> num;
	cout<<"���������ʱ��Ƭ��С"<<endl;
	cin>>TimePice;
	cout<<"  ѡ������㷨��"<<endl;
	cout<<"  1: FCFS  2: ʱ��Ƭ�ֻ� 3: ���ȼ����� 4: �����ҵ���� 5: ����Ӧ���㷨"<<endl;
    cin>>type; 

	Init(process,num);  //��ʼ��

	

	cout<<"������:   ���̵���ϵͳʱ��:    ����ִ��ʱ��:    ����Ȩ:"<<endl; 
	for (int i =0; i<num; i++)
	{
		cout<<process[i].ProcessName<<"  , "<<process[i].ArriveTime<<"  , "<<process[i].Time<<"  , "<<process[i].leval<<endl;  
		//Que.push(process[i]);
	}
	//DisplayQueue(Que);		
	for ( int k=0;k<num;k++)
	{
	  process[k].LeftTime=process[k].Time ;//�Խ���ʣ��ʱ���ʼ��
	}
	  cout<<" ( ˵��: �ڱ��������н�����Ϣ�У����ȼ�һ����ָ�������к�����ȼ�!! )";
	  cout<<endl;   cout<<endl;
	  cout<<"��������"<<"����ռ��CPUʱ�� "<<" ����Ҫռ��ʱ�� "<<" ���ȼ�"<<"   ״̬"<<endl;
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
			default: cout<<"�����㷨���ʹ���!"<<endl;
		}
	}

	system("pause");
}

void Init(struct Process pr[], int size)
{

	cout<<endl;
	for(int i = 0; i<size; i++)
	{
		cout<<"�������"<<i+1<<"�����̵Ľ�����,����ϵͳʱ��,ִ��ʱ��,����Ȩ"<<endl;
	    cin>> pr[i].ProcessName;
		cin>> pr[i].ArriveTime;
		cin>> pr[i].Time;
		cin>> pr[i].leval;
	}	
}
void DisplayQueue(queue<Pro> &Que)			//��ӡ����Ԫ��
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
	process.LeftTime--;					//ĳһʱ����������ʣ��ʱ���
	return;
}/*���к���*/
void Wait()
{
	return ;
}
void Sort(Process pr[],int number)			//�������ȼ�����Ӹߵ���
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
} // ֱ�Ӳ����������̰����ȼ���С��������
 for( int d=number-1;d>number/2;d--)
 {
	  Process temp;
	  temp=pr [d];
	  pr [d] = pr [number-d-1];
	  pr [number-d-1]=temp;
}  // ����������ȼ��Ӵ�С����

void BubbleSort(struct Process pr[], int size)    //ð�������㷨�Խ��̵ִ�ʱ���Ⱥ�����
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
/* �����ҵ�����㷨��ʵ��*/
void sort1 ( Process  pr[], int size)  // �Խ���ʱ��ӵ͵�������
{//  ֱ�Ӳ�������
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
void FCFS(struct Process pr[], int num)    //�����ȷ����㷨
{
	while(1)
	{
		if( num== 0)
		{
			cout<<" ���н��̶��Ѿ�ִ�����!"<<endl;
			exit(1);
		}
		if(pr[0].LeftTime==0)
		{
			cout<<" ����"<<pr[0].ProcessName<< " �Ѿ�ִ�����!"<<endl;
		for (int i=0;i<num;i++)
		 pr[i]=pr[i+1];
          num--;
		}
    else if(pr[num-1].LeftTime==0)
  {
     cout<<" ����"<<pr[num-1].ProcessName<< " �Ѿ�ִ�����!"<<endl;
     num--;
  }
	 else
  {
          cout<<endl;  //����������еĽ���
          pr[0].LeftTime=pr[0].LeftTime- TimePice;
          pr[0].leval =pr[0].leval-1;
          cout<<" "<<pr[0].ProcessName <<"          "<<pr[0].Time <<"                 ";
          cout<<pr[0].LeftTime <<"                 "<<pr[0].leval<<"      ����"; 
          cout<<endl;  
    for(int s=1;s<num;s++)
     {
		 cout<<" "<<pr[s].ProcessName <<"          "<<pr[s].Time <<"                 ";
		 cout<<pr[s].LeftTime    <<"                 "<<pr[s].leval<<"      �ȴ�"<<endl; ;  
         }
  }  // else
  cout<<endl;
  system(" pause");
  cout<<endl;

	}
}
void sort_arriveTime(Process pr[],int size) //�����н��̰��յ���ʱ���������
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
void SSTF(struct Process pr[], int num)    // ����ҵ�����㷨
{

	while(1)
	{
		if(num==0)
		cout<<" ���н��̶��Ѿ�ִ�����!"<<endl;
		



	}
}

void HighPro(struct Process pr[], int num)  // ������Ȩ�㷨
{
}

void HRN(struct Process pr[], int num)  //����Ӧ���㷨
{
}

void TimeTurn(struct Process pr[], int num)  //ʱ��Ƭ��ת�㷨
{
}

