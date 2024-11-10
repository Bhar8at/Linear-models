#include "Data_Preprocessing.cpp"
#include <cmath>    

class LogisticRegression{
    
    private:
    
    IntMatrix sigmoid ( IntMatrix z) {
        
        IntMatrix c;
        intRow row;
        
            for (int i = 0; i < z.size(); i++ ){
                
                row.clear();
                
                for (int j = 0; j < z[i].size(); j++){
                    
                    float x = 1 / ( 1 + exp(-z[i][j]) );
                    row.push_back(x);
            
            }

            c.push_back(row);
        
        }
        
        return c;
 
    }

    public:
    
    double learning_rate;
    int num_of_iterations;

    LogisticRegression( double learning_rate, int num_of_iterations ){
        
        this->learning_rate = learning_rate;
        this->num_of_iterations = num_of_iterations;

    }

    int fit ( IntMatrix X_train, IntMatrix Y_train ){

        // initialize weights and biases
        
        int dataset_size = X_train.size();
        int number_of_features = X_train[0].size();

        IntMatrix weights;
        IntMatrix biases;
        intRow temprow;

        for (int i = 0 ; i < number_of_features; i++){

            temprow.push_back(0);

        }

        weights.push_back(temprow);
        biases.push_back(temprow);
        weights = transpose(weights);
        biases = transpose(biases);
        // Gradient Ascent

        for (int i = 0 ; i < 1000; i++){

            IntMatrix predicted_values = sum(multiply(X_train, weights), biases);
            predicted_values = sigmoid(predicted_values);

            // Gradient computation
            IntMatrix gradient = dot()


        }




    }





};


int runLogisticRegression(){

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

    
    
    return 0;

}
