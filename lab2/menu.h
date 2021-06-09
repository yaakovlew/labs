//
// Created by andre on 16.05.2021.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H


std::ostream& operator<< (std::ostream &out, const std::complex<double> &element){
    if (element.real() != 0) out<<element.real();
    if (element.real() != 0 && element.imag() != 0) out<<" + ";
    if (element.imag() != 0) out<< element.imag()<<" * i";
    return out;
}


void Menu_vectorcomplex(){
    int length;
    std::cout << "Размерность линейного пространства >>";
    std::cin >> length;
    std::complex<double> mas[length];
    std::cout << "Введите координаты вектора :";
    std::cout << std::endl;
    double a,b;
    std::cout<<"Введите дейтсвительную и мнимую часть числа"<<std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "[ " << i + 1 << " ] :";
        std::cout<<"Действительная часть >>";
        std::cin >> a;
        std::cout<<"Мнимая часть >>";
        std::cin>> b;
        std::cout<<std::endl;
        mas[i] = {a , b};
    }
    std::complex<double> elem;
    Vector<std::complex<double>> vec = Vector<std::complex<double>>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать вектор"
              << std::endl
              << "2 - операции над вектором"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            std::cout << vec <<std::endl;
        else if (ch == 2) {
            int op = 1;
            while (op != 0){
                std::cout<<"1 - чтобы умножить вектор на число"
                         << std::endl
                         <<"2 - чтобы сложить с другим вектором"
                         <<std::endl
                         <<"3 - чтобы вычесть другой вектор"
                         <<std::endl
                         <<"4 - найти скалярное произведение"
                         <<std::endl
                         <<"0 - чтобы выйти"
                         <<std::endl
                         <<"Ваш выбор >>";
                std::cin>>op;
                std::cout<<std::endl;
                if (op == 1) {
                    double element;
                    std::cout<<"Введите число на которое будет умножен вектор>>";
                    std::cin>>element;
                    vec.Multip_by_number(element);
                    std::cout<<std::endl;
                }
                else
                if (op == 2){
                    int i,j,length1;
                    std::cout<<"Введите длину второго вектора >>";
                    std::cin>>length1;
                    std::complex<double> mas1[length1];
                    for (int k = 0; k < length1; k++) {
                        std::cout<<"[ "<<k + 1<<" ] : ";
                        std::cout<<"Действительная часть >>";
                        std::cin >> a;
                        std::cout<<"Мнимая часть >>";
                        std::cin>> b;
                        std::cout<<std::endl;
                        mas1[k] = {a , b};
                    }
                    Vector<std::complex<double>> vec2 = Vector<std::complex<double>>(mas1, length1);
                    vec = vec + vec2;
                }
                else
                if (op == 3){
                    int i,j,length1;
                    std::cout<<"Введите длину второго вектора >>";
                    std::cin>>length1;
                    std::complex<double> mas1[length1];
                    for (int k = 0; k < length1; k++) {
                        std::cout<<"[ "<<k + 1<<" ] : ";
                        std::cout<<"Действительная часть >>";
                        std::cin >> a;
                        std::cout<<"Мнимая часть >>";
                        std::cin>> b;
                        std::cout<<std::endl;
                        mas1[k] = {a , b};
                    }
                    Vector<std::complex<double>> vec2 = Vector<std::complex<double>>(mas1, length1);
                    vec = vec - vec2;
                }
                else
                if (op == 4){
                    int i,j,length1;
                    std::cout<<"Введите длину второго вектора >>";
                    std::cin>>length1;
                    std::complex<double> mas1[length1];
                    for (int k = 0; k < length1; k++) {
                        std::cout<<"[ "<<k + 1<<" ] : ";
                        std::cout<<"Действительная часть >>";
                        std::cin >> a;
                        std::cout<<"Мнимая часть >>";
                        std::cin>> b;
                        std::cout<<std::endl;
                        mas1[k] = {a , b};
                    }
                    Vector<std::complex<double>> vec2 = Vector<std::complex<double>>(mas1, length1);
                    std::complex<double> el = vec * vec2;
                    std::cout <<"Скалярное произведение: ";
                    std::cout<<el << std::endl;
                }
            }
        }
        std::cout << "1 - чтобы показать вектор"
                  << std::endl
                  << "2 - операции над вектором"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >>";
        std::cin >> ch;
        std::cout<<std::endl;
    }

}


void Menu_vectorint() {
    int length;
    std::cout << "Размерность линейного пространства >>";
    std::cin >> length;
    int mas[length];
    std::cout << "Введите координаты вектора :";
    std::cout << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    Vector<int> vec = Vector<int>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать вектор"
              << std::endl
              << "2 - операции над вектором"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            std::cout << vec <<std::endl;
        else if (ch == 2) {
            int op = 1;
            while (op != 0){
                std::cout<<"1 - чтобы найти норму вектора"
                         <<std::endl
                         <<"2 - чтобы умножить вектор на число"
                         << std::endl
                         <<"3 - чтобы сложить i-ый столбец с j-ым столбцом"
                         << std::endl
                         <<"4 - чтобы сложить i-ую строку с j-ой стрококй"
                         <<std::endl
                         <<"5 - чтобы вычесть из i-ого столбца с j-ый столбец"
                         <<std::endl
                         <<"6 - чтобы вычесть из i-ой строки j-ую строку"
                         <<std::endl
                         <<"7 - чтобы сложить с другим вектором"
                         <<std::endl
                         <<"8 - чтобы вычесть другой вектор"
                         <<std::endl
                         <<"9 - найти скалярное произведение"
                         <<std::endl
                         <<"0 - чтобы выйти"
                         <<std::endl
                         <<"Ваш выбор >>";
                std::cin>>op;
                std::cout<<std::endl;
                if (op == 1) std::cout<<"Норма вектора :"<<vec.Norm()<<std::endl;
                else
                    if (op == 2) {
                        double element;
                        std::cout<<"Введите число на которое будет умножен вектор>>";
                        std::cin>>element;
                        vec.Multip_by_number(element);
                        std::cout<<std::endl;
                    }
                    else
                        if (op == 7){
                            int i,j,length1;
                            std::cout<<"Введите длину второго вектора >>";
                            std::cin>>length1;
                            int mas1[length1];
                            for (int k = 0; k < length1; k++) {
                                std::cout<<"[ "<<k<<" ] :";                                std::cin >> mas1[k];
                            }
                            Vector<int> vec2 = Vector<int>(mas1, length1);
                            vec = vec + vec2;
                        }
                        else
                            if (op == 8){
                                int i,j,length1;
                                std::cout<<"Введите длину второго вектора >>";
                                std::cin>>length1;
                                int mas1[length1];
                                for (int k = 0; k < length1; k++) {
                                    std::cout<<"[ "<<k<<" ] :";                                std::cin >> mas1[k];
                                }
                                Vector<int> vec2 = Vector<int>(mas1, length1);
                                vec = vec - vec2;
                            }
                            else
                            if (op == 9){
                                int i,j,length1;
                                std::cout<<"Введите длину второго вектора >>";
                                std::cin>>length1;
                                int mas1[length1];
                                for (int k = 0; k < length1; k++) {
                                    std::cout<<"[ "<<k<<" ] :";                                std::cin >> mas1[k];
                                }
                                Vector<int> vec2 = Vector<int>(mas1, length1);
                                std::cout <<"Скалярное произведение: " <<vec * vec2 << std::endl;
                            }
            }
        }
        std::cout << "1 - чтобы показать вектор"
                  << std::endl
                  << "2 - операции над вектором"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >>";
        std::cin >> ch;
        std::cout<<std::endl;
    }
}


void Menu_matrixint(){
        int length;
        std::cout << "Введите размер строки или столбца квадратной матрицы >>";
        std::cin >> length;
        int mas[length * length];
        std::cout << "Введите значения элементов матриц :";
        std::cout << std::endl;
        for (int i = 0; i < length * length; i++) {
            std::cout << "[ " << i / length + 1<< " ] "<< "[ " << i % length + 1<< " ] :";
            std::cin >> mas[i];
            std::cout << std::endl;
        }
        Matrix<int> vec = Matrix<int>(mas, length);
        int ch = -1;
        std::cout << "1 - чтобы показать матрицу"
                  << std::endl
                  << "2 - операции над матрицой"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >>";
        std::cin >> ch;
        while (ch != 0) {
            if (ch == 1)
                std::cout << vec <<std::endl;
            else if (ch == 2) {
                int op = 1;
                while (op != 0){
                    std::cout<<"1 - чтобы найти норму матрицы"
                             <<std::endl
                             <<"2 - чтобы умножить матрицу на число"
                             << std::endl
                             <<"3 - чтобы сложить i-ый столбец с j-ым столбцом"
                             << std::endl
                             <<"4 - чтобы сложить i-ую строку с j-ой стрококй"
                             <<std::endl
                             <<"5 - чтобы вычесть из i-ого столбца с j-ый столбец"
                             <<std::endl
                             <<"6 - чтобы вычесть из i-ой строки j-ую строку"
                             <<std::endl
                             <<"7 - чтобы сложить с другой матрицей"
                             <<std::endl
                             <<"8 - чтобы вычесть другую матрицу"
                             <<std::endl
                             <<"0 - чтобы выйти"
                             <<std::endl
                             <<"Ваш выбор >>";
                    std::cin>>op;
                    std::cout<<std::endl;
                    if (op == 1) std::cout<<"Норма Матрцы :"<<vec.Norm()<<std::endl;
                    else
                    if (op == 2) {
                        double element;
                        std::cout<<"Введите число на которое будет умножена матрица>>";
                        std::cin>>element;
                        vec.Multip_for_number(element);
                        std::cout<<std::endl;
                    }
                    else
                        if (op == 3){
                            int a,b;
                            std::cout<<"Введите i-ый столбец";
                            std::cin>>a;
                            std::cout<<"Введите j-ый столбец";
                            std::cin>>b;
                            vec.ElemChangeStbSum(a,b);
                        }
                        else
                            if (op == 4){
                                int a,b;
                                std::cout<<"Введите i-ую строку";
                                std::cin>>a;
                                std::cout<<"Введите j-ую строку";
                                std::cin>>b;
                                vec.ElemChangeStrSum(a,b);
                            }
                            else
                            if (op == 5){
                                int a,b;
                                std::cout<<"Введите i-ый столбец";
                                std::cin>>a;
                                std::cout<<"Введите j-ый столбец";
                                std::cin>>b;
                                vec.ElemChangeStbSub(a,b);
                            }
                            else
                            if (op == 6){
                                int a,b;
                                std::cout<<"Введите i-ую строку";
                                std::cin>>a;
                                std::cout<<"Введите j-ую строку";
                                std::cin>>b;
                                vec.ElemChangeStrSub(a,b);
                            }
                    else
                    if (op == 7){
                        int i,j,length1;
                        std::cout<<"Введите размер второй матрицы>>";
                        std::cin>>length1;
                        int mas1[length1 * length1];
                        for (int k = 0; k < length1 * length1; k++) {
                            std::cout << "[ " << k / length1 + 1<< " ] "<< "[ " << k % length1 + 1<< " ] :";
                            std::cin >> mas1[k];
                            std::cout << std::endl;
                        }
                        Matrix<int> vec2 = Matrix<int>(mas1, length1);
                        vec = vec + vec2;
                    }
                    else
                    if (op == 8){
                        int i,j,length1;
                        std::cout<<"Введите размер второй матрицы >>";
                        std::cin>>length1;
                        int mas1[length1 * length1];
                        for (int k = 0; k < length1 * length1; k++) {
                            std::cout << "[ " << k / length1 + 1<< " ] "<< "[ " << k % length1 + 1<< " ] :";
                            std::cin >> mas1[k];
                            std::cout << std::endl;
                        }
                        Matrix<int> vec2 = Matrix<int>(mas1, length1);
                        vec = vec - vec2;
                    }
                }
            }
            std::cout << "1 - чтобы показать матрицу"
                      << std::endl
                      << "2 - операции над матрицой"
                      << std::endl
                      << "0 - чтобы закрыть программу"
                      << std::endl
                      << "Ваш выбор >>";
            std::cin >> ch;
            std::cout<<std::endl;
        }
    }



void Menu_matrixdouble(){
    int length;
    std::cout << "Введите размер строки или столбца квадратной матрицы >>";
    std::cin >> length;
    double mas[length * length];
    std::cout << "Введите значения элементов матриц :";
    std::cout << std::endl;
    for (int i = 0; i < length * length; i++) {
        std::cout << "[ " << i / length + 1<< " ] "<< "[ " << i % length + 1<< " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    Matrix<double> vec = Matrix<double>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать матрицу"
              << std::endl
              << "2 - операции над матрицой"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            std::cout << vec <<std::endl;
        else if (ch == 2) {
            int op = 1;
            while (op != 0){
                std::cout<<"1 - чтобы найти норму матрицы"
                         <<std::endl
                         <<"2 - чтобы умножить матрицу на число"
                         << std::endl
                         <<"3 - чтобы сложить i-ый столбец с j-ым столбцом"
                         << std::endl
                         <<"4 - чтобы сложить i-ую строку с j-ой стрококй"
                         <<std::endl
                         <<"5 - чтобы вычесть из i-ого столбца с j-ый столбец"
                         <<std::endl
                         <<"6 - чтобы вычесть из i-ой строки j-ую строку"
                         <<std::endl
                         <<"7 - чтобы сложить с другой матрицей"
                         <<std::endl
                         <<"8 - чтобы вычесть другую матрицу"
                         <<std::endl
                         <<"0 - чтобы выйти"
                         <<std::endl
                         <<"Ваш выбор >>";
                std::cin>>op;
                std::cout<<std::endl;
                if (op == 1) std::cout<<"Норма Матрцы :"<<vec.Norm()<<std::endl;
                else
                if (op == 2) {
                    double element;
                    std::cout<<"Введите число на которое будет умножена матрица>>";
                    std::cin>>element;
                    vec.Multip_for_number(element);
                    std::cout<<std::endl;
                }
                else
                if (op == 3){
                    int a,b;
                    std::cout<<"Введите i-ый столбец";
                    std::cin>>a;
                    std::cout<<"Введите j-ый столбец";
                    std::cin>>b;
                    vec.ElemChangeStbSum(a,b);
                }
                else
                if (op == 4){
                    int a,b;
                    std::cout<<"Введите i-ую строку";
                    std::cin>>a;
                    std::cout<<"Введите j-ую строку";
                    std::cin>>b;
                    vec.ElemChangeStrSum(a,b);
                }
                else
                if (op == 5){
                    int a,b;
                    std::cout<<"Введите i-ый столбец";
                    std::cin>>a;
                    std::cout<<"Введите j-ый столбец";
                    std::cin>>b;
                    vec.ElemChangeStbSub(a,b);
                }
                else
                if (op == 6){
                    int a,b;
                    std::cout<<"Введите i-ую строку";
                    std::cin>>a;
                    std::cout<<"Введите j-ую строку";
                    std::cin>>b;
                    vec.ElemChangeStrSub(a,b);
                }
                else
                if (op == 7){
                    int i,j,length1;
                    std::cout<<"Введите размер второй матрицы>>";
                    std::cin>>length1;
                    double mas1[length1 * length1];
                    for (int k = 0; k < length1 * length1; k++) {
                        std::cout << "[ " << k / length1 + 1<< " ] "<< "[ " << k % length1 + 1<< " ] :";
                        std::cin >> mas1[k];
                        std::cout << std::endl;
                    }
                    Matrix<double> vec2 = Matrix<double>(mas1, length1);
                    vec = vec + vec2;
                }
                else
                if (op == 8){
                    int i,j,length1;
                    std::cout<<"Введите размер второй матрицы >>";
                    std::cin>>length1;
                    double mas1[length1 * length1];
                    for (int k = 0; k < length1 * length1; k++) {
                        std::cout << "[ " << k / length1 + 1<< " ] "<< "[ " << k % length1 + 1<< " ] :";
                        std::cin >> mas1[k];
                        std::cout << std::endl;
                    }
                    Matrix<double> vec2 = Matrix<double>(mas1, length1);
                    vec = vec - vec2;
                }
            }
        }
        std::cout << "1 - чтобы показать матрицу"
                  << std::endl
                  << "2 - операции над матрицой"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >>";
        std::cin >> ch;
        std::cout<<std::endl;
    }
}


void Menu_matrixcomplex(){
    int length;
    double elem1,elem2;
    std::cout << "Введите размер строки или столбца квадратной матрицы >>";
    std::cin >> length;
    std::complex<double> mas[length * length];
    std::cout << "Введите значения элементов матриц :";
    std::cout << std::endl;
    for (int i = 0; i < length * length; i++) {
        std::cout << "[ " << i / length + 1<< " ] "<< "[ " << i % length + 1<< " ] :";
        std::cout<<"Введите действительную часть >>";
        std::cin >> elem1;
        std::cout<<std::endl;
        std::cout<<"Введите мнимую часть >>";
        std::cin >> elem2;
        mas[i] = {elem1, elem2};
        std::cout << std::endl;
    }
    Matrix<std::complex<double>> vec = Matrix<std::complex<double>>(mas, length);
    int ch = -1;
    std::cout << "1 - чтобы показать матрицу"
              << std::endl
              << "2 - операции над матрицой"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> ch;
    while (ch != 0) {
        if (ch == 1)
            std::cout << vec <<std::endl;
        else if (ch == 2) {
            int op = 1;
            while (op != 0){
                std::cout<<"1 - чтобы умножить матрицу на число"
                         << std::endl
                         <<"2 - чтобы сложить i-ый столбец с j-ым столбцом"
                         << std::endl
                         <<"3 - чтобы сложить i-ую строку с j-ой стрококй"
                         <<std::endl
                         <<"4 - чтобы вычесть из i-ого столбца с j-ый столбец"
                         <<std::endl
                         <<"5 - чтобы вычесть из i-ой строки j-ую строку"
                         <<std::endl
                         <<"6 - чтобы сложить с другой матрицей"
                         <<std::endl
                         <<"7 - чтобы вычесть другую матрицу"
                         <<std::endl
                         <<"0 - чтобы выйти"
                         <<std::endl
                         <<"Ваш выбор >>";
                std::cin>>op;
                std::cout<<std::endl;
                if (op == 1) {
                    double element;
                    std::cout<<"Введите число на которое будет умножена матрица>>";
                    std::cin>>element;
                    vec.Multip_for_number(element);
                    std::cout<<std::endl;
                }
                else
                if (op == 2){
                    int a,b;
                    std::cout<<"Введите i-ый столбец";
                    std::cin>>a;
                    std::cout<<"Введите j-ый столбец";
                    std::cin>>b;
                    vec.ElemChangeStbSum(a,b);
                }
                else
                if (op == 3){
                    int a,b;
                    std::cout<<"Введите i-ую строку";
                    std::cin>>a;
                    std::cout<<"Введите j-ую строку";
                    std::cin>>b;
                    vec.ElemChangeStrSum(a,b);
                }
                else
                if (op == 4){
                    int a,b;
                    std::cout<<"Введите i-ый столбец";
                    std::cin>>a;
                    std::cout<<"Введите j-ый столбец";
                    std::cin>>b;
                    vec.ElemChangeStbSub(a,b);
                }
                else
                if (op == 5){
                    int a,b;
                    std::cout<<"Введите i-ую строку";
                    std::cin>>a;
                    std::cout<<"Введите j-ую строку";
                    std::cin>>b;
                    vec.ElemChangeStrSub(a,b);
                }
                else
                if (op == 6){
                    int i,j,length1;
                    std::cout<<"Введите размер второй матрицы>>";
                    std::cin>>length1;
                    std::complex<double> mas1[length1 * length1];
                    for (int k = 0; k < length1 * length1; k++) {
                        std::cout << "[ " << k / length1 + 1<< " ] "<< "[ " << k % length1 + 1<< " ] :";
                        std::cout<<"Введите действительную часть >>";
                        std::cin >> elem1;
                        std::cout<<std::endl;
                        std::cout<<"Введите мнимую часть >>";
                        std::cin >> elem2;
                        mas1[i] = {elem1, elem2};
                        std::cout << std::endl;
                    }
                    Matrix<std::complex<double>> vec2 = Matrix<std::complex<double>>(mas1, length1);
                    vec = vec + vec2;
                }
                else
                if (op == 7){
                    int i,j,length1;
                    std::cout<<"Введите размер второй матрицы >>";
                    std::cin>>length1;
                    std::complex<double> mas1[length1 * length1];
                    for (int k = 0; k < length1 * length1; k++) {
                        std::cout << "[ " << k / length1 + 1<< " ] "<< "[ " << k % length1 + 1<< " ] :";
                        std::cout<<"Введите действительную часть >>";
                        std::cin >> elem1;
                        std::cout<<std::endl;
                        std::cout<<"Введите мнимую часть >>";
                        std::cin >> elem2;
                        mas1[i] = {elem1, elem2};
                        std::cout << std::endl;
                    }
                    Matrix<std::complex<double>> vec2 = Matrix<std::complex<double>>(mas1, length1);
                    vec = vec - vec2;
                }
            }
        }
        std::cout << "1 - чтобы показать матрицу"
                  << std::endl
                  << "2 - операции над матрицой"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >>";
        std::cin >> ch;
        std::cout<<std::endl;
    }
}


void Menu_vectordouble() {
    int length;
    std::cout << "Размерность линейного пространства >>";
    std::cin >> length;
    double mas[length];
    std::cout << "Введите координаты вектора :";
    std::cout << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << "[ " << i + 1 << " ] :";
        std::cin >> mas[i];
        std::cout << std::endl;
    }
    Vector<double> vec = Vector<double>(mas, length);
    int ch = -1;

    std::cout << "1 - чтобы показать вектор"
              << std::endl
              << "2 - операции над вектором"
              << std::endl
              << "0 - чтобы закрыть программу"
              << std::endl
              << "Ваш выбор >>";
    std::cin >> ch;

    while (ch != 0) {
        if (ch == 1)
            std::cout << vec <<std::endl;
        else if (ch == 2) {
            int op = 1;
            while (op != 0){
                std::cout<<"1 - чтобы найти норму вектора"
                         <<std::endl
                         <<"2 - чтобы умножить вектор на число"
                         <<std::endl
                         <<"3 - чтобы сложить с другим вектором"
                         <<std::endl
                         <<"4 - чтобы вычесть другой вектор"
                         <<std::endl
                         <<"5 - найти скалярное произведение"
                         <<std::endl
                         <<"0 - чтобы выйти"
                         <<std::endl
                         <<"Ваш выбор >>";
                std::cin>>op;
                std::cout<<std::endl;
                if (op == 1) std::cout<<"Норма вектора :"<<vec.Norm()<<std::endl;
                else
                if (op == 2) {
                    double element;
                    std::cout<<"Введите число на которое будет умножен вектор>>";
                    std::cin>>element;
                    vec.Multip_by_number(element);
                    std::cout<<std::endl;
                }
                else
                if (op == 3){
                    int i,j,length1;
                    std::cout<<"Введите длину второго вектора >>";
                    std::cin>>length1;
                    double mas1[length1];
                    for (int k = 0; k < length1; k++) {
                        std::cout<<"[ "<<k<<" ] :";                                std::cin >> mas1[k];
                    }
                    Vector<double> vec2 = Vector<double>(mas1, length1);
                    vec = vec + vec2;
                }
                else
                if (op == 4){
                    int i,j,length1;
                    std::cout<<"Введите длину второго вектора >>";
                    std::cin>>length1;
                    double mas1[length1];
                    for (int k = 0; k < length1; k++) {
                        std::cout<<"[ "<<k<<" ] :";                                std::cin >> mas1[k];
                    }
                    Vector<double> vec2 = Vector<double>(mas1, length1);
                    vec = vec - vec2;
                }
                else
                if (op == 5){
                    int i,j,length1;
                    std::cout<<"Введите длину второго вектора >>";
                    std::cin>>length1;
                    double mas1[length1];
                    for (int k = 0; k < length1; k++) {
                        std::cout<<"[ "<<k<<" ] :";                                std::cin >> mas1[k];
                    }
                    Vector<double> vec2 = Vector<double>(mas1, length1);
                    std::cout <<"Скалярное произведение: " <<vec * vec2 << std::endl;
                }
            }
        }
        std::cout << "1 - чтобы показать вектор"
                  << std::endl
                  << "2 - операции над вектором"
                  << std::endl
                  << "0 - чтобы закрыть программу"
                  << std::endl
                  << "Ваш выбор >>";
        std::cin >> ch;
        std::cout<<std::endl;
    }
}

void Menu_matrix(){
    std::cout<<"Какой тип данных вы хотите использовать"
             <<std::endl
             <<"Нажмите 1, чтобы использовать целые числа"
             <<std::endl
             <<"Нажмите 2, чтобы использовать вещественные числа"
             <<std::endl
             <<"Нажмите 3, чтобы использовать комплексные числа"
             <<std::endl
             <<"Нажмите 0, чтобы выйти"
             <<std::endl
             <<"Ваш выбор >>";
    int ch;
    std::cin>>ch;
    if (ch == 1)
        Menu_matrixint();
    else
    if (ch == 2)
        Menu_matrixdouble();
    else
    if (ch == 3)
        Menu_matrixcomplex();

}


void Menu_vector(){
    std::cout<<"Какой тип данных вы хотите использовать"
             <<std::endl
             <<"Нажмите 1, чтобы использовать целые числа"
             <<std::endl
             <<"Нажмите 2, чтобы использовать вещественные числа"
             <<std::endl
             <<"Нажмите 3, чтобы использовать комплексные числа"
             <<std::endl
             <<"Нажмите 0, чтобы выйти"
             <<std::endl
             <<"Ваш выбор >>";
    int ch;
    std::cin>>ch;
    if (ch == 1)
        Menu_vectorint();
    else
        if (ch == 2)
            Menu_vectordouble();
        else
            if (ch == 3)
                Menu_vectorcomplex();

}


void menu(){
    int first_step;
    std::cout<<"Чтобы использовать вектор, нажмите 1, для использования матрицы нажмите 2, чтобы выйти нажмите любую клавишу "<<std::endl<<"Ваш выбор >> ";
    std::cin>>first_step;
    if (first_step == 1)
        Menu_vector();
    else
        if (first_step == 2)
            Menu_matrix();
}



#endif //UNTITLED_MENU_H
