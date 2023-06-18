#ifndef CustomExceptions_h
#define CustomExceptions_h

#include <stdexcept>
using namespace std;

class CustomExceptions : public runtime_error
{
private:
public:
    CustomExceptions() : runtime_error("Made CustomExceptions runtime eror!")
    {
    }
};

#endif