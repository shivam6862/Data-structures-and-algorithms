#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int main()
{
    std::cout << "Excception Handling";
    std::vector<std::string> name(5);
    name = {"a", "b", "c", "d", "e"};
    for (std::string it : name)
    {
        std::cout << it << std::endl;
    }
    try
    {
        name.at(5) = "f";
    }
    catch (const std::out_of_range &err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}