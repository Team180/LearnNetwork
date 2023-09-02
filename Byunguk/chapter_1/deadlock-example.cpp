#include <iostream>
#include <thread>

using namespace std;

int a = 0;
recursive_mutex a_mutex;

int b = 0;
recursive_mutex b_mutex;

int main()
{
    thread t1([]()
    {
        while (true)
        {
            lock_guard<recursive_mutex> a_guard(a_mutex);
            a++;
            lock_guard<recursive_mutex> b_guard(b_mutex);
            b++;
            cout << "t1 done" << endl;
        }
    });

    thread t2([]()
    {
        while (true)
        {
            lock_guard<recursive_mutex> b_guard(b_mutex);
            b++;
            lock_guard<recursive_mutex> a_guard(a_mutex);
            a++;
            cout << "t2 done" << endl;
        }
    });

    t1.join();
    t2.join();

    return 0;
}