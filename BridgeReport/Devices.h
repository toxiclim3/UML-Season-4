#pragma once
#include "DeviceReport.h"
//-----vvv---Реализация тут---vvv--------------------------------------так же отделить?--------------
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
		const std::string keys[] = { "Model", "Type", "Capacity", "Speed" };
		const std::string values[] = { "HyperX Fury", "DDR4", "16 GB", "3 200 MHz" };
		impl->PrintReport("RAM", keys, values, 4);
	}
};