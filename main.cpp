#include <iostream>
#include <locale.h>
void choice(); //Меню выбора
void cart(); //Добавление в корзину
void showmenu(); //Показать меню(БД товаров)
void orderhistory(); //Показать историю заказов (БД истории)
void payment(); //Функция оплаты
void showcart(); //Показать что в корзине
void issue(); //Фукнция выдачи заказа

void main()
{
    setlocale(LC_ALL, "russian");
    choice();
}
void choice() {
    int d = 0;
    bool flag = true;
    while (flag) {
        std::cout << "Что вы хотите сделать?\n1.Посмотреть меню\n2.Добавть в корзину\n3.Посмотреть что в корзине\n4.Посмотреть историю заказов\n5.Выйти\n";
        std::cin >> d;
        switch (d) {
        case 1: {
            showmenu();
            break;
        }
        case 2: {
            showmenu();
            cart();
            break;

        }
        case 3: {
            showcart();
            break;
        }
        case 4: {
            orderhistory();
            break;
        }
        case 5: {
            flag = false;
            break;
        }
        }
    }
}

void cart() {
    int p = 0, c = 0, a = 0, d = 0;
    showmenu();
    std::cout << "Какую позицию вы хотите добавть в заказ?\n";
    std::cin >> p;
    std::cout << "Сколько порций вы хотите добавить?\n";
    std::cin >> a;
    //Тут в БД товаров переносится инфа какой товар и убавляет его количество
    //Тут в БД заказа добавляется товар
    while (c != 2) {
        std::cout << "Хотите добавить что-то ещё?\n1.Да\n2.Нет\n";
        std::cin >> c;
        if (c == 1) {
            cart();
        }
    }
    std::cout << "Хотите оплатить заказ или сделать что-то ещё?\n";
    std::cin >> d;
    switch (d) {
    case 1: {
        payment();
        break;
    }
    case 2: {
        break;
    }
    }
}

void showmenu() {
    //Тут из БД товаров выводятся товары
}

void orderhistory() {
    //Тут из БД истории выводятся заказы
}

void payment() {
    int sum = 0;
    //Тут из бд заказа выводится заказ
    std::cout << "Сумма вашего заказа " << sum;
    //Тут происходит оплата
    issue();
    //Тут из БД заказа инфа переносится в БД истории заказов
}

void showcart() {
    int pay;
    //Тут из бд заказа выводится заказ
    std::cout << "Хотите оплатить заказ?\n1.Да\n2.Нет\n";
    std::cin >> pay;
    switch (pay) {
    case1: {
        payment();
        break;
        }
case2: {
    break;
    }
    }

}

void issue() {
    //Функция выдачи заказа
}