#include<stdio.h>
#include<stdlib.h>
   double atime;            //ƽ����תʱ�� 
   double awtime;    //ƽ����Ȩ��תʱ��
 struct RR
 {
 	char name[20];         //���̺� 
 	int arrivaltime;       //����ʱ�� 
	int runtime;           //����ʱ��
	int starttime;         //��ʼʱ�� 
	int finishtime;        //���ʱ��
	int cycletime;      //��תʱ�� 
	double wctime;      //��Ȩ��תʱ��
	int sign;          //��ɽ��̱�־ 
	int st1;    //ʣ�����ʱ�� 
  };
  struct RR rr[100];
  /*���뺯��*/ 
void input(int n)
{
	printf("������������̺š�����ʱ�䡢����ʱ�䣺\n");
	for(int i=0;i<n;i++)
	{
		rr[i].sign=0; 
		scanf("%s\t%d\t%d",rr[i].name,&rr[i].arrivaltime,&rr[i].runtime);
		rr[i].st1=rr[i].runtime;
	} 
}
/*����ð�ݷ��������̵ĵ���ʱ��Խ��̽�������*/
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
/*ִ��ʱ��Ƭ��ת�����㷨*/ 
void rr_pcb(int n)  
{
	printf("������ʱ��Ƭ��\n");
	int t;
	scanf("%d",&t);  //����ʱ��Ƭ
	int time=rr[0].arrivaltime;     //����ǰʱ��time����ֵ
	int flag=1;          //��־�����������н���
	int sum=0;          //��¼��ɵĽ�����
	printf("\n====================================================================================================================\n");
	printf("���̺� \t����ʱ��\t����ʱ��\t��ʼʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	while(sum<n) //����ɵĽ�����С�ڽ�������
	{
	flag=0;    //��Ǿ�������û�н���
	for(int i=0;i<n;i++) //ʱ��Ƭ��ת��ִ�и����� 
	{
		if(rr[i].sign==1)//����ɽ��� 
		continue;
		else//δ��ɵĽ���
		{
			if(rr[i].st1<=t && time>=rr[i].arrivaltime)//�������е�ʱ��С�ڵ���һ��ʱ��Ƭ 
			{
	 	      flag=1;  //�ѽ��̼��뵽����������
	       	  time+=rr[i].st1;
	 	      rr[i].sign=1; //�˽������
	          rr[i].finishtime=time;  //���ʱ�� 
              rr[i].cycletime=rr[i].finishtime-rr[i].arrivaltime;  //������תʱ��=���ʱ��-����ʱ�� 
			  rr[i].wctime=rr[i].cycletime/(rr[i].runtime*1.0);   //�����Ȩ��תʱ��=��תʱ��/���� 
			  printf("%3s\t  %d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t   %.2lf\n",rr[i].name,
	rr[i].arrivaltime,rr[i].runtime,time-rr[i].st1,time,rr[i].cycletime,rr[i].wctime);
			}		 	    
			else if(rr[i].st1>t&&time>=rr[i].arrivaltime)    //�������ʱ�����ٴ���һ��ʱ��Ƭ 
			{
	 		  flag=1;  //�ѽ��̼��뵽����������
	 		  time+=t;
			  rr[i].st1-=t;
              rr[i].cycletime=rr[i].finishtime-rr[i].arrivaltime; //������תʱ��=���ʱ��-����ʱ�� 
			  rr[i].wctime=rr[i].cycletime/(rr[i].runtime*1.0);  //�����Ȩ��תʱ��=��תʱ��/����
			  printf("%3s\t  %d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t   %.2lf\n",rr[i].name,
	rr[i].arrivaltime,rr[i].runtime,time-t,time,rr[i].cycletime,rr[i].wctime);
			} 
	    	if(rr[i].sign==1)
 		       sum++;     //һ������ִ�����+1
		} 
	 } 
	} 
	/*ƽ����תʱ��  ƽ����Ȩ��תʱ��*/ 
	int sum1=0;
	double sum2=0;
	for(int i=0;i<n;i++)
	{
		
		sum1+=rr[i].cycletime;  //�����н�����תʱ��ĺ� 
		sum2+=rr[i].wctime;  //�����н��̴�Ȩ��תʱ��ĺ� 
	}
	atime=sum1/(n*1.0);  //ƽ����תʱ��=�н�����תʱ��ĺ�/������ 
	awtime=sum2/n;   //ƽ����Ȩ��תʱ��=���н��̴�Ȩ��תʱ��ĺ�/������ 
 } 
 /*�������*/
 void output(int n)
 {
    printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\tƽ����תʱ��    \t\t%.2lf\t\n",atime);
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\tƽ����Ȩ��תʱ��\t\t%.2lf\t\n",awtime);
	printf("====================================================================================================================\n"); 
}
/*������*/
int main()
{
	printf("ʱ��Ƭ��ת�����㷨\n�������ܽ�������\n");
	int n;
	scanf("%d",&n);   //�����ܽ����� 
	input(n);   //���뺯�� 
	rank(n);    //������ 
	rr_pcb(n);   //�����ʱ�� 
	output(n);   //������� 
    system("pause");
	return 0;
 }