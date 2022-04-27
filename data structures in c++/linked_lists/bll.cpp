#include <iostream>

class DLLNode
{
private:
	int _value;
	DLLNode * _previous = NULL;
	DLLNode * _next = NULL;
	
public:
	DLLNode(int value)
	{
		_value = value;
	}
    void setValue(int value)
    {
        _value = value;
    }
    int getValue()
    {
        return _value;
    }
    void setNext(DLLNode * next)
    {
        _next = next;
    }
    DLLNode * getNext()
    {
        return _next;
    }
    void setPrevious(DLLNode * previous)
    {
        _previous = previous;
    }
    DLLNode * getPrevious()
    {
        return _previous;
    }
};

class DLL
{
private:
    DLLNode * _head = NULL;
    DLLNode * _tail = NULL;
    int _length = 0;
    
public:
    int size() const {return _length;}

    void insertAtFront(int value)
    {
        // create node pointer
        DLLNode * node = new DLLNode(value);

        if (node)
        {
            if (!_head)
            {
                _head = node;
                _tail = node;
            }
            else
            {
                node->setNext(_head);
                _head->setPrevious(node);
                _head = node;
            }
            _length++;
        }

        return;
    }

    void insertAtEnd(int value)
    {
        // create node pointer
        DLLNode * node = new DLLNode(value);

        if (node)
        {
            if (!_tail)
            {
                _head = node;
                _tail = node;
            }
            else
            {
                node->setPrevious(_tail);
                _tail->setNext(node);
                _tail = node;
            }
            _length++;
        }

        return;
    }

    void insertAtPosition(int value, int index)
    {

        // create node pointer
        DLLNode * node = new DLLNode(value);

        if (node)
        {
            if (index == 0)
            {
                // and to front
                insertAtFront(value);
                return;
            }
            else if (index >= _length)
            {
                // add to end
                insertAtEnd(value);
                return;
            }
            else
            {
                // add in middle
                int count = 0;
                for (DLLNode * currentNode = _head; count < _length; currentNode = currentNode->getNext())
                {
                    if (count == index)
                    {
                        node->setNext(currentNode);
                        node->setPrevious(currentNode->getPrevious());
                        currentNode->getPrevious()->setNext(node);
                        currentNode->setPrevious(node);
                    }

                    count++;
                }
            }
            _length++;
        }

        return;
    }

    void deleteFront()
    {
        DLLNode * currentHead = _head;
        _head = _head->getNext();
        _head->setPrevious(NULL);
        delete currentHead;
        _length--;
        return;
    }

    void deleteEnd()
    {
        DLLNode * currentTail = _tail;
        _tail = _tail->getPrevious();
        _tail->setNext(NULL);
        delete currentTail;
        _length--;
        return;
    }

    void deleteAtPosition(int index)
    {
        if (index == 0)
        {
            deleteFront();
        }
        else if (index >= _length)
        {
            deleteEnd();
        }
        else
        {            
            int count = 0;
            for (DLLNode * currentNode = _head; count < _length; currentNode = currentNode->getNext())
            {
                if (count == index)
                {
                    DLLNode * nextNode = currentNode->getNext();
                    DLLNode * previousNode = currentNode->getPrevious();
                    
                    std::cout << "prev: " << previousNode->getValue() << std::endl;
                    std::cout << "next: " << nextNode->getValue() << std::endl;

                    previousNode->setNext(NULL);
                    nextNode->setPrevious(previousNode);

                    break;
                }

                count++;
            }
        }

        
        return;
    }

    void traverse ()
    {
        int count = 0;
        DLLNode * currentNode = _head;

        while (count < _length)
        {
            std::cout << "<--(" << currentNode->getValue() << ")-->";

            if (currentNode->getNext())
                currentNode = currentNode->getNext();
            else
                break;
        }            

        std::cout << "NULL" << std::endl;

        return;
    }
};

int main(int argc, char * argv[])
{
    DLL list;
    list.insertAtFront(0);
    list.insertAtFront(10);
    list.insertAtEnd(99);
    list.insertAtEnd(34);
    list.insertAtPosition(100, 1);
    list.insertAtPosition(920, 2);
    list.traverse();

    list.deleteFront();
    list.deleteEnd();
    list.traverse();
    list.deleteAtPosition(2);
    list.insertAtPosition(120, 2);
    list.insertAtEnd(1000);
    list.insertAtPosition(-4, 4);
    list.traverse();
	return 0;
}
