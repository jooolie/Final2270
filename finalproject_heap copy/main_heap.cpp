//
// Created by Josephine  Klefeker  on 4/29/18.
//
#include "finalproject_heap.h"

void split(string line, preg* lady )
{

    stringstream ss(line); //makes line into the thing you are reading from
    string s; // what you are reading into
    int i = 0;
    getline(ss, lady->name,',');
    getline(ss, s,',');
    lady->labor = stoi(s);
    getline(ss, s,',');
    lady->treatment = stoi(s);
}

int main(int argc, char* argv[])
{
    const int arrSize = 880;
    preg arr[arrSize];
    MinHeap M(arrSize);

    ifstream filename;

    if(argc == 2)
    {
        filename.open(argv[1]);
        if(!filename.fail())
        {
            string line;
            int index = 0;
            getline(filename, line, '\r');
            while(getline(filename, line, '\r'))
            {
                split(line, &arr[index]);

                index++;

            }
        }
        else{
            cout << "file failure" << endl;
        }
    }
    else
    {
        cout << "incorrect number of command line arguments" << endl;
    }

   /* const int array_size = 880;
    preg arry[array_size];

    for(int i = 0; i < arrSize; i++)
    {
        M.push(arr[i]);
    }


    for(int i = 0; i < arrSize; i++)
    {
        arry[i] = M.pop();
    }

    cout << "Rank" << '\t' << "patient,  " << "Priority,  " << "Treatment" << endl;
    for(int i = 0; i < arrSize; i++)
    {
        if(i < 9)
        {
            cout << i+1 << ":" << '\t' << arry[i].name << ",  " << arry[i].labor << ",  " <<  arry[i].treatment << endl;
        }
        else
        {
            cout << i+1 << ":" << '\t' << arry[i].name << ",  " << arry[i].labor << ",  " <<  arry[i].treatment << endl;
        }

    }*/

    int total_start_time = 0, total_end_time = 0;
    int pushStartTime=0,pushEndTime=0;
    int popStartTime = 0, popEndTime = 0;
    double push_sum = 0;
    double pop_sum = 0;
    double total_sum = 0;
    for(int i = 0; i< 500; i++) //500 iterations used to calc a mean val
    {
        cout << i << endl;
        total_start_time = clock();
        pushStartTime = clock();
        for(int j = 0; j < arrSize; j++)
        {
            M.push(arr[j]);
        }
        pushEndTime = clock();
        double push_run_time_sum = (double)(pushEndTime-pushStartTime); //time to push all nodes in array
        push_sum = push_sum + push_run_time_sum; //sum of all push times

        popStartTime = clock();
        for(int x = 0; x<arrSize; x++)
        {
            M.pop();
        }
        popEndTime = clock();
        total_end_time = clock();
        double pop_run_time_sum = (double) (popEndTime - popStartTime);
        pop_sum = pop_sum + pop_run_time_sum;
        double total_run_time_sum = (double) (total_end_time - total_start_time);
        total_sum = total_sum + total_run_time_sum;

    }
    double push_run_time_final = (push_sum/500)/CLOCKS_PER_SEC; //calc mean and convert to seconds
    double pop_run_time_final = (pop_sum/500)/CLOCKS_PER_SEC;
    double total_run_time_final = (total_sum/500)/CLOCKS_PER_SEC;

    cout << "Time to push elements onto heap: " << push_run_time_final << endl;
    cout << "Time to pop elements off of heap: " << pop_run_time_final << endl;
    cout << "Time to push and pop elements for heap: " << total_run_time_final << endl;


    return 0;

}
