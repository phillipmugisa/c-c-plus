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

    DLLNode * getNodeAt(int index)
    {
        int count = 0;
        DLLNode * currentNode = _head;
        DLLNode * nodeAtIndex = NULL;
            
        while (currentNode)
        {
            if (count == index)
            {
                nodeAtIndex = currentNode;
            }
            currentNode = currentNode->getNext();
            count++;
        }
        
        return nodeAtIndex;
    }
    
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
        DLLNode * node = new DLLNode(value);
        if (node)
        {
            if (index == 0)
            {
                insertAtFront(value);
                return;
            }
            else if (index >= _length)
            {
                insertAtEnd(value);
                return;
            }
            else
            {
                // get node at index
                DLLNode * nodeAtIndex = getNodeAt(index);

                /*
                    set node next and previous
                    for node to be at index i, the current node becomes its next
                    and the current nodes previour becomes its previous
                */
                
                node->setNext(nodeAtIndex);
                node->setPrevious(nodeAtIndex->getPrevious());

                // set node as next for nodeAtIndex previous
                nodeAtIndex->getPrevious()->setNext(node);                
                // set node as nodeAtIndex previous
                nodeAtIndex->setPrevious(node);

                _length++;
            }
        }
        return;
    }

    void deleteFront()
    {
        DLLNode * currentHead = _head; // store current head node
        _head = currentHead->getNext(); // set head pointer current head next
        _head->setPrevious(NULL); // set new head previous to NULL
        delete currentHead; // delete old head
        _length--;
    }

    void deleteEnd()
    {
        DLLNode * currentTail = _tail; // store current tail node
        _tail = currentTail->getPrevious(); // set tail pointer current tail previous
        _tail->setNext(NULL); // set new tail next to NULL
        delete currentTail; // delete old tail
        _length--;
    }

    void deleteAtPosition(int index)
    {
        if (index == 0)
        {
            deleteFront();
            return;
        }
        else if (index == _length - 1)
        {
            deleteEnd();
            return;
        }

        // get node at index
        DLLNode * nodeAtIndex = getNodeAt(index);
        // node next
        DLLNode * nextNode = nodeAtIndex->getNext();
        // node previous
        DLLNode * previousNode = nodeAtIndex->getPrevious();

        previousNode->setNext(nextNode);
        nextNode->setPrevious(previousNode);

        delete nodeAtIndex;
        _length--;
        return;
    }

    void reverse()
    {
        DLLNode * currentNode = _head;
        while (currentNode)
        {
            DLLNode * nextNode = currentNode->getNext();
            DLLNode * previousNode = currentNode->getPrevious();
            if (!previousNode)
            {
                _tail = currentNode;
            }
            if (!nextNode)
            {
                _head = currentNode;
            }
            currentNode->setNext(previousNode);
            currentNode->setPrevious(nextNode);
            currentNode = nextNode;
        }
        return;
    }

    void sort()
    {

        // bubble sort
        DLLNode * currentNode;
        DLLNode * nextNode;

        int currentNodeIndex;
        int currentNodeValue;
        int nextNodeValue;

        for (int i = 1; i <= size() - 1; i++)
        {
            currentNode = _head;
            for (currentNodeIndex = 0; currentNodeIndex < size() - i; currentNodeIndex++, currentNode = getNodeAt(currentNodeIndex))
            {                
                nextNode = currentNode->getNext();
                currentNodeValue = currentNode->getValue();
                nextNodeValue = nextNode->getValue();

                if (currentNodeValue > nextNodeValue)
                {
                    // swap                    
                    deleteAtPosition(currentNodeIndex);    // remove currentNode
                    insertAtPosition(currentNodeValue, currentNodeIndex + 1); // insert removed node after next node
                }
                else
                    continue;
            }
        }

        return;
    }

    void clear()
    {
        for (DLLNode * currentNode = _head; currentNode != NULL; currentNode = currentNode->getNext())
        {
            DLLNode * nextNode = currentNode->getNext();
            if (nextNode)
            {
                nextNode->setPrevious(NULL);
                _head = nextNode;
                delete currentNode;
            }
            else
            {
                // at tail
                _head = NULL;
                _tail = NULL;
                delete currentNode;
            }
            _length--;
        }
    }

    void traverse(void)
    {
        if (_head)
        {
            DLLNode * currentNode = _head;
            while (currentNode)
            {
                std::cout << currentNode->getValue() << " -> ";
                currentNode = currentNode->getNext();
            }
            std::cout << "NULL" << std::endl;
        }

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
    list.deleteAtPosition(2);
    list.insertAtPosition(120, 2);
    list.insertAtEnd(1000);
    list.insertAtPosition(-4, 4);
    list.traverse();

    list.reverse();
    // list.clear();
    list.traverse();
    std::cout << "-----------------------------sorting----------------------------" << std::endl;
    list.sort();
    list.traverse();


	return 0;
}
