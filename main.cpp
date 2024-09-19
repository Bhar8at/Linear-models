#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "matrix.h"
#include "matrixui.h"


int main(){
    // Opening the File
    // std::ifstream file("Laptop_Data.csv");
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

    // /* Creating Arrays for Each feature 
    // (Using only some features 
    // and will expand on the model later on )
    // */

    // std::vector<std::string> Company;
    // std::vector<std::string> TypeName;
    // std::vector<int> Inches;
    // std::vector<std::string> Ram;
    // std::vector<std::string> Memory;
    // std::vector<std::string> Price;


    // // Processing CSV file into each vector
    // int index = 0;
    // while (std::getline(file, line)){
    //     index = 0;
    //     std::stringstream ss(line);
    //     while(std::getline(ss, word, ',')){
    //         switch (index) {
    //         case 1:
    //             Company.push_back(word);
    //             break;
    //         case 3:
    //             Inches.push_back(stoi(word));
    //         case 2:
    //             TypeName.push_back(word);
    //             break;
    //         case 6:
    //             Ram.push_back(word);
    //             break;
    //         case 7:
    //             Memory.push_back(word);
    //             break;
    //         case 11:
    //             Price.push_back(word);
    //             break;  
    //         default:
    //             break;
    //         }
    //         index++;
    //     }  
    // }

    // Training the Model on Data 
    
    // Testing Matrix Operations
    // IntMatrix x,y;
    // x = FillMatrix();
    // y = FillMatrix();
    // std::cout << "\n\n\n" << std::endl;
    // DisplayMatrix(x);
    // std::cout << std::endl;
    // std:: cout << "Multiplying with " << std::endl;
    // DisplayMatrix(y);
    // std::cout << std::endl;
    // IntMatrix c = multiply(x,y);
    // std::cout << "\n\n" << std::endl;
    // DisplayMatrix(c);

    // // Testing Inverse
    IntMatrix x;
    x = FillMatrix();
    std::cout << "\n\n" << std::endl;
    x = inverse(x);
    std::cout << "\n\n Outputing the Final matrix \n\n" << std::endl;
    DisplayMatrix(x);


    return 0;

}