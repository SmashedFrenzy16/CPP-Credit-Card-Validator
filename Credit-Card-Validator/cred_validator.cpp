#include <iostream>

using namespace std;

bool isString(const string& str) {

    int length = str.length();

    for (int i = 0; i < length; i++) {

        if (str[i] < '0' || str[i] > '9') {

            return false;
        }

        return true;
    }
}

int main()
{

    string number;
    string repeat;

    cout << "Welcome to this Credit Card Validator (Using The Luhn Algorithm) By @SmashedFrenzy16!";

    do
    {

        cout << "Enter your credit card number: ";

        cin >> number;

        if (!isString(number)) {

            cout << "Invalid number!" << endl;

            exit(0);
        }

        int length = number.length();
        int doubleNum = 0;

        for (int i = length - 2; i >= 0; i = i - 2) {

            int doubling = (number[i] - 48) * 2;

            if (doubling > 9) {

                doubling = (doubling / 10) + (doubling % 10);

            }

            doubleNum += doubling;
        }

        for (int i = length - 1; i >= 0; i = i - 2) {

            doubleNum += number[i] - 48;
        }

        cout << (doubleNum % 10 == 0 ? "That is a valid credit card number!" : "That is an invalid credit card number!") << endl;

        cout << "Do you want to validate another credit card number? (y/n): ";

        cin >> repeat;

    } while (repeat == "y" || repeat == "Y");

    return 0;
}