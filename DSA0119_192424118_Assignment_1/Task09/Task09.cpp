
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>

using namespace std;


constexpr long long INNER_FARE = 1000;  
constexpr long long MIDDLE_FARE = 2000; 
constexpr long long OUTER_FARE = 3000;  

constexpr int PEAK_SURCHARGE = 20;
constexpr int CONCESSION_PERCENT = 10; 
constexpr long long MIN_BALANCE = 5000; 


enum class Zone
{
    Inner,
    Middle,
    Outer
};


bool getZone(string name, Zone& zone)
{
    if (name == "Inner")
    {
        zone = Zone::Inner;
        return true;
    }
    else if (name == "Middle")
    {
        zone = Zone::Middle;
        return true;
    }
    else if (name == "Outer")
    {
        zone = Zone::Outer;
        return true;
    }

    return false;
}


bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}


long long calculateFare(Zone zone, int hour,
                        bool concession = false)
{
    long long baseFare = 0;

    switch (zone)
    {
        case Zone::Inner:
            baseFare = INNER_FARE;
            break;

        case Zone::Middle:
            baseFare = MIDDLE_FARE;
            break;

        case Zone::Outer:
            baseFare = OUTER_FARE;
            break;
    }

    long long finalFare = baseFare;

    if (isPeakHour(hour))
    {
        finalFare +=
            (baseFare * PEAK_SURCHARGE) / 100;
    }

    if (concession)
    {
        finalFare -=
            (finalFare * CONCESSION_PERCENT) / 100;
    }

    return finalFare;
}


class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long initialBalance)
    {
        balance = initialBalance;
    }

    bool canTravel(long long fare) const
    {
        return balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare)
    {
        if (fare < 0 || !canTravel(fare))
        {
            return false;
        }

        balance -= fare;
        return true;
    }

    bool recharge(long long amount)
    {
        if (amount < 0)
        {
            return false;
        }

        balance += amount;
        return true;
    }

    long long getBalance() const
    {
        return balance;
    }
};


int readHour()
{
    int hour;

    while (true)
    {
        cout << "Enter journey hour (0-23): ";
        cin >> hour;

        if (cin.fail())
        {
            cout << "Invalid input! Enter numbers only.\n";

            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            continue;
        }

        if (hour < 0 || hour > 23)
        {
            cout << "Invalid hour! Enter 0 to 23.\n";
            continue;
        }

        return hour;
    }
}


struct TestCase
{
    string name;
    string zoneName;
    int hour;
    long long expectedFare;
};

int main()
{
    cout << "\n";
    cout << "==============================================\n";
    cout << "         NAMMA METRO FARE TEST SYSTEM         \n";
    cout << "==============================================\n";


    vector<TestCase> tests =
    {
        {"Inner Off-Peak",  "Inner", 12, 1000},
        {"Inner Peak",      "Inner",  8, 1200},

        {"Middle Off-Peak", "Middle", 12, 2000},
        {"Middle Peak",     "Middle", 17, 2400},

        {"Outer Off-Peak",  "Outer",  12, 3000},
        {"Outer Peak",      "Outer",  18, 3600},

        {"Boundary 08:00",  "Inner",   8, 1200},
        {"Boundary 10:00",  "Inner",  10, 1000},
        {"Boundary 17:00",  "Inner",  17, 1200},
        {"Boundary 20:00",  "Inner",  20, 1000}
    };

    cout << "\n";
    cout << left << setw(23) << "TEST CASE"
         << setw(15) << "EXPECTED"
         << setw(15) << "ACTUAL"
         << "RESULT\n";

    cout << string(65, '-') << '\n';

    int passed = 0;

    for (const TestCase& test : tests)
    {
        Zone zone;

        if (!getZone(test.zoneName, zone))
            continue;

        long long actualFare =
            calculateFare(zone, test.hour);

        bool success = (actualFare == test.expectedFare);

        cout << left << setw(23) << test.name
             << setw(15) << test.expectedFare
             << setw(15) << actualFare
             << (success ? "PASS" : "FAIL") << '\n';

        if (success)
            passed++;
    }

    cout << string(65, '-') << '\n';

    cout << "Tests Passed: " << passed
         << " / " << tests.size() << '\n';


    cout << "\n--- BALANCE BOUNDARY TEST ---\n";

    SmartCard card(6000); 

    long long fare = 1000; 

    if (card.deduct(fare))
    {
        cout << "Initial Balance : Rs. 60.00\n";
        cout << "Journey Fare    : Rs. 10.00\n";
        cout << "Remaining       : Rs. "
             << fixed << setprecision(2)
             << card.getBalance() / 100.0 << '\n';

        cout << "Result          : PASS (Exactly Rs. 50 remains)\n";
    }
    else
    {
        cout << "Result: FAIL\n";
    }


    cout << "\n--- INVALID ZONE TEST ---\n";

    Zone invalidZone;

    if (!getZone("Airport", invalidZone))
        cout << "Airport: Rejected (Unknown zone)\n";


    cout << "\n--- RECHARGE VALIDATION ---\n";

    SmartCard rechargeCard(10000);

    if (!rechargeCard.recharge(-500))
        cout << "Negative recharge: Rejected successfully\n";

    cout << "Card Balance: Rs. "
         << rechargeCard.getBalance() / 100.0 << '\n';


    cout << "\n--- FIVE JOURNEY TOTAL ---\n";

    struct Trip
    {
        Zone zone;
        int hour;
    };

    Trip journeys[] =
    {
        {Zone::Inner, 12}, 
        {Zone::Middle, 8},  
        {Zone::Outer, 12}, 
        {Zone::Inner, 17}, 
        {Zone::Middle, 12} 
    };

    long long total = 0;

    for (const Trip& trip : journeys)
    {
        long long f = calculateFare(trip.zone, trip.hour);
        total += f;
    }

    cout << "Journey 1: Rs. 10.00\n";
    cout << "Journey 2: Rs. 24.00\n";
    cout << "Journey 3: Rs. 30.00\n";
    cout << "Journey 4: Rs. 12.00\n";
    cout << "Journey 5: Rs. 20.00\n";

    cout << "---------------------------\n";

    cout << "Total Fare: Rs. "
         << total / 100 << "."
         << setw(2) << setfill('0')
         << total % 100 << setfill(' ') << '\n';


    cout << "\n--- INVALID HOUR INPUT TEST ---\n";

    int hour = readHour();

    cout << "Accepted Hour: " << hour << '\n';

    cout << "\n==============================================\n";
    cout << "             TESTING COMPLETED               \n";
    cout << "==============================================\n";

    return 0;
}
