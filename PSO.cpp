//
//  PSO.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/30.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include "PSO.hpp"


PSO::PSO(){
    
}

PSO::PSO(int iterations, int population, double W, double alpha1, double alpha2, int Dim){
    iter = iterations;
    pop = population;
    w = W;
    a1 = alpha1;
    a2 = alpha2;
    dim = Dim;
    vector<vector<double> > temp1(pop,vector<double>(dim,0));
    vector<double> temp2(pop,0);
    vector<double> temp3(dim,0);
    vector<vector<double> > temp4(iter,vector<double>(dim,0));
    vector<double> temp5(iter,0);
    Pop = temp1;
    Pop_value = temp2;
    V = temp1;
    pbest = temp1;
    pbest_value = temp2;
    gbest = temp3;
    gbest_value = 100.0;
    result_value = temp5;
    result = temp4;
    
    //
    cout<<"alpha2: "<<alpha2<<endl;
    cout<<"a2: "<<a2<<endl;
    //
    
    /*
    cout<<"result: "<<endl;
    for (int i=0;i<result.size();i++){
        cout<<i<<": ";
        for (int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
}

void PSO::Ackley(){
    Initialization();
    int it=0;
    double best = 100;
    while(it<iter&&best>0){
        cout<<"learning rate: "<<a1<<" "<<a2<<endl;
        pbest = LocalBestUpdate();
        gbest = GlobalBestUpdate();
        V = NewVelocity();
        Pop = NewPosition();
        
        result[it] = gbest;
        result_value[it] = gbest_value;
        
        //LearningRateUpdate();
        
        it++;
        
    }
}

void PSO::Initialization(){
    for (int i=0;i<Pop.size();i++){
        for (int j=0;j<Pop[0].size();j++){
            //[-30,30]
            Pop[i][j] = (((double)rand())/RAND_MAX-0.5)*60;
            //[-0.5.0.5]
            V[i][j] = (((double)rand())/RAND_MAX-0.5);
            pbest[i][j] = Pop[i][j];
        }
        Pop_value[i] = ack::function(dim,pbest[i]);
        pbest_value[i] = Pop_value[i];
        if (pbest_value[i]<gbest_value)
            gbest_value = pbest_value[i];
    }
}

vector<vector<double> > PSO::LocalBestUpdate(){
    vector<vector<double> > temp(pop,vector<double>(dim,0));
    for (int i=0;i<pbest_value.size();i++){
        if (Pop_value[i]<pbest_value[i]){
            pbest_value[i] = Pop_value[i];
            temp[i] = Pop[i];
        }
    }
    return temp;
}

vector<double> PSO::GlobalBestUpdate(){
    vector<double> temp(dim,0);
    for (int i=0;i<Pop_value.size();i++){
        if (Pop_value[i]<gbest_value){
            gbest_value = Pop_value[i];
            temp = Pop[i];
        }
    }
    return temp;
}

vector<vector<double> > PSO::NewVelocity(){
    vector<vector<double> > temp(pop,vector<double>(dim,0));
    for (int i=0;i<V.size();i++){
        for (int j=0;j<V[0].size();j++){
            temp[i][j] = w*V[i][j] + a1*(((double)rand())/RAND_MAX-0.5)*(pbest[i][j]-Pop[i][j]) + a2*(((double)rand())/RAND_MAX-0.5)*(gbest[j]-Pop[i][j]);
        }
    }
    return temp;
}

vector<vector<double> > PSO::NewPosition(){
    vector<vector<double> > temp(pop,vector<double>(dim,0));
    for (int i=0;i<Pop.size();i++){
        for (int j=0;j<Pop[0].size();j++){
            temp[i][j] = Pop[i][j]+V[i][j];
        }
        Pop_value[i] = ack::function(dim,Pop[i]);
    }
    return temp;
}

void PSO::LearningRateUpdate(){
//    a1*=0.9;
//    a2/=0.9;
    a1/=0.9;
    a2*=0.9;
}
