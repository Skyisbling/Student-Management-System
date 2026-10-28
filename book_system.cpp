#include <iostream>
using namespace std;

class Media {
protected:
    char title[50];
    char publication[50];

public:
    virtual void read() {
        cout << "Enter title: ";
        cin.getline(title, 50);

        cout << "Enter publication: ";
        cin.getline(publication, 50);
    }

    virtual void show() {
        cout << "Title: " << title << endl;
        cout << "Publication: " << publication << endl;
    }
};

class Book : public Media {
private:
    int pages;

public:
    void read() {
        Media::read();

        cout << "Enter number of pages: ";
        cin >> pages;
        cin.ignore();
    }

    void show() {
        Media::show();
        cout << "Number of pages: " << pages << endl;
    }
};

class Tape : public Media {
private:
    float playingTime;

public:
    void read() {
        Media::read();

        cout << "Enter playing time in minutes: ";
        cin >> playingTime;
        cin.ignore();
    }

    void show() {
        Media::show();
        cout << "Playing time: " << playingTime
             << " minutes" << endl;
    }
};

int main() {
    Book b;
    Tape t;

    Media *ptr;

    cout << "Enter Book Details" << endl;
    ptr = &b;
    ptr->read();

    cout << "\nEnter Tape Details" << endl;
    ptr = &t;
    ptr->read();

    cout << "\nBook Details" << endl;
    ptr = &b;
    ptr->show();

    cout << "\nTape Details" << endl;
    ptr = &t;
    ptr->show();

    return 0;
}