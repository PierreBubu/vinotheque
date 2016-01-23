#include <gtkmm-3.0/gtkmm.h>
#include "ihm.hpp"
#include "saveReader.hpp"
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "Exemple");

	std::vector<std::string> columnTitles(7);
	columnTitles[0] = "Couleur"; 
	columnTitles[1] = "Domaine"; 
	columnTitles[2] = "Complément"; 
	columnTitles[3] = "Millésime"; 
	columnTitles[4] = "Région"; 
	columnTitles[5] = "Date d'achat"; 
	columnTitles[6] = "Stock"; 

	SaveReader loader("resources/save/save_test.dat");
	std::vector<std::string> columnTitles2(loader.get_columnTitles());
        std::cout << "columnTitles size : " << columnTitles2.size();
        std::vector<std::vector<std::string> > wines(loader.get_wines());

        std::cout << "Init IHM\n";
        std::cout << "wines.size() " << wines.size() << std::endl;
        std::cout << "wines[0].size() " << wines[0].size() << std::endl;

	Ihm ihm(wines.size(),columnTitles2.size(),columnTitles2,wines);

        std::cout << "run IHM\n";
	app->run(ihm);
    return 0;
}
