#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
public:
    explicit Stack(size_t cap) : array_size_(cap), count_(0), array_(new T[cap]) {} // конструктор с параметром
    size_t count() const // метод возврата privete переменной
    {
        return count_;
    }
    
    void push(T const &value) // добавление эл-та в стек
    {
        if(count_ == array_size_)
        {
            std::cout<<"stack overflowed: adding new memory\n";
            T* new_array = new T[_arraysize_*2];
            for(size_t i =0; i < _arraysize_; ++i)
                new_array[i] = _array[i];
                
            _arraysize_ *= 2;
            delete[] _array;
            _array = new_array;
        }
        
        array_[count_++] = value;
    }
    
    T pop() //удаление
    {
        if(count_ == 0)
            throw std::underflow_error("stack is empty");
        else
            return array_[--count_];
    }
    virtual ~Stack() { delete[] _array; } // вирутальный деструктор
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};
