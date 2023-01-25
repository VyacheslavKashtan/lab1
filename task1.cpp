#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 1000

class Queue
{
    char *arr;     
    int capacity;   
    int first;      
    int last;       
    int count;      
 
public:
    Queue(int size = SIZE);    
    ~Queue();                   
 
    int dequeue();
    void add(char x);
    int poll();
    int size();
    bool isEmpty();
    bool isFull();
};
 
Queue::Queue(int size)
{
    arr = new char[size];
    capacity = size;
    first = 0;
    last = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "pusta cherga\n";
        exit(EXIT_FAILURE);
    }
 
    char x = arr[first];
    cout << "vidalenya elementa " << x << endl;
 
    first = (first + 1) % capacity;
    count--;
 
    return x;
}
 
void Queue::add(char item)
{
    if (isFull())
    {
        cout << "queve is full\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "dobavka elementa " << item << endl;
 
    last = (last + 1) % capacity;
    arr[last] = item;
    count++;
}
 
int Queue::poll()
{
    if (isEmpty())
    {
        cout << "pusta cherga\n";
        exit(EXIT_FAILURE);
    }
    return arr[first];
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == capacity);
}
 
int main()
{
    Queue q(5);
 
    q.add('1');
    q.add('2');
    q.add('3');
 
    cout << "pershiy element " << q.poll() << endl;
    q.dequeue();
    
    q.add('4');
 
    cout << "rozmir chergi " << q.size() << endl;
 
    q.dequeue();
    q.dequeue();
    q.dequeue();
 
    if (q.isEmpty()) {
        cout << "pusta\n";
    }
    else {
        cout << "povna\n";
    }
 
    return 0;
}