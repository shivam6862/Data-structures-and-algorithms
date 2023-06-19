#ifndef DM_H
#define DM_H
#include <string>

class dm
{
private:
    std::string name;
    std::string breed;

public:
    dm(std::string name, std::string breed);
    ~dm();
    std::string getName() const;
    std::string getBreed() const;
};
#endif