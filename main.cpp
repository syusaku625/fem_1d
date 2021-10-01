#include <iostream>
#include <vector>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
    vector<double> x = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    vector<double> u(11, 0.0);
    u[0]=1.0;
    double lambda=0.2;
    vector<vector<int>> element(10, vector<int>(2));
    element[0][0]=0; element[0][1]=1;
    element[1][0]=1; element[1][1]=2;
    element[2][0]=2; element[2][1]=3;
    element[3][0]=3; element[3][1]=4;
    element[4][0]=4; element[4][1]=5;
    element[5][0]=5; element[5][1]=6;
    element[6][0]=6; element[6][1]=7;
    element[7][0]=7; element[7][1]=8;
    element[8][0]=8; element[8][1]=9;
    element[9][0]=9; element[9][1]=10;

    double N=0.1/2.0*lambda;
    double dNdx_1 = 10.0;
    double dNdx_2 = -10.0;

    //マトリックスの組み立て
    vector<vector<double>> global_matrix(u.size(), vector<double>(u.size()));
    for(int i=0; i<global_matrix.size(); i++){
        for(int j=0; j<global_matrix[i].size(); j++){
            global_matrix[i][j]=0.0;
        }
    }
    for(int i=0; i<element.size(); i++){
        global_matrix[element[i][0]][element[i][0]] += dNdx_1;
        global_matrix[element[i][0]][element[i][1]] += dNdx_2;
        global_matrix[element[i][1]][element[i][0]] += dNdx_2;
        global_matrix[element[i][1]][element[i][1]] += dNdx_1;
    }

    vector<double> b_vector(u.size(),0.0);
    for(int i=0; i<element.size(); i++){
        b_vector[element[i][0]] += -N;
        b_vector[element[i][1]] += -N;
    }   

    //境界条件の導入
    for(int i=0; i<u.size(); i++){
        global_matrix[0][i] = 0.0;
    }
    global_matrix[0][0] = 1.0;
    b_vector[0]=1.0;

    //連立方程式ソルバー
    int count=1;
    while(1){
        vector<double> u_tmp(u.size(),0.0);
        for(int j=0; j<u_tmp.size(); j++){
            u_tmp[j]=b_vector[j];
        }

        for(int j=0; j<u.size(); j++){
            for(int k=0; k<u.size(); k++){
                if(j!=k){
                    u_tmp[j]-=global_matrix[j][k]*u[k];
                }
            }
            u_tmp[j]/=global_matrix[j][j];
        }
        double error=0;
        for(int j=0; j<u.size(); j++){
            error+=fabs(u[j]-u_tmp[j]);
        }
        cout << "iter : " << count << "  " << "error : " << error << endl;
        for(int j=0; j<u.size(); j++){
            u[j]=u_tmp[j];
        }
        u[0]=1.0;
        if(error<1e-5){
            break;
        }
        count++;
    }

    //出力
    ofstream ofs("output_0.2.dat");
    for(int i=0; i<u.size(); i++){
        ofs << u[i] << endl;
    }
    ofs.close();
}