// Aaron FInlay
// C00226131
// DCCD Assignment
// SUbmission Date: 26/02/21

/* A prime pair, aka twin prime, is a prime number that has a prime gap of two, i.e., differs   
from  another prime number by two, e.g. the twin prime pair (41, 43).
The aim is trying to find all twin prime between 1-2000. This is a parallel program in OpenMP.
*/

#include <deque> 
#include <omp.h>
#include <iostream>
#include <ctime>

using namespace std;

#define NUM_THREADS 8

/* 
Only needed if wished to output all twin prime.
In this scenario, count of twin primes only is desired
void printDeque(deque<int>primeNums)
{
    int count = 0;
    omp_set_num_threads(NUM_THREADS);
    #pragmq omp parallel for
    for (int i = 0; i < primeNums.size() -1; i++)
    {
        /*cout << primeNums.at(i+1) - primeNums.at(i) == 2)
        {
            /* cout << primeNums.at(i) << ","
            << primeNums.at(i+1) << endl; */
            /* count +=1;

        }
    }
    cout << "Pairs of Tein Prime Numbers: " << count << endl;
}*/

void findPrime_innerLoop(deque <int>primeNums, int maxNumber)
{
    int count = 0;
    for (int number = 3; number < maxNumber; number++)
        {
            int isPrimeNum = 0;

            //redirect function for isPrimeNUm needed
            omp_set_num_threads(NUM_THREADS);
            #pragma omp parallel for reduction(+:isPrimeNum)
                for (int j = 0; j < primeNums.size(); j++)
                {
                        int local = 0;
                    if(number % primeNums[j] == 0) 
                    {
                        local = 0;
                    }
                    else
                    {
                            local = 1;
                            isPrimeNum = local + isPrimeNum;
                    }
                    
                }
        if(isPrimeNum == primeNums.size())
            {
                if ((number - primeNums.back()) == 2)  
                    {
                        count += 1;
                        primeNums.push_back(number);
                    }
            }
            cout << "Pairs of Twin Prime" << count << endl;
            //printDeque(primeNUms);
}

void main()
;{
    double durationPeriod = 0.00;
    clock_t startClock;
    deque<int> primeNums; //stores all the found prime nums here
    primeNums.push_back(2);
    int maxNumber = 50;
    startClock = clock();
    findPrime_innerLoop(primeNums, maxNumber);
    durationPeriod = (clock() - startClock) / (double)CLOCKS_PER_SEC;

    cout << "\n Time to compute: " << durationPeriod << "seconds" << endl; //total num of secs passed
    cout<< endl;
    system("pause");
}





























