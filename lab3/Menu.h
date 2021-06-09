#pragma once

#include "Tree.h"
#include "BinHeap.h"


template<typename T>
void Print(Heap<T> elem) {
    std::vector<bool> present = elem.GivePresents();
    std::vector<T> v = elem.GiveElements();
    for (int i = 0; i < v.size(); i++) {
        if (present[i] == true)
            std::cout << v[i] << ' ';
        else std::cout << ' ';
    }
}


template<typename R>
void PrintTree(typename BinTree<R>::Node *p, int level) {
    if (p != nullptr) {
        PrintTree<R>(p->left, level + 1);
        for (int i = 0; i < level; i++) std::cout << "               ";
        std::cout << p->element << std::endl << std::endl;
        PrintTree<R>(p->right, level + 1);
    } else return;
}


template<typename R>
void Print(BinTree<R> &elem) {
    PrintTree<R>(elem.Get_head(), 0);
}


void MenuTreeInt() {
    int length;
    std::cout << "Введите кол-во элементов >>";
    std::cin >> length;
    int mas[length];
    std::cout << "Введите число :";
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    BinTree<int> vec = BinTree<int>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать дерево"
              << std::endl
              << "2 - операции над деревом"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >> ";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            Print(vec);
        else if (ch == 2) {
            int op = 1;
            while (op != 0) {
                std::cout << "1 - чтобы добавить в дерево элемент"
                          << std::endl
                          << "2 - чтобы сохранить дерево в вектор по заданному обходу"
                          << std::endl
                          << "3 - чтобы проверить на вхождение дерева"
                          << std::endl
                          << "4 - чтобы проверить на вхождение элемента в дереве"
                          << std::endl
                          << "5 - чтобы ссклеить 2 дерева"
                          << std::endl
                          << "6 - чтобы вывести максимальный элемент дерева"
                          << std::endl
                          << "7 - чтобы вывести минимальный элемент дерева"
                          << std::endl
                          << "8 -  чтобы удалить элемент дерева"
                          << std::endl
                          << "0 - чтобы выйти"
                          << std::endl
                          << "Ваш выбор >> ";
                std::cin >> op;
                std::cout << std::endl;
                if (op == 1) {
                    int l;
                    std::cout << "Введите элемент >> ";
                    std::cin >> l;
                    std::cout << std::endl;
                    vec.Insert(l);
                    std::cout << "Элемент добавлен!" << std::endl;
                } else if (op == 2) {
                    std::vector<int> el;
                    std::cout << "Ввыбирите обход по которому хотите сохранить дерево в массив : "
                              << std::endl
                              << "1 - klp"
                              << std::endl
                              << "2 - kpl"
                              << std::endl
                              << "3 - lkp"
                              << std::endl
                              << "4 - pkl"
                              << std::endl
                              << "5 - lpk"
                              << std::endl
                              << "6 - plk"
                              << std::endl
                              << "Ваш выбор >> ";
                    int kl;
                    std::cin >> kl;
                    if (kl == 1)
                        el = vec.ToVector("klp");
                    else if (kl == 2)
                        el = vec.ToVector("kpl");
                    else if (kl == 3)
                        el = vec.ToVector("lkp");
                    else if (kl == 4)
                        el = vec.ToVector("pkl");
                    else if (kl == 5)
                        el = vec.ToVector("lpk");
                    if (kl == 6)
                        el = vec.ToVector("plk");
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать вектор"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над деревом"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:el)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                } else if (op == 3) {
                    int pl, len, jr;
                    std::vector<int> v;
                    std::cout << "Какого размера дерева вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этого дерева: ";
                    for (int i = 0; i < len; i++) {
                        std::cin >> jr;
                        v.push_back(jr);
                    }
                    std::cout << std::endl;
                    std::cout << "Введите корень этого дерева >>";
                    int data;
                    std::cin >> data;
                    std::cout << std::endl;
                    if (vec.Search_Tree(v, data))
                        std::cout << "Данное поддерево найдено!" << std::endl;
                    else std::cout << "Данное поддерево не найдено" << std::endl;
                } else if (op == 4) {
                    std::cout << "Введите элемент >>";
                    int in;
                    std::cin >> in;
                    std::cout << std::endl;
                    if (vec.Contains(in) != nullptr)
                        std::cout << "Данный элемент найден!" << std::endl;
                    else std::cout << " Данного элемента в дереве нет!" << std::endl;
                } else if (op == 5) {
                    int pl, len, jr;
                    std::vector<int> v;
                    std::cout << "Какого размера дерева вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этого дерева: ";
                    for (int i = 0; i < len; i++) {
                        std::cin >> jr;
                        v.push_back(jr);
                    }
                    BinTree<int> v2 = BinTree<int>(v);
                    vec.Concat(v2);
                    std::cout << "Данное дерево построено!" << std::endl;
                } else if (op == 6) {
                    std::cout << "Максимальный элемент: " << vec.getMaxNode() << std::endl;
                } else if (op == 7) {
                    std::cout << "Минимальный элемент: " << vec.getMinNode() << std::endl;
                } else if (op == 8) {
                    int k;
                    std::cout << "Введите элемент, который хотите удалить >> ";
                    std::cin >> k;
                    vec.Delete(k);
                    std::cout << std::endl;
                }
            }
        }
        std::cout << "1 - чтобы показать дерево"
                  << std::endl
                  << "2 - операции над деревом"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >> ";
        std::cin >> ch;
        std::cout << std::endl;
    }
}


void MenuTreePerson() {
    int length;
    std::cout << "Введите кол-во элементов >>";
    std::cin >> length;
    std::vector<Person> el;
    std::cout << "Введите элементы :" << std::endl;
    std::string s1, s2;
    int n1, n2, n3;
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cout << "Введите имя: ";
        std::cin >> s1;
        std::cout << std::endl;
        std::cout << "Введите фамилию: ";
        std::cin >> s2;
        std::cout << std::endl;
        std::cout << "Введите день рождения: ";
        std::cin >> n1;
        std::cout << std::endl;
        std::cout << "Введите месяц рождения: ";
        std::cin >> n2;
        std::cout << std::endl;
        std::cout << "Введите год рождения: ";
        std::cin >> n3;
        std::cout << std::endl;
        el.push_back({s1, s2, n1, n2, n3});
    }
    BinTree<Person> vec = BinTree<Person>(el);
    int ch = -1;
    std::cout << "1 - чтобы показать дерево"
              << std::endl
              << "2 - операции над деревом"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >> ";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            Print(vec);
        else if (ch == 2) {
            int op = 1;
            while (op != 0) {
                std::cout << "1 - чтобы добавить в дерево элемент"
                          << std::endl
                          << "2 - чтобы сохранить дерево в вектор по заданному обходу"
                          << std::endl
                          << "3 - чтобы проверить на вхождение дерева"
                          << std::endl
                          << "4 - чтобы проверить на вхождение элемента в дереве"
                          << std::endl
                          << "5 - чтобы ссклеить 2 дерева"
                          << std::endl
                          << "6 - чтобы вывести максимальный элемент дерева"
                          << std::endl
                          << "7 - чтобы вывести минимальный элемент дерева"
                          << std::endl
                          << "0 - чтобы выйти"
                          << std::endl
                          << "Ваш выбор >> ";
                std::cin >> op;
                std::cout << std::endl;
                if (op == 1) {
                    std::cout << "Введите имя: ";
                    std::cin >> s1;
                    std::cout << std::endl;
                    std::cout << "Введите фамилию: ";
                    std::cin >> s2;
                    std::cout << std::endl;
                    std::cout << "Введите день рождения: ";
                    std::cin >> n1;
                    std::cout << std::endl;
                    std::cout << "Введите месяц рождения: ";
                    std::cin >> n2;
                    std::cout << std::endl;
                    std::cout << "Введите год рождения: ";
                    std::cin >> n3;
                    std::cout << std::endl;
                    Person l = Person{s1, s2, n1, n2, n3};
                    vec.Insert(l);
                } else if (op == 2) {
                    std::vector<Person> el;
                    std::cout << "Ввыбирите обход по которому хотите сохранить дерево в вектор : "
                              << std::endl
                              << "1 - klp"
                              << std::endl
                              << "2 - kpl"
                              << std::endl
                              << "3 - lkp"
                              << std::endl
                              << "4 - pkl"
                              << std::endl
                              << "5 - lpk"
                              << std::endl
                              << "6 - plk"
                              << std::endl
                              << "Ваш выбор >> ";
                    int kl;
                    std::cin >> kl;
                    if (kl == 1)
                        el = vec.ToVector("klp");
                    else if (kl == 2)
                        el = vec.ToVector("kpl");
                    else if (kl == 3)
                        el = vec.ToVector("lkp");
                    else if (kl == 4)
                        el = vec.ToVector("pkl");
                    else if (kl == 5)
                        el = vec.ToVector("lpk");
                    if (kl == 6)
                        el = vec.ToVector("plk");
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать вектор"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над деревом"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:el)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                } else if (op == 4) {
                    std::cout << "Введите элемент >>";
                    std::cout << "Введите имя: ";
                    std::cin >> s1;
                    std::cout << std::endl;
                    std::cout << "Введите фамилию: ";
                    std::cin >> s2;
                    std::cout << std::endl;
                    std::cout << "Введите день рождения: ";
                    std::cin >> n1;
                    std::cout << std::endl;
                    std::cout << "Введите месяц рождения: ";
                    std::cin >> n2;
                    std::cout << std::endl;
                    std::cout << "Введите год рождения: ";
                    std::cin >> n3;
                    std::cout << std::endl;
                    Person l = Person{s1, s2, n1, n2, n3};
                    std::cout << std::endl;
                    if (vec.Contains(l) != nullptr)
                        std::cout << "Данный элемент найден!" << std::endl;
                    else std::cout << " Данного элемента в дереве нет!" << std::endl;
                } else if (op == 5) {
                    int pl, len, jr;
                    std::vector<Person> v;
                    std::cout << "Какого размера дерева вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этого дерева: ";
                    for (int i = 0; i < len; i++) {
                        std::cout << "Введите имя: ";
                        std::cin >> s1;
                        std::cout << std::endl;
                        std::cout << "Введите фамилию: ";
                        std::cin >> s2;
                        std::cout << std::endl;
                        std::cout << "Введите день рождения: ";
                        std::cin >> n1;
                        std::cout << std::endl;
                        std::cout << "Введите месяц рождения: ";
                        std::cin >> n2;
                        std::cout << std::endl;
                        std::cout << "Введите год рождения: ";
                        std::cin >> n3;
                        std::cout << std::endl;
                        v.push_back(Person{s1, s2, n1, n2, n3});
                    }
                    BinTree<Person> v2 = BinTree<Person>(v);
                    vec.Concat(v2);
                    std::cout << "Данное дерево построено!" << std::endl;
                } else if (op == 6) {
                    std::cout << "Максимальный элемент: " << vec.getMaxNode() << std::endl;
                } else if (op == 7) {
                    std::cout << "Минимальный элемент: " << vec.getMinNode() << std::endl;
                } else if (op == 8) {
                    std::cout << "Введите элемент, который хотите удалить :";
                    std::cout << std::endl;
                    std::cout << "Введите имя: ";
                    std::cin >> s1;
                    std::cout << std::endl;
                    std::cout << "Введите фамилию: ";
                    std::cin >> s2;
                    std::cout << std::endl;
                    std::cout << "Введите день рождения: ";
                    std::cin >> n1;
                    std::cout << std::endl;
                    std::cout << "Введите месяц рождения: ";
                    std::cin >> n2;
                    std::cout << std::endl;
                    std::cout << "Введите год рождения: ";
                    std::cin >> n3;
                    std::cout << std::endl;
                    Person k = Person{s1, s2, n1, n2, n3};
                    vec.Delete(k);
                    std::cout << std::endl;
                }
            }
        }
        std::cout << "1 - чтобы показать дерево"
                  << std::endl
                  << "2 - операции над деревом"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >> ";
        std::cin >> ch;
        std::cout << std::endl;
    }
}


void MenuHeapInt() {
    int length;
    std::cout << "Введите кол-во элементов >>";
    std::cin >> length;
    int mas[length];
    std::cout << "Введите число :";
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    Heap<int> vec = Heap<int>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать дерево"
              << std::endl
              << "2 - операции над деревом"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >> ";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1) {
            Print(vec);
            std::cout << std::endl;
        } else if (ch == 2) {
            int op = 1;
            while (op != 0) {
                std::cout << "1 - чтобы добавить в кучу элемент"
                          << std::endl
                          << "2 - чтобы сохранить кучу в вектор по заданному обходу"
                          << std::endl
                          << "3 - чтобы проверить на вхождение кучи"
                          << std::endl
                          << "4 - чтобы вывести подкучу"
                          << std::endl
                          << "0 - чтобы выйти"
                          << std::endl
                          << "5 - чтобы удалить элемент"
                          << std::endl
                          << "Ваш выбор >> ";
                std::cin >> op;
                std::cout << std::endl;
                if (op == 1) {
                    int l;
                    std::cout << "Введите элемент >> ";
                    std::cin >> l;
                    std::cout << std::endl;
                    vec.Add(l);
                    std::cout << "Элемент добавлен!" << std::endl;
                } else if (op == 2) {
                    std::vector<int> el;
                    std::cout << "Ввыбирите обход по которому хотите сохранить дерево в массив : "
                              << std::endl
                              << "1 - klp"
                              << std::endl
                              << "2 - kpl"
                              << std::endl
                              << "3 - lkp"
                              << std::endl
                              << "4 - pkl"
                              << std::endl
                              << "5 - lpk"
                              << std::endl
                              << "6 - plk"
                              << std::endl
                              << "Ваш выбор >> ";
                    int kl;
                    std::cin >> kl;
                    if (kl == 1)
                        el = vec.Klp(0);
                    else if (kl == 2)
                        el = vec.Kpl(0);
                    else if (kl == 3)
                        el = vec.Lkp(0);
                    else if (kl == 4)
                        el = vec.Pkl(0);
                    else if (kl == 5)
                        el = vec.Lpk(0);
                    if (kl == 6)
                        el = vec.Plk(0);
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать вектор"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над деревом"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:el)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                } else if (op == 3) {
                    int pl, len;
                    int jr;
                    std::cout << "Какой размер кучи вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этой кучи: ";
                    int mas[len];
                    for (int i = 0; i < len; i++) {
                        std::cin >> jr;
                        mas[i] = jr;
                    }
                    std::cout << std::endl;
                    if (vec.SearchHeap(mas, length))
                        std::cout << "Данное поддерево найдено!" << std::endl;
                    else std::cout << "Данное поддерево не найдено" << std::endl;
                } else if (op == 4) {
                    std::cout << "Введите индекс >>";
                    int in;
                    std::cin >> in;
                    std::cout << std::endl;
                    std::vector<int> v;
                    v = vec.SeeTree(in);
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать кучу"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над кучей"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:v)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                }
                if (op == 5) {
                    std::cout << "Введите элемент >> ";
                    int pro;
                    std::cin >> pro;
                    vec.Delete(pro);
                }
            }
        }
        std::cout << "1 - чтобы показать дерево"
                  << std::endl
                  << "2 - операции над деревом"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >> ";
        std::cin >> ch;
        std::cout << std::endl;
    }
}


void MenuHeapPerson() {
    int length;
    std::cout << "Введите кол-во элементов >>";
    std::cin >> length;
    std::vector<Person> el;
    std::cout << "Введите число :";
    std::string s1, s2;
    int n1, n2, n3;
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cout << std::endl;
        std::cout << "Введите имя: ";
        std::cin >> s1;
        std::cout << std::endl;
        std::cout << "Введите фамилию: ";
        std::cin >> s2;
        std::cout << std::endl;
        std::cout << "Введите день рождения: ";
        std::cin >> n1;
        std::cout << std::endl;
        std::cout << "Введите месяц рождения: ";
        std::cin >> n2;
        std::cout << std::endl;
        std::cout << "Введите год рождения: ";
        std::cin >> n3;
        std::cout << std::endl;
        el.push_back(Person{s1, s2, n1, n2, n3});
    }
    Heap<Person> vec = Heap<Person>(el);
    int ch = -1;
    std::cout << "1 - чтобы показать дерево"
              << std::endl
              << "2 - операции над деревом"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >> ";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1) {
            Print(vec);
            std::cout << std::endl;
        } else if (ch == 2) {
            int op = 1;
            while (op != 0) {
                std::cout << "1 - чтобы добавить в кучу элемент"
                          << std::endl
                          << "2 - чтобы сохранить кучу в вектор по заданному обходу"
                          << std::endl
                          << "3 - чтобы проверить на вхождение кучи"
                          << std::endl
                          << "4 - чтобы вывести подкучу"
                          << std::endl
                          << "5 - чтобы удалить элемент"
                          << std::endl
                          << "0 - чтобы выйти"
                          << std::endl
                          << "Ваш выбор >> ";
                std::cin >> op;
                std::cout << std::endl;
                if (op == 1) {
                    std::cout << "Введите элемент >> ";
                    std::cout << std::endl;
                    std::cout << "Введите имя: ";
                    std::cin >> s1;
                    std::cout << std::endl;
                    std::cout << "Введите фамилию: ";
                    std::cin >> s2;
                    std::cout << std::endl;
                    std::cout << "Введите день рождения: ";
                    std::cin >> n1;
                    std::cout << std::endl;
                    std::cout << "Введите месяц рождения: ";
                    std::cin >> n2;
                    std::cout << std::endl;
                    std::cout << "Введите год рождения: ";
                    std::cin >> n3;
                    std::cout << std::endl;
                    Person l = (Person{s1, s2, n1, n2, n3});
                    vec.Add(l);
                    std::cout << "Элемент добавлен!" << std::endl;
                } else if (op == 2) {
                    std::vector<Person> el;
                    std::cout << "Ввыбирите обход по которому хотите сохранить дерево в массив : "
                              << std::endl
                              << "1 - klp"
                              << std::endl
                              << "2 - kpl"
                              << std::endl
                              << "3 - lkp"
                              << std::endl
                              << "4 - pkl"
                              << std::endl
                              << "5 - lpk"
                              << std::endl
                              << "6 - plk"
                              << std::endl
                              << "Ваш выбор >> ";
                    int kl;
                    std::cin >> kl;
                    if (kl == 1)
                        el = vec.Klp(0);
                    else if (kl == 2)
                        el = vec.Kpl(0);
                    else if (kl == 3)
                        el = vec.Lkp(0);
                    else if (kl == 4)
                        el = vec.Pkl(0);
                    else if (kl == 5)
                        el = vec.Lpk(0);
                    if (kl == 6)
                        el = vec.Plk(0);
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать вектор"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над деревом"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:el)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                } else if (op == 3) {
                    int pl, len;
                    std::cout << "Какой размер кучи вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этой кучи: ";
                    std::vector<Person> el;
                    for (int i = 0; i < len; i++) {
                        std::cout << std::endl;
                        std::cout << "Введите имя: ";
                        std::cin >> s1;
                        std::cout << std::endl;
                        std::cout << "Введите фамилию: ";
                        std::cin >> s2;
                        std::cout << std::endl;
                        std::cout << "Введите день рождения: ";
                        std::cin >> n1;
                        std::cout << std::endl;
                        std::cout << "Введите месяц рождения: ";
                        std::cin >> n2;
                        std::cout << std::endl;
                        std::cout << "Введите год рождения: ";
                        std::cin >> n3;
                        std::cout << std::endl;
                        el.push_back(Person{s1, s2, n1, n2, n3});
                    }
                    std::cout << std::endl;
                    if (vec.SearchHeap(el))
                        std::cout << "Данное поддерево найдено!" << std::endl;
                    else std::cout << "Данное поддерево не найдено" << std::endl;
                } else if (op == 4) {
                    std::cout << "Введите индекс >>";
                    int in;
                    std::cin >> in;
                    std::cout << std::endl;
                    std::vector<Person> v;
                    v = vec.SeeTree(in);
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать кучу"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над кучей"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:v)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                }
                if (op == 5) {
                    std::cout << "Введите элемент >> ";
                    std::cout << std::endl;
                    std::cout << "Введите имя: ";
                    std::cin >> s1;
                    std::cout << std::endl;
                    std::cout << "Введите фамилию: ";
                    std::cin >> s2;
                    std::cout << std::endl;
                    std::cout << "Введите день рождения: ";
                    std::cin >> n1;
                    std::cout << std::endl;
                    std::cout << "Введите месяц рождения: ";
                    std::cin >> n2;
                    std::cout << std::endl;
                    std::cout << "Введите год рождения: ";
                    std::cin >> n3;
                    std::cout << std::endl;
                    Person pro = Person{s1, s2, n1, n2, n3};
                    vec.Delete(pro);
                }
            }
        }
        std::cout << "1 - чтобы показать дерево"
                  << std::endl
                  << "2 - операции над деревом"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >> ";
        std::cin >> ch;
        std::cout << std::endl;
    }
}


void MenuHeapDouble() {
    int length;
    std::cout << "Введите кол-во элементов >>";
    std::cin >> length;
    double mas[length];
    std::cout << "Введите число :";
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    Heap<double> vec = Heap<double>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать дерево"
              << std::endl
              << "2 - операции над деревом"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >> ";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1) {
            Print(vec);
            std::cout << std::endl;
        } else if (ch == 2) {
            int op = 1;
            while (op != 0) {
                std::cout << "1 - чтобы добавить в кучу элемент"
                          << std::endl
                          << "2 - чтобы сохранить кучу в вектор по заданному обходу"
                          << std::endl
                          << "3 - чтобы проверить на вхождение кучи"
                          << std::endl
                          << "4 - чтобы вывести подкучу"
                          << std::endl
                          << "5 - чтобы удалить элемент"
                          << std::endl
                          << "0 - чтобы выйти"
                          << std::endl
                          << "Ваш выбор >> ";
                std::cin >> op;
                std::cout << std::endl;
                if (op == 1) {
                    double l;
                    std::cout << "Введите элемент >> ";
                    std::cin >> l;
                    std::cout << std::endl;
                    vec.Add(l);
                    std::cout << "Элемент добавлен!" << std::endl;
                } else if (op == 2) {
                    std::vector<double> el;
                    std::cout << "Ввыбирите обход по которому хотите сохранить дерево в массив : "
                              << std::endl
                              << "1 - klp"
                              << std::endl
                              << "2 - kpl"
                              << std::endl
                              << "3 - lkp"
                              << std::endl
                              << "4 - pkl"
                              << std::endl
                              << "5 - lpk"
                              << std::endl
                              << "6 - plk"
                              << std::endl
                              << "Ваш выбор >> ";
                    int kl;
                    std::cin >> kl;
                    if (kl == 1)
                        el = vec.Klp(0);
                    else if (kl == 2)
                        el = vec.Kpl(0);
                    else if (kl == 3)
                        el = vec.Lkp(0);
                    else if (kl == 4)
                        el = vec.Pkl(0);
                    else if (kl == 5)
                        el = vec.Lpk(0);
                    if (kl == 6)
                        el = vec.Plk(0);
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать вектор"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над деревом"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:el)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                } else if (op == 3) {
                    int pl, len;
                    double jr;
                    std::cout << "Какой размер кучи вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этой кучи: ";
                    double mas[len];
                    for (int i = 0; i < len; i++) {
                        std::cin >> jr;
                        mas[i] = jr;
                    }
                    std::cout << std::endl;
                    if (vec.SearchHeap(mas, length))
                        std::cout << "Данное поддерево найдено!" << std::endl;
                    else std::cout << "Данное поддерево не найдено" << std::endl;
                } else if (op == 4) {
                    std::cout << "Введите индекс >>";
                    double in;
                    std::cin >> in;
                    std::cout << std::endl;
                    std::vector<double> v;
                    v = vec.SeeTree(in);
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать кучу"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над кучей"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:v)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                }

                if (op == 5) {
                    std::cout << "Введите элемент >> ";
                    double pro;
                    std::cin >> pro;
                    vec.Delete(pro);
                }
            }
        }
        std::cout << "1 - чтобы показать дерево"
                  << std::endl
                  << "2 - операции над деревом"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >> ";
        std::cin >> ch;
        std::cout << std::endl;
    }
}


void MenuTreeDouble() {
    int length;
    std::cout << "Введите кол-во элементов >>";
    std::cin >> length;
    double mas[length];
    std::cout << "Введите число :";
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    BinTree<double> vec = BinTree<double>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать дерево"
              << std::endl
              << "2 - операции над деревом"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >> ";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            Print(vec);
        else if (ch == 2) {
            int op = 1;
            while (op != 0) {
                std::cout << "1 - чтобы добавить в дерево элемент"
                          << std::endl
                          << "2 - чтобы сохранить дерево в вектор по заданному обходу"
                          << std::endl
                          << "3 - чтобы проверить на вхождение дерева"
                          << std::endl
                          << "4 - чтобы проверить на вхождение элемента в дереве"
                          << std::endl
                          << "5 - чтобы ссклеить 2 дерева"
                          << std::endl
                          << "6 - чтобы вывести максимальный элемент дерева"
                          << std::endl
                          << "7 - чтобы вывести минимальный элемент дерева"
                          << std::endl
                          << "0 - чтобы выйти"
                          << std::endl
                          << "Ваш выбор >> ";
                std::cin >> op;
                std::cout << std::endl;
                if (op == 1) {
                    double l;
                    std::cout << "Введите элемент >> ";
                    std::cin >> l;
                    std::cout << std::endl;
                    vec.Insert(l);
                    std::cout << "Элемент добавлен!" << std::endl;
                } else if (op == 2) {
                    std::vector<double> el;
                    std::cout << "Ввыбирите обход по которому хотите сохранить дерево в массив : "
                              << std::endl
                              << "1 - klp"
                              << std::endl
                              << "2 - kpl"
                              << std::endl
                              << "3 - lkp"
                              << std::endl
                              << "4 - pkl"
                              << std::endl
                              << "5 - lpk"
                              << std::endl
                              << "6 - plk"
                              << std::endl
                              << "Ваш выбор >> ";
                    double kl;
                    std::cin >> kl;
                    if (kl == 1)
                        el = vec.ToVector("klp");
                    else if (kl == 2)
                        el = vec.ToVector("kpl");
                    else if (kl == 3)
                        el = vec.ToVector("lkp");
                    else if (kl == 4)
                        el = vec.ToVector("pkl");
                    else if (kl == 5)
                        el = vec.ToVector("lpk");
                    if (kl == 6)
                        el = vec.ToVector("plk");
                    std::cout << std::endl
                              << "Вы можете воспользоваться вектором!"
                              << std::endl
                              << " Нажмите 1, чтобы показать вектор"
                              << std::endl
                              << "0 - чтобы вернуться к операциям над деревом"
                              << std::endl
                              << "Ваш выбор >> ";
                    int k;
                    std::cin >> k;
                    if (k == 1) {
                        std::cout << "Вектор: ";
                        for (auto j:el)
                            std::cout << j << ' ';
                        std::cout << std::endl;
                    }
                } else if (op == 3) {
                    int pl, len;
                    double jr;
                    std::vector<double> v;
                    std::cout << "Какого размера дерева вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этого дерева: ";
                    for (int i = 0; i < len; i++) {
                        std::cin >> jr;
                        v.push_back(jr);
                    }
                    std::cout << std::endl;
                    std::cout << "Введите корень этого дерева >>";
                    double data;
                    std::cin >> data;
                    std::cout << std::endl;
                    if (vec.Search_Tree(v, data))
                        std::cout << "Данное поддерево найдено!" << std::endl;
                    else std::cout << "Данное поддерево не найдено" << std::endl;
                } else if (op == 4) {
                    std::cout << "Введите элемент >>";
                    double in;
                    std::cin >> in;
                    std::cout << std::endl;
                    if (vec.Contains(in) != nullptr)
                        std::cout << "Данный элемент найден!" << std::endl;
                    else std::cout << " Данного элемента в дереве нет!" << std::endl;
                } else if (op == 5) {
                    int pl, len;
                    double jr;
                    std::vector<double> v;
                    std::cout << "Какого размера дерева вы хотите проверить на вхождение >> ";
                    std::cin >> len;
                    std::cout << "Введите элементы этого дерева: ";
                    for (int i = 0; i < len; i++) {
                        std::cin >> jr;
                        v.push_back(jr);
                    }
                    BinTree<double> v2 = BinTree<double>(v);
                    vec.Concat(v2);
                    std::cout << "Данное дерево построено!" << std::endl;
                } else if (op == 6) {
                    std::cout << "Максимальный элемент: " << vec.getMaxNode() << std::endl;
                } else if (op == 7) {
                    std::cout << "Минимальный элемент: " << vec.getMinNode() << std::endl;
                } else if (op == 8) {
                    int k;
                    std::cout << "Введите элемент, который хотите удалить >> ";
                    std::cin >> k;
                    vec.Delete(k);
                    std::cout << std::endl;
                }
            }
        }
        std::cout << "1 - чтобы показать дерево"
                  << std::endl
                  << "2 - операции над деревом"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >> ";
        std::cin >> ch;
        std::cout << std::endl;
    }
}


void MenuTree() {
    int k;
    std::cout << "Какой тип данных вы хотите использовать?"
              << std::endl
              << "1 - чтобы использовать целые числа"
              << std::endl
              << "2 - чтобы использовать вещественные числа"
              << std::endl
              << "3 - чтобы использовать структуру студенты"
              << std::endl
              << "0 - чтобы выйти"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> k;
    std::cout << std::endl;
    if (k == 1)
        MenuTreeInt();
    else if (k == 2)
        MenuTreeDouble();
    else if (k == 3)
        MenuTreePerson();
}

void MenuHeap() {
    int k;
    std::cout << "Какой тип данных вы хотите использовать?"
              << std::endl
              << "1 - чтобы использовать целые числа"
              << std::endl
              << "2 - чтобы использовать вещественные числа"
              << std::endl
              << "3 - чтобы использовать структуру студенты"
              << std::endl
              << "0 - чтобы выйти"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> k;
    std::cout << std::endl;
    if (k == 1)
        MenuHeapInt();
    else if (k == 2)
        MenuHeapDouble();
    else if (k == 3)
        MenuHeapPerson();
}


void Menu() {
    std::cout << "1 - чтобы использовать дерево"
              << std::endl
              << "2 - чтобы использовать кучу"
              << std::endl
              << "Ваш выбор >>";
    int k;
    std::cin >> k;
    if (k == 1)
        MenuTree();
    if (k == 2)
        MenuHeap();
}



