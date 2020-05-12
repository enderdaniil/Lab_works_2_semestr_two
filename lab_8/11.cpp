#include <iostream>

using namespace std;

class Stack
{
protected:
    int* Values;                   
    int Size;                   
    int Top;

public:
    Stack(): Size(10)
    { 
        Top = -1;
        Values = new int[Size];
    }

    Stack(int s) : Size(s)
    {
        Top = -1;
        Values = new int[Size];
    }

    void Push(int number)
    {
        Top++;
        Values[Top] = number;
    }

    int Pop()
    {
        return Values[Top];
        Top--;
    }
};

struct Pair
{
    int x;
    int y;
};

class PairStack : public Stack
{
public:
    
    PairStack()
    {
        Stack(10);
    }

    PairStack(int a) 
    {
        Stack::Size = a;
        Top = -1;
        Values = new int[Size];
    }

    void Push(Pair a)
    {
        Stack::Push(a.x);
        Stack::Push(a.y);
    }

    Pair Pop()
    {
        Pair rez;
        rez.y = Stack::Pop();
        Stack::Top--;
        rez.x = Stack::Pop();
        Stack::Top--;
        return(rez);
    }
};

int main()
{
    PairStack show;

    Pair cord;
    cord.x = 2;
    cord.y = -3;

    show.Push(cord);

    Pair result = show.Pop();

    cout << "Result x = " << result.x << endl;
    cout << "Result y = " << result.y << endl;

	return 0;
}
