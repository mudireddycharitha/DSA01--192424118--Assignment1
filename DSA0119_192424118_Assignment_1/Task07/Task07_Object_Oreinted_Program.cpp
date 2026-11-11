
#include <iostream>
#include <iomanip>
using namespace std;

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;

// SmartCard class
class SmartCard
{
private:
    long long balance;

    static constexpr long long MIN_BALANCE_PAISE = 5000;

public:

    // Constructor
    SmartCard(long long initialBalance)
    {
        balance = initialBalance;
    }

    // Check whether travel is allowed
    bool canTravel(long long fare) const
    {
        return (fare >= 0 &&
                balance >= fare &&
                balance - fare >= MIN_BALANCE_PAISE);
    }

    // Deduct fare safely
    bool deduct(long long fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            return true;
        }

        return false;
    }

    // Return current balance
    long long getBalance() const
    {
        return balance;
    }
};

// Calculate fare
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

// Display money
void displayMoney(long long amount)
{
    cout << amount / 100 << "."
         << setw(2) << setfill('0')
         << amount % 100 << setfill(' ');
}

int main()
{
    SmartCard card(10000);

    int zones[] = {1, 3, 2};
    bool peakHours[] = {false, true, false};

    cout << "====================================\n";
    cout << "      METRO SMART CARD - OOP\n";
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

        if (card.canTravel(f) && card.deduct(f))
        {
            cout << "Fare Rs ";
            displayMoney(f);
            cout << " | Approved";
        }
        else
        {
            cout << "Denied (low balance)";
        }

        cout << " | Balance Rs ";
        displayMoney(card.getBalance());
        cout << '\n';
    }

    cout << "\nFinal Balance: Rs ";
    displayMoney(card.getBalance());

    cout << "\n====================================\n";

    return 0;
}
