#include <iostream>
#include <string>
using namespace std;

class Car {
private:
	string name;
	string body;
	int horsepower;
	int wheelRadius;
	int gearCount;
	string transmission;
public:
	void setName(const string& n)
	{ 
		name = n; 
	}
	void setBody(const string& b) 
	{ 
		body = b; 
	}
	void setHorsepower(int hp) 
	{
		horsepower = hp; 
	}
	void setWheelRadius(int r) 
	{
		wheelRadius = r; 
	}
	void setGearCount(int g) 
	{ 
		gearCount = g;
	}
	void setTransmission(const string& t)
	{ 
		transmission = t;
	}

	string getName() const
	{
		return name;
	}
	string getBody() const 
	{ 
		return body;
	}
	int getHorsepower() const 
	{ 
		return horsepower; 
	}
	int getWheelRadius() const
	{ 
		return wheelRadius; 
	}
	int getGearCount() const
	{ 
		return gearCount;
	}
	string getTransmission() const 
	{
		return transmission;
	}

	void show()
	{
		cout << "Car: " << name << endl;
		cout << "  Body: " << body << endl;
		cout << "  Horsepower: " << horsepower << endl;
		cout << "  Wheel radius: " << wheelRadius << endl;
		cout << "  Gears: " << gearCount << endl;
		cout << "  Transmission: " << transmission << endl << endl;
	}
};

class CarBuilder 
{
protected:
	Car* car;
public:
	CarBuilder() 
	{ 
		car = new Car();
	}
	virtual ~CarBuilder()
	{
		delete car; 
	}
	Car* getCar() 
	{ 
		return car;
	}

	virtual void buildName() = NULL;
	virtual void buildBody() = NULL;
	virtual void buildHorsepower() = NULL;
	virtual void buildWheels() = NULL;
	virtual void buildGears() = NULL;
	virtual void buildTransmission() = NULL;
};

class DaewooLanosBuilder : public CarBuilder 
{
public:
	void buildName() override 
	{
		car->setName("Daewoo Lanos"); 
	}
	void buildBody() override 
	{
		car->setBody("Седан"); 
	}
	void buildHorsepower() override 
	{
		car->setHorsepower(98); 
	}
	void buildWheels() override 
	{ 
		car->setWheelRadius(13);
	}
	void buildGears() override 
	{
		car->setGearCount(5);
	}
	void buildTransmission() override
	{ 
		car->setTransmission("Manual"); 
	}
};

class FordProbeBuilder : public CarBuilder 
{
public:
	void buildName() override 
	{
		car->setName("Ford Probe");
	}
	void buildBody() override 
	{ 
		car->setBody("Купе");
	}
	void buildHorsepower() override 
	{
		car->setHorsepower(160); 
	}
	void buildWheels() override 
	{ 
		car->setWheelRadius(14); 
	}
	void buildGears() override
	{ 
		car->setGearCount(4);
	}
	void buildTransmission() override
	{ 
		car->setTransmission("Auto"); 
	}
};

class UAZPatriotBuilder : public CarBuilder 
{
public:
	void buildName() override 
	{
		car->setName("UAZ Патриот");
	}
	void buildBody() override 
	{
		car->setBody("Универсал");
	}
	void buildHorsepower() override 
	{
		car->setHorsepower(120);
	}
	void buildWheels() override
	{ 
		car->setWheelRadius(16);
	}
	void buildGears() override
	{
		car->setGearCount(4);
	}
	void buildTransmission() override 
	{
		car->setTransmission("Manual");
	}
};

class HyundaiGetzBuilder : public CarBuilder {
public:
	void buildName() override 
	{ 
		car->setName("Hyundai Getz"); 
	}
	void buildBody() override 
	{ 
		car->setBody("Хетчбэк");
	}
	void buildHorsepower() override
	{ 
		car->setHorsepower(66); 
	}
	void buildWheels() override 
	{ 
		car->setWheelRadius(13); 
	}
	void buildGears() override
	{
		car->setGearCount(4);
	}
	void buildTransmission() override
	{ 
		car->setTransmission("Auto"); 
	}
};

class Shop {
public:
	void construct(CarBuilder* builder)
	{
		builder->buildName();
		builder->buildBody();
		builder->buildHorsepower();
		builder->buildWheels();
		builder->buildGears();
		builder->buildTransmission();
	}
};

int main() {
	setlocale(LC_ALL, "");
	Shop shop;

	DaewooLanosBuilder daewoo;
	shop.construct(&daewoo);
	daewoo.getCar()->show();

	FordProbeBuilder ford;
	shop.construct(&ford);
	ford.getCar()->show();

	UAZPatriotBuilder uaz;
	shop.construct(&uaz);
	uaz.getCar()->show();

	HyundaiGetzBuilder hyundai;
	shop.construct(&hyundai);
	hyundai.getCar()->show();

	system("pause");
	return 0;
}
