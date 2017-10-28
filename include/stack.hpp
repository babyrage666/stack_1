#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
public:
	Stack() : array_size_(1), count_(0), array_(new T[1]) {} //конструктор по умаолчанию (размер  = 1)
    Stack(size_t cap) : array_size_(cap), count_(0), array_(new T[cap]) {} // конструктор с параметром

    size_t count() const // метод возврата privete переменной
    {
        return count_;
    }

    void push(T const &value) // добавление эл-та в стек
    {
        if(count_ == array_size_)
        {
            cout<<"stack overflowed: adding new memory\n";
            T* new_array_ = new T[array_size_*2];
            for(size_t i =0; i < array_size_; ++i)
                new_array_[i] = array_[i];
            delete[] array_;
            array_ = new_array_;
        }
        
        array_[count_] = value;
		++count_;
    }
    
    T pop() //удаление элемента
    {
        if(count_ == 0)
            throw runtime_error("stack is empty");
		--count_; 
        return array_[count_];
    }
    virtual ~Stack() { delete[] array_; } // вирутальный деструктор
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};
