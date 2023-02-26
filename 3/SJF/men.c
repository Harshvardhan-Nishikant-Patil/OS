#include <stdio.h>
#include <stdlib.h>
int choice;
int finish[10], process_name[10], arrival_time[10], burst_time[10], waiting_time[10], turn_around_time[10];
int avg_wait_time, avg_turn_around_time;
int n, pending, remain_burst_time[10], time, count;
void input()
{
    int i;
    printf("\nEnter number of processes");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        process_name[i] = i;
        printf("\n Enter Burst Time of Process %d:", process_name[i]);
        scanf("%d", &burst_time[i]);
        remain_burst_time[i] = burst_time[i];
        printf("\n Enter arrival time of Process %d:", process_name[i]);
        scanf("%d", &arrival_time[i]);
    }
}
void menu()
{
    printf("\n\n\n\n***MENU**");
    printf("\n 1. Round Robin");
    printf("\n 2. Sjf Preemptive");
    printf("\n 3. exit");
    printf("\n Enter your choice");
    scanf("%d", &choice);
}
void output()
{
    int i;
    printf("\n\n\nProcess \tA.T. \tB.T. \tW.T. \tT.A.T");
    for (i = 0; i < n; i++)
        printf("\n P%d \t %d \t %d \t %d \t %d", process_name[i], arrival_time[i], burst_time[i],
               waiting_time[i], turn_around_time[i]);
}
void round_robin()
{
    int time_quantam, i;
    input();
    pending = n;
    printf("\n Enter time Quantam");
    scanf("%d", &time_quantam);

    printf("\nGantt Chart==> ");

    // initialize finish and wait time for all processes to 0

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
        waiting_time[i] = 0;
    }
    // Start execution
    for (time = 0, count = 0; pending > 0;)
    {
        // case for remaining burst time less than or equal to time quantum
        if (finish[count] != 1 && arrival_time[count] <= time &&
            remain_burst_time[count] <= time_quantam)
        {

            time += remain_burst_time[count];
            // Complete process and decalre as finshed
            pending--;
            finish[count] = 1;
            waiting_time[count] -= arrival_time[count];
            turn_around_time[count] = waiting_time[count] + burst_time[count];
            // output(count);

            // Print gant chart
            for (i = 0; i < remain_burst_time[count]; i++)
                printf("P%d ", process_name[count]);
            for (i = 0; i < n; i++)
            {
                if (i == count || finish[i] == 1)
                    continue;
                waiting_time[i] += remain_burst_time[count];
            }
            remain_burst_time[count] = 0;
        }

        // case 2 burst time greater than time quantam
        else if (finish[count] != 1 && arrival_time[count] <= time &&
                 remain_burst_time[count] >= time_quantam)
        {
            remain_burst_time[count] -= time_quantam;
            time += time_quantam;
            for (i = 0; i < n; i++)
            {
                if (i == count || finish[i] == 1)
                    continue;
                waiting_time[i] += time_quantam;
            }
            // gantt chart
            for (i = 0; i < time_quantam; i++)
                printf("P%d ", process_name[count]);
        }
        count = (count + 1) % 3;
    }
    output();
}
void sort()
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (remain_burst_time[i] < remain_burst_time[j])
            {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = remain_burst_time[i];
                remain_burst_time[i] = remain_burst_time[j];
                remain_burst_time[j] = temp;

                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = waiting_time[i];
                waiting_time[i] = waiting_time[j];
                waiting_time[j] = temp;

                temp = process_name[i];
                process_name[i] = process_name[j];
                process_name[j] = temp;

                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;
            }
        }
    }
}
void sjf_preempt()
{
    int i;
    input();
    pending = n;
    printf("\n\n\nGantt Chart==> ");
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
        waiting_time[i] = 0;
    }

    for (time = 0, count = 0; pending > 0;)
    {
        sort();
        for (count = 0; count < n; count++)
        {
            if (finish[count] != 1 && arrival_time[count] <= time)
            {
                // gant chart
                printf("P%d ", process_name[count]);
                // increment time line
                time += 1;
                remain_burst_time[count] -= 1;

                for (i = 0; i < n; i++)
                {
                    if (i == count || finish[i] == 1)
                        continue;
                    waiting_time[i] += 1;
                }

                if (remain_burst_time[count] == 0)
                {
                    pending--;
                    finish[count] = 1;
                    waiting_time[count] -= arrival_time[count];
                    turn_around_time[count] = waiting_time[count] + burst_time[count];
                }
                break;
            }
        }
    }
    output();
}
int main()
{
    while (1)
    {
        menu();
        switch (choice)
        {
        case 1:
            round_robin();
            break;
        case 2:
            sjf_preempt();
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
