#ifndef IHM_HPP
#define IHM_HPP

#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include <string>

/* Define the main window which will contain all the widgets
 */

class Ihm : public Gtk::Window {
	
	private:
			int nbRows, nbCols;

			//Gtk::Grid main container
			Gtk::Grid grid;

			//Title Buttons
			std::vector<Gtk::Button> buttons;

			// Text Grid
			std::vector<Gtk::Entry> textTable;

	public:
			Ihm();
			Ihm(int nbRows, int nbCols, std::vector<std::string> buttonNames=std::vector<std::string>());
			Ihm(int nbRows, int nbCols, std::vector<std::string> buttonNames, std::vector<std::vector<std::string> > winesEntries);

			virtual ~Ihm();
			

};

#endif
