//
//  main.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/19.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "execute.hpp"

using namespace std;

void prompt(const int Algo,const int runs,const int iterations);

int main(int argc, const char * argv[]) {
    const string algo = argv[1];
    const int runs = stoi(argv[2]);
    const int iterations = stoi(argv[3]);
    //const int bits = stoi(argv[4]);
    
    string filename= argv[4];
    cout<<"filename: "<<filename<<endl;
    
    const int population = stoi(argv[5]);
    const double w = stod(argv[6]);
    const double a1 = stod(argv[7]);
    const double a2 = stod(argv[8]);
    const int dim = stoi(argv[9]);
    
    if (algo=="pso"){
        prompt(1, runs, iterations);
        execute(1, runs, iterations, filename, population, w, a1, a2, dim);
    }
    else{
        cerr<<"No such algorithm!"<<endl;
    }
    return 0;
}


void prompt(const int Algo,const int runs,const int iterations){
    cout<<"Problem: Ackley's Function"<<endl;
    cout<<"----------------------------------------"<<endl;
    switch (Algo) {
        case 1:
            cout<<"Particle Swarm Optimization:"<<endl;
            break;
        default:
            break;
    }
    cout<<"Runs: "<<runs<<endl;
    cout<<"Iterations: "<<iterations<<endl;
    cout<<"----------------------------------------"<<endl;
}
