#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

//gets user input
double get_values(const string &question) {
    double input_value;
    cout << question;
    cin >> input_value;
    return input_value;
}

//solves the equation, prints out possible solutions
void discriminant(double a, double b, double c) {
    double x1, x2, discrim;

    //solve for the discriminant
    discrim = (b * b) - (4 * a * c);

    //if its negative, it has imaginary roots and no real roots
    if (discrim < 0) {
        cout << "This equation has no real roots";
    }

    //discriminant is positive, it has two solutions
    if (discrim > 0) {
        x1 = ((-b) + sqrt(discrim)) / (2 * a);
        x2 = ((-b) - sqrt(discrim)) / (2 * a);

        printf("\nThe solutions to the quadratic equation are %lf, %lf \n", x1, x2);
    }

    //discriminant is zero, it has one solution that is repeated
    if (discrim == 0) {
        x1 = -b / (2 * a);
        printf("The solution to the quadratic equation is %lf \n", x1);
    }
}

//main function
int main() {
    double a, b, c;

    //keep asking for a if user gives invalid input
    while (true) {
        a = get_values("Enter a value for a:");
        if (a != 0) {
            break;
        } else {
            cout << "ERROR: a can not be zero\n";
        }
    }

    b = get_values("Enter a value for b:");
    c = get_values("Enter a value for c:");

    //calls discriminant function
    discriminant(a, b, c);
    return 0;
}