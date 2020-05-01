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
using namespace std;

enum Pizza { Pepperoni, Hawaiian, FourCheese};
enum SIZE {Small = 25, Medium = 30, Big = 35};

class Pizzeria {
protected:
    int Price;
    Pizza pizza;
    SIZE Size;
    int Cheese;
    int Salt;

public:
    std::string Adress;

    Pizzeria(std::string Adress) {
        this -> Adress = Adress;
    }

    void callStuff () const {
        cout << "How can I help you?" << endl;
    }


    int AddCheese (int &Cheese) {
        int CheeseBonus = 0;
        if (Cheese > 0) {
            CheeseBonus = Cheese * 1.5 + 10;
        }
        return CheeseBonus;
    };

    int AddSalt (int &Salt) {
        int SaltBonus = 0;
        if (Salt > 0) {
            SaltBonus = Salt * 0.5 + 10;
        }
        return SaltBonus;
    };

    int setSize(SIZE &Size) {
        int ChosenSize = 0;
        if (Size > 0) {
            ChosenSize = Size * 2;
        }
        return ChosenSize;
    };

    int IncresePrice() {
        int k = AddCheese(Cheese);
        if (k > 0) { cout << "We`re gonna add " << Cheese << " g of cheese then" << endl;}
        int t = AddSalt(Salt);
        if (t > 0) { cout << "We`re gonna add " << Salt << " g of salt then" << endl;}
        int m = setSize(Size);
        Price += k + t + m;
    }

    virtual void setPrice() {
        int Bonus = IncresePrice();
        Price += Bonus;
    };

    int getPrice() { return Price;};

    virtual void MakeOrder(Pizza pizza) {
        int Cheese;
        int Salt;
        int Size;
        cout << "What size do you want?" << endl;
        cin >> Size;
        cout << "Would you like to add some cheese on top? " << endl;
        cin >> Cheese;
        cout << "Salt? " << endl;
        cin >> Salt;
        switch (pizza) {
            case Pepperoni:
                setPrice();
                break;
            case Hawaiian:
                setPrice();
                break;
            case FourCheese:
                setPrice();
                break;
        }
    }
};

int main() {
    Pizzeria PizzaHut("Green ave, 113");
    int Cheese;
    int Salt;
    int size;
    int order;
    cout << " ヽ(*・ω・)ﾉ Hello, Pizza! ヽ(*・ω・)ﾉ" << endl;
    cout << "Choose pizza " << ::endl;
    cout << "-------------------------------- MENU -------------------------------------" << endl;
    cout << "1_________________________________________________________________Pepperoni" << endl;
    cout << "2__________________________________________________________________Hawaiian" << endl;
    cout << "3________________________________________________________________FourCheese" << endl;
    cin >> order;


    switch (order) {
        case 1:
            PizzaHut.MakeOrder(Pepperoni);
            cout << "Your order in total will be " << PizzaHut.getPrice() << endl;
            break;
        case 2:
            PizzaHut.MakeOrder(Hawaiian);
            cout << "Your order in total will be " << PizzaHut.getPrice() << endl;
            break;
        case 3:
            PizzaHut.MakeOrder(FourCheese);
            cout << "Your order in total will be " << PizzaHut.getPrice() << endl;
            break;
        case 4:
            PizzaHut.callStuff();
            break;
    }


    return 0;

};