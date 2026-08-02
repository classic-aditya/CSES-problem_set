#include <iostream>
#include <climits>
int main()
{
    int digit, moves = 0;
    std::cin >> digit;
    while (digit > 0)
    {
        int temp_copyofDigit = digit;
        int biggestDigit = INT_MIN;
        while (temp_copyofDigit)
        {
            if (temp_copyofDigit % 10 > biggestDigit)
                biggestDigit = temp_copyofDigit % 10;
            temp_copyofDigit /= 10;
        }
        digit -= biggestDigit;
        moves++;
    }
    std::cout<<moves;
}