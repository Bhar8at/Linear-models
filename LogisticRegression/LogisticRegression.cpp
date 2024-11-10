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


