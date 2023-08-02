#include <bits/stdc++.h>
using namespace std;

// A sample function whose time taken to
// be measured
void fun()
{
    for (int i=0; i<10; i++)
    {
    }
}

int main()
{
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;

    /* You can call it like this : start = time(NULL);
     in both the way start contain total time in seconds
     since the Epoch. */
    time(&start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    fun();

    // Recording end time.
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
