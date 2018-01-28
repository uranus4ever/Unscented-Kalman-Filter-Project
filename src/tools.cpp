#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
    * Calculate the RMSE here.
  */
    VectorXd rmse(4);
    rmse << 0, 0, 0, 0;

    // check the validity of the following inputs:
    // * the estimation vector size should not be zero
    // * the estimation vector size should equal ground truth vector size
    if(estimations.size() != ground_truth.size()){
        cout << "Invalid estimation or ground_truth data. Should have the same size" << endl;
        return rmse;
    }
    if(estimations.size() == 0){
        cout << "Input is empty" << endl;
        return rmse;
    }

    //Accumulate squared residuals
    for(unsigned int i=0; i < estimations.size(); ++i){
        VectorXd residual = estimations[i] - ground_truth[i];

        //Coefficient-wise multiplication
        residual = residual.array()*residual.array();
        rmse += residual;
    }

    //calculate the mean
    rmse = rmse / estimations.size();

    //calculate the squared root
    rmse = rmse.array().sqrt();

    return rmse;
}