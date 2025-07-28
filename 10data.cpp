#include<iostream>
#include<cstring>
using namespace std;

struct Student {
    char email[100];
    char number[20];
    char rollno[8];
    char name[100];
    float marks;
};

int main() {
    Student data[10];

    for(int i = 0; i < 10; i++) {
        cout << "Student " << i + 1 << endl;
        
bool validName = false;
while (!validName) {
    cout << "\nEnter the name of the student as (name_surname): ";
    cin >> data[i].name;

    validName = true;
    int len = strlen(data[i].name);

    // Check allowed characters
    for (int j = 0; j < len; j++) {
        char c = data[i].name[j];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')) {
            cout << "Invalid character in name. Only letters and underscore allowed.\n";
            validName = false;
            break;
        }
    }

    if (validName) {
        // Check for duplicates with previously entered students
        for (int k = 0; k < i; k++) {   // only check previous students, not including current i
            if (strcmp(data[i].name, data[k].name) == 0) {
                cout << "Repeated name. Please enter a unique name.\n";
                validName = false;
                break;
            }
        }
    }
}


 bool validRollno = false;
        while (!validRollno) {
            cout << "\nEnter the rollno: ";
            cin >> data[i].rollno;
            validRollno = true;
            for(int j = 0; j < strlen(data[i].rollno); j++) {
                if(!(data[i].rollno[j] >= '0' && data[i].rollno[j] <= '9')) {
                    cout << "Invalid roll number. Please enter a valid roll number.\n";
                    validRollno = false;
                    break;
                }
            }
                        for(int k = 0;k<i+1;k++){
                for(int p = 1;p<=i+1;p++){
                        if((!strcmp(data[k].rollno,data[p].rollno))&& k!= p){
                            cout << "Repeated rollno. Please enter a unique rollno.\n";
                            validRollno = false;
                            break;
                        }
                    }
                }
        }

        bool validMarks = false;
        while (!validMarks) {
            cout << "\nEnter the marks of the student: ";
            cin >> data[i].marks;
            if(data[i].marks > 100 || data[i].marks < 0) {
                cout << "Invalid marks. Please enter marks between 0 and 100.\n";
            } else {
                validMarks = true;
            }
        }

bool validEmail = false;
while (!validEmail) {
    cout << "\nEnter the college email (name.surname@vit.edu): ";
    cin >> data[i].email;

    int len = strlen(data[i].email);
    if (len < 13) { 
        cout << "Invalid email. Too short.\n";
        continue;
    }

    bool endsWithVit = true;
    const char* suffix = "@vit.edu";
    for (int j = 0; j < 8; j++) {
        if (data[i].email[len - 8 + j] != suffix[j]) {
            endsWithVit = false;
            break;
        }
    }

    if (!endsWithVit) {
        cout << "Invalid email. Must end with @vit.edu\n";
        continue;
    }

    int atCount = 0;
    int atIndex = -1;
    for (int j = 0; j < len; j++) {
        if (data[i].email[j] == '@') {
            atCount++;
            atIndex = j;
        }
    }

    if (atCount != 1 || atIndex < 3) {
        cout << "Invalid email. Must contain one '@' and a valid name before it.\n";
        continue;
    }

    bool hasDot = false;
    for (int j = 0; j < atIndex; j++) {
        if (data[i].email[j] == '.') {
            hasDot = true;
            break;
        }
    }

    if (!hasDot) {
        cout << "Invalid email. Must be in format name.surname@vit.edu\n";
        continue;
    }

    for (int j = 0; j < atIndex; j++) {
        if (data[i].email[j] == '.') {
            data[i].name[j] = '_';
        } else {
            data[i].name[j] = data[i].email[j];
        }
    }
    data[i].name[atIndex] = '\0';
    validEmail = true;
        for(int k = 0;k<i+1;k++){
            for(int p = 1;p<=i+1;p++){
                    if((!strcmp(data[k].email,data[p].email))&& k!= p){
                        cout << "Repeated email. Please enter a unique email.\n";
                        validEmail = false;
                        break;
                    }
                }
            }
}



        bool validNumber = false;
        while (!validNumber) {
            cout << "\nEnter the mob. number of the student: ";
            cin >> data[i].number;
            if(strlen(data[i].number) != 10) {
                cout << "Invalid mobile number length. Please enter a 10-digit mobile number.\n";
            } else {
                validNumber = true;
                for(int j = 0; j < 10; j++) {
                    if(!(data[i].number[j] >= '0' && data[i].number[j] <= '9')) {
                        cout << "Invalid mobile number. Please enter a valid mobile number.\n";
                        validNumber = false;
                        break;
                    }
                }
                for(int k = 0;k<i+1;k++){
                    for(int p = 1;p<=i+1;p++){
                        if((!strcmp(data[k].number,data[p].number))&& k!= p){
                            cout << "Repeated number. Please enter a unique number.\n";
                            validNumber = false;
                            break;
                        }
                        
                    }
                }
            }
        }
        
        cout << endl;
    }

    for(int i = 0; i < 10; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "\tStudent Name: " << data[i].name << endl;
        cout << "\tStudent Rollno: " << data[i].rollno << endl;
        cout << "\tStudent Marks: " << data[i].marks << endl;
        cout << "\tStudent Email: " << data[i].email << endl;
        cout << "\tStudent Phone: " << data[i].number << endl;
    }
    return 0;
}
