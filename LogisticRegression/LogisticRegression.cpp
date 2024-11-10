#include "Data_Preprocessing.cpp"
#include <cmath>    

class LogisticRegression{
    
    private:
    
    double sigmoid ( double z ) {
        return 1 / (1 + exp(-z));
    }

    void normalize(IntMatrix& X) {
        for (int j = 0; j < X[0].size(); j++) {
            double mean = 0;
            double stddev = 0;
            
            // Calculate mean
            for (int i = 0; i < X.size(); i++) {
                mean += X[i][j];
            }
            mean /= X.size();
            
            // Calculate standard deviation
            for (int i = 0; i < X.size(); i++) {
                stddev += pow(X[i][j] - mean, 2);
            }
            stddev = sqrt(stddev / X.size());
            
            // Normalize
            for (int i = 0; i < X.size(); i++) {
                if (stddev != 0) { // Avoid division by zero
                    X[i][j] = (X[i][j] - mean) / stddev;
                }
            }
        }
    }

    public:
    IntMatrix weights;
    double learning_rate;
    int num_of_iterations;

    LogisticRegression( double learning_rate, int num_of_iterations ){
        
        this->learning_rate = learning_rate;
        this->num_of_iterations = num_of_iterations;

    }

    int fit ( IntMatrix X_train, IntMatrix Y_train ){

        // initialize weights and normalizing the values in the dataset
        // To prevent large values from affecting the weights

        normalize(X_train);
        float dataset_size = X_train.size();
        int number_of_features = X_train[0].size();
        float m = 1 / dataset_size;
        intRow temprow;

        for (int i = 0 ; i < number_of_features; i++){

            temprow.push_back(static_cast<float>(rand()) / RAND_MAX * 0.01);

        }

        weights.push_back(temprow);
        weights = transpose(weights);
        // Gradient Ascent
        for (int i = 0 ; i < num_of_iterations; i++){
            
            IntMatrix predicted_values;
            intRow temprow;
            for (int i = 0; i < dataset_size; i++) {
            
                double z = 0.0;
            
                for (int j = 0; j < number_of_features; j++) {
                    z += X_train[i][j] * weights[j][0];

                }
                temprow.push_back(sigmoid(z));
                predicted_values.push_back(temprow);
            
            }

            // Updating weights using gradient
            
            for (int j = 0; j < number_of_features; j++) {
                
                double gradient = 0.0;
                
                for (int i = 0; i < dataset_size; i++) {
                    gradient += (predicted_values[i][0] - Y_train[i][0]) * X_train[i][j];
                
                }
                weights[j][0] -= learning_rate * gradient / num_of_iterations;
            }

        }
    }

    IntMatrix predict(IntMatrix X_test) {
        normalize(X_test);

        
        IntMatrix predictions;
        intRow temprow;
        for (int i = 0; i < X_test.size(); i++) {
            double z = 0.0;
            for (int j = 0; j < X_test[0].size(); j++) {
                z += X_test[i][j] * weights[j][0];
            }
            z = sigmoid(z) >= 0.5 ? 1 : 0; // Classify based on threshold of 0.5
            temprow.push_back(z);
            predictions.push_back(temprow);
            temprow.clear();
        }
        return predictions;
    }
};


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
