/*
 * Kyle & Tanner's Prime Number Checker
 *
 * Description:
 *   This program takes a number of inputs from the user and determines if the inputs are prime or not.
 * Input Requirements:
 *   The program was made to work with positive numbers.
 *   Inputs must be of the type unsigned long long, aka an unsigned 64 bit integer.
 * Output Description:
 *   The program outputs whether or not the number you input is prime, and if not, two numbers that multiply to equal your number.
 *
 */
#include <iostream>
using namespace std;
int main()
{
    bool prime; //Whether or not the number entered is prime
    unsigned long long multiplierOne = 0; //One of the numbers that multiplies to give you your number
    unsigned long long multiplierTwo = 0; //The number that multiplies with multiplierOne to give you your number
    unsigned long long num = 1; //The actual number
    while(num != 0) //0 is the... when you enter 0 the program stops asking for numbers.
    {
        cout << "What number would you like to test (0 to stop) : ";
        cin >> num;
        prime = true; //Assume the number is prime.
        /*
         * It's much easier to prove a number is not prime than it is to prove it is prime.
         * Therefore, we will assume the number is prime until it has been proven otherwise.
         */
        if(num == 2)
            goto q; //If the number is two, skip down to q. Two is a prime number, no need for calculations here.

        if(num % 2==0)
        {
            /*
             * This set of code determines if the number at hand is divisible by two.
             * If it is, set one of the multipliers to two and sets the other one to
             *      num / 2;
             */
            multiplierOne = 2;
            multiplierTwo = num / 2;
            prime = false;
            goto q;
        }

        for(int i = 3; (i <= num / i) & prime; i += 2)
        {
            /*
             * These blocks of code loop through the integers up to num/i
             *      We use num/i because of the following:
             *          Whatever-They're-Calleds of 100:
             *              1  * 100
             *              2  * 50
             *              4  * 25
             *              5  * 20
             *              10 * 10
             *              20 * 5
             *              25 * 4
             *              50 * 2
             *              100* 1
             *          See what happens at sqrt(100), aka 10?
             *          The Whatever-They're-Calleds start to repeat.
             *          Since we were constrained by only being able to use <iostream>, I figured that $i would
             *            should never be able to hit $num/$i. In other words, only very rarely should $i^2 equal $num.
             *            This was Tanner's idea.
             *      We started the loop at 3 because we've already checked if $num was divisible by 2.
             *      After that, we increase $i by 2 each time so we can skip all of the evens.
             *        This was Kyle's idea.
             */
            if(num%i==0)
            {
                multiplierOne = i;
                multiplierTwo = num / i;
                prime = false;
            }
        }

        q:
            if (num != 0)
                (prime) ? cout << num << " is prime.\n\n" : cout << num << " is not prime.\n\t" << multiplierOne << " * " << multiplierTwo << " == " << num << "\n\n";
    }
    cout << "\n-----\nDone\n";
    return 0;
}
