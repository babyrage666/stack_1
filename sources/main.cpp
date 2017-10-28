#include <iostream>
#include <stdexcept>
#include <stack.hpp>
using namespace std;

int main() 
{
    try 
    {	
		Stack<char> stack1(4); //объект с параметром
		stack1.push('r');
		stack1.push('e');
		stack1.push('l');
		stack1.push('l');
		stack1.push('i'); //выделение доп. памяти
		stack1.push('k');
		for(int i = 0; i < 7; ++i)
			cout<<stack1.pop();
		cout<<"\n";

    } 
    catch (const exception& e) 
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
