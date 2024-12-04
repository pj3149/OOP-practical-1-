#include <iostream>
using namespace std;

class Complex {
    double real;
    double img;

public:
    Complex(); // Default Constructor

    // Overloaded operators
    friend istream &operator>>(istream &, Complex &);  // Input
    friend ostream &operator<<(ostream &, const Complex &); // Output
    Complex operator+(Complex);  // Addition
    Complex operator*(Complex);  // Multiplication
};

// Default Constructor
Complex::Complex() {
    real = 0;
    img = 0;
}

// Overloaded >> operator for input
istream &operator>>(istream &input, Complex &c) {
    cout << "Enter real and imaginary parts: ";
    input >> c.real >> c.img;
    return input;
}

// Overloaded << operator for output
ostream &operator<<(ostream &output, const Complex &c) {
    output << c.real << " + " << c.img << "i";
    return output;
}

// Overloading + operator for addition
Complex Complex::operator+(Complex c1) {
    Complex temp;
    temp.real = real + c1.real;
    temp.img = img + c1.img;
    return temp;
}

// Overloading * operator for multiplication
Complex Complex::operator*(Complex c2) {
    Complex temp;
    temp.real = real * c2.real - img * c2.img;
    temp.img = real * c2.img + img * c2.real;
    return temp;
}

int main() {
    Complex C1, C2, C3, C4;
    int flag = 1;
    char b;

    while (flag == 1) {
        cout << "Enter Complex Number 1:\n";
        cin >> C1;
        cout << "Enter Complex Number 2:\n";
        cin >> C2;

        int menu_flag = 1;

        while (menu_flag == 1) {
            cout << "\nComplex Number 1: " << C1 << endl;
            cout << "Complex Number 2: " << C2 << endl;
            cout << "********** MENU **********" << endl;
            cout << "1. Addition of Complex Numbers" << endl;
            cout << "2. Multiplication of Complex Numbers" << endl;
            cout << "3. Exit\n";
            cout << "Enter your choice from the menu (1 to 3): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                C3 = C1 + C2;
                cout << "Addition: " << C3 << endl;
                cout << "Do you want to perform another operation? (y/n): ";
                cin >> b;
                if (b == 'y' || b == 'Y') {
                    menu_flag = 1;
                } else {
                    cout << "Thanks for using this program!\n";
                    flag = 0;
                    menu_flag = 0;
                }
            } else if (choice == 2) {
                C4 = C1 * C2;
                cout << "Multiplication: " << C4 << endl;
                cout << "Do you want to perform another operation? (y/n): ";
                cin >> b;
                if (b == 'y' || b == 'Y') {
                    menu_flag = 1;
                } else {
                    cout << "Thanks for using this program!\n";
                    flag = 0;
                    menu_flag = 0;
                }
            } else if (choice == 3) {
                cout << "Thanks for using this program!\n";
                flag = 0;
                menu_flag = 0;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
