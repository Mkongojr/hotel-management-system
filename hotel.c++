#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

class Hotel{
    private:
    int room_number;
    char name[30], address[50], mobile_number[15];

    public:
    void add_customer(){
        cout << "\n enter the room number=" << endl;
        cin >> room_number;
        cout << "\n enter customers name=" << endl;
        cin.ignore();
        cin.getline(name, 30);
        cout << "\n enter the customers address no=" << endl;
        cin.ignore();
        cin.getline(address, 50);
        cout<<"\n enter the customers mobile number="<<endl;
        cin.ignore();
        cin.getline(mobile_number, 15);
        cout << "\n mobile_number"<<endl;
    }
    void show_customer(){
        cout << "\n room_number= " << room_number;
        cout << "\n customers name= " << name;
        cout << "\n customers address= " << address;
        cout << "\n customers mobile number" << mobile_number;
    }
    void modify_customer_record(){
        cout << "\n room number= " << room_number;
        cout << "\n modify customers name=";
        cin.ignore();
        cin.getline(name, 30);
        cout<<"\n modify customers address=";
        cin.ignore();
        cin.getline(address, 50);
        cout << "\n modify customers mobile number=";
        cin.ignore();
        cin.getline(mobile_number, 15);
    }
    int getRoomNumber(){
        return room_number;
    }
    char *getName(){
        return name;
    }
    char *getAddress(){
        return address;
    }
};