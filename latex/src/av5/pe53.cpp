#include <iostream>
#include <cstring>
using namespace std;

class WebPage {
private:
	char url[100];
	char *content;
public:
	WebPage(const char *url = "", const char *content = "") {
		strcpy(this->url, url);
		this->content = new char[strlen(content) + 1];
		strcpy(this->content, content);
	}
	WebPage(const WebPage &wp) {
		strcpy(url, wp.url);
		content = new char[strlen(wp.content) + 1];
		strcpy(content, wp.content);
	}

	WebPage& operator=(const WebPage &wp) {
		if(this == &wp) return *this;
		strcpy(url, wp.url);
		delete [] content;
		content = new char[strlen(wp.content) + 1];
		strcpy(content, wp.content);	
		return *this;
	}

	~WebPage() {
		delete [] content;
	}

	bool operator==(const WebPage &wp) {
		return strcmp(url, wp.url) == 0;
	}

	friend ostream& operator<<(ostream &out, const WebPage &wp) {
		out << wp.url << endl;
		out << wp.content << endl;
		return out;
	}
};

class WebServer {
private:
	char name[100];
	WebPage *pages;
	int size;
public:
	WebServer(const char *name="") {
		strcpy(this->name, name);
		size = 0;
	}
	WebServer(const WebServer &ws) {
		strcpy(name, ws.name);
		size = ws.size;
		pages = new WebPage[size];
		wp_copy(pages, ws.pages, size);
	}
	void wp_copy(WebPage *p1, WebPage *p2, int n) {
		for(int i = 0; i < n; ++i) {
			p1[i] = p2[i];
		}
	}
	WebServer& operator=(const WebServer &ws) {
		if(this == &ws) return *this;
		strcpy(name, ws.name);
		size = ws.size;
		delete [] pages;
		pages = new WebPage[size];
		wp_copy(pages, ws.pages, size);	
		return *this;
	}
	~WebServer() {
		delete [] pages;
	}

	WebServer& operator+=(const WebPage &wp) {
		WebPage *temp = new WebPage[size + 1];
		wp_copy(temp, pages, size);
		delete [] pages;
		pages = temp;
		pages[size] = wp;
		size++;
		return *this;
	}

	WebServer& operator-=(const WebPage &wp) {
		WebPage *temp = new WebPage[size - 1];
		int k = 0;
		for(int i = 0; i < size; ++i) {
			if(!(pages[i] == wp)) {
				temp[k++] = pages[i];
			}
		}
		delete [] pages;
		pages = temp;
		size--;
		return *this;
	}

	friend ostream& operator<<(ostream &out, const WebServer &ws) {
		out << ws.name << endl;
		for(int i = 0; i < ws.size; ++i) {
			out << ws.pages[i];
		}
		return out;
	}
};

int main() {
	WebServer ws("FINKI Server");
	WebPage wp1("www.google.com", "The world");
	WebPage wp2("www.facebook.com", "The people");
	WebPage wp3("www.twitter.com", "The birds");
	ws += wp1;
	ws += wp2;
	ws += wp3;
	cout << ws;
	ws -= wp2;
	cout << "After deleting facebook.com" << endl;
	cout << ws;
	return 0;
}