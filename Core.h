#ifndef CORE_HPP
#define CORE_HPP
#include <string>

class Core {
private:
	/// <summary>
	/// Version number of application
	/// </summary>
	static std::string version;
public:
	/// <summary>
	/// Constructor used to instantiate the class
	/// </summary>
	Core();
	/// <summary>
	/// Displays the menu
	/// </summary>
	void display_core_menu();

	/// <summary>
	/// Displays a menu showing financial tools
	/// </summary>
	void display_fintool_menu();

	/// <summary>
	/// Displays a menu showing credit card / loan management
	/// </summary>
	void display_cc_manager();

	/// <summary>
	/// Gets the version member variable.
	/// </summary>
	/// <returns>A string value</returns>
	std::string get_version();

	/// <summary>
	/// Clears a line in the cout.
	/// </summary>
	void line_clear();
};
#endif // CORE_HPP
