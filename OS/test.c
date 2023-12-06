#include<stdio.h>
#include<stdlib.h>
   double atime;            //平均周转时间 
   double awtime;    //平均带权周转时间
 struct RR
 {
 	char name[20];         //进程号 
 	int arrivaltime;       //到达时间 
	int runtime;           //运行时间
	int starttime;         //开始时间 
	int finishtime;        //完成时间
	int cycletime;      //周转时间 
	double wctime;      //带权周转时间
	int sign;          //完成进程标志 
	int st1;    //剩余服务时间 
  };
  struct RR rr[100];
  /*输入函数*/ 
void input(int n)
{
	printf("请依次输入进程号、到达时间、运行时间：\n");
	for(int i=0;i<n;i++)
	{
		rr[i].sign=0; 
		scanf("%s\t%d\t%d",rr[i].name,&rr[i].arrivaltime,&rr[i].runtime);
		rr[i].st1=rr[i].runtime;
	} 
}
/*采用冒泡法，按进程的到达时间对进程进行排序*/
void rank(int n)
{
	int i,j;
	struct RR temp; 
	for(j=0;j<n-1;j++)
	for(i=0;i<n-1-j;i++)
	{
		if(rr[i].arrivaltime>rr[i+1].arrivaltime)
		{
			temp=rr[i];
			rr[i]=rr[i+1];
			rr[i+1]=temp;
		}
	}
}
/*执行时间片轮转调度算法*/ 
void rr_pcb(int n)  
{
	printf("请输入时间片：\n");
	int t;
	scanf("%d",&t);  //输入时间片
	int time=rr[0].arrivaltime;     //给当前时间time赋初值
	int flag=1;          //标志就绪队列中有进程
	int sum=0;          //记录完成的进程数
	printf("\n====================================================================================================================\n");
	printf("进程号 \t到达时间\t运行时间\t开始时间\t完成时间\t周转时间\t带权周转时间\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	while(sum<n) //当完成的进程数小于进程总数
	{
	flag=0;    //标记就绪队列没有进程
	for(int i=0;i<n;i++) //时间片轮转法执行各进程 
	{
		if(rr[i].sign==1)//已完成进程 
		continue;
		else//未完成的进程
		{
			if(rr[i].st1<=t && time>=rr[i].arrivaltime)//还需运行的时间小于等于一个时间片 
			{
	 	      flag=1;  //把进程加入到就绪队列中
	       	  time+=rr[i].st1;
	 	      rr[i].sign=1; //此进程完成
	          rr[i].finishtime=time;  //完成时间 
              rr[i].cycletime=rr[i].finishtime-rr[i].arrivaltime;  //计算周转时间=完成时间-到达时间 
			  rr[i].wctime=rr[i].cycletime/(rr[i].runtime*1.0);   //计算带权周转时间=周转时间/服务 
			  printf("%3s\t  %d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t   %.2lf\n",rr[i].name,
	rr[i].arrivaltime,rr[i].runtime,time-rr[i].st1,time,rr[i].cycletime,rr[i].wctime);
			}		 	    
			else if(rr[i].st1>t&&time>=rr[i].arrivaltime)    //还需服务时间至少大于一个时间片 
			{
	 		  flag=1;  //把进程加入到就绪队列中
	 		  time+=t;
			  rr[i].st1-=t;
              rr[i].cycletime=rr[i].finishtime-rr[i].arrivaltime; //计算周转时间=完成时间-到达时间 
			  rr[i].wctime=rr[i].cycletime/(rr[i].runtime*1.0);  //计算带权周转时间=周转时间/服务
			  printf("%3s\t  %d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t   %.2lf\n",rr[i].name,
	rr[i].arrivaltime,rr[i].runtime,time-t,time,rr[i].cycletime,rr[i].wctime);
			} 
	    	if(rr[i].sign==1)
 		       sum++;     //一个进程执行完就+1
		} 
	 } 
	} 
	/*平均周转时间  平均带权周转时间*/ 
	int sum1=0;
	double sum2=0;
	for(int i=0;i<n;i++)
	{
		
		sum1+=rr[i].cycletime;  //求所有进程周转时间的和 
		sum2+=rr[i].wctime;  //求所有进程带权周转时间的和 
	}
	atime=sum1/(n*1.0);  //平均周转时间=有进程周转时间的和/进程数 
	awtime=sum2/n;   //平均带权周转时间=所有进程带权周转时间的和/进程数 
 } 
 /*输出函数*/
 void output(int n)
 {
    printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\t平均周转时间    \t\t%.2lf\t\n",atime);
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\t平均带权周转时间\t\t%.2lf\t\n",awtime);
	printf("====================================================================================================================\n"); 
}
/*主函数*/
int main()
{
	printf("时间片轮转调度算法\n请输入总进程数：\n");
	int n;
	scanf("%d",&n);   //输入总进程数 
	input(n);   //输入函数 
	rank(n);    //排序函数 
	rr_pcb(n);   //计算各时间 
	output(n);   //输出函数 
    system("pause");
	return 0;
 }