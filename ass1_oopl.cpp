// Implement a class Complex which represents the Complex Number data type. Implement the
// following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.



// add functiom of substraction and divide 
// function of find conjugate of complex number C1 and C2
// added a function to check whether input for complex number are valid or not (only integer values) 
// made switch statement for giving result rather than if else




#include <iostream>     // library to perform input and output operations  
#include <limits>       // library to check wheather given complex number is valid or not 
using namespace std;    // contains the built-in classes and declared functions (entities having the same name but with different semantics)

class Complex {
    double real;    //store real part of complex number
    double img;     //store imaginary part of complex number

public:             // accessible from other parts of the program
    Complex();      // Default Constructor
    friend istream & operator >> (istream &, Complex &); // Input (declaring a friend function that overloads the >> operator for the Complex class)
    friend ostream & operator << (ostream &, const Complex &); // Output (declaring a friend function that overloads the << operator for the Complex class)
    Complex operator + (const Complex &) const; // Addition                   (reference to a constant Complex object)
    Complex operator - (const Complex &) const; // Subtraction
    Complex operator * (const Complex &) const; // Multiplication
    Complex operator / (const Complex &) const; // Division
    Complex conjugate() const; // Complex conjugate
};

Complex::Complex() {      // constructor definition for a class named Complex
    real = 0;
    img = 0;              //real and img are data members (variables) of the Complex class
}
istream & operator >> (istream & in, Complex & c) {  //function declaration for overloading the >> operator to work with objects of the Complex class

    while (!(in >> c.real >> c.img)) {
        cout << "Invalid input. Enter only numeric values.\n";
        in.clear();      //clear the stored values       
        in.ignore(numeric_limits<streamsize>::max(), '\n');           
        cout << "Enter Real and Imaginary part of the Complex Number : ";
    }
    return in;
}

ostream & operator << (ostream & out, const Complex & c) {   
    out << c.real << " + " << c.img << "i";
    return out;
}

Complex Complex::operator + (const Complex & c) const {        //to perform addition of two complex number
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

Complex Complex::operator - (const Complex & c) const {        //to perform substraction of two complex number
    Complex temp;
    temp.real = real - c.real;
    temp.img = img - c.img;
    return temp;
}

Complex Complex::operator * (const Complex & c) const {       //to perform multiplication of two complex number
    Complex temp;
    temp.real = real * c.real - img * c.img;
    temp.img = real * c.img + img * c.real;
    return temp;
}

Complex Complex::operator / (const Complex & c) const {       //to perform division of two complex number
    Complex temp;
    double denominator = c.real * c.real + c.img * c.img;
    temp.real = (real * c.real + img * c.img) / denominator;
    temp.img = (img * c.real - real * c.img) / denominator;
    return temp;
}

Complex Complex::conjugate() const {           //to perform conjugate of a complex number
    Complex conj;
    conj.real = real;
    conj.img = -img;
    return conj;
}

int main() {              //entry point for program
    Complex C1, C2, result, conjugateResult;  
    int flag = 1;
    char choice;
    
    while (flag == 1) {
        cout << "Enter Real and Imaginary part of the Complex Number 1:\n";
        cin >> C1;
        
        cout << "Enter Real and Imaginary part of the Complex Number 2:\n";
        cin >> C2;
        
         int f = 1;
        while (f == 1) {
            cout << "Complex Number 1: " << C1 << endl;
            cout << "Complex Number 2: " << C2 << endl;
            cout << "********** MENU **********" << endl;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Division" << endl;
            cout << "5. Conjugate of Complex Number 1" << endl;
            cout << "6. Conjugate of Complex Number 2" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter operation you want to perform: ";
            
            int option;
            cin >> option;
            
            switch (option) {                        //switch statement to perform required function
                case 1:
                    result = C1 + C2;
                    cout << "Addition Result: " << result << endl;
                    break;
                case 2:
                    result = C1 - C2;
                    cout << "Subtraction Result: " << result << endl;
                    break;
                case 3:
                    result = C1 * C2;
                    cout << "Multiplication Result: " << result << endl;
                    break;
                case 4:
                    result = C1 / C2;
                    cout << "Division Result: " << result << endl;
                    break;
                case 5:
                    conjugateResult = C1.conjugate();
                    cout << "Conjugate of Complex Number 1: " << conjugateResult << endl;
                    break;
                case 6:
                    conjugateResult = C2.conjugate();
                    cout << "Conjugate of Complex Number 2: " << conjugateResult << endl;
                    break;
                case 7:
                    cout << "Exiting program. Goodbye!\n";
                    flag = 0;
                    f = 0;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number from 1 to 7.\n";
                    break;
            }
            
            if (option >= 1 && option <= 6) {
                cout << "Do you want to perform another operation? (y/n): ";
                cin >> choice;
                if (choice != 'y' && choice != 'Y') {
                    cout << "Exiting program. Goodbye!\n";
                    flag = 0;
                    f = 0;
                }
            }
        }
    }
    
    return 0;
}






