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
            cout << "\nEnter the name of the student as (name_surename): ";
            cin >> data[i].name;
            
            validName = true;
            for(int j = 0; j < strlen(data[i].name); j++) {
                if(data[i].name[j] >= '!' && data[i].name[j] <= '@') {
                    cout << "Invalid name. Please enter a valid name.\n";
                    validName = false;
                    break;
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
            cout << "\nEnter the email of the student: ";
            cin >> data[i].email;

            char sum[100] = "";
            int k = 0;
            int len = strlen(data[i].email);
            if(len < 8) {
                cout << "Invalid email. Please enter a valid email.\n";
                continue; 
            }

            for(int j = 8; j > 0; j--) {
                sum[k++] = data[i].email[len - j];
            }
            sum[k] = '\0';

            if(strcmp(sum, "@vit.edu") != 0) {
                cout << "Invalid email domain. Please enter a valid email with @vit.edu domain.\n";
            } else {
                validEmail = true;
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
