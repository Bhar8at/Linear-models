#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "matrix.h"
#include "matrixui.h"
#include "RowTransform.h"

float magnitude (intRow A){
        float sum = 0;
        for (int i = 0 ; i < A.size(); i++){
            sum += A[i]*A[i];
        }
        sum = sqrt(sum);
        return sum;
    }



int main(){
    // // Opening the File
    // std::ifstream file("Student_Performance.csv");
    // if (!file.is_open()){
    //     std::cerr << "Cannot Open File" << std::endl;
    // }


    // // Processing File Data
    // std::string line;
    // std::string word;
    
    // // Viewing Headers
    // std::cout << "Headers are : "<< std::endl;
    // if  (std::getline(file, line)){
    //     std::stringstream ss(line);
    //     while (std::getline(ss, word, ',')){
    //         std::cout << word << std::endl;
    //     }
    //     std::cout << std::endl;
    // }    

    // IntMatrix X , Y;
    // intRow x , y;
    
    // // Processing CSV file into each vector
    // int index = 0;
    // int linecount = 0;
    // while (std::getline(file, line) && linecount < 10){
    //     index = 0;
    //     std::stringstream ss(line);
        
    //     while(std::getline(ss, word, ',')){
    //         if (index == 5){
    //             y.push_back(stof(word)); 
    //         }
    //         else if (index == 2){
    //             if (word == "Yes"){
    //             x.push_back(1);
    //             }
    //             else{
    //                 x.push_back(0);
    //             }
    //         }
    //         else{
    //             x.push_back(stoi(word));
    //         }
    //         index++;
    //     }
    
    //     linecount++;
    //     X.push_back(x);
    //     Y.push_back(y);
    //     x.clear();
    //     y.clear();
    // }
    


    /* 
    Training the MODEL
    */






















    // // Training Model on Data using Normal Equations (Unstable)
    // std::cout << "Going to compute the transpose of the matrix" << std::endl;
    // IntMatrix Step1 = transpose(X);        // Step 1: Transpose of X
    // IntMatrix Step2 = multiply(Step1, X);  // Step 2: Multiply transpose(X) with X
    // std::cout << " OK ITS not THE MULTIPLY FUNCTION " << std::endl;
    // IntMatrix Step3 = inverse(Step2);      // Step 3: Inverse of the result from Step 2
    // IntMatrix Step4 = multiply(Step3, Step1);  // Step 4: Multiply inverse with transpose(X)
    // IntMatrix B = multiply(Step4, Y);      // Step 5: Multiply the result with Y
    // std::cout << " The parameters are : " <<std::endl;
    // DisplayMatrix(B);
    // IntMatrix Yhat = multiply(X,B);
    // for (int i = 0 ; i < 10 ; i ++){
    //     std::cout << "The Predicted output is " << Yhat[i][0] <<" and the real value is " << Y[i][0] << std::endl; 
    // }


    // // // Testing Inverse
    // IntMatrix x;
    // x = FillMatrix();
    // std::cout << "\n\n" << std::endl;
    // x = inverse(x);
    // std::cout << "\n\n Outputing the Final matrix \n\n" << std::endl;
    // DisplayMatrix(x);


    return 0;

}