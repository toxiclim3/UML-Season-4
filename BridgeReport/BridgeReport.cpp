#include <iostream>
#include "Devices.h"



int main()
{
	ConsoleReport console;
	Device* device = nullptr;
	std::cout << "Select device: \n1.GPU\n2.CPU\n3.Storage drive\n4.RAM\n";
	int choice;
	std::cin >> choice;
	switch (choice) 
		{
			case 1:
			{
				device = new GPU(&console);
				break;
			}
			case 2:
			{
				device = new CPU(&console); 
				break; 
			}
			case 3:
			{ 
				device = new Storage(&console); 
				break;
			}
			case 4:
			{ 
				device = new RAM(&console);
				break;
			}
			default:
			{
				std::cout << "Invalid choice\n";
				return 0;
			}
		}
	device->ShowReport();
	delete device;

	system("pause");
	return 0;
}
