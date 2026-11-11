
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

const double fares[] = {
    10.00, 24.00, 30.00, 12.00, 20.00
};

const long long faresPaise[] = {
    1000, 2400, 3000, 1200, 2000
};

const int PATTERN_SIZE = 5;

void calculateTotals(long long journeyCount)
{
    double doubleTotal = 0.0;
    long long paiseTotal = 0;

    int intTotal = 0;
    bool intOverflow = false;

    for (long long i = 0; i < journeyCount; i++)
    {
        int index = i % PATTERN_SIZE;

        doubleTotal += fares[index];

        paiseTotal += faresPaise[index];

        if (!intOverflow)
        {
            if (faresPaise[index] > INT_MAX - intTotal)
            {
                intOverflow = true;
            }
            else
            {
                intTotal += static_cast<int>(faresPaise[index]);
            }
        }
    }

    cout << "\nJourney Count: " << journeyCount << '\n';

    cout << "Double Total (Rs.) : "
         << fixed << setprecision(2)
         << doubleTotal << '\n';

    cout << "Integer Total (Rs.): "
         << static_cast<double>(paiseTotal) / 100.0
         << '\n';

    cout << "Difference (Rs.)   : "
         << fixed << setprecision(2)
         << (doubleTotal -
             static_cast<double>(paiseTotal) / 100.0)
         << '\n';

    if (intOverflow)
    {
        cout << "Int Status         : OVERFLOW WOULD OCCUR\n";
    }
    else
    {
        cout << "Int Status         : SAFE\n";
        cout << "Int Total (Paise)  : " << intTotal << '\n';
    }

    cout << "Long Long (Paise)  : " << paiseTotal << '\n';

    cout << "--------------------------------------------\n";
}

int main()
{
    cout << "============================================\n";
    cout << "      METRO NETWORK TOTAL COMPARISON        \n";
    cout << "============================================\n";

    cout << "\nFive Journey Fare Pattern:\n";

    for (int i = 0; i < PATTERN_SIZE; i++)
    {
        cout << "Journey " << i + 1
             << " : Rs. " << fixed << setprecision(2)
             << fares[i] << '\n';
    }

    cout << "\nTotal for Five Journeys: Rs. 96.00\n";

    calculateTotals(20000);
    calculateTotals(500000);
    calculateTotals(3000000);

    cout << "\n--- FLOATING-POINT PRECISION TEST ---\n";

    double a = 0.1;
    double b = 0.2;

    cout << setprecision(17);
    cout << "0.1 + 0.2 = " << a + b << '\n';

    cout << "\n--- FINAL EVALUATION ---\n";
    cout << "Integer-paise calculation is preferred.\n";
    cout << "long long safely stores the network total.\n";
    cout << "A 32-bit int cannot store the final paise total.\n";

    cout << "\n============================================\n";
    cout << "             TESTING COMPLETED              \n";
    cout << "============================================\n";

    return 0;
}
