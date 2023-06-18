#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void dosomthing(int num);
void procssssomthing(int num);

int main()
{
    try
    {
        cout << "enter a number ";
        int num;
        cin >> num;
        dosomthing(num);
    }
    catch (const std::runtime_error &err)
    {
        std::cout << err.what() << std::endl;
    }
    catch (const out_of_range &err)
    {
        cout << err.what() << endl;
    }

    return 0;
}
void dosomthing(int num)
{
    try
    {
        procssssomthing(num);
    }
    catch (const invalid_argument &err)
    {
        throw; // rethrow
    }
    catch (const out_of_range &err)
    {
        throw; // rethrow
    }
}
void procssssomthing(int num)
{
    if (num <= 0)
    {
        throw invalid_argument("Marks can not be negative number!");
    }
    else if (num > 100)
    {
        throw invalid_argument("Marks can not be number larger then 100!");
    }
    else
    {
        cout << "Number " << num << endl;
    }
}