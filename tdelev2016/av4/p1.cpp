#include <cstring>
#include <iostream>
using namespace std;

class User {
private:
    char name[100];  
public:
    User(const char* name){
        strcpy(this->name, name);
    }

    bool isEqual(User &u) {
        if(strcmp(this->name, u.name) == 0){
            return true;
        }
        return false;
    }

    char* getName() {
        return name;
    } 

};
int main() {
    User u("John");
    User x("John");
    cout << u.getName() << endl;
    if(u.isEqual(x)) {
        cout << "Equal" << endl;
    } else {
        cout << "Not equal" << endl;
    }
    return 0;
}
 