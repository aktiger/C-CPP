/*
Author: Justinzhang
Email:  uestczhangchao@gmail.com
Time:   2012-10-4 10:15:21
Desc:   This program is used to implement the child-sibling representation of trees,
        I use a queue to tranverse the tree by layer. This problem is most recently
        meet at the oppo writting test. Of course the first time i meet is at the
        data structure course.
*/
#include <iostream>
using namespace std;

typedef struct Node
{
     struct Node *sibling;
     struct Node *child;   
     char name;
}node;



int main(int argc, char *argv[])
{
    node a,b,c,d,e,f,g,h;
    node* queue[10];
    size_t front=0, end=0;
    
    for(size_t i=0; i<10; i++)
    {
        queue[i] = NULL;
    }
    
    
    a.name = 'A';
    b.name = 'B';
    c.name = 'C';
    d.name = 'D';
    e.name = 'E';
    f.name = 'F';
    g.name = 'G';
    h.name = 'H';
    /*****************************/

    a.child = &b;
    a.sibling = NULL;
    
    b.child = NULL;
    b.sibling = &c;
    
    c.child = &e;
    c.sibling = &d;
    
    e.child = NULL;
    e.sibling = &f;
    
    d.child = NULL;
    d.sibling = NULL;
    
    e.child = NULL;
    e.sibling = &f;
    
    f.child = &h;
    f.sibling = &g;
    
    g.child = NULL;
    g.sibling = NULL;
    
    h.child = NULL;
    h.sibling = NULL;
    /*end of initialization*/
    queue[end++] = &a; //enque the first element of the tree;
    cout << queue[front]->name << endl;
    cout << boolalpha << (front==end) << endl;
    
    while(front!=end) // when the queue is not empty
    {
        node *tmp = queue[front];
        node *tmp2 = tmp;
        cout << tmp->name << "  ";
        front++;
        if(tmp && tmp->sibling!=NULL)
        {
            queue[end++] = tmp->sibling;
        }
        if(tmp2 && tmp2->child)
        {
            queue[end++] = tmp2->child;
        }        
    } 
    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
