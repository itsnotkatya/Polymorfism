//Реализовать программу демонстрирующую предметную область "Пиццерия"
//
//Заказ - это список из выбранных пользователем пицц.
//
//Пицца - это блюдо, которое выбирает пользователь. Пицца обладает именем(текст), описанием(текст), размером (один из вариантов 25, 30, 35, 40, который выбирает пользователь), ценой(зависит от размера выбранной пиццы и ингредиентов). Пользователь может подсолить любую пиццу N-раз или добавить сыра M-раз - это увеличивает цену в зависимости от вида и размера пиццы (формулу придумать на ваше усмотрение)
//
//Заказ - формируется пользователем через консоль, возможность добавить пиццу, распечатать заказ в консоль.
//
//Печать заказа - вывод всего списка выбранных пользователем пицц, с указанием названия, описания, N-соли и M-сыра, размера пиццы и стоимости пиццы с учётом всех параметров
//
// В конце распечатанного заказа вывести итоговую сумму за заказ

#include <iostream>
#include <vector>

using namespace std;

//enum Pizza { Pepperoni, Hawaiian, FourCheese};
enum SIZE {Small = 25, Medium = 30, Large = 35};

struct Ingridients {
    int Cheese;
    int Salt;
};

class Pizza {
protected:
    unsigned int Price;
    SIZE size;
    Ingridients * data;
    string descripsion;
    string name;
public:

    ~Pizza() {};

    virtual string getName() const = 0;

    virtual string getDescription() const = 0;

    virtual unsigned int getSize() const = 0;

    virtual unsigned int getCheese() const = 0;

    virtual unsigned int getSalt() const = 0;

    virtual unsigned int getPrice() const = 0;

    virtual void AddCheese(Ingridients cheese) = 0;

    virtual void AddSalt(Ingridients salt) = 0;

};

class Pepperoni : public Pizza {
public:

    Pepperoni(SIZE size1) {
        name = "Pepperoni";
        descripsion = "Italian classic";
        data->Cheese = 0;
        data->Salt = 0;

        switch (size) {
            case 0:
                this->size = Small;
                cout << "Small size";
                break;
            case 1:
                this->size = Medium;
                cout << "Medium size";
                break;
            case 2:
                this->size = Large;
                cout << "Large size";
                break;
            default:
                this->size = Small;
                cout << "Small size";
                break;
        }
        Price = this -> size*10;
    }

    unsigned int getCheese() const override {
        return data -> Cheese;
    }

    unsigned int getSalt() const override {
        return data -> Salt;
    }

    string getName() const override {
        return name;
    }

    string getDescription() const override {
        return descripsion;
    }

    unsigned int getPrice() const override {
        return Price;
    }

    void AddCheese(Ingridients ingridients) override {
       int plusCheese = data -> Cheese;
        Price += plusCheese * 7;
    }

    void AddSalt(Ingridients ingridients) override {
        int plusSalt = data -> Salt;
        Price += plusSalt * 2;
    }
};

class Hawaiian : public Pizza {
public:

    Hawaiian(SIZE size1) {
        name = "Hawaiian";
        descripsion = "Who loves pineapple?";
        data->Cheese = 0;
        data->Salt = 0;

        switch (size) {
            case 0:
                this->size = Small;
                cout << "Small size";
                break;
            case 1:
                this->size = Medium;
                cout << "Medium size";
                break;
            case 2:
                this->size = Large;
                cout << "Large size";
                break;
            default:
                this->size = Small;
                cout << "Small size";
                break;
        }
        Price = this -> size*10;
    }

    unsigned int getCheese() const override {
        return data -> Cheese;
    }

    unsigned int getSalt() const override {
        return data -> Salt;
    }

    string getName() const override {
        return name;
    }

    string getDescription() const override {
        return descripsion;
    }

    unsigned int getPrice() const override {
        return Price;
    }

    void AddCheese(Ingridients ingridients) override {
        int plusCheese = data -> Cheese;
        Price += plusCheese * 5;
    }

    void AddSalt(Ingridients ingridients) override {
        int plusSalt = data -> Salt;
        Price += plusSalt * 2;
    }
};

class FourCheese : public Pizza {
public:

    FourCheese(SIZE size1) {
        name = "FourCheese";
        descripsion = "Extra cheese";
        data->Cheese = 0;
        data->Salt = 0;

        switch (size) {
            case 0:
                this->size = Small;
                cout << "Small size";
                break;
            case 1:
                this->size = Medium;
                cout << "Medium size";
                break;
            case 2:
                this->size = Large;
                cout << "Large size";
                break;
            default:
                this->size = Small;
                cout << "Small size";
                break;
        }
        Price = this -> size*10;
    }

    unsigned int getCheese() const override {
        return data -> Cheese;
    }

    unsigned int getSalt() const override {
        return data -> Salt;
    }

    string getName() const override {
        return name;
    }

    string getDescription() const override {
        return descripsion;
    }

    unsigned int getPrice() const override {
        return Price;
    }

    void AddCheese(Ingridients ingridients) override {
        int plusCheese = data -> Cheese;
        Price += plusCheese * 10;
    }

    void AddSalt(Ingridients ingridients) override {
        int plusSalt = data -> Salt;
        Price += plusSalt * 2;
    }
};

class Order {
    vector <Pizza *> pizza;
public:

    void Increase (Pizza * pizza1) {
        pizza.push_back(pizza1);
    }

    void TakeOrder() {
        unsigned int TotalPrice;
        int order = pizza.size();

        for (int i = 0; i < order; i++) {
            cout << "You ordered " << pizza[i] -> getName() << endl;
            pizza[i] -> getDiscription() << endl;
            cout << "Pizza size is " <<pizza[i] -> getSize() << endl;
            cout << "Salt " << pizza[i] -> getSalt() << endl;
            cout << "Cheese " << pizza[i] -> getCheese() << endl;

            TotalPrice += pizza[i].Price;
        }
        cout << "Your total price will be " << TotalPrice;
    }

    void MakeOrder() {
        string pizzaType;
        SIZE pizzaSize;
        int addCheese;
        int addSalt;
        int choise;
        int size;
        int cheese;
        int salt;

        cout << "Choose size:" << endl;
        cout << "1. Small" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Large" << endl;

        cin >> size;
        switch (size) {
            case 1:
                pizzaSize = Small;
                break;
            case 2:
                pizzaSize = Medium;
                break;
            case 3:
                pizzaSize = Large;
                break;
        }

        cout << "Cheese?" << endl;
        cout << "1. + 5g of cheese" << endl;
        cout << "2. +15g of cheese" << endl;
        cout << "3. nothing" << endl;

        cin >> cheese;
        switch (cheese) {
            case 1:
                addCheese = 5;
                break;
            case 2:
                addCheese = 15;
                break;
            case 3:
                addCheese = 0;
                break;
        }

        cout << "Salt?" << endl;
        cout << "1. + 1g of salt" << endl;
        cout << "2. +2g of salt" << endl;
        cout << "3. nothing" << endl;

        cin >> salt;
        switch (salt) {
            case 1:
                addSalt = 1;
                break;
            case 2:
                addSalt = 2;
                break;
            case 3:
                addSalt = 0;
                break;
        }

        cin >> choise;
        switch (choise) {
            case 1:
                new Pepperoni (pizzaSize);
                break;
            case 2:
                new Hawaiian (pizzaSize);
                break;
            case 3:
                new FourCheese (pizzaSize);
                break;
        }
    }
};



int main() {
    cout << " ヽ(*・ω・)ﾉ Hello, Pizza! ヽ(*・ω・)ﾉ" << endl;
    cout << "Choose pizza " << ::endl;
    cout << "-------------------------------- MENU -------------------------------------" << endl;
    cout << "1_________________________________________________________________Pepperoni" << endl;
    cout << "2__________________________________________________________________Hawaiian" << endl;
    cout << "3________________________________________________________________FourCheese" << endl;

   Order order;
   order.MakeOrder();
   order.TakeOrder();


    return 0;

};