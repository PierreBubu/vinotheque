#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "saveReader.hpp"


const std::string SaveReader::title_nb_cols = "title_nb_cols";
const std::string SaveReader::wine_nb_rows = "wine_nb_rows";

SaveReader::SaveReader() : pathToSavedFile(""), nbTitleCols(0), nbWinesRows(0), columnTitles(), wines() {
}

SaveReader::SaveReader(std::string path_to_file) : pathToSavedFile(path_to_file) {
	readSaveFile();
}

void SaveReader::readSaveFile() {
	std::cout << "path to file" << pathToSavedFile << std::endl;
	std::ifstream fichier;
	fichier.open(pathToSavedFile);
	std::string readString;
        int readChar = 0;

        // Read all the file to a string
        while(readChar != EOF) {
            readChar = fichier.get();
            readString += (readChar);
        } 

        //Tokenize the file on \n
        std::vector<std::string> tokens = Tokenize(readString, "\n");
        std::cout << "File content : " << readString << std::endl;
        for(int k = 0 ; k < tokens.size() ; k++) {
            std::cout << "token : " << tokens[k] << std::endl;
        }

        //  Read nb cols
        // Search line "title_nb"
        bool found = false;
        unsigned int i = 0;
        int pos = 0;
        std::cout << "Filling nbTitleCols\n";
        while(!found && i < tokens.size()) {
            pos = tokens[i].find(title_nb_cols);
            found = pos != std::string::npos;
            i++;
        }
        i--;
        std::cout << "titleCols : " << tokens[i] << std::endl;
        if(found) {
            std::vector<std::string> words = Tokenize(tokens[i], "=");
            nbTitleCols = std::stoi(words[1]);
        }
        std::cout << "Read nb title columns : " << nbTitleCols << std::endl;

        found = false;
        pos = 0;
        i = 0;

        std::cout << "Filling nbWinesRows\n";
        while(!found && i < tokens.size()) {
            pos = tokens[i].find(wine_nb_rows);
            found = pos != std::string::npos;
            i++;
        }
        i--;
        std::cout << "nbWines : " << tokens[i] << std::endl;
        if(found) {
            std::vector<std::string> words = Tokenize(tokens[i], "=");
            nbWinesRows = std::stoi(words[1]);
        }
        std::cout << "Read nb wines rows : " << nbWinesRows << std::endl;
        
        // Fill title columns
        std::cout << "Begin of Filling Titles Columns";
        columnTitles.resize(nbTitleCols);

        found = false ;
        while(!found && i < tokens.size()) {
            found = (tokens[i].find("||") != std::string::npos);
            i++;
        }
        i--;
        columnTitles = Tokenize(tokens[i], "||");
        std::cout << "columnTitles\n";
        for(int l = 0 ; l < columnTitles.size() ; l++) {
            std::cout << columnTitles[i] << std::endl;
        }


	// Fill wines
	wines.resize(nbWinesRows);

        // Find beginning of the wines
        i++;
        found = false;
        while(!found && i < tokens.size()) {
            found = (tokens[i].find("||") != std::string::npos);
            i++;
        }
        i--;

        std::cout << "Begin of Filling Wines";
	for(unsigned int j = 0 ; j < nbWinesRows ; j++) {
		wines[j].resize(nbWinesRows);
                wines[j] = Tokenize(tokens[i], "||"); 
                i++;
	}
        std::cout << "end of reading\n";
	fichier.close();
}


std::vector<std::string> SaveReader::get_columnTitles() {
    return columnTitles;
}
std::vector<std::vector<std::string> > SaveReader::get_wines() {
    return wines;
}

                      
std::vector<std::string> SaveReader::Tokenize(const std::string& str,
                      const std::string& delimiters){
    std::cout << "Begin of Tokenize\n";
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);
    std::vector<std::string> tokens;

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
    std::cout << "End of Tokenize\n";
    return tokens;
}
