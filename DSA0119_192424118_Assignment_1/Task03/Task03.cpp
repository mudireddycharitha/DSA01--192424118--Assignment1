
#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    string name = "Charitha";
    int cardID = 101;
    long long transactionID = 12345678901LL;
    long long balance = 25050;  
    long long fare = 3000;     
    char cardType = 'S';
    bool active = true;
    char zone = 'A';

    cout << "====================================\n";
    cout << "       METRO SMART CARD SYSTEM\n";
    cout << "====================================\n";

    cout << "Passenger Name : " << name << '\n';
    cout << "Card ID        : " << cardID << '\n';
    cout << "Transaction ID : " << transactionID << '\n';
    cout << fixed << setprecision(2);
    cout << "Card Balance   : Rs. " << balance / 100.0 << '\n';
    cout << "Fare           : Rs. " << fare / 100.0 << '\n';
    cout << "Card Type      : " << cardType << '\n';
    cout << "Card Active    : " << boolalpha << active << '\n';
    cout << "Passenger Zone : Zone " << zone << '\n';

    cout << "\n------ DATA TYPE SIZES ------\n";
    cout << "int       : " << sizeof(int) << " bytes\n";
    cout << "long long : " << sizeof(long long) << " bytes\n";
    cout << "double    : " << sizeof(double) << " bytes\n";
    cout << "float     : " << sizeof(float) << " bytes\n";
    cout << "char      : " << sizeof(char) << " bytes\n";
    cout << "bool      : " << sizeof(bool) << " bytes\n";
    cout << "string    : " << sizeof(string) << " bytes\n";

    cout << "\n------ INTEGER LIMITS ------\n";
    cout << "INT_MAX   : " << INT_MAX << '\n';
    cout << "LLONG_MAX : " << LLONG_MAX << '\n';

    long long total = 3000000LL * 3600LL;

    cout << "\n------ NETWORK COLLECTION ------\n";
    cout << "Journeys  : 3000000\n";
    cout << "Total     : Rs. " << total / 100.0 << '\n';
    cout << "Int Safe  : " << boolalpha << (total <= INT_MAX) << '\n';

    double d = 0.0;
    long long p = 0;

    for (int i = 0; i < 10; i++)
    {
        d += 0.10;
        p += 10;
    }

    cout << "\n------ PRECISION CHECK ------\n";
    cout << setprecision(17) << "Double : " << d << '\n';
    cout << "Integer: " << p << " paise\n";

    int a = 10;
    double b = 2.5;

    cout << "\n------ TYPE COMPATIBILITY ------\n";
    cout << "int + double = " << a + b << '\n';

    cout << "\n====================================\n";
    cout << "       TASK 3 COMPLETED!\n";
    cout << "====================================\n";

    return 0;
}
