#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

#define array_size 1000

int total=0;

class Blood_Bank
{
private:
    string name[array_size];
    int id[array_size];
    string blood_group[array_size];
    int number_of_donate[array_size];
    string last_date_of_donate[array_size];
    string phone_number[array_size];
    string email[array_size];

public:
    void choice()
    {
        load_data();
        while(1)
        {
            int a;
            cout<<"\t\t\t\tBlood Bank Management System"<<endl;
            cout<<"\t\t\t ========================================"<<endl;
            cout<<"\t\t\t\t1. Add New Data"<<endl;
            cout<<"\t\t\t\t2. View List of Donor"<<endl;
            cout<<"\t\t\t\t3. Search Donor"<<endl;
            cout<<"\t\t\t\t4. Edit a Data"<<endl;
            cout<<"\t\t\t\t5. Delete a Donor Info"<<endl;
            cout<<"\t\t\t\t6. Exit and save"<<endl;
            cout<<"\t\t\t\t";
            cin>>a;
            system("cls");
            switch(a)
            {
            case 1:
                add_data();
                break;
            case 2:
                view_data();
                break;
            case 3:
                search_doner();
                break;
            case 4:
                edit_data();
                break;
            case 5:
                delete_data();
                break;
            case 6:
                    exit_and_save();
                break;
            default:
                cout<<"Invalid Input"<<endl;
            }
        }

    }
    void add_data()
    {
        cout<<"\t\t\t\tAdd New Data"<<endl;
        cout<<"\t\t\t ========================="<<endl;
        cout<<"\t\t\t\tEnter Name: ";
        cin>>name[total];
        cout<<"\t\t\t\tEnter ID: ";
        cin>>id[total];
        cout<<"\t\t\t\tBlood Group: ";
        cin>>blood_group[total];
        cout<<"\t\t\t\tNumber of Blood Donate: ";
        cin>>number_of_donate[total];
        cout<<"\t\t\t\tLast Date of Blood Donate: ";
        cin>>last_date_of_donate[total];
        cout<<"\t\t\t\tPhone Number: ";
        cin>>phone_number[total];
        cout<<"\t\t\t\tEmail: ";
        cin>>email[total];
        total++;
        system("cls");
        cout<<"\n\n\n\n\t\t\t\tAdding Data Successfully"<<endl;
        Sleep(1500);
        system("cls");
    }
    void view_data()
    {
        if(total==0)
        {
            cout<<"Empty! Please adding some data"<<endl;
            Sleep(1500);
            system("cls");
            return;
        }
        cout<<"\t\t\t\tDonor List"<<endl;
        cout<<"\t\t\t ========================="<<endl;
        for(int i=0; i<total; i++)
        {
            cout<<"\t\tName: "<<name[i]<<"  |   ID: "<<id[i]<<"  |   Blood Group: "<<blood_group[i]<<endl;
        }
        system("pause");
        system("cls");
    }

    void search_doner()
    {
        if(total==0)
        {
            cout<<"Empty! Please adding some data"<<endl;
            Sleep(1500);
            system("cls");
            return;
        }
        int d_id;

        cout<<"\t\t\t\tSearch a Donor"<<endl;
        cout<<"\t\t\t ========================="<<endl;
        cout<<"Enter a Donor Id: ";
        cin>>d_id;
        for(int i=0; i<total; i++)
        {
            if(d_id==id[i])
            {
                cout<<"\t\t\t\tName: "<<name[i]<<endl;
                cout<<"\t\t\t\tID: "<<id[i]<<endl;
                cout<<"\t\t\t\tBlood Group: "<<blood_group[i]<<endl;
                cout<<"\t\t\t\tNumber of Blood Donate: "<<number_of_donate[i]<<endl;
                cout<<"\t\t\t\tLast Date of Blood Donate: "<<last_date_of_donate[i]<<endl;
                cout<<"\t\t\t\tPhone Number: "<<phone_number[i]<<endl;
                cout<<"\t\t\t\tEmail: "<<email[i]<<endl;
                system("pause");
                system("cls");
                break;
            }

        }
    }
    void delete_data()
    {
        if(total==0)
        {
            cout<<"Empty! Please adding some data"<<endl;
            Sleep(1500);
            system("cls");
            return;
        }

        cout<<"\t\t\t\tDelete a Data"<<endl;
        cout<<"\t\t\t ========================="<<endl;
        int x;
        cout<<"Enter ID: ";
        cin>>x;
        for(int i=0; i<total; i++)
        {
            if(x==id[i])
            {
                for(int j=i; j<total; j++)
                {
                    name[j]=name[j+1];
                    id[j]=id[j+1];
                    blood_group[j]=blood_group[j+1];
                    number_of_donate[j]=number_of_donate[j+1];
                    last_date_of_donate[j]=last_date_of_donate[j+1];
                    phone_number[j]=phone_number[j+1];
                    email[j]=email[j+1];
                }
                total--;
                cout<<name[i]<<"s Data is Deleted!"<<endl;
                Sleep(1500);
                system("cls");
            }
        }
    }
    void edit_data()
    {
         if(total==0)
        {
            cout<<"Empty! Please adding some data"<<endl;
            Sleep(1500);
            system("cls");
            return;
        }

        int c;
        cout<<"\t\t\t\tEdit a Data"<<endl<<endl;
        cout<<"Enter Id which you want to edit: ";
        cin>>c;
        for(int i=0; i<total; i++)
        {
            if(c==id[i])
            {
                cout<<"\t\t\t\tPrevious Data"<<endl;
                cout<<"\t\t\t ========================="<<endl;
                cout<<"\t\t\t\tName: "<<name[i]<<endl;
                cout<<"\t\t\t\tBlood Group: "<<blood_group[i]<<endl;
                cout<<"\t\t\t\tNumber of Blood Donate: "<<number_of_donate[i]<<endl;
                cout<<"\t\t\t\tLast Date of Blood Donate: "<<last_date_of_donate[i]<<endl;
                cout<<"\t\t\t\tPhone Number: "<<phone_number[i]<<endl;
                cout<<"\t\t\t\tEmail: "<<email[i]<<endl;

                cout<<"\t\t\t ========================="<<endl;
                cout<<"\t\t\t\tNew Data"<<endl;
                cout<<"\t\t\t -------------------------"<<endl;
                cout<<"\t\t\t\tName: ";
                cin>>name[i];
                cout<<"\t\t\t\tBlood Group: ";
                cin>>blood_group[i];
                cout<<"\t\t\t\tNumber of Blood Donate: ";
                cin>>number_of_donate[i];
                cout<<"\t\t\t\tLast Date of Blood Donate: ";
                cin>>last_date_of_donate[i];
                cout<<"\t\t\t\tPhone Number: ";
                cin>>phone_number[i];
                cout<<"\t\t\t\tEmail: ";
                cin>>email[i];
                system("cls");
                cout<<"Data Edited Successfully"<<endl;
                Sleep(1500);
                system("cls");
            }
        }

    }

    void exit_and_save(){
        fstream file;
        file.open("data.txt",ios::out);
        for(int i=0;i<total;i++){
           file<<endl<<name[i]<<"    "<<id[i]<<"    "<<blood_group[i]<<"    "<<number_of_donate[i]<<"    "<<last_date_of_donate[i]<<"    "<<phone_number[i]<<"    "<<email[i];
        }
        file.close();
        cout<<"Save data successfully!"<<endl;
        Sleep(1000);
        exit(1);
    }

    void load_data(){
        int index=0;
        fstream file;
        file.open("data.txt",ios::in);
            while(file>>name[index]>>id[index]>>blood_group[index]>>number_of_donate[index]>>last_date_of_donate[index]>>phone_number[index]>>email[index]){
            index++;
            total++;
        }
        file.close();
    }
};

int main()
{
    Blood_Bank B;
    B.choice();
    return 0;
}
