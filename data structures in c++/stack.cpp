#include <iostream>

class Stack {
    private:
        int _maxLen = 5;
        int _len;
        int * _top = NULL;
        int * elements = new int [_maxLen];

    public:
        Stack()
        {
            _len = 0;
        }
        int size() const { return _len; }
        void push(int num)
        {
            if (_len > _maxLen)
            {
                int newMax = _maxLen * 2;
                int * newStack  = new int [newMax];

                // copy old items
                for (int i = 0; i < _len; i++)
                {
                    newStack[i] = elements[i];
                }

                delete[] elements;
                elements = newStack;
                _maxLen = newMax;
            }
                
            elements[_len] = num;
            _top =  (elements + _len);
            _len++;

        }
        int pop()
        {
            if (_len <= 0)
                return -1;
                
            int numToRemove = *_top;
            _top = NULL;
            delete _top;

            _len--;

            _top = (elements + (_len - 1));

            return numToRemove;
        }
};

int main(int argc, char * argv[])
{
    Stack stack1 = Stack();

    for (int i = 1; i < 10; i++)
    {
        stack1.push(i);
    }
    
    std::cout << "Size: " << stack1.size() << std::endl;

    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;
    std::cout << stack1.pop() << std::endl;

    std::cout << "Size: " << stack1.size() << std::endl;

}