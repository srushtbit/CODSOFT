#include <iostream>
using namespace std;

float add(float a, float b)
{
    return (a + b);
}

float subtract(float a, float b)
{
    return (a - b);
}

float multiply(float a, float b)
{
    return (a * b);
}

float div(float a, float b)
{
    return (a / b);
}

int main()
{
    int n;
    float a, b;
    // taking two numbers as input
    cout << "Enter the first number :";
    cin >> a;
    cout << "Enter the secind number :";
    cin >> b;
    // giving optipns of operation to user using switch-case
    cout << "Press \n 1 for additon. \n 2 for substraction. \n 3 for multiplication. \n 4 for division: ";
    cin >> n;

    switch (n)
    {
    case 1:
        cout<<  add(a, b); // calling function's and passing input numbers as paramater
        break;

    case 2:
        cout<<subtract(a, b); // calling function's and passing input numbers as paramater
        break;

    case 3:
        cout<<multiply(a, b); // calling function's and passing input numbers as paramater
        break;

    case 4:
        cout<<div(a, b); // calling function's and passing input numbers as paramater
        break;

    default:
        cout << "!!Invalid Input.....";
    }
    cout << "\n^_^ Thank you for using me ^_^";
    return 0;
}