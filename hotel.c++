#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

class Hotel
{
private:
    int room_number;
    char name[30], address[50], mobile_number[15];

public:
    void add_customer()
    {
        cout << "\n enter the room number=" << endl;
        cin >> room_number;
        cout << "\n enter customers name=" << endl;
        cin.ignore();
        cin.getline(name, 30);
        cout << "\n enter the customers address no=" << endl;
        cin.ignore();
        cin.getline(address, 50);
        cout << "\n enter the customers mobile number=" << endl;
        cin.ignore();
        cin.getline(mobile_number, 15);
        cout << "\n mobile_number" << endl;
    }
    void show_customer()
    {
        cout << "\n room_number= " << room_number;
        cout << "\n customers name= " << name;
        cout << "\n customers address= " << address;
        cout << "\n customers mobile number" << mobile_number;
    }
    void modify_customer_record()
    {
        cout << "\n room number= " << room_number;
        cout << "\n modify customers name=";
        cin.ignore();
        cin.getline(name, 30);
        cout << "\n modify customers address=";
        cin.ignore();
        cin.getline(address, 50);
        cout << "\n modify customers mobile number=";
        cin.ignore();
        cin.getline(mobile_number, 15);
    }
    int getRoomNumber()
    {
        return room_number;
    }
    char *getName()
    {
        return name;
    }
    char *getAddress()
    {
        return address;
    }
    char *getMobileNumber()
    {
        return mobile_number;
    }
    void report(){
        cout << room_number << setw(10) << name << setw(20) << address << setw(20) << mobile_number << setw << endl;
    }
};
fstream fp;
Hotel h;

void save_customer(){
    system("cls");
    fp.open("main.dat", ios::out | ios::app);
    h.add_customer();
    fp.write((char *)&h, sizeof(Hotel));
    fp.close();
}
void display_customer(int roomNumber){
    system("cls");
    cout << "\n customer details\n";
    int check = 0;
    fp.open("main.dat", ios::in);
    while(fp.read((char *)&h,sizeof(Hotel))){
        if(h.getRoomNumber()==roomNumber){
            h.show_customer();
            check = 1;
        }
    }
    fp.close();
    if(check==0)
        cout << "\n customer does not exist.";
}
void modifyCustomer(){
    system("cls");
    int roomNumber, found = 0;
    cout << "\n\n\t modify customers record";
    cout << "\n\n\t enter the room number";
    cin >> roomNumber;
    fp.open("main.dat", ios::in | ios::out);
    while(fp.read((char *)&h,sizeof(Hotel))&&"found==0"){
        if(h.getRoomNumber()==roomNumber){
            h.show_customer();
            cout << "\n enter customers new information" << endl;
            h.modify_customer_record();
            long long unsigned int pos = -1 * sizeof(h);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&h, sizeof(Hotel));
            cout << "\n\n\t record updated successful...";
            found = 1;
        }
    }
    fp.close();
    if(found==0)
        cout << "\n\n record not found";
}
void delete_customer(){
    system("cls");
    char roomNumber;
    int flag = 0;
    cout << "\n\n\n\t delete customer";
    cout << "\n\n enter the room of the customer you want to delete=";
    cin >> roomNumber;
    fp.open("main.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0, ios::beg);
    
}