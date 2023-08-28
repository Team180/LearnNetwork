#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
const int MaxCount = 1500000;

bool IsPrimeNumber(int num)
{
    if (num == 1) return false;
    if (num == 2 || num == 3) return true;

    for (int i = 2; i < num - 1; i++)
    {
        if (num % i == 0) return false;
    }

    return true;
}

void PrintNumbers(const vector<int>& primes)
{
    for (int v : primes)
        cout << v << endl;
}

int main()
{
    vector<int> primes;

    auto t0 = chrono::system_clock::now();

    for (int i = 1; i <= MaxCount; i++)
    {
        if (IsPrimeNumber(i)) primes.push_back(i);
    }

    auto t1 = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
    cout << "Took " << duration << " ms" << endl;

    // PrintNumbers(primes);

    return 0;
}

