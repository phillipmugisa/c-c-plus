#include <iostream>

class Node {
    private:
        int _value = 0;
        Node * _next = NULL;
    public:
        Node(int value, Node * next = NULL)
        {
            _value = value;
            _next = next;
        }

        int getValue()
        {
            return _value;
        }
        void setValue(int value)
        {
            _value = value;
        }
        Node * getNext()
        {
            if (_next == NULL)
            {
                return NULL;
            }
            return _next;
        }
        void setNext(Node * next)
        {
            // if (_next != NULL)
            // {
            //     _next->setNext(next);
            // }
            _next = next;
        }
};

class SingleLinkedList {
    private:
        int _len = 0;
        Node * _head, *_tail;

    public:
        SingleLinkedList()
        {
            _head = NULL;
            _tail = NULL;
        }
        int size() const { return _len; }

        void push(int nodeValue)
        {
            Node * newNode = new Node(nodeValue);
            // adding to start(default way of adding to a linked list)
           if (newNode)
           {
                if (_head == NULL)
                {
                    _head = newNode;
                    _tail = newNode;
                }
                else
                {
                    newNode->setNext(_head);
                    _head = newNode;
                }
                _len++;
           }
        }

        void append(int nodeValue)
        {
            // adding to end(default way of adding to a linked list)
            Node * newNode = new Node(nodeValue);
            if(newNode)
            {
                _tail->setNext(newNode);
                _len++;
                
                _tail = newNode;
            }           

            return;
        }

        void removeAt(int index)
        {
            Node * previousNode = NULL;
            Node * currentNode = _head;
            for (int i = 0; i < _len; i++)
            {
                if (i == index)
                {
                    if (i == 0)
                    {
                        _head = currentNode->getNext();
                    }
                    else
                    {
                        previousNode->setNext(currentNode->getNext());
                    }
                    
                    delete currentNode;
                    _len--;                    
                    return;
                }
                previousNode = currentNode;
                currentNode = currentNode->getNext();
            }
        }

        void appendAt(int index, int nodeValue)
        {
            Node * previousNode = NULL;
            Node * currentNode = _head;
            Node * newNode = new Node(nodeValue);

            for (int i = 0; i < _len; i++)
            {
                if (i == index)
                {
                    if (i == 0)
                    {
                        newNode->setNext(_head);
                        _head = newNode;
                    }
                    else
                    {
                        previousNode->setNext(newNode);
                        newNode->setNext(currentNode);
                    }
                    
                    _len++;                    
                    return;
                }
                previousNode = currentNode;
                currentNode = currentNode->getNext();
            }
        }

        void display()
        {   
            Node * currentNode = _head;
            while(currentNode)
            {
                std::cout << currentNode->getValue() << " -> ";
                currentNode = currentNode->getNext();
            }
            std::cout << "NULL" << std::endl;
        }
        void clear()
        {
            Node * currentNode = _head;         
            
            while (currentNode)
            {
                Node * next = currentNode->getNext();
                delete currentNode;
                currentNode = next;
                _len--;
            }
        }
};




// DLL

class DLLNode {
    public:
        int _value;
        DLLNode * prev, * next;

        DLLNode(int value) 
        {
            _value = value;
        }
};

class DLL {
    private:
        int _len = 0;
        DLLNode * _head, *_tail;

    public:
        DLL()
        {
            _head = NULL;
            _tail = NULL;
        }
        int size() const { return _len; }

        void push(int nodeValue)
        {
            DLLNode * newNode = new DLLNode(nodeValue);
           if (newNode)
           {
                if (_head == NULL)
                {
                    _head = newNode;
                    _tail = newNode;
                }
                else
                {
                    newNode->next = _head;
                    _head->prev = newNode;
                    _head = newNode;
                }
                _len++;
           }
        }

        void append(int nodeValue)
        {
            DLLNode * newNode = new DLLNode(nodeValue);
            if(newNode)
            {
                _tail->next = newNode;
                newNode->prev = _tail;
                _len++;
                
                _tail = newNode;
            }           

            return;
        }

        void appendAt(int index, int nodeValue)
        {
            int count = 0;
            DLLNode * newNode = new DLLNode(nodeValue);
            for (DLLNode * currentNode = _head; currentNode != NULL; currentNode = currentNode->next)
            {
                if(count == index)
                {                    

                    if (index == 0)
                    {
                        newNode->next = currentNode;
                        currentNode->prev = newNode;
                        _head = newNode;
                    }
                    else
                    {
                        newNode->prev = currentNode->prev;
                        newNode->next = currentNode;                      

                        currentNode->prev->next = newNode;
                        currentNode->prev = newNode;
                    }

                    _len++;
                }
                count++;
            }
        }

        void removeAt(int index)
        {
            if (_head == NULL)
                return;

            int count = 0;
            for (DLLNode * currentNode = _head; currentNode != NULL; currentNode = currentNode->next)
            {
                if(count == index)
                {
                    if (index == 0)
                    {
                        currentNode->next->prev = NULL;
                        _head = currentNode->next;
                    }
                    else if (index == (_len - 1))
                    {
                        currentNode->prev->next = NULL;
                        _tail = currentNode->prev;
                    }
                    else
                    {
                        currentNode->prev->next = currentNode->next;
                        currentNode->next->prev = currentNode->next;
                    }

                    delete currentNode;
                    _len--;
                }
                count++;
            }
        }

        void display()
        {
            for (DLLNode * currentNode = _head; currentNode != NULL; currentNode = currentNode->next)
            {
                std::cout << currentNode->_value << " <-> ";
            }

            std::cout << "NULL" << std::endl;
        }
        void clear()
        {
            if (_head == NULL)
                return;
                
            DLLNode * currentNode = _head;
            while(currentNode != NULL) 
            {
                DLLNode * nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
                _len--;
            }
        }
};


int main(int argc, char *argv[])
{

    SingleLinkedList list1 = SingleLinkedList();
    
    for(int i = 0; i < 5; i++)
    {
        list1.push(i);
    }
    for(int i = 0; i > -5; i--)
    {
        list1.append(i);
    }

    list1.removeAt(0);
    list1.removeAt(4);
    list1.removeAt(3);

    std::cout << "List size: " << list1.size() << std::endl;


    list1.display();

    list1.appendAt(0, 100);
    list1.appendAt(4, 90);

    list1.appendAt((list1.size() - 1), 88);
    std::cout << "List size: " << list1.size() << std::endl;

    list1.display();

    list1.clear();
    std::cout << "List size after clear: " << list1.size() << std::endl;


    std::cout << "\n" << std::endl;

    std::cout << "---------------------------DLL------------------------------" << std::endl;

    std::cout << "\n" << std::endl;


    DLL DDList = DLL();
    
    for(int i = 0; i < 5; i++)
    {
        DDList.push(i);
    }
    for(int i = 0; i > -5; i--)
    {
        DDList.append(i);
    }
    
    DDList.display();

    DDList.removeAt(0);
    DDList.removeAt(4);
    DDList.removeAt(7);

    std::cout << "List size: " << DDList.size() << std::endl;


    DDList.display();

    DDList.appendAt(0, 100);
    DDList.appendAt(3, 90);

    DDList.appendAt((DDList.size() - 1), 88);

    DDList.display();
    std::cout << "List size: " << DDList.size() << std::endl;

    DDList.clear();
    std::cout << "List size after clear: " << DDList.size() << std::endl;

    return 0;
}