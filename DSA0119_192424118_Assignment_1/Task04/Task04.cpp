
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    cout << "====================================\n";
    cout << "       METRO SMART CARD SYSTEM\n";
    cout << "      TYPE CONVERSION DEMONSTRATION\n";
    cout << "====================================\n\n";

    cout << "1. Integer to Double Conversion\n";

    int baseFare = 30;
    double convertedFare = baseFare; 

    cout << "Base Fare       : " << baseFare << '\n';
    cout << "Converted Fare  : " << convertedFare << "\n\n";


    cout << "2. Double to Integer Conversion\n";

    double originalBalance = 250.75;
    int convertedBalance = originalBalance;  

    cout << "Original Balance: " << originalBalance << '\n';
    cout << "Converted Value : " << convertedBalance;
    cout << " (fraction discarded)\n\n";


    cout << "3. Arithmetic Type Conversion\n";

    int fare = 30;
    double peakSurcharge = 5.5;
    double totalFare = fare + peakSurcharge;

    cout << "Base Fare       : " << fare << '\n';
    cout << "Peak Surcharge  : " << peakSurcharge << '\n';
    cout << "Total Fare      : " << totalFare << "\n\n";


    cout << "4. Mixed Data Type Calculation\n";

    int passengers = 2;
    double farePerPassenger =
        totalFare / static_cast<double>(passengers);

    cout << "Number of Passengers : " << passengers << '\n';
    cout << "Fare Per Passenger   : " << farePerPassenger << "\n\n";


    cout << "5. Integer Division vs Explicit Conversion\n";

    int a = 7, b = 2;

    double result1 = a / b;
    double result2 = static_cast<double>(a) / b;

    cout << "Integer Division     : " << result1 << '\n';
    cout << "Explicit Conversion  : " << result2 << "\n\n";

    cout << "6. Character Promotion\n";

    char ch = 'A' + 2;

    cout << "Character            : " << ch << '\n';
    cout << "Character + 1        : " << ch + 1 << "\n\n";


    cout << "7. Boolean Conversion\n";

    bool flag = 5;

    cout << "Default Boolean      : " << flag << '\n';
    cout << "Boolean with boolalpha: "
         << boolalpha << flag << noboolalpha << "\n\n";


    cout << "8. Signed and Unsigned Comparison\n";

    unsigned int u = 1;
    int s = -1;

    cout << "Signed Value         : " << s << '\n';
    cout << "Unsigned Value       : " << u << '\n';

    cout << "Comparison Result    : "
         << (s < u ? "s < u" : "s >= u") << "\n\n";


    cout << "9. Safe Initialization\n";

    int safeAmount{30};
    double safeFare{static_cast<double>(7) / 2};

    cout << "Safe Integer Amount  : " << safeAmount << '\n';
    cout << "Safe Fare            : " << safeFare << "\n\n";

    cout << "10. Metro Fare Calculation\n";

    int normalFare = 30;
    int peakRate = 20;

    double surcharge =
        static_cast<double>(normalFare) * peakRate / 100.0;

    double finalFare = normalFare + surcharge;

    cout << "Normal Fare          : Rs. " << normalFare << '\n';
    cout << "Peak Surcharge       : Rs. " << surcharge << '\n';
    cout << "Final Fare           : Rs. " << finalFare << '\n';


    cout << "\n====================================\n";
    cout << "Type conversions demonstrated successfully.\n";
    cout << "====================================\n";

    return 0;
}
