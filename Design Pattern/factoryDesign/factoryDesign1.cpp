#include<iostream>
#include<memory>

using namespace std;

class Document {
public:
    virtual void open() = 0;
    virtual ~Document() {}
};

class PDF : public Document {
public:
    void open() override{
        cout << "Opening PDF document." << endl;
    }
};

class Word : public Document {
public:
    void open() override{
        cout << "Opening Word document." << endl;
    }
};


class Excel : public Document {
public:
    void open() override{
        cout << "Opening Excel document." << endl;
    }

};


class DocumentFactory {
public:
    static unique_ptr<Document> createDocument(const string &type) {
        if(type == "pdf") return make_unique<PDF>();
        else if(type == "word") return make_unique<Word>();
        else if(type == "excel") return make_unique<Excel>();
        else return nullptr;
    }
};


int main() {
    string userChoice;
    cout << "Enter document type (pdf/word/excel): ";
    cin >> userChoice;

    auto doc = DocumentFactory::createDocument(userChoice);
    
    if(doc)
        doc->open();
    else
        cout << "Invalid document type!" << endl;

    return 0;
}


