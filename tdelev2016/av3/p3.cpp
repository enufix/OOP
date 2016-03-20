#include <iostream>
#include <cstring>
using namespace std;

class Email {
private:
    char to[50];
    char from[50];
    char subject[255];
    char body[1000];
    bool isValid(const char *email) {
        while(*email) {
            if(*email == '@') return true;
            ++email;
        }
        return false;
    }
public:
    Email(const char to[], const char from[], 
        const char subject[], const char body[]) {
        strcpy(this->to, to);
        strcpy(this->from, from);
        strcpy(this->subject, subject);
        strcpy(this->body, body);
    }
    bool send() {
        if(isValid(from) && isValid(to)) {
            cout << "From: " << from << endl;
            cout << "To: " << to << endl;
            cout << "Subject: " << subject << endl;
            cout << "Body: " << body << endl;
            return true;
        }
        return false;
    }
};

int main() {
    Email e("xyz@students.finki.ukim.mk", "tdelevfinki.ukim.mk",
        "Hello to all", "This is the body");
    if(e.send()) {
        cout << "Email sent success!" << endl;
    } else {
        cout << "Invalid from or to email address" << endl;
    }
    return 0;
}