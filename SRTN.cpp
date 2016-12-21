#include <iostream>
#include <cstdlib>
using namespace std;

void SRTN(){
    int ar_time;                // arrival time
    int b_time;                 // burst time
    int numOfProcess=0;         // total number of processes
    int countInsertProcess=0;   // counter for number if processes
    int t_waitTime;             // total wait time
    int t_turnaroundTime;       // total turnaround time
    int t_burstTime;            // total burst time
    int time, remain, endTime, smallest, n, i;
    float avg_WaitingTime;
    float avg_TurnaroundTime;

    int burstTime_store[10];// = new int[10];    // array storing burst time of the processes
    int arrivalTime_store[10];// = new int[10];  // array storing arrival time of the processes
    int turnaroundTime_store[10];// = new int[10]; // store the turnaround for every process
    int waitingTime_store[10];// = new int[10]; // store the waiting time for every process.
    int remainingTime[10];// = new int[10];      // remaining of process.
    int finish[10];// = new int[10];             // process complete

    // asking user how many process will be calculated
    do{
        cout << "How many processes (3-7): ";
        cin >> numOfProcess;
        if (numOfProcess<2 || numOfProcess>7)
            cout << "Invalid input.\n";
    }while(numOfProcess<2 || numOfProcess>7);

    // input the detail of the process involve
    for (int i=1; i<=numOfProcess; i++){
        cout << "Process[" << i << "]:\n";
        cout << "Arrival time: ";
        cin >> ar_time;
        arrivalTime_store[i-1] = ar_time;
        //cout << endl;
        cout << "Burst time: ";
        cin >> b_time;
        burstTime_store[i-1] = b_time;
    }

    // Print the inserted input.
    cout << endl << endl;
    cout << "\t--------------------------------\n";
    cout << "\t|   Processes input detail     |\n";
    cout << "\t--------------------------------\n";
    cout << "Process \t Arrival time \t Burst time\n";
    for (int i=0; i<numOfProcess; i++){
        cout << "P[" << i << "]\t\t\t" << arrivalTime_store[i] << "\t\t" << burstTime_store[i] << endl;
    }
    cout << endl;

    t_turnaroundTime = 0;
    t_waitTime = 0;

    for (int i=0; i<numOfProcess; i++){
        remainingTime[i] = burstTime_store[i];
    }

    i=0;
    remain=0;
     cout << "        Shortest Remaining Time Next    \n";
     cout << "--------------------------------------------\n";
     cout << "| Process | Turnaround Time | Waiting Time |\n";
     cout << "--------------------------------------------\n";
    remainingTime[11] = 999;
    remain = numOfProcess;

    for(time=0;remain!=0;time++){
        smallest=11;
        for(i=0;i<=numOfProcess;i++){
            if(arrivalTime_store[i]<=time && remainingTime[i]<remainingTime[smallest]  && remainingTime[i]>0){
                smallest=i;
            }
        }
        if(smallest==11){
            continue;
        }
        remainingTime[smallest]--;

        if(remainingTime[smallest]==0)
        {
            remain--;
            endTime=time+1;
            cout << "| P[" << smallest+1 << "]"<< "    |       "<<time+1- arrivalTime_store[smallest] << "         "<< "|         "<<time+1- arrivalTime_store[smallest]-burstTime_store[smallest] << "    |"<<endl;
            cout << "--------------------------------------------\n";

            t_waitTime+=endTime-burstTime_store[smallest]-arrivalTime_store[smallest];
            t_turnaroundTime+=endTime-arrivalTime_store[smallest];

        }
    }

    cout << endl;
    t_waitTime = t_waitTime / numOfProcess;
    t_turnaroundTime = t_turnaroundTime / numOfProcess;

    cout << "\n\nThe Average Turnaround for SRTN is    : " <<  t_turnaroundTime <<endl;
    cout << "The Average Waiting Time for SRTN is  : " <<  t_waitTime <<endl;
}

int main()
{
    SRTN();

}
