#include <iostream>
#include <string>

class ReportImplementor 
{
public:
	virtual void PrintReport(const std::string& title, const std::string keys[], const std::string values[], int size) = NULL;
	virtual ~ReportImplementor() = default;
};

class ConsoleReport : public ReportImplementor 
{
public:
	void PrintReport(const std::string& title, const std::string keys[], const std::string values[], int size) override
	{
		std::cout << "=== " << title << " ===\n";
		for (int i = 0; i < size; ++i) 
		{
			std::cout << keys[i] << ": " << values[i] << "\n";
		}
		std::cout << std::endl;
	}
};

class Device
{
protected:
	ReportImplementor* impl;
public:
	Device(ReportImplementor* i) : impl(i) {}
	void SetImplementor(ReportImplementor* i)
	{
		impl = i; 
	}
	virtual void ShowReport() = NULL;
	virtual ~Device() = default;
};

class GPU : public Device 
{
public:
	GPU(ReportImplementor* i) : Device(i) {}
	void ShowReport() override 
	{
		const std::string keys[] = { "Model", "Memory", "Core Clock" };
		const std::string values[] = { "NVIDIA GeForce RTX 3080", "10 GB", "1 440 MHz" };
		impl->PrintReport("GPU", keys, values, 3);
	}
};

class CPU : public Device 
{
public:
	CPU(ReportImplementor* i) : Device(i) {}
	void ShowReport() override 
	{
		const std::string keys[] = { "Model", "Cores", "Threads", "Base Clock" };
		const std::string values[] = { "Intel Core i9-11900K", "8", "16", "3.5 GHz" };
		impl->PrintReport("CPU", keys, values, 4);
	}
};

class Storage : public Device 
{
public:
	Storage(ReportImplementor* i) : Device(i) {}
	void ShowReport() override 
	{
		const std::string keys[] = { "Model", "Capacity", "Type" };
		const std::string values[] = { "Samsung 970 EVO Plus", "1 TB", "SSD" };
		impl->PrintReport("Storage", keys, values, 3);
	}
};

class RAM : public Device
{
public:
	RAM(ReportImplementor* i) : Device(i) {}
	void ShowReport() override 
	{
		const std::string keys[] = {"Model", "Type", "Capacity", "Speed" };
		const std::string values[] = {"HyperX Fury", "DDR4", "16 GB", "3 200 MHz" };
		impl->PrintReport("RAM", keys, values, 4);
	}
};

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
