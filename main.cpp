#include <iostream>
#include <vector>
using namespace std;

enum SIZE {Small = 25, Medium = 30, Large = 35};

class Pizza {
protected:
    string name;
    string descripsion;
    unsigned int price;
    int size;
    int Cheese;
    int Salt;
public:

     virtual string getName() = 0;

     virtual string getDescription() = 0;

     virtual unsigned int getPrice() = 0;

     virtual unsigned int getSize() = 0;

     virtual unsigned int getCheese() = 0;

     virtual unsigned int getSalt() = 0;

     virtual void AddCheese(int cheese_count) = 0;

     virtual void AddSalt(int salt_count) = 0;
};

class Pepperoni : public Pizza {
public:

    explicit Pepperoni(SIZE size) {
        name = "Pepperoni";
        descripsion = "Italian classic";
        Cheese = 0;
        Salt = 0;

        switch (size) {
            case Small:
                this->size = Small;
                cout << "Small size";
                break;
            case Medium:
                this->size = Medium;
                cout << "Medium size";
                break;
            case Large:
                this->size = Large;
                cout << "Large size";
                break;
            default:
                this->size = Small;
                cout << "Small size";
                break;
        }
        price = this -> size*10;
    }

     unsigned int getCheese() override {
        return  Cheese;
    }

    unsigned int getSalt() override {
        return  Salt;
    }

     string getName() override {
        return name;
    }

     unsigned int getSize() override {
        return size;
    }

     string getDescription() override {
        return descripsion;
    }

     unsigned int getPrice() override {
        return price;
    }

    void AddCheese(int cheese_count) override {
       Cheese += cheese_count;
        price += cheese_count * 7;
    }

    void AddSalt(int salt_count) override {
        Salt += salt_count;
        price += salt_count * 2;
    }
};

class Hawaiian : public Pizza {
public:
    explicit Hawaiian(SIZE size1) {
        name = "Hawaiian";
        descripsion = "Who loves pineapple?";
        Cheese = 0;
        Salt = 0;

        switch (size) {
            case Small:
                this->size = Small;
                cout << "Small size";
                break;
            case Medium:
                this->size = Medium;
                cout << "Medium size";
                break;
            case Large:
                this->size = Large;
                cout << "Large size";
                break;
            default:
                this->size = Small;
                cout << "Small size";
                break;
        }
        price = this -> size*10;
    }

    unsigned int getCheese() override {
        return  Cheese;
    }

    unsigned int getSalt() override {
        return  Salt;
    }

    string getName() override {
        return name;
    }

    unsigned int getSize() override {
        return size;
    }

    string getDescription() override {
        return descripsion;
    }

    unsigned int getPrice() override {
        return price;
    }

    void AddCheese(int cheese_count) override {
        Cheese += cheese_count;
        price += cheese_count * 7;
    }

    void AddSalt(int salt_count) override {
        Salt += salt_count;
        price += salt_count * 2;
    }
};

class FourCheese : public Pizza {
public:
    explicit FourCheese(SIZE size) {
        name = "FourCheese";
        descripsion = "Extra cheese";
        Cheese = 0;
        Salt = 0;

        switch (size) {
            case Small:
                this->size = Small;
                cout << "Small size";
                break;
            case Medium:
                this->size = Medium;
                cout << "Medium size";
                break;
            case Large:
                this->size = Large;
                cout << "Large size";
                break;
            default:
                this->size = Small;
                cout << "Small size";
                break;
        }
        price = this -> size * 10;
    }

     unsigned int getCheese() override {
        return  Cheese;
    }

     unsigned int getSalt() override {
        return  Salt;
    }

     string getName() override {
        return name;
    }

     unsigned int getSize() override {
        return size;
    }

    string getDescription() override {
        return descripsion;
    }

     unsigned int getPrice() override {
        return price;
    }

    void AddCheese(int cheese_count) override {
        Cheese += cheese_count;
        price += cheese_count * 7;
    }

    void AddSalt(int salt_count) override {
        Salt += salt_count;
        price += salt_count * 2;
    }
};

class Order {
    vector <Pizza *> menu;
    unsigned int TotalPrice = 0;
public:

     void Increase (Pizza * pizza) {
        menu.push_back(pizza);
        TotalPrice += pizza->getPrice();
    }

    void TakeOrder() {
        int order = menu.size();

        for (int i = 0; i < order; i++) {
            cout << "You ordered " << menu[i] -> getName() << endl;
            menu[i] -> getDescription();
            cout << "Pizza size is " <<menu[i] -> getSize() << endl;
            cout << "Salt " << menu[i] -> getSalt() << endl;
            cout << "Cheese " << menu[i] -> getCheese() << endl;

            TotalPrice += menu[i] -> getPrice();
        }
        cout << "Your total price will be " << TotalPrice;
    }

     void add_cheese(Pizza &pizza, int count) {
        pizza.AddCheese(count);
    };

     void add_salt(Pizza &pizza, int count) {
        pizza.AddSalt(count);
    }

     void MakeOrder() {
        int pizzaType;
        int size;
        SIZE size1 = Small;
        int cheese;
        int salt;

        cout << "Hello, Pizza!" << endl;
        cout << "Choose pizza " << ::endl;
        cout << "-------------------------------- MENU -------------------------------------" << endl;
        cout << "1_________________________________________________________________Pepperoni" << endl;
        cout << "2__________________________________________________________________Hawaiian" << endl;
        cout << "3________________________________________________________________FourCheese" << endl;

        cin >> pizzaType;

        cout << "Choose size:" << endl;
        cout << "1. Small____25" << endl;
        cout << "2. Medium___30" << endl;
        cout << "3. Large____35" << endl;

        cin >> size;
        if (size == 25) {
            size1 = Small;
        }
        if (size == 30) {
            size1 = Medium;
        }
        if (size == 35) {
            size1 = Large;
        }

        cout << "Cheese?" << endl;
        cout << "1. + 5g of cheese" << endl;
        cout << "2. +15g of cheese" << endl;
        cout << "3. nothing" << endl;

        cin >> cheese;

        cout << "Salt?" << endl;
        cout << "1. + 1g of salt" << endl;
        cout << "2. +2g of salt" << endl;
        cout << "3. nothing" << endl;

        cin >> salt;

        switch (pizzaType) {
            case 1: {
                Pepperoni *pepperoni = new Pepperoni(size1);
                add_cheese(*pepperoni, cheese);
                add_salt(*pepperoni, salt);
                Increase(pepperoni);
                break;
            }
            case 2: {
                Hawaiian *hawaiian = new Hawaiian(size1);
                add_cheese(*hawaiian, cheese);
                add_salt(*hawaiian, salt);
                Increase(hawaiian);
                break;
            }
            case 3: {
                FourCheese *fourCheese = new FourCheese(size1);
                add_cheese(*fourCheese, cheese);
                add_salt(*fourCheese, salt);
                Increase(fourCheese);
                break;
            }
        }

    }
};

int main() {
    Order order;

   order.MakeOrder();
   order.TakeOrder();
    return 0;

};