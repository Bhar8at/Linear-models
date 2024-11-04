#include "Data_Preprocessing.cpp"


int MultipleLinearRegression(){

    // Call parse_csv and capture the returned pair
    std::pair<IntMatrix, IntMatrix> result = parse_csv();

    // Extract X and Y from the pair
    IntMatrix X = result.first;
    IntMatrix Y = result.second;


    // Training Model on Data using Normal Equations (Unstable)
    std::cout << "Going to compute the transpose of the matrix" << std::endl;
    IntMatrix Step1 = transpose(X);        // Step 1: Transpose of X
    IntMatrix Step2 = multiply(Step1, X);  // Step 2: Multiply transpose(X) with X
    std::cout << " OK ITS not THE MULTIPLY FUNCTION " << std::endl;
    IntMatrix Step3 = inverse(Step2);      // Step 3: Inverse of the result from Step 2
    IntMatrix Step4 = multiply(Step3, Step1);  // Step 4: Multiply inverse with transpose(X)
    IntMatrix B = multiply(Step4, Y);      // Step 5: Multiply the result with Y
    std::cout << " The parameters are : " <<std::endl;
    DisplayMatrix(B);
    IntMatrix Yhat = multiply(X,B);
    for (int i = 0 ; i < 10 ; i ++){
        std::cout << "The Predicted output is " << Yhat[i][0] <<" and the real value is " << Y[i][0] << std::endl; 
    }

    // Train Model using Gradient Descent


    return 0;

}
