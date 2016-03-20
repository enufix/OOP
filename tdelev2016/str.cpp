#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char *content;
public:
    String(const char *c) {
        cout << "constructor" << endl;
        content = new char[strlen(c) + 1];
        strcpy(content, c);
    }
    String(const String &s) {
        cout << "copy constructor" << endl;
        content = new char[strlen(s.content) + 1];
        strcpy(content, s.content);
    }
    String& operator=(const String &s) {
        if(this == &s) return *this;
        cout << "operator = " << endl;
        delete [] content;
        content = new char[strlen(s.content) + 1];
        strcpy(content, s.content);
//        content = s.content;
        return *this;
    }
    void show() {
        cout << content << endl;
    }
    void setChar(int i, char x) {
        content[i] = x;
    }
    ~String() {
        delete [] content;
    }
};

int main() {
    String x = "The X man";
    String h = x;
    /*String x(h);
    String i("it's me");
    i = h;*/
    //h = "How are you";
   /* h.show(); // Hello
    i.show(); // Hello
    x.show(); // Hello
    h.setChar(0, 'M');
    h.show(); // Mello
    x.show(); // ?
    i.show(); // ? Hello ? Mello
    x = x;
    x.show();   */
    return 0;
}