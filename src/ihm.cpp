#include "ihm.hpp"
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include <string>
#include <iostream>

Ihm::Ihm() : nbRows(0), nbCols(0), grid(), buttons(0), textTable(0) {

}

Ihm::Ihm(int nbRow, int nbCol, std::vector<std::string> columnTitles) : nbRows(nbRow),  nbCols(nbCol),grid(), buttons(7), textTable(nbCols * nbRows) {
	this->set_title("Test");
	this->set_border_width(0);
	this->add(grid);

	for(int i = 0 ; i < nbCols ; i++) {
            std::cout << " i : " << i << std::endl;
		buttons[i].set_label(columnTitles[i]);
		grid.attach(buttons[i],i,0,1,1);
		for(int j = 0 ; j < nbRows ; j++) {
                    std::cout << " j : " << j << std::endl;
			textTable[j*nbCols + i].set_text(std::to_string(j) + " , " + std::to_string(i));
			grid.attach(textTable[nbCols*j+i], i,j,1,1);
		}
	}

	show_all_children();

}

Ihm::Ihm(int nbRow, int nbCol, std::vector<std::string> buttonNames, std::vector<std::vector<std::string> > winesEntries) : nbRows(nbRow), nbCols(nbCol), buttons(nbCols), textTable(nbCols*nbRows) {
    this->set_title("Test");
    this->set_border_width(0);
    this->add(grid);

    for(int i = 0 ; i < nbCols ; i++) {
        std::cout << " i : " << i << std::endl;
        buttons[i].set_label(buttonNames[i]);
        grid.attach(buttons[i],i,0,1,1);
        for(int j = 0 ; j < nbRows ; j++) {
            std::cout << " j : " << j << std::endl;
            textTable[j*nbCols + i].set_text(winesEntries[j][i]);
            grid.attach(textTable[nbCols*j+i], i,j,1,1);
        }
    }

    show_all_children();
 
}

Ihm::~Ihm() {}
