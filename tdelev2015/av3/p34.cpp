#include <iostream>
#include <cstring>
using namespace std;

class Email {
private:
	char from[100];
	char to[100];
	char subject[500];
	char body[5000];
public:
	Email(char *from = "", char *to = "", char *subject = "",
	 char *body = "") {
		strcpy(this->from, from);
		strcpy(this->to, to);
		strcpy(this->subject, subject);
		strcpy(this->body, body);
	}

	char* getFrom() {
		return from;
	}

	char* getTo() {
		return to;
	}

	char* getSubject() {
		return subject;
	}

	char* getBody() {
		return body;
	}

	void send() {
		cout << "Your email is sent." << endl;
	}

};

bool validEmail(char *email) {
	int count = 0;
	while(*email) {
		if(*email == '@') {
			++count;
		}
		++email;
	}
	return count == 1;
}

int main() {
	char from[100];
	char to[100];
	char subject[500];
	char body[5000];
	cout << "From: ";
	cin >> from;
	cout << "To: ";
	cin >> to;
	cout << "Subject: ";
	cin >> subject;
	cout << "Body: ";
	cin >> body;
	if(validEmail(from) && validEmail(to)) {
		Email e(from, to, subject, body);
		e.send();
		cout << e.getBody();
	} else {
		cout << "Email format not valid" << endl;
	}
	return 0;
}