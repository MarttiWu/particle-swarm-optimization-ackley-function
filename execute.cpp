//
//  execute.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/1.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include "execute.hpp"

void execute(const int Algo,const int runs,const int iterations,const string filename,const int population,const double w,const double a1, const double a2,const int dim){
    srand((unsigned)time(NULL));
    vector<double> avg(iterations/block);
    if (filename==""){
        for (int i=0;i<runs;i++){
            cout<<"----------------------------------------"<<endl;
            cout<<"run: "<<i<<endl;
            time_t start=0, end=0;
            if (Algo==1){
                PSO *r = new PSO(iterations, population, w, a1, a2, dim);
                start = time(NULL);
                r->Ackley();
                for (int j=0;j<iterations/block;j++){
                    avg[j] += r->get_result_value(j*block);
                }
                cout<<"Best: "<<r->get_result_value(iterations-1)<<endl;
                cout<<endl;
                end = time(NULL);
            }
            double diff = difftime(end, start);
            cout<<"Run time: "<<diff<<"s"<<endl;
        }
        cout<<"----------------------------------------"<<endl;
        for (int i=0;i<avg.size();i++){
            avg[i]/=runs;
        }
        for (int i=0;i<avg.size();i++){
             cout<<"Iter "<<i*block<<" average: "<<avg[i]<<endl;
        }
    }
    else{
        cout<<"random number file"<<endl;
        //left blank
        //complete when needed
    }
}
