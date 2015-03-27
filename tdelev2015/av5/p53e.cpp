#include <iostream>
#include <cstring>
using namespace std;

class WebPage {
private:
  char url[100];
  char* content;
  void copy(const WebPage& wp) {
    strcpy(url, wp.url);
    content = new char[strlen(wp.content) + 1];
    strcpy(content, wp.content);
  }
public:
  WebPage(char* url = "", char* content = "") {
    strcpy(this->url, url);
    this->content = new char[strlen(content) + 1];
    strcpy(this->content, content);
  }

  WebPage(const WebPage &wp) {
    copy(wp);
  }

  ~WebPage() {
    delete [] content;
  }

  WebPage& operator=(const WebPage &wp) {
    if (this != &wp) {
      delete [] content;
      copy(wp);
    }
    return *this;
  }

  void print() {
    cout << url << endl;
    cout << content << endl;
  }
};

class WebServer {
private:
  WebPage *pages;
  int n;
  char name[100];
  void copy(const WebServer &s) {
    strcpy(name, s.name);
    n = s.n;
    pages = new WebPage[n];
    for (int i = 0; i < n; ++i) {
      pages[i] = s.pages[i];
    }
  }
public:
  WebServer(char* name) {
    strcpy(this->name, name);
    n = 0;
    pages = NULL;
  }

  WebServer(const WebServer &s) {
    copy(s);
  }

  ~WebServer() {
    //if (pages != NULL)
    delete [] pages;
  }

  WebServer& operator=(const WebServer &s) {
    if (this != &s) {
      delete [] pages;
      copy(s);
    }
    reserver.add(wp1);
    server.add(wp2);
    server.add(wp3);
    server.print(); turn *this;
  }

  void add(WebPage &wp) {
    WebPage* temp = pages;
    pages = new WebPage[n + 1];
    for (int i = 0; i < n; ++i) {
      pages[i] = temp[i];
    }
    pages[n] = wp;
    delete [] temp;
    ++n;
  }

  void print() {
    for (int i = 0; i < n; ++i) {
      pages[i].print();
    }
  }

};

int main() {
  WebPage wp1("www.google.com", "The search engine");
  WebPage wp2("www.bing.com", "Because it's not google");
  WebPage wp3("www.altavista.com", "The dinosaurus");
  WebServer server("nginx");
  server.add(wp1);
  server.add(wp2);
  server.add(wp3);
  server.print();
  return 0;
}