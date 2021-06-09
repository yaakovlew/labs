//
// Created by andre on 28.05.2021.
//
#pragma once
#ifndef UNTITLED1_BINHEAP_H
#define UNTITLED1_BINHEAP_H

#include <algorithm>
#include <vector>
#include <optional>
#include "Tree.h"


class ElementDoesntExist {
};

template<typename T>
class Heap {


public:


    Heap(T *mas, int length) {
        for (int i = 0; i < length; i++)
            Add(mas[i]);
    }


    Heap(const Heap<T> &el) {
        Length = el.Length;
        for (int i = 0; i < el.GivePresents().size(); i++) {
            present.push_back(el.GivePresents()[i]);
            v.push_back(el.GiveElements()[i]);
        }

    }


    std::vector<bool> GivePresents() const {
        return present;
    }


    std::vector<T> GiveElements() const {
        return v;
    }


    Heap(std::vector<T> vec) {
        for (auto k:vec)
            Add(k);
    }


    Heap() {}


    std::vector<int> ToVector(int index) {
        std::vector<T> el;
        el.push_back(index);
        Klp(0, [&el](T data) {
            el.push_back(data);
        });
    }


    void Add(T n) {
        v.push_back(n);
        present.push_back(true);
        sort(v.begin(), v.end(), [](T a, T b) {
                 return a > b;
             }
        );
    }


    void Delete(T elemet) {
        int i = 0;
        while ((v[i] > elemet || v[i] < elemet) && i != v.size())
            i++;
        if (v[i] > elemet || v[i] < elemet) throw ElementDoesntExist();
        else present[i] = false;
        Length--;
    }


    int SearchIndex(T elem) {
        int i = 0;
        while ((v[i] > elem || elem > v[i]) && i != v.size())
            i++;
        if (v[i] > elem || elem > v[i]) {
            throw ElementDoesntExist();
            return (-1);
        } else return i;
    }


    std::vector<T> Klp(int index) {
        std::vector<T> elem;
        elem.push_back(v[0]);
        Klp(index, [&elem](T data) {
            elem.push_back(data);
        });
        return elem;
    }


    std::vector<T> Kpl(int index) {
        std::vector<T> elem;
        elem.push_back(v[0]);
        Kpl(index, [&elem](T data) {
            elem.push_back(data);
        });
        return elem;
    }


    std::vector<T> Lpk(int index) {
        std::vector<T> elem;
        Lpk(index, [&elem](T data) {
            elem.push_back(data);
        });
        elem.push_back(v[0]);
        return elem;
    }


    std::vector<T> Plk(int index) {
        std::vector<T> elem;
        Plk(index, [&elem](T data) {
            elem.push_back(data);
        });
        elem.push_back(v[0]);
        return elem;
    }


    std::vector<T> Pkl(int index) {
        std::vector<T> elem;
        Pkl(index, [&elem](T data) {
            elem.push_back(data);
        });
        return elem;
    }


    std::vector<T> Lkp(int index) {
        std::vector<T> elem;
        Lkp(index, [&elem](T data) {
            elem.push_back(data);
        });
        return elem;
    }


    std::vector<T> SeeTree(int index){
        std:: vector r = Klp(index);
        std::vector<T> lem(r.size());
        if (index != 0) {
            for (int i = 0; i < lem.size(); i++)
                lem[i] = r[i];
            lem[0] = v[index];
            return lem;
        }
        else return r;
    }



    bool SearchHeap(T* mas,int length){
        int index = SearchIndex(mas[0]);
        std::vector<T> el = SeeTree(index);
        std::vector<T> el1;
        sort(el.begin(), el.end());
        for(int i = 0; i < length; i++)
            el1.push_back(mas[i]);
        sort(el1.begin(), el1.end());
        bool flag = true;
        for (int i = 0; i < length; i++) {
                if (el[i] != el1[i])
                    flag = false;
        }
            return flag;
    }


    bool SearchHeap(std::vector<T> mas){
        int index = SearchIndex(mas[0]);
        std::vector<T> el = SeeTree(index);
        std::vector<T> el1;
        sort(el.begin(), el.end());
        for(int i = 0; i < mas.size(); i++)
            el1.push_back(mas[i]);
        sort(el1.begin(), el1.end());
        bool flag = true;
        for (int i = 0; i < mas.size(); i++) {
            if (el[i] > el1[i] || el1[i] > el[i])
                flag = false;
        }
        return flag;
    }




private:


    std::vector<T> v;
    std::vector<bool> present;
    int Length;


    void Klp(int index, std::function<void(T)> f) {
        index = 2 * index;
        if (index >= v.size())
            return;
        if (index + 1 < v.size()){
            index++;
            if (present[index] == true){
                f(v[index]);
                Klp(index, f);
            }
        }
        if (index + 1 < v.size()){
            index++;
            if (present[index] == true){
                f(v[index]);
                Klp(index, f);
            }
        }
    }


    void Kpl(int index, std::function<void(T)> f) {
        index = 2 * index;
        if (index >= v.size())
            return;
        index = index + 2;
        if (index < v.size()){
            if (present[index] == true){
                f(v[index]);
                Kpl(index, f);
            }
        }
        index--;
        if (index < v.size()){
            if (present[index] == true){
                f(v[index]);
                Kpl(index, f);
            }
        }
    }


    void Plk(int index, std::function<void(T)> f) {
        index = 2 * index;
        if (index >= v.size())
            return;
        index = index + 2;
        if (index < v.size()){
            if (present[index] == true){
                f(v[index]);
                Plk(index, f);
            }
        }
        index--;
        if (index < v.size()){
            if (present[index] == true){
                f(v[index]);
                Plk(index, f);
            }
        }
    }


    void Lpk(int index, std::function<void(T)> f) {
        index = 2 * index;
        if (index >= v.size())
            return;
        if (index + 1 < v.size()){
            index++;
            if (present[index] == true){
                f(v[index]);
                Lpk(index, f);
            }
        }
        if (index + 1 < v.size()){
            index++;
            if (present[index] == true){
                f(v[index]);
                Lpk(index, f);
            }
        }
    }


    void Pkl(int index, std::function<void(T)> f) {
        index = 2 * index;
        if (index >= v.size())
            return;
        index = index + 2;
        if (index < v.size()){
            if (present[index] == true){
                f(v[index]);
                Pkl(index, f);
            }
        }
        index--;
        if (index == 1)
            f(v[0]);
        if (index < v.size()){
            if (present[index] == true){
                f(v[index]);
                Pkl(index, f);
            }
        }
    }


    void Lkp(int index, std::function<void(T)> f) {
        index = 2 * index;
        if (index >= v.size())
            return;
        if (index + 1 < v.size()){
            index++;
            if (present[index] == true){
                f(v[index]);
                Lkp(index, f);
            }
            if (index == 1)
                f(v[0]);
        }
        if (index + 1 < v.size()){
            index++;
            if (present[index] == true){
                f(v[index]);
                Lkp(index, f);
            }
        }
    }
};


#endif //UNTITLED1_BINHEAP_H
