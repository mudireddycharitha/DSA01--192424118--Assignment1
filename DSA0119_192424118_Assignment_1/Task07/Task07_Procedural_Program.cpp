
#include <iostream>
#include <iomanip>
using namespace std;

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(int zone, bool peak)
{
    int baseFare;

    switch (zone)
    {
        case 1:
            baseFare = BASE_PAISE[0];
            break;

        case 2:
            baseFare = BASE_PAISE[1];
            break;

        case 3:
            baseFare = BASE_PAISE[2];
            break;

        default:
            return -1;
    }

    long long totalFare = baseFare;

    if (peak)
    {
        totalFare +=
            (baseFare * PEAK_SURCHARGE_PERCENT) / 100;
    }

    return totalFare;
}

bool canTravel(long long balance, long long fare)
{
    return (fare >= 0 &&
            balance >= fare &&
            balance - fare >= MIN_BALANCE_PAISE);
}

bool deduct(long long &balance, long long fare)
{
    if (canTravel(balance, fare))
    {
        balance -= fare;
        return true;
    }

    return false;
}

void displayMoney(long long amount)
{
    cout << amount / 100 << "."
         << setw(2) << setfill('0')
         << amount % 100 << setfill(' ');
}

int main()
{
    long long balance = 10000;

    int zones[] = {1, 3, 2};
    bool peakHours[] = {false, true, false};

    cout << "====================================\n";
    cout << "   METRO SMART CARD - PROCEDURAL\n";
    cout << "====================================\n";

    for (int i = 0; i < 3; i++)
    {
        long long f = calculateFare(
            zones[i], peakHours[i]);

        cout << "\nJourney " << i + 1 << ": ";

        if (f < 0)
        {
            cout << "Invalid zone\n";
            continue;
        }

        if (deduct(balance, f))
        {
            cout << "Fare Rs ";
            displayMoney(f);
            cout << " | Approved";
        }
        else
        {
            cout << "Denied (low balance)";
        }

        cout << " | Balance Rs "
             << balance / 100 << "."
             << setw(2) << setfill('0')
             << balance % 100 << setfill(' ')
             << '\n';
    }

    cout << "\nFinal Balance: Rs ";
    displayMoney(balance);

    cout << "\n====================================\n";

    return 0;
}
