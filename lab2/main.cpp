#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "menu.h"
#include "tests.h"
#include <complex>


using namespace std;

int main() {
    test_constructor1();
    test_constructor2();
    test_constructor3();
    test_resize();
    test_Append();
    test_getlength();
    test_prepend();
    test_insertat();
    test_Get();
    test_prep();
    test_append();
    test_constr1();
    test_constr2();
    test_Getl();
    test_Getfirst();
    test_Getlast();
    test_InsAt();
    test_matconstructor1();
    test_matsum();
    test_matraz();
    test_stbsum();
    test_stbraz();
    test_get();
    test_norm();
    test_matconstructor2();
    test_matconstructor3();
    test_Getv();
    test_vconstructor1();
    test_vconstructor2();
    test_vconstructor3();
    test_vlength();
    test_mult_by_number();
    test_normv();
    menu();
        return 0;
}