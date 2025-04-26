#include <iostream>

#define MESSAGE "Hello, LLVM World!"

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    std::cout << MESSAGE << std::endl;
    std::cout << "Factorial of 5 is: " << factorial(5) << std::endl;
    return 0;
}
