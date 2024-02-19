// Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
class Product
{
public:
    int id;
    string name;
    float price;
    string category;
    Product(int i, const string& s1, float f, const string& s2) : id(i), name(s1), price(f), category(s2) {}
    void PrintProduct() {
        cout << id << ", " << name << ", " << price << ", " << category << "\n";
    }
    void PrintID() {
        cout << id << "\n";
    }
    int GetID() {
        return id;
    }
    void UpdateID(int newID) {
        id = newID;
    }
    void PrintName() {
        cout << name << "\n";
    }
    string GetName() {
        return name;
    }
    void UpdateName(string newName) {
        name = newName;
    }
    void PrintPrice() {
        cout << price << "\n";
    }
    float GetPrice() {
        return price;
    }
    void UpdatePrice(float newPrice) {
        price = newPrice;
    }
    void PrintCategory() {
        cout << category << "\n";
    }
    string GetCategory() {
        return category;
    }
    void UpdateCategory(string newCategory) {
        category = newCategory;
    }
};

vector<Product> products;
void Insert(int id, string name, float price, string category) {
    products.push_back(Product(id, name, price, category));
}
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void Delete(int j) {
    char answer;
    cout << "Do you wish to remove the product? y/n\n";
    cin >> answer;
    if (answer == tolower('y')) {
        products.erase(products.begin() + j);
    }
    else if (answer == tolower('n')) {
        cout << "Great, continue!\n";
    }
}
void Search() {
    int x;
    char answer;
    char remove;

    int ID;
    string name;
    float price;
    string category;
    int i;
    string n;
    float p;
    string c;

    int counts = 0;
    cout << "How would you like to search the product? 1:ID 2:name 3:price 4:category\n";
    cin >> x;

    switch (x)
    {
    case 1:
        cout << "What product ID are you looking for?\n";
        cin >> i;
        for (int j = 0; j < products.size(); j++) {
            if (products[j].GetID() == i) {
                products[j].PrintProduct();
                Delete(j);
                cout << "Would you want to change the product ID? y/n\n";
                cin >> answer;
                counts++;
                if (answer == tolower('y')) {
                    cout << "What would be the new ID? Old ID: " << products[j].GetID() << "\n";
                    cin >> ID;
                    products[j].UpdateID(ID);
                    products[j].PrintProduct();
                }
                else {
                    cout << "ok letz continue\n";
                }
            }
        }
        if (counts == 0) {
            cout << "sorry no such product ID\n";
        }
        break;
    case 2:
        cout << "What product name are you looking for?\n";
        cin >> n;
        for (int j = 0; j < products.size(); j++) {
            if (products[j].GetName() == n) {
                products[j].PrintProduct();
                Delete(j);
                cout << "Would you want to change the product Name? y/n\n";
                cin >> answer;
                counts++;
                if (answer == tolower('y')) {
                    cout << "What would be the new Name? Old Name: " << products[j].GetName() << "\n";
                    cin >> name;
                    products[j].UpdateName(name);
                    products[j].PrintProduct();
                }
                else {
                    cout << "ok letz continue\n";
                }
            }
        }
        if (counts == 0) {
            cout << "sorry no such product Name\n";
        }
        break;
    case 3:
        cout << "What product price are you looking for?\n";
        cin >> p;
        for (int j = 0; j < products.size(); j++) {
            if (products[j].GetPrice() == p) {
                products[j].PrintProduct();
                Delete(j);
                cout << "Would you want to change the product Price? y/n\n";
                cin >> answer;
                counts++;
                if (answer == tolower('y')) {
                    cout << "What would be the new Price? Old Price: " << products[j].GetPrice() << "\n";
                    cin >> price;
                    products[j].UpdatePrice(price);
                    products[j].PrintProduct();
                }
                else {
                    cout << "ok letz continue\n";
                }
            }
        }
        if (counts == 0) {
            cout << "sorry no such product Price\n";
        }
        break;
    case 4:
        cout << "What product category are you looking for?\n";
        cin >> c;
        for (int j = 0; j < products.size(); j++) {
            if (products[j].GetCategory() == c) {
                products[j].PrintProduct();
                Delete(j);
                cout << "Would you want to change the product Category? y/n\n";
                cin >> answer;
                counts++;
                if (answer == tolower('y')) {
                    cout << "What would be the new Category? Old Category: " << products[j].GetCategory() << "\n";
                    cin >> category;
                    products[j].UpdateCategory(category);
                    products[j].PrintProduct();
                }
                else {
                    cout << "ok letz continue\n";
                }
            }
        }
        if(counts == 0){
            cout << "sorry no such product Category\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    default:
        cout << "error input\n";
        break;
    }
}
void BubbleSort() {
    auto start = chrono::steady_clock::now();
    int n = products.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (products[j].GetPrice() > products[j + 1].GetPrice()) {
                swap(products[j], products[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    auto end = chrono::steady_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting took " << duration.count() << " seconds\n";
}
void InsertionSort() {
    auto start = chrono::steady_clock::now();
    int n = products.size();
    for (int i = 1; i < n; ++i) {
        Product current = products[i];
        int j = i - 1;
        while (j >= 0 && products[j].GetPrice() > current.GetPrice()) {
            products[j + 1] = products[j];
            j--;
        }
        products[j + 1] = current;
    }
    auto end = chrono::steady_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting took " << duration.count() << " seconds\n";
}

int main()
{
    string myText;
    string file_contents;

    int id;
    string name;
    float price;
    string category;

    bool leave = false;
    int a;
    char answer;

    ifstream MyReadFile("product_data.txt");
    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, myText)) {
            stringstream ss(myText);
            string word;

            getline(ss, word, ',');
            id = stoi(word);

            getline(ss, word, ',');
            name = trim(word);

            getline(ss, word, ',');
            price = stof(word);

            getline(ss, word, ',');
            category = trim(word);

            ss >> id >> name >> price >> category;
            products.push_back(Product(id, name, price, category));
        }
    }
    InsertionSort();
    cout << products.size() << endl;
    for (int i = 0; i < products.size(); i++) {
        products[i].PrintProduct();
    }
    while (!leave) {
        cout << "do you want to 1:search a product 2: insert a product?\n";
        cin >> a;
        switch (a)
        {
        case 1:
            Search();
            break;
        case 2:
            cout << "What would be the product ID?\n";
            cin >> id;
            cout << "What would be the product Name?\n";
            cin >> name;
            cout << "What would be the product Price?\n";
            cin >> price;
            cout << "What would be the product Category?\n";
            cin >> category;
            Insert(id, name, price, category);
            products[products.size() - 1].PrintProduct();
            BubbleSort();
            break;
        default:
            cout << "error input\n";
            break;
        }
        cout << "do you wish to leave the function? y/n\n";
        cin >> answer;
        if (answer == tolower('y')) {
            leave = true;
        }
        else if (answer == tolower('n')) {
            leave = false;
        }
        else {
            cout << "error unput\n";
            leave = false;
        }
    }
    cout << "out";
    MyReadFile.close();
}
