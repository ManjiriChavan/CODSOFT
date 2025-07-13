#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
    char choice;

    cout << "===== SIMPLE CALCULATOR =====" << endl;

    do {
        // Input two numbers
        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter an operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        // Perform operation
        switch (op) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 == 0)
                    cout << "Error: Division by zero!" << endl;
                else
                    cout << "Result: " << num1 / num2 << endl;
                break;
            default:
                cout << "Invalid operator!" << endl;
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}
