/*
Author:justinzhang
Email:uestczhangchao@gmail.com
Time:2012-11-27 19:05:15
Desc: This file is used to practice the observer pattern.
*/
#include <iostream>
#include <vector>
using namespace std;

class observer;

class subject
{
    public:
    vector<observer *> observer_list;
    virtual void add(observer *)=0;
    virtual void del(observer *)=0;
    virtual void notifyAll()=0;
    virtual bool getstate()=0;
};

class concretesubject1:public subject
{

    public:
        bool state;
        virtual void notifyAll();
        virtual void add(observer *);
        virtual void del(observer *);
        virtual bool getstate()
        {
            return state;
        }
        concretesubject1(bool stat)
        {
            this->state = stat;
        }

};
void concretesubject1::add(observer *ob)
{
    observer_list.push_back(ob);
}

void concretesubject1::del(observer *ob)
{
    vector<observer *>::iterator it = observer_list.begin();
    for(;it!=observer_list.end();)
    {
        if(ob==*it)
        {
            observer_list.erase(it++);
        }
        else
        {
            it++;
        }
    }
}


class observer
{
    public:
        virtual void update()=0;
};
class concreteobserver1:public observer
{
    bool state;
    public:
    concreteobserver1(bool stat,subject* sub)
    {
        state = stat;
        subj = sub;
    }
    subject *subj;
    virtual void update();
    bool getstate()
    {
        return state;
    }

};

void concreteobserver1::update()
{
    state = subj->getstate();
}

class concreteobserver2:public observer
{
    bool state;
    public:
    concreteobserver2(bool stat,subject* sub)
    {
        state = stat;
        subj = sub;
    }
    subject *subj;
    virtual void update();
    bool getstate()
    {
        return state;
    }
};

void concreteobserver2::update()
{
    state = subj->getstate();
}

/*
Hear i put notifyAll after update, cause i will use the update
method in it~
*/
void concretesubject1::notifyAll()
{
    vector<observer *>::iterator it = observer_list.begin();
    for(;it!=observer_list.end(); it++)
    {
        (*it)->update();
    }
}



int main()
{
    concretesubject1 cs1(false);
    concreteobserver1 ob1(false,&cs1);
    concreteobserver2 ob2(false,&cs1);
    cs1.add(&ob1);
    cs1.add(&ob2);
    cs1.state = true;
    cout << cs1.state << endl;
    cs1.notifyAll();
    cout << ob1.getstate() << endl;
    cout << ob2.getstate() << endl;

    cs1.state = false;
    cs1.del(&ob1);
    cs1.notifyAll();
    cout << ob1.getstate() << endl;
    cout << ob2.getstate() << endl;

    return 0;
}
