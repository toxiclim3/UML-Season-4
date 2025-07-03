// Navigator using the Strategy pattern in C++ without <memory>
#include <iostream>
#include <string>

class RouteStrategy 
{
public:
	virtual void buildRoute(const std::string& start, const std::string& end) = NULL;
	virtual ~RouteStrategy() {}
};

class CarRouteStrategy : public RouteStrategy 
{
public:
	void buildRoute(const std::string& start, const std::string& end) override
	{
		std::cout << "Building a car route from " << start << " to " << end << ".\n";
	}
};

class WalkRouteStrategy : public RouteStrategy
{
public:
	void buildRoute(const std::string& start, const std::string& end) override
	{
		std::cout << "Building a walking route from " << start << " to " << end << ".\n";
	}
};

class PublicTransportRouteStrategy : public RouteStrategy 
{
public:
	void buildRoute(const std::string& start, const std::string& end) override
	{
		std::cout << "Building a public transport route from " << start << " to " << end << ".\n";
	}
};

class Navigator
{
private:
	RouteStrategy* strategy = nullptr;
public:
	void setStrategy(RouteStrategy* newStrategy) 
	{
		strategy = newStrategy;
	}
	void buildRoute(const std::string& start, const std::string& end)
	{
		if (strategy) 
		{
			strategy->buildRoute(start, end);
		}
		else 
		{
			std::cout << "No strategy selected.\n";
		}
	}
};

int main() {
	Navigator navigator;
	CarRouteStrategy car;
	WalkRouteStrategy walk;
	PublicTransportRouteStrategy bus;

	std::cout << "Select route type: 1 - Car, 2 - Walk, 3 - Public Transport\n";
	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		navigator.setStrategy(&car);
		break;
	case 2:
		navigator.setStrategy(&walk);
		break;
	case 3:
		navigator.setStrategy(&bus);
		break;
	default:
		std::cout << "Invalid choice.\n";
		return 1;
	}
	navigator.buildRoute("Point A", "Point B");
	return 0;
}
