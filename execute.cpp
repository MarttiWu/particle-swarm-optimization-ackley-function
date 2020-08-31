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
    //float avg=0;
    if (filename==""){
        for (int i=0;i<runs;i++){
            cout<<"----------------------------------------"<<endl;
            cout<<"run: "<<i<<endl;
            time_t start=0, end=0;
            if (Algo==1){
                cout<<"exe w: "<<w<<endl;
                cout<<"exe a1: "<<a1<<endl;
                cout<<"exe a2: "<<a2<<endl;
                cout<<"exe dim: "<<dim<<endl;
                PSO *r = new PSO(iterations, population, w, a1, a2, dim);
                start = time(NULL);
                r->Ackley();
                //r->get_result();
                for (int j=0;j<iterations/block;j++){
                    avg[j] += r->get_result_value(j*block);
                }
                cout<<"Best: "<<r->get_result_value(iterations-1)<<endl;
                
                //avg+=r->get_best();
                //cout<<"best: "<<r->get_best()<<endl;
                //cout<<"best route: ";
                //r->print_bestroute();
                //cout<<"to file"<<endl;
                //r->to_file();
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
