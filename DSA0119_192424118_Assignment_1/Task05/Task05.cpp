
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "====================================\n";
    cout << "       METRO SMART CARD SYSTEM\n";
    cout << "       OPERATORS DEMONSTRATION\n";
    cout << "====================================\n\n";

    cout << fixed << setprecision(2);

    cout << "1. Arithmetic Operators\n";

    int baseFare = 30;
    int surcharge = 6;

    cout << "Base Fare       : Rs. " << baseFare << '\n';
    cout << "Surcharge       : Rs. " << surcharge << '\n';
    cout << "Addition        : " << baseFare + surcharge << '\n';
    cout << "Subtraction     : " << baseFare - surcharge << '\n';
    cout << "Multiplication  : " << baseFare * 2 << '\n';
    cout << "Division        : " << baseFare / 2 << '\n';
    cout << "Modulus         : " << baseFare % 7 << "\n\n";


    cout << "2. Relational and Logical Operators\n";

    int balance = 250;
    int minimumBalance = 50;

    cout << "Balance         : Rs. " << balance << '\n';
    cout << "Minimum Balance : Rs. " << minimumBalance << '\n';
    cout << "Sufficient Balance: "
         << boolalpha << (balance >= minimumBalance) << '\n';

    int hour = 9;

    bool peakHour =
        (hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20);

    cout << "Journey Hour    : " << hour << ":00\n";
    cout << "Peak Hour       : " << peakHour << "\n\n";

    cout << "3. Peak Surcharge Calculation\n";

    int fare = 30;
    int peakRate = 20;

    int peakSurcharge = peakHour
        ? fare * peakRate / 100
        : 0;

    int totalFare = fare + peakSurcharge;

    cout << "Base Fare       : Rs. " << fare << '\n';
    cout << "Peak Surcharge  : Rs. " << peakSurcharge << '\n';
    cout << "Total Fare      : Rs. " << totalFare << "\n\n";

    cout << "4. Passenger Concession\n";

    bool isStudent = true;
    int concessionRate = 10; 

    int concession = isStudent
        ? totalFare * concessionRate / 100
        : 0;

    int payableFare = totalFare - concession;

    cout << "Student Status  : "
         << (isStudent ? "Yes" : "No") << '\n';
    cout << "Concession      : Rs. " << concession << '\n';
    cout << "Payable Fare    : Rs. " << payableFare << "\n\n";


    // 5. Operator Precedence
    cout << "5. Operator Precedence\n";

    int x = 5, y = 3;

    cout << "x + y * 2       : " << x + y * 2 << '\n';
    cout << "(x + y) * 2     : " << (x + y) * 2 << "\n\n";

    cout << "6. Increment Operators\n";

    int p = 5, q = 3;

    int result = p++ + ++q;

    cout << "Expression Result: " << result << '\n';
    cout << "Post-increment p : " << p << '\n';
    cout << "Pre-increment q  : " << q << "\n\n";

    cout << "7. Division and Modulus\n";

    cout << "10 / 3           : " << 10 / 3 << '\n';
    cout << "10 % 3           : " << 10 % 3 << '\n';
    cout << "-10 / 3          : " << -10 / 3 << '\n';
    cout << "-10 % 3          : " << -10 % 3 << "\n\n";


    cout << "8. Compound Assignment\n";

    int total = 0;

    for (int i = 0; i < 10; i += 3)
    {
        total += i;
    }

    cout << "Loop Total       : " << total << '\n';


    cout << "\n====================================\n";
    cout << "Operators demonstrated successfully.\n";
    cout << "====================================\n";

    return 0;
}
