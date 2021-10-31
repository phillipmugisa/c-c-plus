#include <iostream>


class DynamicArray {
    private:
        // number of elements in array
        int _capacity = 0;
        // max number
        int _array_size = 5;
        int * _array = new int[_array_size];
    public:
        DynamicArray()
        {
            // _array_size = size;
        }
        void push(int new_number)
        {
            if (_capacity < _array_size)
            {
                *(_array + _capacity) = new_number;
            }
            else
            {
                // create new array of double size
                int new_arr_size = _array_size * 2;
                int * new_arr = new int[new_arr_size];

                // copy existing elements into new array
                for (int i = 0; i < _array_size; i++)
                {
                    *(new_arr + i) = *(_array + i);
                }

                delete[] _array;
                delete _array;

                _array = new_arr;
                _array_size = new_arr_size;

                *(_array + _capacity) = new_number;

            }
            _capacity++;
        };
        int size()
        {
            return _array_size;
        }
        int get(int index)
        {
            if (_capacity > 0)
            {
                return *(_array + index);
            }
            return -1;
        }
        void set(int index, int value)
        {
            if (index < _array_size && _capacity > 0)
            {
               *(_array + index) = value;
            }
        }
        int pop()
        {
            if (_capacity > 0)
            {
                int val_to_pop =  this->get(0);
                for (int i = 1; i < _capacity; i++)
                {
                    *(_array + (i - 1)) = *(_array + i);
                }
                // set last item to 0
                *(_array + (_capacity - 1)) = 0;

                return val_to_pop;
            }
            return -1;
        }
};

int main(int argc, char * argv[])
{

    DynamicArray my_numbers = DynamicArray();

    for (int i = 0; i < 10; i++)
    {
        my_numbers.push(i);

    }

    for (int i = 0; i < my_numbers.size(); i++)
    {
        std::cout << my_numbers.get(i) << std::endl;

    }

    std::cout << my_numbers.pop() << std::endl;
    return 0;
}