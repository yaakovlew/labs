//
// Created by andre on 21.05.2021.
//
#pragma once
#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <tuple>


bool operator>(std::function<int(int arg1)> f1, std::function<int(int arg2)> f2) {
    int arg1 = 2;
    int arg2 = 2;
    if (f1(arg1) > f2(arg2))
        return true;
    else
        return false;
}




class Person {
public:
    std::string name = "";
    std::string surname = "";
    int day = 0;
    int month = 0;
    int year = 0;

    /*Person(std::string name, std::string surname, int day, int month, int year)
    {
        this->name = name;
        this->surname = surname;
        this->day = day;
        this->month = month;
        this->year = year;
    }*/
};


std::ostream &operator<<(std::ostream &out, const Person& element) {
    for (auto k:element.surname)
        out<<k;
    std::cout<<" ";
    for (auto k:element.name)
        out<<k;
    out<<"  "
       <<element.day
       <<"."
       <<element.month
       <<"."
       <<element.year;
    return out;
}


bool operator==(const Person& p1, const Person& p2) {
    return (std::tie(p1.year, p1.month, p1.day )
         == std::tie(p2.year, p2.month, p2.day ));
}



bool operator<(const Person& p1, const Person& p2) {
    return (std::tie(p1.year, p1.month, p1.day )
          < std::tie(p2.year, p2.month, p2.day ));
}

bool operator>(const Person& p1, const Person& p2) {
    return (std::tie(p1.year, p1.month, p1.day )
            > std::tie(p2.year, p2.month, p2.day ));
}


class DontExistelement {
};


template<class T>
class BinTree {

public:

    struct Node {
        T element{};
        int height = 0;
        Node *left = nullptr;
        Node *right = nullptr;
    };


    BinTree(std::vector<T> mas) {
        for (int i = 0; i < mas.size(); i++)
            Insert(mas[i]);
    }


    BinTree(T *arr, int length) {
        for (int i = 0; i < length; i++)
            Insert(arr[i]);
    }


    BinTree(const BinTree<T> &elem) {
        Kpl(elem.head, [&](T arg) {
            Insert(arg);
        });
    }


    BinTree() {}


    Node *Get_head() {
        return head;
    }


    std::vector<T> ToVector(const std::string s) const {
        std::vector<T> el;
        auto f = [&el](T arg) {
            el.push_back(arg);
        };
        if (s == "klp")
            Klp(f);
        else if (s == "kpl")
            Kpl(f);
        else if (s == "lpk")
            Lpk(f);
        else if (s == "plk")
            Plk(f);
        else if (s == "lkp")
            Lkp(f);
        else if (s == "pkl")
            Pkl(f);
        return el;
    }


    BinTree<T> Where(std::function<bool(T)> f) {
        std::vector<T> el = ToVector("klp");
        std::vector<T> el1;
        for (auto k:el)
            if (f(k))
                el1.push_back(k);
        BinTree<T> rez = BinTree<T>(el1);
        return rez;
    }


    ~BinTree(){
        Clear(head);
    }


    void Clear(Node* root){
        if (root == nullptr)
            return;
        Clear(root->right);
        Clear(root->left);
        delete root;
    }



    void Concat(const BinTree<T> &el) {
        std::vector<T> mas = el.ToVector("klp");
        for (auto k:mas)
            Insert(k);
    }


    void Klp(std::function<void(T)> f) const {
        Klp(head, f);
    }


    void Kpl(std::function<void(T)> f) const {
        Kpl(head, f);
    }


    void Lpk(std::function<void(T)> f) const {
        Lpk(head, f);
    }


    void Plk(std::function<void(T)> f) const {
        Plk(head, f);
    }


    void Pkl(std::function<void(T)> f) const {
        Pkl(head, f);
    }


    void Lkp(std::function<void(T)> f) const {
        Lkp(head, f);
    }


    void Insert(T data) {
        head = Insert(head, data);
    }


    void map(T(*func)(T)) {
        map(head, *(func));
    }


    T getMaxNode() {
        return getMaxNode(head);
    }


    void Delete(T data){
        Node* ptr = Contains(data);
        if (ptr != nullptr)
            Delete(Parent(head, ptr), ptr);
    }


    T getMinNode() {
        return getMinNode(head);
    }



    Node *Contains(T data) const {
        std::vector<T> el = ToVector("plk");
        int z = 0;
        for (int i = 0; i < el.size(); i++)
            if (el[i] == data)
                z = 1;
            if (z == 1)
                return Contains(head, data);
            else
                return nullptr;

    }


    Node* GetLeft(Node* p){
        return p->left;
    }


    Node* GetRight(Node* p){
        return p->right;
    }


    std::vector<T> CheckTree(T element) {
        if (Contains(element) != nullptr) {
            Node *ptr = Contains(element);
            std::vector<T> lem;
            klp(ptr, [&lem](T data) { lem.push_back(data); });
            return lem;
        } else
            throw DontExistelement();
    }


    unsigned char height(Node *p) {
        return p ? p->height : 0;
    }


    int deferencehight(Node *p) {
        return height(p->right) - height(p->left);
    }


    void fixheight(Node *p) {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }


    Node *rotateright(Node *p) {
        Node *q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }


    Node *rotateleft(Node *q) {
        Node *p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }


    Node *balance(Node *p) {
        fixheight(p);
        if (deferencehight(p) == 2) {
            if (deferencehight(p->right) < 0)
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if (deferencehight(p) == -2) {
            if (deferencehight(p->left) > 0)
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }


    bool Search_Tree(std::vector<T> vec, T koren) {
        Node *ptr = Contains(koren);
        std::vector<T> rez;
        if (ptr != nullptr) {
            Klp(ptr, [&rez](T data) {
                rez.push_back(data);
            });
        }
        std::sort(rez.begin(), rez.end());
        std::sort(vec.begin(), vec.end());
        if (rez.size() != vec.size())
            return false;
        else {
            for (int i = 0; i < rez.size(); i++)
                if (rez[i] != vec[i])
                    return false;
        }
        return true;
    }


private:
    Node *head = nullptr;


    Node *Contains(Node *root, T data) const{
        if (root == nullptr)
            return nullptr;
        if (root->element == data)
            return root;
        else if (root == nullptr)
            return nullptr;
        Node* pl = Contains(root->left, data);
        Node* pr = Contains(root->right, data);
        if (pl != nullptr)
            return pl;
        else if (pr != nullptr)
            return pr;
        else return nullptr;
    }


    Node* Parent(Node* root, Node* elem)const{
        if (root == nullptr)
            return nullptr;
        if (root->right == elem || root->left == elem)
            return root;
        Node* pl = Parent(root->left, elem);
        Node* pr = Parent(root->right, elem);
        if (pl != nullptr)
            return pl;
        else if (pr != nullptr)
            return pr;
        else return nullptr;
    }


    void map(Node *root, T(*func)(T)) {
        if (root == nullptr)
            return;
        root->element = (*func)(root->element);
        mapc(root->left, (*func));
        mapc(root->right, (*func));
    }


    void Klp(Node *root, std::function<void(T)> f) const {
        if (root == nullptr)
            return;
        f(root->element);
        Klp(root->left, f);
        Klp(root->right, f);
    }


    /*void Delete(Node* parent, Node* ptr){
        if (ptr->left == nullptr && ptr->right == nullptr) {
            if (parent->right == ptr){
                parent->right = nullptr;
            }
            else parent->left = nullptr;
        }
        else
        if (ptr->left == nullptr && ptr->right != nullptr){
            if (parent->right == ptr)
                parent->right = ptr->right;
            else parent->left = ptr->right;
        }
        else
        if (ptr->left != nullptr && ptr->right == nullptr){
            if (parent->right == ptr)
                parent->right = ptr->left;
            else parent->left = ptr->left;
        }
        else
        if (ptr->left != nullptr && ptr->right != nullptr){
            if (parent->left == ptr){
                Node* pt = ptr->left;
                while (pt->right != nullptr)
                    pt = pt->right;
                parent->left = pt;
            }
           else
            {
                Node* pt = ptr;
                while (pt->right != nullptr)
                    pt = pt->right;
                parent->right = pt;
            }
        }
    }
*/


    void Delete(Node* parent, Node* child){
        if (parent->left == child)
            parent->left = nullptr;
        else if (parent->right == child)
            parent->right = nullptr;
        if (child->left != nullptr)
            Push_back(head, child->left);
        if (child->right != nullptr)
            Push_back(head, child->right);
    }


    void Kpl(Node *root, std::function<void(T)> f) const {
        if (root == nullptr)
            return;
        f(root->element);
        Kpl(root->right, f);
        Kpl(root->left, f);
    }


    std::vector<T> Where(std::vector<T> el, std::function<bool(T)> f) {
        std::vector<T> mas;
        for (int i = 0; i < el.size(); i++)
            if (f(el[i]) == true)
                mas.push_back(el[i]);
        return mas;
    }


    void Lpk(Node *root, std::function<void(T)> f) const {
        if (root == nullptr)
            return;
        Lpk(root->right, f);
        Lpk(root->left, f);
        f(root->element);
    }


    void Plk(Node *root, std::function<void(T)> f) const {
        if (root == nullptr)
            return;
        Plk(root->left, f);
        Plk(root->right, f);
        f(root->element);
    }


    void Lkp(Node *root, std::function<void(T)> f) const {
        if (root == nullptr)
            return;
        Lkp(root->left, f);
        f(root->element);
        Lkp(root->right, f);
    }


    void Pkl(Node *root, std::function<void(T)> f) const {
        if (root == nullptr)
            return;
        Pkl(root->right, f);
        f(root->element);
        Pkl(root->left, f);
    }


    Node *Insert(Node *p, T k) {
        if (!p) return new Node{k};
        if (k > p->element)
            p->left = Insert(p->left, k);
        else
            p->right = Insert(p->right, k);
        return balance(p);
    }


    Node* Push_back(Node *p, Node* ptr){
        if (!p) return ptr;
        if (ptr->element > p->element)
            p->left = Push_back(p->left, ptr);
        else
            p->right = Push_back(p->right, ptr);
        return balance(p);
    }


    T getMaxNode(Node *root) {
        while (root->left) {
            root = root->left;
        }
        return root->element;
    }


    T getMinNode(Node *root) {
        while (root->right) {
            root = root->right;
        }
        return root->element;
    }
};


#endif //UNTITLED1_TREE_H
