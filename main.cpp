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

float Rowdot (intRow Row1, intRow Row2){
    float sum = 0;
    for (int i = 0; i < Row1.size(); i++){
        sum += (Row1[i] * Row2[i]);
    }
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


    // QR Decomposition
    IntMatrix A = FillMatrix();
    IntMatrix B = transpose(A);
    intRow u,e;
    IntMatrix E;

    

    for (int i = 0 ; i < B.size(); i++){
        // Calculating the U
        // Creating a Default Sum row
        printf("\n Finding E%d:\n", i+1);
        intRow Sum;

        for (int j = 0; j < B[i].size(); j++){
            Sum.push_back(0);
        }

        //Building the subtracting part
        for (int j = 0; j < E.size(); j++){
            float temp = Rowdot(B[i], E[j]);
            printf("The dot product is %f\n",temp);
            intRow tempa = Rowmultiply(E[j],temp);
            Sum =  RowadddRow(Sum,tempa);
        }

        printf("\n subtracting ");
        DisplayRow(B[i]);
        DisplayRow(Sum);
        printf("\n");

        u = RowsubRow(B[i],Sum);
        float modu = magnitude(u);
        e = Rowdiv(u,modu);
        E.push_back(e);
    
    }
        printf("Done for Realsies");

        // IntMatrix Q = transpose(E);

        // Constructing R
        IntMatrix R;
        intRow R_row;
        for (int i = 0 ; i < E.size(); i++){
            for (int j = 0; j < E.size(); i++){
            if (i < j){
                R_row.push_back(0);
            }
            else{
                printf("%d %d",j,i);
                int tempr = Rowdot(B[j],E[i]);
                R_row.push_back(tempr);
                }
            }
            R.push_back(R_row);
            R_row.clear();
        }

    

    DisplayMatrix(E);
    printf("\n\n");
    DisplayMatrix(R);





















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