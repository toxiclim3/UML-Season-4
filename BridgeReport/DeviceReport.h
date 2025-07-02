#pragma once
#include <iostream>
#include <string>
//---------------vvv---Абтрактное тут---vvv--------------------------
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