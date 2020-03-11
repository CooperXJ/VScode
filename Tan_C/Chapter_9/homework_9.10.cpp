#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

typedef struct stu{
    int ID;
    int Score;
    struct stu* next;
}Stu;

Stu *Create_LinkList(int count)
{
    Stu * head = (Stu*)malloc(sizeof(Stu));
    Stu *tail = head;

    tail->next = NULL;

    for(int i =0;i<count;i++)
    {
        Stu * p = (Stu*)malloc(sizeof(Stu));
        cin>>p->ID;
        cin>>p->Score;
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }

    return head;   
}

void show(Stu *head)
{
    Stu *p = head->next;
    while (p!=NULL)
    {
        cout<<p->ID<<" "<<p->Score<<endl;
        p = p->next;
    }    
}

Stu * Merge(Stu *head1,Stu *head2)
{
    Stu *p1 = head1->next;
    Stu *p2 = head2->next;
    Stu *head = (Stu*)malloc(sizeof(Stu));
    Stu *tail = head;
    tail->next = NULL;

    while (p1!=NULL&&p2!=NULL)
    {
        Stu *t = (Stu*)malloc(sizeof(Stu));
        if(p1->ID<p2->ID)
        {
            t->ID = p1->ID;
            t->Score = p1->Score;
            t->next = tail->next;
            tail->next = t;
            tail = t;
            p1 = p1->next;
        }
        else
        {
            t->ID = p2->ID;
            t->Score = p2->Score;
            t->next = tail->next;
            tail->next = t;
            tail = t;
            p2 = p2->next;
        }  
    }
    
    if(p1!=NULL)
    {
        Stu *t = (Stu*)malloc(sizeof(Stu));

        t->ID = p1->ID;
        t->Score = p1->Score;
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
    
    if(p2!=NULL)
    {
        Stu *t = (Stu*)malloc(sizeof(Stu));

        t->ID = p2->ID;
        t->Score = p2->Score;
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }

    return head;
}

void sort(Stu *head)
{
    for(Stu *p = head->next;p!=NULL;p = p->next)
    {
        for(Stu *q = p->next;q!=NULL;q = q->next)
        {
            if(p->ID>q->ID)
            {
                int t = q->ID;
                q->ID = p->ID;
                p->ID = t;

                t = q->Score;
                q->Score = p->Score;
                p->Score = t;
            }
        }
    }
}

int main()
{
    Stu *head1 = Create_LinkList(4);
    show(head1);
    cout<<"--------"<<endl;
    sort(head1);
    show(head1);
    // cout<<"--------"<<endl;
    // Stu *head2 = Create_LinkList(3);
    // show(head2);
    // cout<<"--------"<<endl;
    // Stu* head = Merge(head1,head2);
    // show(head);

    system("pause");
}