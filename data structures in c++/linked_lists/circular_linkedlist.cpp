/*
    This program shows the implementation of a circular singly linked links
*/

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
    SLLNode * _next = this;

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
                _head->setNext(node);
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
                node->setNext(_head);
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
            
            SLLNode * nodeAtIndex = getNodeAt(index);
            SLLNode * previousNode = getNodeAt(index - 1);

            // node points to node at passed index
            node->setNext(nodeAtIndex);

            // set next for previous
            previousNode->setNext(node);

            _length++;

        }
    }
    void deleteFront()
    {
        // store _head
        SLLNode * atFront = _head;
        // set next to _head
        _head = _head->getNext();

        std::cout << "new head: " << _head->getValue() << std::endl;

        // set tail to point to new head
        _tail->setNext(_head);
        // delete previous _head
        delete atFront;
        _length--;
        return;
    }
    void deleteEnd()
    {
        SLLNode * previousNode = getNodeAt(_length - 2);
        // delete _tail
        delete _tail;
        _tail = previousNode;
        // _tail always points to head
        _tail->setNext(_head);

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

    void clear()
    {
        SLLNode * currentNode = _head;
        SLLNode * nextNode = NULL;

        while (currentNode)
        {
            if(!nextNode)
            {
                // delete tail since its next is NULL because head was alright deleted
                delete currentNode;
            }
            else
            {
                delete currentNode;
                currentNode = nextNode;
                nextNode = currentNode->getNext();
            }

            _length--;
        }
    }

    void traverse()
    {
        SLLNode * currentNode = _head;
        while(currentNode)
        {
            std::cout << currentNode->getValue() << " -> ";

            // check if at tail
            if (currentNode != _tail )
                currentNode = currentNode->getNext();
            else
                break;
        }

        std::cout << "HEAD" << std::endl;
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
    // list.insertAtPosition(2, 120);
    // list.insertAtEnd(1000);
    // list.insertAtPosition(2, -4);
    // list.traverse();

    return 0;
}