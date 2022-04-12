// this program demonstrates the operation on a singly linked list
/*
    -> insertAtFront
    -> insertAtEnd
    -> insertAtPosition
    -> deleteFront
    -> deleteEnd
    -> deletePosition

    -> traverse()
    -> sort()
    -> reverseLL()

*/

#include <iostream>

class SLLNode
{
private:
    int _value;
    SLLNode * _next = NULL;

public:
    SLLNode(int value)
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
    void setNext(SLLNode * next)
    {
        _next = next;
    }
    SLLNode * getNext()
    {
        return _next;
    }
};

class SLL
{
private:
    SLLNode * _head = NULL;
    SLLNode * _tail = NULL;
    int _length = 0;

public:
    int size() {return _length;}
    void insertAtFront(int value)
    {
        // create new node
        SLLNode * node = new SLLNode(value);
        if (node)
        {
            if(_head == NULL)
            {
                _head = node;
                _tail = node;
            }
            else
            {
                node->setNext(_head);
                _head = node;
            }
            
            _length++;
        }

    }
    void insertAtEnd(int value)
    {
        // create new node
        SLLNode * node = new SLLNode(value);
        if (node)
        {
            if(!_tail)
            {
                _head = node;
                _tail = node;
            }
            else
            {
                _tail->setNext(node);
                _tail = node;
            }
            _length++;
        }
    }
    void insertAtPosition(int index, int value)
    {
        // create new node
        SLLNode * node = new SLLNode(value);
        if (node)
        {            
            int count = 0;

            SLLNode * currentNode = _head;
            SLLNode * nextNode = currentNode->getNext();

            while(nextNode)
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
                else if (count == index - 1)
                {
                    node->setNext(nextNode);
                    currentNode->setNext(node);
                    _length++;
                }

                currentNode = nextNode;
                nextNode = currentNode->getNext();
                count++;
            }
        }
    }
    void deleteFront()
    {
        // store _head
        SLLNode * atFront = _head;
        // set next to _head
        _head = _head->getNext();
        // delete previous _head
        atFront = NULL;
        _length--;
        return;
    }
    void deleteEnd()
    {
        // locate node before _tail
        int count = 0;

        SLLNode * currentNode = _head;
        SLLNode * previousNode = NULL;

        while (count < _length)
        {

            if (count == _length - 1)
            {
                _tail = previousNode;
                previousNode->setNext(currentNode->getNext()); // !important, tail's next is set to NULL

                delete currentNode;
                _length--;
                return;
                
            }

            previousNode = currentNode;
            currentNode = currentNode->getNext();
            count++;
        }

        _length--;

    }
    void deletePosition(int index)
    {
        int count = 0;

        SLLNode * currentNode = _head;
        SLLNode * nextNode = currentNode->getNext();

        while (count < _length)
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
            else if (count == index - 1)
            {
                // create temp
                SLLNode * nodeToDate = nextNode;
                // set current node's next to the node to be deleted's next
                currentNode->setNext(nextNode->getNext());
                // delete node
                delete nodeToDate;

                _length--;
                return;
            }

            currentNode = nextNode;
            nextNode = currentNode->getNext();
            count++;
        }
    }

    SLLNode * getNodeAt(int index)
    {
        SLLNode * node = _head;

        for (int i = 0; i <= index; i++)
        {
            if (i == index)
                break;

            node = node->getNext();
        }

        return node;
    }

    void clear()
    {
        SLLNode * currentNode = _head;
        SLLNode * previousNode = NULL;

        while (currentNode)
        {
            if (previousNode)
            {
                delete previousNode;
            }
            previousNode = currentNode;
            currentNode = currentNode->getNext();
            
            _length--;

        }

        std::cout << "List cleared, length: " << size() << std::endl;
    }

    void traverse()
    {
        SLLNode * currentNode = _head;
        while(currentNode)
        {
            std::cout << currentNode->getValue() << " -> ";
            currentNode = currentNode->getNext();
        }
        std::cout << "NULL" << std::endl;
    }

    void reverseLL()
    {
        SLLNode * previousNode = NULL, * currentNode = _head, * nextNode;

        while (currentNode)
        {
            if (!previousNode)
                _tail = currentNode;
                
            nextNode = currentNode->getNext();
            currentNode->setNext(previousNode);

            previousNode = currentNode;
            currentNode = nextNode;
        }

        _head = previousNode;
        
    }

    void sort()
    {
        // USING BUBBLE SORT

        SLLNode * currentNode;
        SLLNode * nextNode;

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
                    deletePosition(currentNodeIndex);    // remove currentNode
                    insertAtPosition(currentNodeIndex + 1, currentNodeValue); // insert removed node after next node
                }
                else
                    continue;
            }
        }

    }
};

int main (int argc, char * argv[])
{

    SLL list;
    list.insertAtFront(0);
    list.insertAtFront(10);
    list.insertAtEnd(99);
    list.insertAtEnd(34);
    list.insertAtPosition(1, 100);
    list.insertAtPosition(3, 920);
    list.traverse();

    list.deleteFront();
    list.deleteEnd();
    list.deletePosition(2);
    list.insertAtPosition(2, 120);
    list.insertAtEnd(1000);
    list.insertAtPosition(2, -4);
    list.traverse();

    // list.clear();
    std::cout << "\n";
    std::cout << "**********************************" << std::endl;
    std::cout << "**********reversing list**********" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "\n";
    list.reverseLL();
    list.traverse();

    std::cout << "\n";
    std::cout << "**********************************" << std::endl;
    std::cout << "**********sorting list************" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "\n";
    list.sort();
    list.traverse();


    return 0;
}