
#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeakTime(int hour, int minute)
{
    int time = hour * 60 + minute;

    return ((time >= 480 && time <= 600) ||
            (time >= 1020 && time <= 1200));
}

long long fare(Zone z, bool peak)
{
    int baseFare;

    switch (z)
    {
        case Zone::Inner:
            baseFare = BASE_PAISE[0];
            break;

        case Zone::Middle:
            baseFare = BASE_PAISE[1];
            break;

        case Zone::Outer:
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

bool canTravel(long long balance, long long f)
{
    return (f >= 0 &&
            balance >= f &&
            balance - f >= MIN_BALANCE_PAISE);
}

void displayMoney(long long amount)
{
    cout << amount / 100 << "."
         << setw(2) << setfill('0')
         << amount % 100
         << setfill(' ');
}

int main()
{
    long long balance = 10000;  

    struct Trip
    {
        Zone zone;
        int hour;
        int minute;
        bool endOfDay = false;
    };

    Trip trips[] =
    {
        {Zone::Inner, 11, 0},
        {Zone::Outer, 17, 30},
        {Zone::Middle, 14, 0},

        {static_cast<Zone>(99), 12, 0},

        {Zone::Inner, 0, 0, true}
    };

    cout << "====================================\n";
    cout << "       METRO SMART CARD SYSTEM\n";
    cout << "       DAILY FARE PROCESSING\n";
    cout << "====================================\n\n";

    for (const Trip& t : trips)
    {
        if (t.endOfDay)
        {
            break;
        }

        long long f = fare(t.zone, false);

        if (f < 0)
        {
            cout << "Invalid journey skipped\n";
            continue;
        }

        bool peak = isPeakTime(t.hour, t.minute);

        f = fare(t.zone, peak);

        if (canTravel(balance, f))
        {
            balance -= f;

            cout << "Fare Rs ";
            displayMoney(f);
        }
        else
        {
            cout << "Denied (low balance)";
        }

        cout << " balance Rs "
             << balance / 100 << '\n';
    }

    cout << "\nPeak Hour Boundary Tests\n";

    bool morningPeak = isPeakTime(10, 0);
    bool eveningPeak = isPeakTime(20, 0);

    cout << "10:00 AM: "
         << (morningPeak ? "Peak" : "Non-Peak")
         << " - Fare Rs ";

    displayMoney(fare(Zone::Inner, morningPeak));

    cout << '\n';

    cout << "8:00 PM: "
         << (eveningPeak ? "Peak" : "Non-Peak")
         << " - Fare Rs ";

    displayMoney(fare(Zone::Inner, eveningPeak));

    cout << '\n';

    cout << "\n====================================\n";
    cout << "Final Card Balance: Rs "
         << balance / 100 << '\n';
    cout << "====================================\n";

    return 0;
}
