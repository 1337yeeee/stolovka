#include <iostream>
#include <locale.h>
void choice(); //���� ������
void cart(); //���������� � �������
void showmenu(); //�������� ����(�� �������)
void orderhistory(); //�������� ������� ������� (�� �������)
void payment(); //������� ������
void showcart(); //�������� ��� � �������
void issue(); //������� ������ ������

void main()
{
    setlocale(LC_ALL, "russian");
    choice();
}
void choice() {
    int d = 0;
    bool flag = true;
    while (flag) {
        std::cout << "��� �� ������ �������?\n1.���������� ����\n2.������� � �������\n3.���������� ��� � �������\n4.���������� ������� �������\n5.�����\n";
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
    std::cout << "����� ������� �� ������ ������� � �����?\n";
    std::cin >> p;
    std::cout << "������� ������ �� ������ ��������?\n";
    std::cin >> a;
    //��� � �� ������� ����������� ���� ����� ����� � �������� ��� ����������
    //��� � �� ������ ����������� �����
    while (c != 2) {
        std::cout << "������ �������� ���-�� ���?\n1.��\n2.���\n";
        std::cin >> c;
        if (c == 1) {
            cart();
        }
    }
    std::cout << "������ �������� ����� ��� ������� ���-�� ���?\n";
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
    //��� �� �� ������� ��������� ������
}

void orderhistory() {
    //��� �� �� ������� ��������� ������
}

void payment() {
    int sum = 0;
    //��� �� �� ������ ��������� �����
    std::cout << "����� ������ ������ " << sum;
    //��� ���������� ������
    issue();
    //��� �� �� ������ ���� ����������� � �� ������� �������
}

void showcart() {
    int pay;
    //��� �� �� ������ ��������� �����
    std::cout << "������ �������� �����?\n1.��\n2.���\n";
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
    //������� ������ ������
}