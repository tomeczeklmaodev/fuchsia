#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char* argv[])
{

	for (int i = 0; i < argc; i++)
	{
		//std::cout << "[recv-arg@pos:" << i << "]: " << argv[i] << "\n";
		if (strcmp(argv[i], "about") == 0) {
			std::cout << "Fuchsia 0.1.0\n\n";
			std::cout << "Terminal tool to help set up a new Windows device.\n";
			std::cout << "https://github.com/tomeczeklmaodev/fuchsia\n";
		} else if (strcmp(argv[i], "print") == 0) { // i added this as a test; will remove later
			std::string subarg = argv[i + 1];
			std::cout << subarg << "\n";
		} else if (strcmp(argv[i], "uas") == 0) {
			std::string uas_username = argv[i + 1];
			std::string uas_fullname = argv[i + 2];
			std::cout << "Creating user '" << uas_username << " (" << uas_fullname << ")'\n";
			std::string uas_accountcreation = "net user " + uas_username + " /fullname:\"" + uas_fullname + "\" /add /logonpasswordchg:yes /active:yes";
			std::string uas_addtogroup = "net localgroup Administratorzy " + uas_username + " /add"; // this is for Windows with pl_PL language pack
			// std::string uas_addtogroup = "net localgroup Administrators " + uas_username + " /add";  // uncomment for en_US
			std::cout << uas_accountcreation << std::endl; // only here to see what will the 'net user' command look like
			std::cout << uas_addtogroup << std::endl; // only here to see what will the 'net localgroup' command look like
			std::system(uas_accountcreation.c_str()); // requires admin privileges, just like 'net localgroup'
			std::system(uas_addtogroup.c_str()); // will replace later with something more safe + this shit requires admin privileges to run,
												 // so you have to run cmd as admin everytime you want to use this part of the program.
												 // i'll just recommend always running cmd as admin when running fuchsia,
												 // even though it is not recommended when a program uses system() -> security flaw.
		}
	}
	return 0;
}