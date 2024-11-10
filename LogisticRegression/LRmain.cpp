#include "LogisticRegression.cpp"






int runLogisticRegression(){

    // Data PreProcessing
    
    std::pair<IntMatrix, IntMatrix> result = parse_csv_LR();
    IntMatrix X = result.first;
    IntMatrix Y = result.second;
    std::cout << " - > The Predictor variable and the parameters have been obtained!" << std::endl;

    // Splitting Data into Training and Testing sets
    
    IntMatrix X_train, X_test, Y_train, Y_test;
    for (int i = 0; i < 768; i++){
        if (i < 600){
            X_train.push_back(X[i]);
            Y_train.push_back(Y[i]);
        }
        else{   
            X_test.push_back(X[i]);
            Y_test.push_back(Y[i]);
        }
    }

    std::cout << " - > The Data has been split into Training and Testing Data " << std::endl;


    // Performing Logistic Regression

    LogisticRegression LR(0.01, 1000);

    std::cout << " - > Fitting the Data!" << std::endl;

    LR.fit(X_train, Y_train);

    std::cout << " -> Predicting the Values!" << std::endl;

    IntMatrix Yhat = LR.predict(X_test);



    // Displaying the Confusion matrix

    int correctly_predicted = 0;
    int predicted_1_correctly = 0;
    int predicted_1_incorrectly = 0;
    
    for (int i = 0 ; i < Yhat.size() ; i ++){
        if (Yhat[i][0] == Y_test[i][0]){
            correctly_predicted += 1;
            if (Yhat[i][0] == 1){
                predicted_1_correctly+=1;
            }
        }
        else {
            if (Yhat[i][0] == 1){
                predicted_1_incorrectly+=1;
            }
        }
    }
    float correct = correctly_predicted;
    std::cout << "Accuracy: " << float(correct/169)*100 <<"%"<< std::endl;
    std::cout << "Confusion matrix:" << std::endl;
    std::cout << "  predicted correctly  predicted incorrectly" << std::endl;
    std::cout << "0         " << correctly_predicted - predicted_1_correctly <<"                  "<< 169 - correctly_predicted - predicted_1_incorrectly << std::endl;
    std::cout << "1         " << predicted_1_correctly <<"                  "<< predicted_1_incorrectly << std::endl; 
    
    

    
    return 0;

}
