#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int _data)
    {
        this->data = _data;
        this->next = NULL;
    }
};

class Queue
{

public:
    ListNode *front;
    ListNode *rear;
    int length;

    Queue()
    {
        front = NULL;
        rear = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        return false;
    }
    int getSize()
    {
        return this->length;
    }
    void enQueue(int _data)
    {
        ListNode *newNode = new ListNode(_data);
        if (front == NULL)
        {
            this->front = this->rear = newNode;
        }
        else
        {
            this->rear->next = newNode;
            this->rear = newNode;
        }
        length++;
    }
    int deQueue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        else
        {
            ListNode *temp = this->front;
            int data = temp->data;
            this->front = this->front->next;
            delete temp;
            length--;
            return data;
        }
    }
    int peek()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return this->front->data;
    }
    int getRear (){
        return this->rear->data;
    }

    void print()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        ListNode *temp = this->front;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    
};

int main()
{
    Queue *queue = new Queue();
    queue->enQueue(1);
    queue->enQueue(2);
    queue->enQueue(3);
    queue->enQueue(99);
    cout<<endl;
    queue->print();
    cout<<endl;

    while (!queue->isEmpty())
    {
        queue->deQueue();
    }
    
    queue->print();

    return 0;
}