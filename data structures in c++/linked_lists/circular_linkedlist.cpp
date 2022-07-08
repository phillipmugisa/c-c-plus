/*
    This program shows the implementation of a circular singly linked links
    For a circular linked list, the tail node points to the head node.
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

class CLLNode
{
private:
    int _value;
    CLLNode * _next = this;

public:
    CLLNode(int value)
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
    void setNext(CLLNode * next)
    {
        _next = next;
    }
    CLLNode * getNext()
    {
        return _next;
    }
};

class CLL
{
private:
    CLLNode * _head = NULL;
    CLLNode * _tail = NULL;
    int _length = 0;


    CLLNode * getNodeAt(int index)
    {
	if (index < _length)
	{
		CLLNode * node = _head;

		for (int i = 0; i <= index; i++)
		{
		    if (i == index)
			break;

		    node = node->getNext();
		}
		return node;
	}
	// return empty node
	CLLNode * node = new CLLNode(0);
	return node;
    }

public:
    int size() {return _length;}
    void insertAtFront(int value)
    {
        // create new node
        CLLNode * node = new CLLNode(value);
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
                _tail->setNext(node);
                _head = node;
            }
            
            _length++;
        }

    }
    void insertAtEnd(int value)
    {
        // create new node
        CLLNode * node = new CLLNode(value);
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
        CLLNode * node = new CLLNode(value);
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
            
            CLLNode * nodeAtIndex = getNodeAt(index);
            CLLNode * previousNode = getNodeAt(index - 1);

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
        CLLNode * atFront = _head;
        // set next to _head
        _head = _head->getNext();

        // set tail to point to new head
        _tail->setNext(_head);
        // delete previous _head
        delete atFront;
        _length--;
        return;
    }
    void deleteEnd()
    {
	// locate node before current tail
        CLLNode * previousNode = getNodeAt(_length - 2);
        // delete _tail
        delete _tail;
        _tail = previousNode;
        // _tail always points to head
        _tail->setNext(_head);

        _length--;
	return;
    }
    void deletePosition(int index)
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

	// get node before node at passed index
	CLLNode * nodeAtIndex = getNodeAt(index);
	CLLNode * prevNode = getNodeAt(index - 1);

	prevNode->setNext(nodeAtIndex->getNext());
	delete nodeAtIndex;
	return;

    }

    void clear()
    {
        CLLNode * currentNode = _head;
        CLLNode * nextNode = NULL;

	while (currentNode)
	{
		nextNode = currentNode->getNext();
		delete currentNode;
	}
    }

    void traverse()
    {
        CLLNode * currentNode = _head;
        while(currentNode)
        {
        	 std::cout << currentNode->getValue() << " -> ";

	        // check if at tail
		if (currentNode == _tail) break;
		
		currentNode = currentNode->getNext();
        }

        std::cout << "HEAD" << std::endl;
    }
};

int main (int argc, char * argv[])
{

    CLL list;
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

    return 0;
}
