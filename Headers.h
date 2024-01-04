///Data Structures Lab
///Package
///Telephone Directory
///Group: Shyam Sundaar H & Shankesh U K
///Roll Number: 21PW33 & 21PW31

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;

struct node1
{
    string name;
    long long int cno;
    struct node1 *link;
};

struct node2
{
    string name;
    long long int cno;
    struct node2 *lchild, *rchild;
};

class Linked_list
{
        struct node1 *start=NULL, *ptr=NULL;
        static int no;
    public:
        void create_node1(string, long long int);
        void ins_end(string, long long int);
        long long int del_beg();
        long long int del_mid(string);
        void no_of_elts();
        void searchh(string);
        void display();
        long long int searchhh(string);
        bool first(string);
        void edit(string, string);
        void edit(string, long long int);
};

class Binary_Search_Tree
{
        struct node2 *root=NULL, *ptr=NULL;
    public:
        void create_node2(string, long long int);
        void insert(string, long long int);
        node2 *return_root();
        int getcount(struct node2 *);
        void display_inorder(struct node2 *);
        void edit(string, string);
        void edit(string, long long int);
        bool deleteNode(string);
};

class Stack
{
        string S1[100];
        long long int S2[100];
        string N[50];
        long long int NO[50];
        string arr[50];
        int num,top1,top2;
        int ndlt;
    public:
        Stack()
        {
            top1=-1;
            top2=-1;
            num=100;
            ndlt=0;
            for(int i=0;i<50;i++)
            {
                N[i]="";
            }
            for(int i=0;i<50;i++)
            {
                NO[i]=0;
            }
            for(int i=0;i<num;i++)
            {
                S1[i]="";
            }
            for(int i=0;i<num;i++)
            {
                S2[i]=0;
            }
        }
        bool push1(string);
        bool push2(long long int);
        string pop1();
        long long int pop2();
        void display_stack();
        void restore(string, Linked_list, Binary_Search_Tree);
};
