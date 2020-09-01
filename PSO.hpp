//
//  PSO.hpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/30.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#ifndef PSO_hpp
#define PSO_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>

#include "Ackley.hpp"

using namespace std;

class PSO{
public:
    PSO();
    PSO(int iterations, int population, double W, double alpha1, double alpha2, int Dim);
    void Ackley();
    void Initialization();
    vector<vector<double> > LocalBestUpdate();
    vector<double> GlobalBestUpdate();
    vector<vector<double> > NewVelocity();
    vector<vector<double> > NewPosition();
    double get_result_value(int iter){return result_value[iter];}
    //vector<vector<double> > get_result(){return result;}
    void LearningRateUpdate();
private:
    int iter;
    int pop;
    double w;
    double a1;
    double a2;
    int dim;
    vector<vector<double> > Pop;
    vector<double> Pop_value;
    
    vector<vector<double> > V;
    
    vector<vector<double> > pbest;
    vector<double> pbest_value;
    vector<double> gbest;
    double gbest_value;
    
    vector<double> result_value;
    vector<vector<double> > result;
};


#endif /* PSO_hpp */
