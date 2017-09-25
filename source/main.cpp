#include <iostream>
#include <stdexcept>
#include <stack.hpp>

int main() 
{
    Stack<int> stack(10); //объект с параметром

    try 
    {
        for(int i = 0; i <= stack.cout(); ++i)
            stack.push(i);
        for(int j = 0; j <= stack.cout(); ++j)
            stack.pop();
    } 
    catch (std::overflow_error e) 
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
