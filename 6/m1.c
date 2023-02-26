#include <stdio.h>

int frameSize;
/********************************************************Common for ALL START*************************************************************************************/
int checkPageFault(int page, int frames[])
{
    for (int i = 0; i < frameSize; i++)
    {
        if (frames[i] == page)
        {
            return 0;
        }
    }
    return 1;
}

void printFrame(int frames[], int size, char hm)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", frames[i]);
    }
    printf("%c\n", hm);
}
/********************************************************Common for ALL END*************************************************************************************/

/********************************************************FIFO START*************************************************************************************/
int fifo(int requestSequence[], int seq)
{
    int size = 0;
    int frames[frameSize];
    int ind = 0;
    int numberOfPageFault = 0;
    for (int i = 0; i < seq; i++)
    {
        if (checkPageFault(requestSequence[i], frames))
        {
            if (size < frameSize)
            {
                numberOfPageFault++;
                frames[i] = requestSequence[i];
                size++;
                printFrame(frames, size, 'm');
            }
            else
            {
                numberOfPageFault++;
                frames[ind] = requestSequence[i];
                ind = (ind + 1) % frameSize;
                printFrame(frames, size, 'm');
            }
        }
        else
        {
            printFrame(frames, size, 'h');
        }
    }

    return numberOfPageFault;
}
/********************************************************FIFO END*************************************************************************************/

/********************************************************OPTIMAL START*************************************************************************************/
int getFarthestIndex(int requestResponse[], int start, int seq, int frames[])
{
    int far = -1;
    int ind;
    for (int i = 0; i < frameSize; i++)
    {
        int flagToCheckNoOcurrance = 0;
        for (int j = start; j < seq; j++)
        {
            if (frames[i] == requestResponse[j])
            {
                if (far < j)
                {
                    ind = i;
                    far = j;
                }
                flagToCheckNoOcurrance = 1;
                break;
            }
        }
        if (flagToCheckNoOcurrance == 0)
        {
            return i;
        }
    }
    return ind;
}

int optimal(int requestSequence[], int seq)
{
    int numberOfPageFaults = 0;
    int size = 0;
    int frames[frameSize];
    for (int i = 0; i < seq; i++)
    {
        if (checkPageFault(requestSequence[i], frames))
        {
            if (size < frameSize)
            {
                frames[i] = requestSequence[i];
                numberOfPageFaults++;
                size++;
                printFrame(frames, size, 'm');
            }
            else
            {
                int ind = getFarthestIndex(requestSequence, i - 1, seq, frames);
                numberOfPageFaults++;
                frames[ind] = requestSequence[i];
                printFrame(frames, size, 'm');
            }
        }
        else
        {
            printFrame(frames, size, 'h');
        }
    }
    return numberOfPageFaults;
}
/********************************************************OPTIMAL END*************************************************************************************/

/********************************************************LRU START*************************************************************************************/

int getLeastRecentlyUsedInd(int requestSequence[], int start, int frames[], int seq)
{
    int least = seq;
    int ind;
    for (int i = 0; i < frameSize; i++)
    {
        for (int j = start; j >= 0; j--)
        {
            if (requestSequence[j] == frames[i])
            {
                if (least > j)
                {
                    least = j;
                    ind = i;
                }
                break;
            }
        }
    }
    return ind;
}
int lru(int requestSequence[], int seq)
{
    int numberOfPageFaults = 0;
    int size = 0;
    int frames[frameSize];
    for (int i = 0; i < seq; i++)
    {

        if (checkPageFault(requestSequence[i], frames))
        {
            if (size < frameSize)
            {
                frames[i] = requestSequence[i];
                numberOfPageFaults++;
                size++;
                printFrame(frames, size, 'm');
            }
            else
            {
                int ind = getLeastRecentlyUsedInd(requestSequence, i - 1, frames, seq);
                frames[ind] = requestSequence[i];
                numberOfPageFaults++;
                printFrame(frames, size, 'm');
            }
        }
        else
        {
            printFrame(frames, size, 'h');
        }
    }
    return numberOfPageFaults;
}
/********************************************************LRU END*************************************************************************************/

int main()
{
    int seq;
    printf("Enter Request Sequence size: ");
    scanf("%d", &seq);
    // int requestSequence[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,3,};
    int requestSequence[seq];
    for (int i = 0; i < seq; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &requestSequence[i]);
    }
    printf("\nEnter Frame size: ");
    scanf("%d", &frameSize);
    int answer;
    int choice = 0;
    while (choice != 4)
    {
        printf("\n\nEnter Choice: \n1. FIFO\n2.OPTIMAL\n3.LRU\n4.EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            answer = fifo(requestSequence, seq);
            printf("\nTotal Number of page faults for FIFO are: %d", answer);
            break;
        case 2:
            answer = optimal(requestSequence, seq);
            printf("\nTotal Number of page faults for OPTIMAL are: %d", answer);
            break;
        case 3:
            answer = lru(requestSequence, seq);
            printf("\nTotal Number of page faults for LRU are: %d", answer);
            break;
        case 4:
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }
    return 0;
}