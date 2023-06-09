#include <chrono>
#include <fstream>
#include <algorithm>
#include <string>

#define n 1000000

using namespace std;

int main()
{
    string filename = "testx.txt"; // test number x

    // Open the report file
    ofstream fo;
    fo.open("SortInCpp_report.txt");

    // Loop through every single test
    for (char i = '0'; i < ':'; i++)
    { // i is the test index
        // array to store the numbers in test i
        long *numarr = new long[n];

        // Open test i and read the numbers
        filename[4] = i;
        ifstream fi;
        fi.open(filename);
        for (long j = 0; j < n; j++)
        {
            fi >> numarr[j];
        }
        fi.close();

        // Measure the time
        auto start = chrono::high_resolution_clock::now(); // start time
        sort(numarr, numarr + n);                          // sorting
        auto end = chrono::high_resolution_clock::now();   // end time
        chrono::duration<double> duration = end - start;   // calculate duration

        // Write the result
        fo << duration.count() << std::endl;

        // Free up memory
        delete[] numarr;
    }

    fo.close();
    return 0;
}
