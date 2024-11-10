#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "../external/linear-algebra-framework/matrix.h"
#include "../external/linear-algebra-framework/matrixui.h"
#include "../external/linear-algebra-framework/RowTransform.h"

std::pair<IntMatrix, IntMatrix> parse_csv_LR(){

    // Opening the File
    std::ifstream file("LogisticRegression/Dataset.csv");

    if (!file.is_open()){

        std::cerr << "Cannot Open File" << std::endl;

    }

    // Processing File Data

    std::string line;
    std::string word;
    
    // Viewing Headers

    std::cout << "Headers are : "<< std::endl;

    if  (std::getline(file, line)){
    
        std::stringstream ss(line);
    
        while (std::getline(ss, word, ',')){
    
            std::cout << word << std::endl;
    
        }
    
        std::cout << std::endl;
    }    


    IntMatrix X , Y;
    intRow x , y;
    
    // Processing CSV file into each vector

    int collumn = 0; // To keep track of the column 
    int row = 0; // to keep track of row 

    while (std::getline(file, line)){

        collumn = 0;

        std::stringstream ss(line);
        
        while(std::getline(ss, word, ',')){


            // Pushing the Outcome (Predictor variable)
            if (collumn == 8){ 

                y.push_back(stof(word)); 

            }

            else{

                x.push_back(stoi(word));

            }

            collumn++;

        }
    
        row++;
        X.push_back(x);
        Y.push_back(y);
        x.clear();
        y.clear();

    }

    return std::make_pair(X, Y);

}