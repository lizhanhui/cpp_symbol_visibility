//
// Created by Li Zhanhui on 2021/3/19.
//

#ifndef SAMPLE_CALC_H
#define SAMPLE_CALC_H

#include <string>

#include "calc_export.h"

class CALC_EXPORT_API Calc {
public:
    void greet(const std::string& name);
};

class Foo {
public:
    void bar();
};

#endif//SAMPLE_CALC_H
