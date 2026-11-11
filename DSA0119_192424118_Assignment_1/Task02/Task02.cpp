#include <iostream>
using namespace std;

constexpr int INNER_FARE_PAISE = 1000;
constexpr int MIDDLE_FARE_PAISE = 2000;
constexpr int OUTER_FARE_PAISE = 3000;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

enum class Zone
{
    Inner,
    Middle,
    Outer
};

int main()
{
    cout << "Namma Metro Fare Configuration\n";
    cout << "------------------------------\n";

    cout << "Inner Fare: Rs. "
         << INNER_FARE_PAISE / 100.0 << '\n';

    cout << "Middle Fare: Rs. "
         << MIDDLE_FARE_PAISE / 100.0 << '\n';

    cout << "Outer Fare: Rs. "
         << OUTER_FARE_PAISE / 100.0 << '\n';

    cout << "Peak Surcharge: "
         << PEAK_SURCHARGE_PERCENT << "%\n";

    cout << "Minimum Balance: Rs. "
         << MIN_BALANCE_PAISE / 100.0 << '\n';

    Zone selectedZone = Zone::Inner;

    if (selectedZone == Zone::Inner)
        cout << "Selected Zone: Inner\n";

    return 0;
}
