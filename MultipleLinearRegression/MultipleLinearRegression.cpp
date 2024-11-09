#include "Data_Preprocessing.cpp"
#include <cmath>    

int MultipleLinearRegression(){

    // Data PreProcessing
    
    std::pair<IntMatrix, IntMatrix> result = parse_csv();
    IntMatrix X = result.first;
    IntMatrix Y = result.second;

    // Splitting Data into Training and Testing sets
    
    IntMatrix X_train, X_test, Y_train, Y_test;
    for (int i = 0; i < 1000; i++){
        if (i < 800){
            X_train.push_back(X[i]);
            Y_train.push_back(Y[i]);
        }
        else{   
            X_test.push_back(X[i]);
            Y_test.push_back(Y[i]);
        }
    }



    // Training Model on Data using Normal Equations 

    IntMatrix Step1 = transpose(X_train);            // Step 1: Transpose of X
    IntMatrix Step2 = multiply(Step1, X_train);      // Step 2: Multiply transpose(X) with X
    IntMatrix Step3 = inverse(Step2);          // Step 3: Inverse of the result from Step 2
    IntMatrix Step4 = multiply(Step3, Step1);  // Step 4: Multiply inverse with transpose(X)
    IntMatrix B = multiply(Step4, Y_train);          // Step 5: Multiply the result with Y
    DisplayMatrix(B);
    IntMatrix Yhat = multiply(X_test,B);
    for (int i = 0 ; i < 10 ; i ++){
        std::cout << "The Predicted output is " << Yhat[i][0] <<" and the real value is " << Y_test[i][0] << std::endl; 
    }


    // Evaluvation using RMSE value 
    float MSE = 0;
    for (int i = 0 ; i < 200; i++){
        MSE = MSE + (Y_test[i][0] - Yhat[i][0]) * (Y_test[i][0] - Yhat[i][0]);
    }
    MSE = MSE / 200;
    float RMSE = sqrtf(MSE);
    std::cout << std::endl;
    std::cout << "The RMSE value is " << RMSE << std::endl;
    
    return 0;

}
