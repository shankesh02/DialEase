#include"Headers.h"

///Linked List Funtion Definitions

int Linked_list::no=1;

void Linked_list::create_node1(string nam,long long int elt)
{
    struct node1 *n=new node1;
    n->name=nam;
    n->cno=elt;
    n->link=NULL;
    start=n;
}

void Linked_list::ins_end(string nam, long long int elt)
{
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    struct node1 *n=new node1;
    n->name=nam;
    n->cno=elt;
    n->link=NULL;
    ptr->link=n;
    no++;
}

long long int Linked_list::del_beg()
{
    struct node1 *temp=NULL;
    ptr=start;
    temp=ptr;
    start=start->link;
    delete temp;
    no--;
    return ptr->cno;
}

long long int Linked_list::del_mid(string item)
{
    struct node1 *temp=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->link==NULL)
        {
            break;
        }
        else if(ptr->link->name==item)
        {
            temp=ptr->link;
            ptr->link=ptr->link->link;
            no--;
            return temp->cno;
            break;
        }
        else
            ptr=ptr->link;
    }
    if(ptr->link==NULL)
    {
        cout<<"\nContact is not available to delete!";
        return false;
    }
    delete temp;
}

void Linked_list::searchh(string a)
{
    int c=0;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->name==a)
        {
            c=1;
            cout<<"\nContact found!"<<endl;
            cout<<"\nContact Name  : "<<ptr->name;
            cout<<"\nContact Number: "<<ptr->cno;
            break;
        }
        else
            ptr=ptr->link;
    }
    if(c==0)
        cout<<"\nContact not found!"<<endl;
}

long long int Linked_list::searchhh(string a)
{
    int c=0;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->name==a)
        {
            c=1;
            return ptr->cno;
            break;
        }
        else
            ptr=ptr->link;
    }
    if(c==0)
        return false;
}

void Linked_list::no_of_elts()
{
    cout<<"\nNumber of contacts: "<<no<<endl;
}

void Linked_list::display()
{
    cout<<"\n------ Contacts ------";
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<"\n\nContact Name: "<<ptr->name;
        cout<<"\nContact Number: "<<ptr->cno;
        ptr=ptr->link;
    }
}

bool Linked_list::first(string nam)
{
    ptr=start;
    if(ptr->name==nam)
        return true;
    else
        return false;
}

void Linked_list::edit(string nam, string a)
{
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->name==nam)
        {
            ptr->name=a;
            cout<<"\n\nContact Edited Successfully!";
            break;
        }
        else
            ptr=ptr->link;
    }
}

void Linked_list::edit(string nam, long long int mno)
{
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->name==nam)
        {
            ptr->cno=mno;
            cout<<"\n\nContact Edited Successfully!";
            break;
        }
        else
            ptr=ptr->link;
    }
}

///Binary Search Tree Function Definitions

void Binary_Search_Tree::create_node2(string nam, long long int a)
{
    struct node2 *n=new node2;
    n->name=nam;
    n->cno=a;
    n->lchild=NULL;
    n->rchild=NULL;
    root=n;
}

void Binary_Search_Tree::insert(string nam, long long int a)
{
    struct node2 *par=NULL;
    ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->name<nam)
        {
            par=ptr;
            ptr=ptr->rchild;
        }
        else
        {
            par=ptr;
            ptr=ptr->lchild;
        }
    }
    if(par->name<nam)
    {
        struct node2 *n=new node2;
        n->name=nam;
        n->cno=a;
        n->lchild=NULL;
        n->rchild=NULL;
        par->rchild=n;
    }
    else
    {
        struct node2 *n=new node2;
        n->name=nam;
        n->cno=a;
        n->lchild=NULL;
        n->rchild=NULL;
        par->lchild=n;
    }
}

node2 *Binary_Search_Tree::return_root()
{
    return root;
}

int Binary_Search_Tree::getcount(struct node2 *T)
{
    if(T==NULL)
        return 0;
    else
        return getcount(T->lchild)+1+getcount(T->rchild);
}

void Binary_Search_Tree::display_inorder(struct node2 *T)
{
    if(T!=NULL)
    {
        display_inorder(T->lchild);
        cout<<"\n\nContact Name: "<<T->name;
        cout<<"\nContact Number: "<<T->cno;
        display_inorder(T->rchild);
    }
}

void Binary_Search_Tree::edit(string nam, string a)
{
    ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->name==nam)
        {
            ptr->name=a;
            break;
       }
       else if(ptr->name<nam)
        {
           ptr=ptr->rchild;
        }
        else
        {
            ptr=ptr->lchild;
        }
    }
}

void Binary_Search_Tree::edit(string nam, long long nno)
{
    ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->name==nam)
        {
            ptr->cno=nno;
            break;
       }
       else if(ptr->name<nam)
        {
           ptr=ptr->rchild;
        }
        else
        {
            ptr=ptr->lchild;
        }
    }
}

bool Binary_Search_Tree::deleteNode(string nam)
{
    struct node2 *p=return_root(), *q=NULL, *rp=NULL, *s=NULL, *f=NULL;
    while(p!=NULL && p->name!=nam)
    {
        q=p;
        if(p->name<nam)
        {
            p=p->rchild;
        }
        else
        {
            p=p->lchild;
        }
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p->name<q->name)
        {
            q->lchild=NULL;
        }
        else
        {
            q->rchild=NULL;
        }
        return true;
    }
    else
    {
        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            f=p;
            rp=p->rchild;
            s=rp->lchild;
            while(s!=NULL)
            {
                p=rp;
                rp=s;
                s=rp->lchild;
            }
            if(f!=p)
            {
                p->lchild=rp->rchild;
                rp->rchild=f->rchild;
            }
            rp->lchild=f->lchild;
            if(rp->name>q->name)
            {
                q->rchild=rp;
            }
            else
            {
                q->lchild=rp;
            }
            return true;
        }
        else
        {
            if(p->lchild==NULL)
            {
                rp=p->rchild;
            }
            else
            {
                rp=p->lchild;
            }
            if(p->name<q->name)
            {
                q->lchild=rp;
            }
            else
            {
                q->rchild=rp;
            }
            return true;
        }
    }
}

///Stack Function Definitions

bool Stack::push1(string nam)
{
    if(top1==num-1)
        return false;
    else
    {
        S1[++top1]=nam;
        ndlt++;
        return true;
    }
}

bool Stack::push2(long long int a)
{
    if(top2==num-1)
        return false;
    else
    {
        S2[++top2]=a;
        return true;
    }
}

string Stack::pop1()
{
    string a;
    if(top1==-1)
        return "False";
    a=S1[top1];
    top1=top1-1;
    ndlt--;
    return a;
}

long long int Stack::pop2()
{
    long long int d;
    if(top2==-1)
        return false;
    d=S2[top2];
    top2=top2-1;
    return d;
}

void Stack::display_stack()
{
    long long int arr2[10];
    int cc=ndlt;
    for(int i=0;i<cc;i++)
    {
        arr2[i]=pop2();
        arr[i]=pop1();
    }
    for(int i=0;i<cc;i++)
    {
        push1(arr[i]);
        push2(arr2[i]);
    }
    for(int i=0;i<cc;i++)
    {
        cout<<"\n("<<i+1<<") "<<arr[i]<<"\t\t"<<arr2[i];
    }
}

void Stack::restore(string nam, Linked_list ll, Binary_Search_Tree bb)
{
    int c=0,x=0,i=0;
    string cmp;
    long long int mn;
    while(c==0)
    {
        cmp=pop1();
        x++;
        if(cmp=="False")
        {
            c=2;
        }
        else if(cmp==nam)
        {
            c=1;
        }
        else
        {
            N[i]=cmp;
            i++;
        }
    }
    if(c==1)
    {
        for(int i=0;i<x-1;i++)
        {
            mn=pop2();
            NO[i]=mn;
        }
        mn=pop2();
        for(int i=0;i<x-1;i++)
        {
            push1(N[i]);
            push2(NO[i]);
        }
        ll.ins_end(cmp,mn);
        bb.insert(cmp,mn);
    }
    else
    {
        cout<<"\nContact not available to restore!";
    }
}

