//Aaron Finlay
//DCDD Assignment
// Submission Date: 26/02/21
// Prime pairs or twin primes is a prome no. that has a prime gap of two, which basically differs from another
//Prime no. by two, e.g. the twin prime pair (41, 43).
//Aim is to find all prime no. between 1-50

//Most involved tasks will be finding the prime no. and printing/counting twinPrime
#include <ctime>
#include <deque>
#include <iostream>

using namespace std;

void printDeque(deque<int>primeNums)
    {
        int count = 0; 
        for (int i = 0; i < primeNums.size() -1; i++)
            {
                if (primeNums.at(i + 1) - primeNums.at(i) == 2)
                    {
                        cout << primeNums.at(i) << "," 
                        << primeNums.at(i + 1) << endl;
                        count++;
                    }   
            }
            cout << "Pairs of Tin Primes: " << count << endl;
    }

void prime(deque<int>primeNums, int maxNumber)//can only check odd numbers hence num+=2
{
    for (int number = 3; number<maxNumber; number+=2) // max int to be checked
    {
        bool isPrimeNum = false;
        //Divide number by primeNumber < number/2
        for (int j = 0; j < primeNums.size() && (primeNums[j] < maxNumber / 2) +1; j++)
            {
                if (number % primeNums[j] == 0) //for composite num
                                                //break the loop
                {
                    isPrimeNum = false;
                    break;
                }
                else
                {
                    isPrimeNum = true;
                }
                if (isPrimeNum)
                {
                    primeNums.push_back(number);
                }
            }      
    }
    printDeque(primeNums);
}

void main()
;{
    double durationPeriod = 0.00;
    clock_t startClock;
    deque<int> primeNums; //this code stores found prime numbers
    primeNums.push_back(2);
    int maxNumber = 50;
    startClock = clock();
    prime(primeNums, maxNumber);
    durationPeriod = (clock() - startClock) / (double)CLOCKS_PER_SEC;

    cout << "\nTime taken to compute: " << durationPeriod << " seconds" << endl; //amount of seconds passed
    cout << endl;
    system("pause");
}
                
            










