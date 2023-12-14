#include <iostream>
#include <random>
#include <chrono>

using namespace std;
void Number_Guessing_Game()
{
    int flag = 1, user_input, i = 0;
    // Use the current time as a seed for the random number generator
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    // Define a distribution (e.g., uniform distribution between 1 and 100)
    uniform_int_distribution<int> dist(1, 10000);
    while (flag == 1)
    {
        // Generate a random number
        int randomNumber = dist(mt);

        while (i == 0)
        {
            cout << "Guess the number " << endl;
            cin >> user_input;
            if (user_input > randomNumber)
            {
                cout << "Too High" << endl;
            }
            else if (user_input < randomNumber)
            {
                cout << "Too Low" << endl;
            }
            else
            {
                cout << "Congratulations, You guessed it right!" << endl;
                break;
            }
        }
        while (true)
        {
            cout << "Do you wish to continue(1 for Yes and 0 for No):";
            cin >> flag;
            if (flag != 0 && flag != 1)
            {
                cout << "Invalid Input" << endl;
            }

            else
            {
                break;
            }
        }
    }
}

int main()
{

    Number_Guessing_Game();

    return 0;
}
