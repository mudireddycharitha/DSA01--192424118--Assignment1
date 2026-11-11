
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>

using namespace std;

double readAmount(string message, bool allowZero)
{
    double value;

    while (true)
    {
        cout << message;
        cin >> value;

        if (cin.fail())
        {
            cout << "Invalid input! Please enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (!isfinite(value) || value < 0 ||
            (!allowZero && value == 0))
        {
            cout << "Invalid amount! Enter a valid positive value.\n";
            continue;
        }

        return value;
    }
}

int main()
{
    string passengerName;
    string sourceStation;
    string destinationStation;

    double balance, fare, remainingBalance;

    cout << "\n";
    cout << "============================================\n";
    cout << "          METRO SMART CARD SYSTEM           \n";
    cout << "============================================\n";

    cout << "\nEnter Passenger Name: ";
    getline(cin, passengerName);

    cout << "Enter Source Station: ";
    getline(cin, sourceStation);

    cout << "Enter Destination Station: ";
    getline(cin, destinationStation);

    balance = readAmount("\nEnter Card Balance (Rs.): ", true);

    fare = readAmount("Enter Journey Fare (Rs.): ", false);

    cout << "\n\n";
    cout << "============================================\n";
    cout << "              JOURNEY REPORT                \n";
    cout << "============================================\n";

    cout << fixed << setprecision(2);

    cout << left << setw(25) << "Passenger Name"
         << ": " << passengerName << '\n';

    cout << left << setw(25) << "Source Station"
         << ": " << sourceStation << '\n';

    cout << left << setw(25) << "Destination Station"
         << ": " << destinationStation << '\n';

    cout << "--------------------------------------------\n";

    cout << left << setw(25) << "Card Balance"
         << ": Rs. " << balance << '\n';

    cout << left << setw(25) << "Journey Fare"
         << ": Rs. " << fare << '\n';

    cout << "--------------------------------------------\n";

    if (balance >= fare)
    {
        remainingBalance = balance - fare;

        cout << left << setw(25) << "Remaining Balance"
             << ": Rs. " << remainingBalance << '\n';

        cout << "--------------------------------------------\n";

        cout << "GATE STATUS : APPROVED\n";
        cout << "MESSAGE     : Journey Authorized!\n";
    }
    else
    {
        cout << left << setw(25) << "Remaining Balance"
             << ": Rs. " << balance << '\n';

        cout << "--------------------------------------------\n";

        cout << "GATE STATUS : DENIED\n";
        cout << "MESSAGE     : Insufficient Balance!\n";
    }

    cout << "============================================\n";
    cout << "          THANK YOU! TRAVEL SAFE            \n";
    cout << "============================================\n";

    return 0;
}
