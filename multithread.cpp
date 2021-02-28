// Aaron FInlay
// C00226131
// DCCD Assignment
// SUbmission Date: 26/02/21

/* A prime pair, aka twin prime, is a prime number that has a prime gap of two, i.e., differs   
from  another prime number by two, e.g. the twin prime pair (41, 43).
*/

#include <deque> 
#include <omp.h>
#include <iostream>
#include <ctime>

using namespace std;

#define NUM_THREADS 1

//Code used to print every twin prime in output
void printDeque(deque<int>primeNums)
{
    int count = 0;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for
    for (int i = 0; i < primeNums.size() -1; i++)
    {
        if(primeNums.at(i+1) - primeNums.at(i) == 2)
        {
             cout << primeNums.at(i) << ","
            << primeNums.at(i+1) << endl; 
             count +=1;

        }
    
    cout << "Pairs of Twin Prime Numbers: " << count << endl;
    }
}
// divide each number with different prime numbers. e.g. if 27 is a prime, one thread will divide 27 by 2 and another thread 27 by 5. 
//Reason: 27/2:localNum = 1 remainder
// 27/3:localNum = 0 remainder 
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
                        int localNum = 0;
                    if(number % primeNums[j] == 0) 
                    {
                        localNum = 0;
                    }
                    else
                    {
                            localNum = 1;
                            isPrimeNum = localNum + isPrimeNum;
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
            printDeque(primeNums);
            }
}

int main (int argc, char* argv[])
{
    double durationPeriod = 0.00;
    clock_t startClock;
    deque<int> primeNums; //stores all the found prime nums here
    primeNums.push_back(2);
    primeNums.push_back(3);
    primeNums.push_back(5);      
    primeNums.push_back(7);
    primeNums.push_back(11);
    primeNums.push_back(13);
    primeNums.push_back(17);
    primeNums.push_back(19);
    primeNums.push_back(23);
    primeNums.push_back(29);
    primeNums.push_back(31);
    primeNums.push_back(37);
    primeNums.push_back(41);
    primeNums.push_back(43);
    primeNums.push_back(47);



    int maxNumber = 50;
    startClock = clock();
    findPrime_innerLoop(primeNums, maxNumber);
    durationPeriod = (clock() - startClock) / (double)CLOCKS_PER_SEC;

    cout << "\n Time to compute: " << durationPeriod << "seconds" << endl; //total num of secs passed
    cout<< endl;

    system("pause");
    
}
    





























