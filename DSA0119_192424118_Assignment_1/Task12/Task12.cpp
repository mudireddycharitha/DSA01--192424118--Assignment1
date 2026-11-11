
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

using Money = long long;

const Money MINIMUM_BALANCE = 5000;
const int PEAK_SURCHARGE = 20;
const int WEEKEND_DISCOUNT = 10;

enum class Zone {
    Inner,
    Middle,
    Outer,
    Airport,
    Count
};

const array<Money, 4> FARE_TABLE = {
    1000, 2000, 3000, 6000
};

const char* zoneName(Zone zone) {
    switch (zone) {
        case Zone::Inner:   return "Inner";
        case Zone::Middle:  return "Middle";
        case Zone::Outer:   return "Outer";
        case Zone::Airport: return "Airport";
        default:            return "Invalid";
    }
}

int zoneIndex(Zone zone) {
    return static_cast<int>(zone);
}

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

Money calculateFare(Zone zone, int hour, bool weekend) {
    int index = zoneIndex(zone);

    if (index < 0 ||
        index >= static_cast<int>(FARE_TABLE.size())) {
        return -1;
    }

    if (hour < 0 || hour > 23) {
        return -1;
    }

    Money fare = FARE_TABLE[index];

    if (weekend) {
        fare = fare * (100 - WEEKEND_DISCOUNT) / 100;
    }
    else if (isPeakHour(hour)) {
        fare = fare * (100 + PEAK_SURCHARGE) / 100;
    }

    return fare;
}

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;
    bool active;

public:
    MonthlyPass(Zone first, Zone second)
        : firstZone(first),
          secondZone(second),
          active(true) {}

    bool covers(Zone zone) const {
        return active &&
               (zone == firstZone || zone == secondZone);
    }

    void deactivate() {
        active = false;
    }
};

// SmartCard manages balance and travel payments.
class SmartCard {
private:
    Money balance;

public:
    SmartCard(Money initialBalance) {
        balance = initialBalance;
    }

    Money getBalance() const {
        return balance;
    }

    bool recharge(Money amount) {
        if (amount <= 0) {
            return false;
        }

        balance += amount;
        return true;
    }

    bool travel(Zone zone, int hour, bool weekend,
                const MonthlyPass* pass) {

        if (pass != nullptr && pass->covers(zone)) {
            cout << zoneName(zone)
                 << " journey: Covered by monthly pass.\n";
            return true;
        }

        Money fare = calculateFare(zone, hour, weekend);

        if (fare < 0) {
            cout << "Invalid journey details.\n";
            return false;
        }

        if (balance < fare ||
            balance - fare < MINIMUM_BALANCE) {

            cout << zoneName(zone)
                 << " journey: Rejected. Minimum balance rule.\n";
            return false;
        }

        balance -= fare;

        cout << zoneName(zone)
             << " journey: Fare Rs. "
             << fixed << setprecision(2)
             << fare / 100.0 << " deducted.\n";

        return true;
    }
};

int main() {

    cout << "====================================\n";
    cout << "   REVISED METRO SMART CARD SYSTEM\n";
    cout << "====================================\n\n";

    cout << "FARE TABLE\n";

    for (int i = 0; i < 4; i++) {
        cout << left << setw(10)
             << zoneName(static_cast<Zone>(i))
             << " Rs. " << fixed << setprecision(2)
             << FARE_TABLE[i] / 100.0 << '\n';
    }

    cout << "\nFARE CALCULATION TESTS\n";

    cout << "Inner weekday off-peak: Rs. "
         << calculateFare(Zone::Inner, 11, false) / 100.0
         << '\n';

    cout << "Middle weekday peak: Rs. "
         << calculateFare(Zone::Middle, 8, false) / 100.0
         << '\n';

    cout << "Airport weekday peak: Rs. "
         << calculateFare(Zone::Airport, 18, false) / 100.0
         << '\n';

    cout << "Airport weekend off-peak: Rs. "
         << calculateFare(Zone::Airport, 11, true) / 100.0
         << '\n';

    cout << "Airport weekend peak: Rs. "
         << calculateFare(Zone::Airport, 18, true) / 100.0
         << '\n';

    cout << "\nMONTHLY PASS TESTS\n";

    SmartCard card(10000); 

    MonthlyPass pass(Zone::Inner, Zone::Airport);

    card.travel(Zone::Inner, 9, false, &pass);
    card.travel(Zone::Airport, 18, true, &pass);

    card.travel(Zone::Middle, 8, false, &pass);

    cout << "\nRemaining card balance: Rs. "
         << card.getBalance() / 100.0 << '\n';

    cout << "\nPASS EXPIRY TEST\n";

    pass.deactivate();

    card.travel(Zone::Inner, 11, false, &pass);

    cout << "\nFinal card balance: Rs. "
         << card.getBalance() / 100.0 << '\n';

    return 0;
}
