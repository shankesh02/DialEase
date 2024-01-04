#include"Functions.cpp"
void arrow(int real_position,int arrow_position);

void arrow(int real_position,int arrow_position)
{
    if(real_position==arrow_position)
        cout<<"--->";
    else
        cout<<"    ";
}

void case14(Linked_list L, Binary_Search_Tree b, Stack s)
{
    int position=10,key_pressed=0,nn=0;
    while(1)
    {
        while(key_pressed!=13)
        {
            system("cls");
            cout<<"--------------- Display Methods --------------- \n\n";
            arrow(10,position);
            cout<<" Display in Contact Creation Order\n";
            arrow(11,position);
            cout<<" Display Contacts\n";
            arrow(12,position);
            cout<<" Display Deleted Contacts\n";
            arrow(13,position);
            cout<<" Go Back To Main Menu\n";

            key_pressed=getch();
            if(key_pressed==80&&position!=13)
                position++;
            else if(key_pressed==72&&position!=10)
                position--;
            else
                position=position;
        }
        switch(position)
        {
            case 10:
                L.display();
                getch();
                position=10;key_pressed=0;
                break;

            case 11:
                cout<<"\n\n-----------Contacts-----------\n\n";
                b.display_inorder(b.return_root());
                getch();
                position=10;key_pressed=0;
                break;

            case 12:
                cout<<"\n\n-----------Deleted Contacts-----------\n\n";
                s.display_stack();
                getch();
                position=10;key_pressed=0;
                break;

            case 13:
                nn=10;
                break;
        }
        if(nn==10)
            break;
    }
}

void case13(Linked_list L, Binary_Search_Tree b)
{
    system("cls");
    cout<<"\nEditing a contact";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<399999999;j++)
        {
            if(j==39999998)
                cout<<".";
        }
    }
    int position=10,key_pressed=0,nn=0;
    string nam,a;
    long long int nno;
    char ch;
    cin.ignore();
    cout<<"\n\nEnter the Contact Name: ";
    getline(cin,nam);
    L.searchh(nam);
    getch();
    while(1)
    {
        while(key_pressed!=13)
        {
            system("cls");
            cout<<"--------------- Edit Contact --------------- \n\n";
            arrow(10,position);
            cout<<" Edit Contact Name\n";
            arrow(11,position);
            cout<<" Edit Contact Number\n\n";
            arrow(13,position);
            cout<<" Edit Another Contact\n";
            arrow(14,position);
            cout<<" Go Back To Main Menu\n";

            key_pressed=getch();
            if(key_pressed==80&&position!=14)
                position++;
            else if(key_pressed==72&&position!=10)
                position--;
            else
                position=position;
        }
        switch(position)
        {
            case 10:
                cin.ignore();
                cout<<"\n\nEnter the Edited Contact Name: ";
                getline(cin,a);
                L.edit(nam,a);
                b.edit(nam,a);
                nam=a;
                getch();
                position=10;key_pressed=0;
                break;

            case 11:
                cout<<"\n\nEnter the Edited Contact Number: ";
                cin>>nno;
                L.edit(nam,nno);
                b.edit(nam,nno);
                getch();
                position=10;key_pressed=0;
                break;

            case 13:
                case13(L,b);
                nn=10;
                break;

            case 14:
                nn=10;
                break;
        }
        if(nn==10)
            break;
    }
}

int main()
{
    Stack s;
    Linked_list L;
    Binary_Search_Tree b;
    int position=10,key_pressed=0, count=0;
    long long int pno;
    string nam;
    char choice;
    ifstream open1("Name.txt");
    ifstream open2("Number.txt");
    while(!open1.eof() && !open2.eof())
    {
        getline(open1,nam);
        open2.read((char *)(&pno),sizeof(pno));
        if(count==0)
        {
            L.create_node1(nam,pno);
            b.create_node2(nam,pno);
            count++;
        }
        else
        {
            L.ins_end(nam,pno);
            b.insert(nam,pno);
        }
    }
    open1.close();
    open2.close();
    b.deleteNode(nam);
    L.del_mid(nam);
    while (1)
    {
        while(key_pressed!=13)
        {
            system("cls");
            cout<<"\t\t\t\t\t+-----------------------------+\n";
            cout<<"\t\t\t\t\t|      Telephone Directory    |";
            cout<<"\n\t\t\t\t\t|     Create.Delete.Restore   |\n";
            cout<<"\t\t\t\t\t+-----------------------------+\n";
            arrow(10,position);
            cout<<" Create Contact\n";
            arrow(11,position);
            cout<<" Delete Contact\n";
            arrow(12,position);
            cout<<" Search Contact\n";
            arrow(13,position);
            cout<<" Edit Contact\n";
            arrow(14,position);
            cout<<" Display Contacts\n";
            arrow(15,position);
            cout<<" Restore Contact\n";
            arrow(16,position);
            cout<<" EXIT\n";

            key_pressed=getch();
            if(key_pressed==80&&position!=16)
                position++;
            else if(key_pressed==72&&position!=10)
                position--;
            else
                position=position;
        }
        switch(position)
        {
            case 10 :
                {
                    system("cls");
                    ofstream write1("Name.txt",ios::app);
                    ofstream write2("Number.txt",ios::app);
                    cout<<"\nCreating a new contact";
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<399999999;j++)
                        {
                            if(j==39999998)
                                cout<<".";
                        }
                    }
                    cin.ignore();
                    cout<<"\n\nEnter the Contact Name: ";
                    getline(cin,nam);
                    cout<<"\nEnter the Contact Number: ";
                    cin>>pno;
                    if(count==0)
                    {
                        L.create_node1(nam,pno);
                        b.create_node2(nam,pno);
                        write1<<nam<<endl;
                        write2.write((const char *)(&pno),sizeof(pno));
                        cout<<"\nContact created!";
                        count++;
                    }
                    else
                    {
                        L.ins_end(nam,pno);
                        b.insert(nam,pno);
                        write1<<nam<<endl;
                        write2.write((const char *)(&pno),sizeof(pno));
                        cout<<"\nContact created!";
                    }
                    cout<<endl<<"\nDo you want to save another contact?(y/n): ";
                    cin>>choice;
                    if(choice=='n' || choice=='N')
                    {
                        cout<<"\n\t\tGoing Back To Main Menu...";
                        getch();
                        position=10;key_pressed=0;
                    }
                    write1.close();
                    write2.close();
                    break;
                }
            case 11:
                system("cls");
                cout<<"\nDeleting a contact";
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<399999999;j++)
                    {
                        if(j==39999998)
                            cout<<".";
                    }
                }
                cin.ignore();
                cout<<"\n\nEnter the Contact Name: ";
                getline(cin,nam);
                if(L.first(nam))
                {
                    pno=L.del_beg();
                    b.deleteNode(nam);
                    s.push1(nam);
                    s.push2(pno);
                    cout<<"\nContact deleted!";
                }
                else
                {
                    b.deleteNode(nam);
                    pno=L.del_mid(nam);
                    if(pno!=0)
                    {
                        s.push1(nam);
                        s.push2(pno);
                        cout<<"\nContact deleted!";
                    }
                }
                cout<<endl<<"\nDo you want to delete another contact?(y/n): ";
                cin>>choice;
                if(choice=='n' || choice=='N')
                {
                    cout<<"\n\t\tGoing Back To Main Menu...";
                    getch();
                    position=10;key_pressed=0;
                }
                break;

            case 12:
                system("cls");
                cout<<"\nSearching a contact";
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<399999999;j++)
                    {
                        if(j==39999998)
                            cout<<".";
                    }
                }
                cin.ignore();
                cout<<"\n\nEnter the Contact Name: ";
                getline(cin,nam);
                L.searchh(nam);
                cout<<endl<<"\n\nDo you want to search another contact?(y/n): ";
                cin>>choice;
                if(choice=='n' || choice=='N')
                {
                    cout<<"\n\t\tGoing Back To Main Menu...";
                    getch();
                    position=10;key_pressed=0;
                }
                break;

            case 13:
                case13(L,b);
                position=10;key_pressed=0;
                break;

            case 14:
                case14(L,b,s);
                position=10;key_pressed=0;
                break;

            case 15:
                cout<<"\n\n-----------Deleted Contacts-----------\n\n";
                s.display_stack();
                cin.ignore();
                cout<<"\n\nEnter the contact name to restore: ";
                getline(cin,nam);
                s.restore(nam,L,b);
                getch();
                position=10;key_pressed=0;
                break;

            case 16:
                exit(1);
                break;
        }
    }

}
