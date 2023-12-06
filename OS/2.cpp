#include <iostream>
using namespace std;

struct Process
{
    char ProcessName; // 进程名字
    int ArriveTime;   // 进程到达系统的时间
    int Time;         // 进程需要时间
    int leval;        // 进程优先级
    int LeftTime;     // 进程运行一段时间后还需要的时间
    int FinishTime;   //完成时间
};

void Init(struct Process pr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "请输入第" << i + 1 << "个进程的进程名,到达系统时间,执行时间,优先权" << endl;
        cin >> pr[i].ProcessName;
        cin >> pr[i].ArriveTime;
        cin >> pr[i].Time;
        cin >> pr[i].leval;
    }
}

void FCFS(struct Process pr[], int num) //先来先服务算法
{
    int RevolveTime[num]; //周转时间
    double DQTime[num];   //带权周转时间
    int current_time;     //当前时间
    double total = 0;
    double temp = 0;
    cout << "进程名\t当前时间\t服务时间\t完成时间\t周转时间" << endl;
    for (int i = 0; i < num; i++)
    {
        Process current_process = pr[i];

        // 如果当前时间小于进程到达时间，则等待进程到达
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

    cout << "平均等待时间:" << total / num << endl;
    cout << "平均周转时间:" << temp / num << endl;
}

void SSTF(struct Process pr[], int num)
{
    int i, j, temp, total = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    int start_time[num];      // 每个进程的开始时间
    int wait_time[num];       // 每个进程的等待时间
    int turnaround_time[num]; //每个进程的周转时间

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (pr[i].Time > pr[j].Time)
            {
                // 根据服务时间对进程进行排序
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

    // 计算每个进程的开始时间、等待时间和周转时间
    for (i = 1; i < num; i++)
    {
        start_time[i] = start_time[i - 1] + pr[i - 1].Time;
        wait_time[i] = start_time[i] - pr[i].ArriveTime;

        if (wait_time[i] < 0)
        {
            wait_time[i] = 0;
        }
    }

    // 计算每个进程的结束时间和周转时间
    for (i = 0; i < num; i++)
    {
        pr[i].FinishTime = start_time[i] + pr[i].Time;
        turnaround_time[i] = pr[i].FinishTime - pr[i].ArriveTime;
        total += wait_time[i];
    }

    // 输出每个进程的等待时间和周转时间
    cout << "进程名 \t服务时间 \t完成时间 \t等待时间 \t周转时间" << endl;
    for (i = 0; i < num; i++)
    {

        cout << pr[i].ProcessName << "\t\t" << pr[i].Time << "\t\t" << pr[i].FinishTime << "\t\t"
             << wait_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    // 输出平均等待时间和平均周转时间
    avg_wait_time = (float)total / num;
    total = 0;
    for (i = 0; i < num; i++)
    {
        total += turnaround_time[i];
    }
    avg_turnaround_time = (float)total / num;
    cout << "平均等待时间:" << avg_wait_time << endl;
    cout << "平均带权周转时间:" << avg_turnaround_time << endl;
}

void HighPro(struct Process pr[], int num) // 高优先权算法
{
    int i, j, temp, total = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    int start_time[num]; // 记录每个进程的开始时间
    // int FinishTime[num];  // 记录每个进程的结束时间
    int wait_time[num];       // 记录每个进程的等待时间
    int turnaround_time[num]; // 记录每个进程的周转时间

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (pr[i].leval < pr[j].leval)
            {
                // 根据服务时间对进程进行排序
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

    // 计算每个进程的开始时间、等待时间和周转时间
    for (i = 1; i < num; i++)
    {
        start_time[i] = start_time[i - 1] + pr[i - 1].Time;
        wait_time[i] = start_time[i] - pr[i].ArriveTime;

        if (wait_time[i] < 0)
        {
            wait_time[i] = 0;
        }
    }

    // 计算每个进程的结束时间和周转时间
    for (i = 0; i < num; i++)
    {
        pr[i].FinishTime = start_time[i] + pr[i].Time;
        turnaround_time[i] = pr[i].FinishTime - pr[i].ArriveTime;
        total += wait_time[i];
    }

    cout << "进程名\t    服务时间\t  完成时间\t  等待时间\t  周转时间" << endl;
    for (i = 0; i < num; i++)
    {

        cout << pr[i].ProcessName << "\t\t" << pr[i].Time << "\t\t" << pr[i].FinishTime
             << "\t\t" << wait_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    // 输出平均等待时间和平均周转时间
    avg_wait_time = (float)total / num;
    total = 0;
    for (i = 0; i < num; i++)
    {
        total += turnaround_time[i];
    }
    avg_turnaround_time = (float)total / num;
    cout << "平均等待时间: " << avg_wait_time << endl;
    cout << "平均带权周转时间:" << avg_turnaround_time << endl;
}

void HRN(struct Process pr[], int num)
{
    int i, j, total_time = 0;
    float highest_response_ratio, response_ratio, avg_wait_time, avg_turnaround_time;
    int waiting_time[num], turnaround_time[num];

    waiting_time[0] = 0; // 初始进程等待时间为0

    for (i = 1; i < num; i++)
    {
        // 计算等待时间
        waiting_time[i] = waiting_time[i - 1] + pr[i - 1].Time - pr[i].ArriveTime;
        pr[i].FinishTime = waiting_time[i] + pr[i].Time;
        // 如果等待时间为负数，将其置为0
        if (waiting_time[i] < 0)
            waiting_time[i] = 0;
    }

    cout << "进程名\t服务时间\t完成时间\t等待时间\t周转时间\t响应比" << endl;
    for (i = 0; i < num; i++)
    {
        total_time += waiting_time[i];
        turnaround_time[i] = pr[i].Time + waiting_time[i];
        response_ratio = (float)turnaround_time[i] / pr[i].Time;

        // 输出每个进程的等待时间和周转时间
        cout << pr[i].ProcessName << "\t\t" << pr[i].Time << "\t\t" << pr[i].FinishTime << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << "\t\t" << response_ratio << endl;
    }
    // 输出平均等待时间和平均周转时间
    avg_wait_time = total_time / num;
    total_time = 0;
    for (i = 0; i < num; i++)
    {
        total_time += turnaround_time[i];
    }
    avg_turnaround_time = total_time / num;
    cout << "平均等待时间:" << avg_wait_time << endl;
    cout << "平均带权周转时间:" << avg_turnaround_time << endl;

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

    cout << "最高响应比进程：" << pr[j].ProcessName << endl;
}
void TimeTurn(Process pr[], int num, int Timepice)
{
    int i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0, avg_weighted_turnaround_time = 0;
    int time_quantum = Timepice; // 时间片长度
    int remain = num;            // 剩余进程数量
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

    cout << "进程名\t完成时间\t周转时间\t等待时间" << endl;
    for (i = 0; i < num; i++)
    {
        cout << pr[i].ProcessName << "\t\t" << pr[i].FinishTime << "\t\t" << pr[i].FinishTime - pr[i].ArriveTime << "\t\t"
             << waiting_time[i] << endl;
    }
    cout << "\n平均等待时间：" << avg_waiting_time << endl;
    cout << "平均周转时间：" << avg_turnaround_time << endl;
    cout << "平均带权周转时间：" << avg_weighted_turnaround_time << endl;
}

int main()
{
    int type; // 选择算法的类型
    int num;  // 进程个数
    int Timepice;
    const int Size = 30;
    struct Process process[Size];

    cout << "请输入进程个数(不超过30):" << endl;
    cin >> num;

    Init(process, num); // 初始化

    cout << "进程名:\t进程到达系统时间:\t进程执行时间:\t优先权:\n"
         << endl;
    for (int i = 0; i < num; i++)

    {

        cout << process[i].ProcessName << "               " << process[i].ArriveTime << "               "
             << process[i].Time << "             " << process[i].leval << endl;
    }
    cout << "  1: FCFS  2: 短作业优先 3: 高优先权 4: 高响应比算法 5: 时间片轮转算法" << endl;
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
        cout << "请输出时间片" << endl;
        cin >> Timepice;

        TimeTurn(process, num, Timepice);

        break;
    default:
        cout << "输入算法类型错误!" << endl;
    }

    system("pause");
    return 0;
}
