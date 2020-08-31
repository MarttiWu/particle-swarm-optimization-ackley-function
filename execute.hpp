//
//  execute.hpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/8.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#ifndef execute_hpp
#define execute_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include "PSO.hpp"

using namespace std;

const int block = 10;

void execute(const int Algo,const int runs,const int iterations,const string filename,const int population,const double w,const double a1, const double a2,const int dim);

#endif /* execute_hpp */
