#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool randomSuccess()
{
	return rand() % 100 < 90;
}

class PowerSupply 
{
public:
	void powerOn() 
	{
		cout << "Power Supply: Power ON\n";
	}
	void powerOff()
	{ 
		cout << "Power Supply: Power OFF\n";
	}
	void supplyTo(const string& device)
	{ 
		cout << "Power Supply: Power supplied to " << device << "\n";
	}
	void stopSupplyTo(const string& device) 
	{ 
		cout << "Power Supply: Power stopped to " << device << "\n";
	}
};

class Sensors 
{
public:
	bool checkVoltage() 
	{
		cout << "Sensors: Checking voltage... ";
		if (randomSuccess()) 
		{
			cout << "OK\n";
			return true;
		}
		else
		{
			cout << "FAILED\n";
			return false;
		}
	}

	bool checkTemp(const string& device) 
	{
		cout << "Sensors: Checking temperature for " << device << "... ";
		if (randomSuccess()) 
		{
			cout << "OK\n";
			return true;
		}
		else
		{
			cout << "FAILED\n";
			return false;
		}
	}

	void checkAllTemps()
	{ 
		cout << "Sensors: All system temperatures are normal\n";
	}
};

class VideoCard 
{
public:
	void start() 
	{ 
		cout << "VideoCard: Started\n";
	}
	void checkMonitorConnection() 
	{ 
		cout << "VideoCard: Monitor connection check passed\n"; 
	}
	void displayRAMData() 
	{ 
		cout << "VideoCard: Displaying RAM data\n"; 
	}
	void displayOpticalDriveInfo() 
	{ 
		cout << "VideoCard: Displaying Optical Drive Info\n";
	}
	void displayHDDData() 
	{
		cout << "VideoCard: Displaying HDD data\n"; 
	}
	void farewellMessage()
	{ 
		cout << "VideoCard: Displaying farewell message\n"; 
	}
};

class RAM
{
public:
	void start() 
	{
		cout << "RAM: Initialized\n"; 
	}
	void analyze()
	{
		cout << "RAM: Memory analysis complete\n";
	}
	void clear() 
	{ 
		cout << "RAM: Cleared\n";
	}
};

class HDD {
public:
	void start()
	{ 
		cout << "HDD: Started\n"; 
	}
	void checkBootSector()
	{ 
		cout << "HDD: Boot sector check passed\n";
	}
	void stop() 
	{
		cout << "HDD: Stopped\n"; 
	}
};

class OpticalDrive 
{
public:
	void start()
	{
		cout << "Optical Drive: Started\n";
	}
	void checkDisk()
	{
		cout << "Optical Drive: Disk check complete\n"; 
	}
	void reset() 
	{ 
		cout << "Optical Drive: Returned to initial position\n";
	}
};

class ComputerFacade
{
	PowerSupply ps;
	Sensors sensors;
	VideoCard vc;
	RAM ram;
	HDD hdd;
	OpticalDrive od;
	bool poweredOn = false;

	bool check(bool condition, const string& failMsg)
	{
		if (!condition) 
		{
			cout << failMsg << " Aborting startup.\n";
			poweredOn = false;
			return false;
		}
		return true;
	}

public:
	void turnOn() 
	{
		cout << "--- Turning ON the computer ---\n";
		ps.powerOn();
		poweredOn = true;

		if (!check(sensors.checkVoltage(), "Voltage check failed."))
		{
			return;
		}
		if (!check(sensors.checkTemp("Power Supply"), "Power supply temperature check failed."))
		{
			return;
		}
		if (!check(sensors.checkTemp("Video Card"), "Video card temperature check failed.")) 
		{
			return;
		}

		ps.supplyTo("Video Card");
		vc.start();
		vc.checkMonitorConnection();

		if (!check(sensors.checkTemp("RAM"), "RAM temperature check failed."))
		{
			return;
		}

		ps.supplyTo("RAM");
		ram.start();
		ram.analyze();
		vc.displayRAMData();

		ps.supplyTo("Optical Drive");
		od.start();
		od.checkDisk();
		vc.displayOpticalDriveInfo();

		ps.supplyTo("HDD");
		hdd.start();
		hdd.checkBootSector();
		vc.displayHDDData();

		sensors.checkAllTemps();
	}

	void turnOff() {
		if (!poweredOn) {
			cout << "Computer is already OFF.\n";
			return;
		}

		cout << "\n--- Turning OFF the computer ---\n";
		hdd.stop();
		ram.clear();
		ram.analyze();
		vc.farewellMessage();

		od.reset();

		ps.stopSupplyTo("Video Card");
		ps.stopSupplyTo("RAM");
		ps.stopSupplyTo("Optical Drive");
		ps.stopSupplyTo("HDD");

		sensors.checkVoltage();
		ps.powerOff();
		poweredOn = false;
	}
};

int main() {
	srand(time(nullptr));

	ComputerFacade computer;
	computer.turnOn();

	system("pause");

	computer.turnOff();

	system("pause");

	return 0;
}
