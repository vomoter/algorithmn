#include <iostream>
using namespace std;

struct Process
{
    char ProcessName; // ��������
    int ArriveTime;   // ���̵���ϵͳ��ʱ��
    int Time;         // ������Ҫʱ��
    int leval;        // �������ȼ�
    int LeftTime;     // ��������һ��ʱ�����Ҫ��ʱ��
    int FinishTime;   //���ʱ��
};

void Init(struct Process pr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "�������" << i + 1 << "�����̵Ľ�����,����ϵͳʱ��,ִ��ʱ��,����Ȩ" << endl;
        cin >> pr[i].ProcessName;
        cin >> pr[i].ArriveTime;
        cin >> pr[i].Time;
        cin >> pr[i].leval;
    }
}

void FCFS(struct Process pr[], int num) //�����ȷ����㷨
{
    int RevolveTime[num]; //��תʱ��
    double DQTime[num];   //��Ȩ��תʱ��
    int current_time;     //��ǰʱ��
    double total = 0;
    double temp = 0;
    cout << "������\t��ǰʱ��\t����ʱ��\t���ʱ��\t��תʱ��" << endl;
    for (int i = 0; i < num; i++)
    {
        Process current_process = pr[i];

        // �����ǰʱ��С�ڽ��̵���ʱ�䣬��ȴ����̵���
        if (current_time < current_process.ArriveTime)
        {
            current_time = current_process.ArriveTime;
        }
        current_process.FinishTime = current_time + current_process.Time;
        RevolveTime[i] = current_process.FinishTime - current_process.ArriveTime;
        total = total + current_time;
        temp = temp + RevolveTime[i];

        cout << current_process.ProcessName << "\t\t" << current_time << "\t\t" << current_process.Time
             << "\t\t" << current_process.FinishTime << "\t\t" << RevolveTime[i] << endl;
    }

    cout << "ƽ���ȴ�ʱ��:" << total / num << endl;
    cout << "ƽ����תʱ��:" << temp / num << endl;
}

void SSTF(struct Process pr[], int num)
{
    int i, j, temp, total = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    int start_time[num];      // ÿ�����̵Ŀ�ʼʱ��
    int wait_time[num];       // ÿ�����̵ĵȴ�ʱ��
    int turnaround_time[num]; //ÿ�����̵���תʱ��

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (pr[i].Time > pr[j].Time)
            {
                // ���ݷ���ʱ��Խ��̽�������
                temp = pr[i].Time;
                pr[i].Time = pr[j].Time;
                pr[j].Time = temp;

                temp = pr[i].ProcessName;
                pr[i].ProcessName = pr[j].ProcessName;
                pr[j].ProcessName = temp;
            }
        }
    }

    start_time[0] = 0;
    wait_time[0] = 0;

    // ����ÿ�����̵Ŀ�ʼʱ�䡢�ȴ�ʱ�����תʱ��
    for (i = 1; i < num; i++)
    {
        start_time[i] = start_time[i - 1] + pr[i - 1].Time;
        wait_time[i] = start_time[i] - pr[i].ArriveTime;

        if (wait_time[i] < 0)
        {
            wait_time[i] = 0;
        }
    }

    // ����ÿ�����̵Ľ���ʱ�����תʱ��
    for (i = 0; i < num; i++)
    {
        pr[i].FinishTime = start_time[i] + pr[i].Time;
        turnaround_time[i] = pr[i].FinishTime - pr[i].ArriveTime;
        total += wait_time[i];
    }

    // ���ÿ�����̵ĵȴ�ʱ�����תʱ��
    cout << "������ \t����ʱ�� \t���ʱ�� \t�ȴ�ʱ�� \t��תʱ��" << endl;
    for (i = 0; i < num; i++)
    {

        cout << pr[i].ProcessName << "\t\t" << pr[i].Time << "\t\t" << pr[i].FinishTime << "\t\t"
             << wait_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    // ���ƽ���ȴ�ʱ���ƽ����תʱ��
    avg_wait_time = (float)total / num;
    total = 0;
    for (i = 0; i < num; i++)
    {
        total += turnaround_time[i];
    }
    avg_turnaround_time = (float)total / num;
    cout << "ƽ���ȴ�ʱ��:" << avg_wait_time << endl;
    cout << "ƽ����Ȩ��תʱ��:" << avg_turnaround_time << endl;
}

void HighPro(struct Process pr[], int num) // ������Ȩ�㷨
{
    int i, j, temp, total = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    int start_time[num]; // ��¼ÿ�����̵Ŀ�ʼʱ��
    // int FinishTime[num];  // ��¼ÿ�����̵Ľ���ʱ��
    int wait_time[num];       // ��¼ÿ�����̵ĵȴ�ʱ��
    int turnaround_time[num]; // ��¼ÿ�����̵���תʱ��

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (pr[i].leval < pr[j].leval)
            {
                // ���ݷ���ʱ��Խ��̽�������
                temp = pr[i].leval;
                pr[i].leval = pr[j].leval;
                pr[j].leval = temp;

                temp = pr[i].ProcessName;
                pr[i].ProcessName = pr[j].ProcessName;
                pr[j].ProcessName = temp;
            }
        }
    }

    start_time[0] = 0;
    wait_time[0] = 0;

    // ����ÿ�����̵Ŀ�ʼʱ�䡢�ȴ�ʱ�����תʱ��
    for (i = 1; i < num; i++)
    {
        start_time[i] = start_time[i - 1] + pr[i - 1].Time;
        wait_time[i] = start_time[i] - pr[i].ArriveTime;

        if (wait_time[i] < 0)
        {
            wait_time[i] = 0;
        }
    }

    // ����ÿ�����̵Ľ���ʱ�����תʱ��
    for (i = 0; i < num; i++)
    {
        pr[i].FinishTime = start_time[i] + pr[i].Time;
        turnaround_time[i] = pr[i].FinishTime - pr[i].ArriveTime;
        total += wait_time[i];
    }

    cout << "������\t    ����ʱ��\t  ���ʱ��\t  �ȴ�ʱ��\t  ��תʱ��" << endl;
    for (i = 0; i < num; i++)
    {

        cout << pr[i].ProcessName << "\t\t" << pr[i].Time << "\t\t" << pr[i].FinishTime
             << "\t\t" << wait_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    // ���ƽ���ȴ�ʱ���ƽ����תʱ��
    avg_wait_time = (float)total / num;
    total = 0;
    for (i = 0; i < num; i++)
    {
        total += turnaround_time[i];
    }
    avg_turnaround_time = (float)total / num;
    cout << "ƽ���ȴ�ʱ��: " << avg_wait_time << endl;
    cout << "ƽ����Ȩ��תʱ��:" << avg_turnaround_time << endl;
}

void HRN(struct Process pr[], int num)
{
    int i, j, total_time = 0;
    float highest_response_ratio, response_ratio, avg_wait_time, avg_turnaround_time;
    int waiting_time[num], turnaround_time[num];

    waiting_time[0] = 0; // ��ʼ���̵ȴ�ʱ��Ϊ0

    for (i = 1; i < num; i++)
    {
        // ����ȴ�ʱ��
        waiting_time[i] = waiting_time[i - 1] + pr[i - 1].Time - pr[i].ArriveTime;
        pr[i].FinishTime = waiting_time[i] + pr[i].Time;
        // ����ȴ�ʱ��Ϊ������������Ϊ0
        if (waiting_time[i] < 0)
            waiting_time[i] = 0;
    }

    cout << "������\t����ʱ��\t���ʱ��\t�ȴ�ʱ��\t��תʱ��\t��Ӧ��" << endl;
    for (i = 0; i < num; i++)
    {
        total_time += waiting_time[i];
        turnaround_time[i] = pr[i].Time + waiting_time[i];
        response_ratio = (float)turnaround_time[i] / pr[i].Time;

        // ���ÿ�����̵ĵȴ�ʱ�����תʱ��
        cout << pr[i].ProcessName << "\t\t" << pr[i].Time << "\t\t" << pr[i].FinishTime << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << "\t\t" << response_ratio << endl;
    }
    // ���ƽ���ȴ�ʱ���ƽ����תʱ��
    avg_wait_time = total_time / num;
    total_time = 0;
    for (i = 0; i < num; i++)
    {
        total_time += turnaround_time[i];
    }
    avg_turnaround_time = total_time / num;
    cout << "ƽ���ȴ�ʱ��:" << avg_wait_time << endl;
    cout << "ƽ����Ȩ��תʱ��:" << avg_turnaround_time << endl;

    highest_response_ratio = response_ratio;
    j = 0;

    for (i = 1; i < num; i++)
    {
        if (highest_response_ratio < response_ratio)
        {
            highest_response_ratio = response_ratio;
            j = i;
        }
    }

    cout << "�����Ӧ�Ƚ��̣�" << pr[j].ProcessName << endl;
}
void TimeTurn(Process pr[], int num, int Timepice)
{
    int i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0, avg_weighted_turnaround_time = 0;
    int time_quantum = Timepice; // ʱ��Ƭ����
    int remain = num;            // ʣ���������
    int waiting_time[num];
    int current_time = 0;

    for (i = 0; i < num; i++)
    {
        pr[i].LeftTime = pr[i].Time;
    }

    i = 0;
    while (remain)
    {
        if (pr[i].LeftTime > 0)
        {
            if (pr[i].LeftTime > time_quantum)
            {
                current_time += time_quantum;
                pr[i].LeftTime -= time_quantum;
            }
            else
            {
                current_time += pr[i].LeftTime;
                pr[i].FinishTime = current_time;
                pr[i].LeftTime = 0;
                remain--;

                waiting_time[i] = current_time - pr[i].ArriveTime - pr[i].Time;
                if (waiting_time[i] < 0)
                {
                    waiting_time[i] = 0;
                }

                avg_waiting_time += waiting_time[i];
                avg_turnaround_time += current_time - pr[i].ArriveTime;
                avg_weighted_turnaround_time += (float)(current_time - pr[i].ArriveTime) / pr[i].Time;
            }
        }
        i = (i + 1) % num;
    }

    avg_waiting_time /= num;
    avg_turnaround_time /= num;
    avg_weighted_turnaround_time /= num;

    cout << "������\t���ʱ��\t��תʱ��\t�ȴ�ʱ��" << endl;
    for (i = 0; i < num; i++)
    {
        cout << pr[i].ProcessName << "\t\t" << pr[i].FinishTime << "\t\t" << pr[i].FinishTime - pr[i].ArriveTime << "\t\t"
             << waiting_time[i] << endl;
    }
    cout << "\nƽ���ȴ�ʱ�䣺" << avg_waiting_time << endl;
    cout << "ƽ����תʱ�䣺" << avg_turnaround_time << endl;
    cout << "ƽ����Ȩ��תʱ�䣺" << avg_weighted_turnaround_time << endl;
}

int main()
{
    int type; // ѡ���㷨������
    int num;  // ���̸���
    int Timepice;
    const int Size = 30;
    struct Process process[Size];

    cout << "��������̸���(������30):" << endl;
    cin >> num;

    Init(process, num); // ��ʼ��

    cout << "������:\t���̵���ϵͳʱ��:\t����ִ��ʱ��:\t����Ȩ:\n"
         << endl;
    for (int i = 0; i < num; i++)

    {

        cout << process[i].ProcessName << "               " << process[i].ArriveTime << "               "
             << process[i].Time << "             " << process[i].leval << endl;
    }
    cout << "  1: FCFS  2: ����ҵ���� 3: ������Ȩ 4: ����Ӧ���㷨 5: ʱ��Ƭ��ת�㷨" << endl;
    cin >> type;

    switch (type)
    {
    case 1:
        FCFS(process, num);
        break;
    case 2:
        SSTF(process, num);
        break;
    case 3:
        HighPro(process, num);
        break;
    case 4:
        HRN(process, num);
        break;
    case 5:
        cout << "�����ʱ��Ƭ" << endl;
        cin >> Timepice;

        TimeTurn(process, num, Timepice);

        break;
    default:
        cout << "�����㷨���ʹ���!" << endl;
    }

    system("pause");
    return 0;
}
