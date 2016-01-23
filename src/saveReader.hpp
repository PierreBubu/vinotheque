#ifndef SAVE_READER_HPP
#define SAVE_READER_HPP

#include <iostream>
#include <vector>
#include <string>

/** Utility class to read the content of the saved wines and provides access
 * to it.
 */

class SaveReader {
	protected:
		std::string pathToSavedFile;
		unsigned int nbTitleCols;
		unsigned int nbWinesRows;
		std::vector<std::string> columnTitles;
		std::vector<std::vector<std::string> > wines;

	public:
                static std::vector<std::string> Tokenize(const std::string& chaine, const std::string& delimiters = " ");
		SaveReader();
		SaveReader(std::string path_to_file);
		std::vector<std::string> get_columnTitles();
		std::vector<std::vector<std::string> > get_wines();

	private:
		void readSaveFile();
                static const std::string title_nb_cols;
                static const std::string wine_nb_rows;
		


};

#endif 
