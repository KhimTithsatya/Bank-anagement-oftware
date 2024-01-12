#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct PersonInfo {
    char gender;
    string name;
    int id;
    string role;
    string phonenumber;
    string email;
    
};

struct Staff {
    PersonInfo person;
    char gender;
    string role;
    int id;
    string phonenumber;
    string email;
};

bool validation_id(int id){
    if(cin.fail() || id <= 0){
        return false;
    }
    else{
        return true;
    }
}

int get_id(){
    int id;
    while (true){
        cout << "Enter ID:";
        cin >>id;
        if(!validation_id(id)){
            cin.clear();
            cin.ignore(1000,'\n');
        }
        else{
            return id;
        }
    }
}

bool validation_name(string name){
    if (name.length() <= 3) {
        return false;
}
    
    for (int i = 0; i < name.length(); i++) {
        if (!(name[i] >= 65 && name[i] <= 122)) {
            return false;
        }
    }
    return true;
}


void displayMenu() {
    cout << "\t\t\t\t\t\t\t\t================="<<endl;
    cout << "\t\t\t\t\t\t\t\tBANK MANAGEMENT" << endl;
    cout << "\t\t\t\t\t\t\t\t================="<<endl;
    cout << "================="<<endl;
    cout << "\tUSER MENU"<<endl;
    cout << "================="<<endl;
    cout << "1. ADD NEW USER" << endl;
    cout << "================="<<endl;
    cout << "2. OUTPUT USER" << endl;
    cout << "================="<<endl;
    cout << "3. UPDATE USER"<<endl;
    cout << "================="<<endl;
    cout << "4. DELETE USER"<<endl;
    cout << "================="<<endl;
    cout << "5. SEARCH USER"<<endl;
    cout << "================="<<endl;
    cout << "6. SORT USER"<<endl;
    cout << "================="<<endl;
    cout << "7. SAVE USER"<<endl;
    cout << "================="<<endl;
    cout << "0. EXIT" << endl;
    cout << "================="<<endl;

}

int getChoice() {
    int choice;
    cout << "Enter choice:"<<endl;
    cin >> choice;
    return choice;
}

Staff getStaff() {
    Staff s;
    cout << "Enter ID(3 digits):";
    cin >> s.person.id;
    cout << "Enter Name:";
    cin.ignore();
    getline(cin, s.person.name);
    cout << "Enter gender(M/F):";
    cin >> s.gender;
    cout << "Enter Role:";
    cin>>s.role;
    cout << "Enter phonenumber:";
    cin>>s.phonenumber;
    cout << "Enter E-mail:";
    cin >>s.email;
    return s;
}

void inputStaff(Staff s[], int num,int& count) {
    cout << "Input User" << endl;
    for (int i = 0; i < num; i++) {
        s[count++] = getStaff();
    }
}

void outputSaffs(Staff s[], int count) {
    cout << "------------------------------------Output User----------------------------------------------" << endl;
    
        cout << "|" << setw(5) << "ID"  << setw(5) << "|" << setw(5) << "Name" << setw(5) << "|" << setw(5) << "Gender" << setw(5) << "|" << setw(5) << "Role" << setw(5)<<"|"<<setw(5) <<"Phonenumber"<<setw(5)<<"|" << "E-mail"<<setw(20)<<"|"<<endl;
        for (int i = 0; i < count; i++) {
            cout << s[i].person.id << setw(10) << s[i].person.name << setw(10) << s[i].gender << setw(10) << s[i].role<< setw(10)<<s[i].phonenumber <<setw(15)<<s[i].email<<endl;
    }
    }

void displayStaff(Staff s){
    cout<<"1. ID:"<<s.person.id<<endl;
    cout<<"2. Name:"<<s.person.name<<endl;
    cout<<"3. Gender:"<<s.gender<<endl;
    cout<<"5. Role:"<<s.role<<endl;
    cout<<"6. Phonemumber:"<<s.phonenumber<<endl;
    cout<<"7. Enter E-mail:"<<s.email<<endl;
//    cout<<"ID\t"<<s.person.id<<"|\t"<<"Name\t"<<s.person.name<<"|"<<"Gender\t"<<s.gender<<"|"<<"Role\t"<<s.role<<"Phonemunber/t"<<s.phonenumber<<"|";
}
int findStaffById(Staff s[], int count, int id){
    for(int i=0;i<count;i++){
        if(s[i].person.id==id){
            return i;
        }
    }
    return -1;
}
void updateStaffsById(Staff s[], int count,int id){
    int option;
    int index=findStaffById(s,count,id);
    if(index!=-1){
            displayStaff(s[index]);
            option=getChoice();
            switch(option){
                case 1:
                    cout<<"Enter new id:";
                    cin>>s[index].person.id;
                    break;
                case 2:
                    cout<<"Enter new name:";
                    cin>>s[index].person.name;
                    break;
                case 3:
                    cout<<"Enter new gender:";
                    cin>>s[index].gender;
                    break;
                case 4:
                    cout<<"Enter new role";
                    cin>>s[index].role;
                case 5:
                    cout<<"Enter new phonenumber";
                    cin>>s[index].phonenumber;
            }
            cout<<"Updated successfully"<<endl;
        }else{
            cout<<"Not found"<<endl;
        }
    
}
void updateStaffsByName(Staff s[], int count,string name){
    int option;
    for(int i=0;i<count;i++){
        if(s[i].person.name==name){
            displayStaff(s[i]);
            option=getChoice();
            switch(option){
                case 1:
                    cout<<"Enter new id:";
                    cin>>s[i].person.id;

                    break;
                case 2:
                    cout<<"Enter new name:";
                    cin>>s[i].person.name;
                    break;
                case 3:
                    cout<<"Enter new gender:";
                    cin>>s[i].gender;
                    break;
                case 4:
                    cout<<"Enter new role";
                    cin>>s[i].role;
                case 5:
                    cout<<"Enter new phonenumber";
                    cin>>s[i].phonenumber;
                    break;
            }
            cout<<"Updated successfully"<<endl;
            break;
        }
    }
}
void deleteStaffsById(Staff s[], int &count, int id){
    char ch;
    int index=findStaffById(s,count,id);
    if(index!=-1){
            displayStaff(s[index]);
            cout<<"Are you sure to delete?(y/n)";
            cin>>ch;
            if(ch=='y'){
                for(int j=index;j<count-1;j++){
                    s[j]=s[j+1];
                }
                count--;
                cout<<"Deleted successfully"<<endl;
            }
    }else{
        cout<<"Not found"<<endl;
    }
}

void searchStaffsById(Staff s[], int count, int id){
    int index=findStaffById(s,count,id);
    if(index!=-1){
        displayStaff(s[index]);
    }else{
        cout<<"Not found"<<endl;
    }
}

void sortStaffById(Staff s[], int count, int option){
    switch(option){
        case 1:
            for(int i=0;i<count;i++){
                for(int j=0;j<count-i-1;j++){
                    if(s[j].person.id>s[j+1].person.id){
                        Staff st;
                        st=s[j];
                        s[j]=s[j+1];
                        s[j+1]=st;
                    }

                }
            }
        break;
        case 2:
            for(int i=0;i<count;i++){
                for(int j=0;j<count-i-1;j++){
                    if(s[j].person.id<s[j+1].person.id){
                        Staff st;
                        st=s[j];
                        s[j]=s[j+1];
                        s[j+1]=st;
                    }

                }
            }

        break;
    }
    cout<<"Sorted successfully"<<endl;
}
 

void performMenuChoice(int choice, Staff s[], int &count) {
    enum OPTION {EXIT, INPUT, OUTPUT, UPDATE, DELETE, SEARCH, SORT, SAVE};
    switch (choice) {
    case INPUT: {
        int num;
        cout << "How many User?:";
        cin >> num;
        inputStaff(s, num, count);
        break;
    }
    case OUTPUT:
        outputSaffs(s, count);
        break;
    case UPDATE:{
        int option;
        cout<<"==============="<<endl;
        cout<<"1.Update by id"<<endl;
        cout<<"==============="<<endl;
        cout<<"2.Update by Name"<<endl;
        cout<<"==============="<<endl;
        option=getChoice();
        switch(option){
            case 1:{
                int id;
                cout<<"Enter id:";
                cin>>id;
                updateStaffsById(s,count,id);
                break;
            }
            case 2:{
                string name;
                cout<<"Enter name:";
                cin>>name;
                updateStaffsByName(s,count,name);
                break;
            }
        }
        break;
    }
    case DELETE:{
        int option;
        cout<<"==============="<<endl;
        cout<<"1.Delete by id"<<endl;
        cout<<"==============="<<endl;
        cout<<"2.Delete by Name"<<endl;
        cout<<"==============="<<endl;
        option=getChoice();
        switch(option){
            case 1:{
                int id;
                cout<<"Enter id:";
                cin>>id;
                deleteStaffsById(s,count,id);
                break;
            }
            case 2:{
                string name;
                cout<<"Enter name:";
                cin>>name;
                //deleteStudentsByName(s,count,name);
                break;
            }
        }
    }
    break;
       
    case SEARCH:{
        int option;
        cout<<"==============="<<endl;
        cout<<"1.Search by id"<<endl;
        cout<<"==============="<<endl;
        cout<<"2.Search by Name"<<endl;
        cout<<"==============="<<endl;
        option=getChoice();
        switch(option){
            case 1:{
                int id;
                cout<<"Enter id:";
                cin>>id;
                searchStaffsById(s,count,id);
                break;
            }
            case 2:{
                string name;
                cout<<"Enter name:";
                cin>>name;
                
            
                break;
            }
        }
        break;
    }
    case SORT:{
    int option;
        cout<<"==============="<<endl;
        cout<<"1.Sort by id"<<endl;
        cout<<"==============="<<endl;
        cout<<"2.Sort by Name"<<endl;
        cout<<"==============="<<endl;
        option=getChoice();
        switch(option){
            case 1:{
                cout<<"1.Ascending"<<endl;
                cout<<"2.Descending"<<endl;
                option=getChoice();
                sortStaffById(s,count,option);
                break;
            }
            case 2:{
            
                break;
            }
        }
        break;
    }
//        case 7:
//            cout << "|" << setw(5) << "ID"  << setw(5) << "|" << setw(5) << "Name" << setw(5) << "|" << setw(5) << "Gender" << setw(5) << "|" << setw(10) << "Role" << setw(5) <<"Phonenumber"<<setw(5)<<"|" << endl;
//            for (int i = 0; i < count; i++) {
//                cout << setw(5) << s[i].id << setw(10) << s[i].person.name << setw(10) << s[i].person.gender << setw(10) << s[i].role<< setw(10)<<s[i].phonenumber << endl;
//            }
//        break;
        case SAVE:{
            //step1:open file
            ofstream outFile;
            outFile.open("staff.dat", ios::out | ios::binary);
            //step2:write data to file
            for (int i = 0; i < count; i++) {
                Staff sta = s[i];
                outFile.write(reinterpret_cast<char*>(&sta), sizeof(sta));
            
            }
            //step3:close file
            outFile.close();
            cout << "saved successfully" << endl;
            break;
        }
        case EXIT:
        exit(0);
    default:
        cout << "Invalid" << endl;
        break;
    }
}
struct account{
    string username;
    string password;
};
void login_menu(){
    string username;
    string password;
    account users[20];
    account user;
    int c = 0;
    bool flag = false;
    
    ifstream inFile;
    inFile.open("accounts.dat", ios::in);
    while (inFile.read(reinterpret_cast<char*>(&user), sizeof(user))) {
        users[c] = user;
        c++;
    }
    
    inFile.close();
    
    
    do {
        
        cout << "LOGIN MENU" << endl;
        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;
        for (int i = 0; i < c; i++) {
            if (users[i].username == username && users[i].password ==  password) {
                flag = true;
                break;
            }
        }
        
        
    } while (!flag);
    
  }
void outputmain_menu(){
    int choice;
    cout<<"==========="<<endl;
    cout<<" Main Menu"<<endl;
    cout<<"==========="<<endl;
    cout<<"1.Register"<<endl;
    cout<<"==========="<<endl;
    cout<<"2.Login"<<endl;
    cout<<"==========="<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"==========="<<endl;
    cout<<"Enter your chioce:"<<endl;
    cin>>choice;
    
}



void register_menu() {

    account acc;
    cout<<"REGISTER MENU"<<endl;
    cout << "Enter username:";
    cin >> acc.username;
    cout << "Enter password:";
    cin >> acc.password;
    ofstream outFile;
    outFile.open("accounts.dat", ios::out | ios::app | ios::binary);
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));
    outFile.close();

}


int main()
{
    const int SIZE = 100;
    Staff s[SIZE];
    int count = 0;
    int choice;
    
    outputmain_menu();
    
    register_menu();
    
    //login();
    account users[2];
    account user;
    int c = 0;
    //step1:open file
    ifstream iFile;
    iFile.open("accounts.dat", ios::in | ios::binary);
    //step2:write data to file
    while (iFile.read(reinterpret_cast<char*>(&user), sizeof(user))) {
        users[c++] = user;
    }
    //step3:close file
    iFile.close();
    string username;
    string password;
    bool flag = false;
    

    
    
    do {

        cout << "LOGIN MENU" << endl;
        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;
        for (int i = 0; i < c; i++) {
            if (users[i].username == username && users[i].password == password) {
                flag = true;
                do {
                    displayMenu();
                    choice = getChoice();
                    performMenuChoice(choice, s, count);
                } while (choice != 0);

                break;
            }
        }


    } while (!flag);

    //step1:open file
    ifstream inFile;
    inFile.open("staff.dat", ios::in | ios::binary);
    //step2:write data to file
    Staff sta;
    while(inFile.read(reinterpret_cast<char*>(&sta), sizeof(sta))){
        s[count++]=sta;
    }
    //step3:close file
    inFile.close();

    return 0;
}

