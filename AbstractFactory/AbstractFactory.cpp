// Абстрактные классы
#include <iostream>
#include <vector>
using namespace std;

class Herbivore {
protected:
	int weight;
	bool life;
public:
	Herbivore(int w = 50) : weight(w), life(true) {}

	virtual void EatGrass()
	{
		if (life) weight += 10;
		cout << "The " << name() << " eats grass and gains 10 weight! Current weight : " << weight << "\n";
	}
	int getWeight() const
	{
		return weight;
	}
	bool isAlive() const
	{
		return life;
	}
	void die()
	{
		life = false;
	}
	virtual string name() const = 0;
};

class Carnivore {
protected:
	int power;
public:
	Carnivore(int p = 100) : power(p) {}
	virtual void Eat(Herbivore* h) {
		if (!h->isAlive()) return;
		if (power > h->getWeight())
		{
			power += 10;
			h->die();
			cout << name() << " eats the " << h->name() << " and gains 10 power.\n";
		}
		else
		{
			power -= 10;
			cout << name() << " fails to eat the " << h->name() << " and loses 10 power.\n";
		}
	}
	virtual string name() const = NULL;
};



class Wildebeest : public Herbivore
{
public:
	string name() const override { return "Wildebeest"; }
};

class Bison : public Herbivore
{
public:
	string name() const override { return "Bison"; }
};

class Elk : public Herbivore
{
public:
	string name() const override { return "Elk"; }
};



class Lion : public Carnivore
{
public:
	string name() const override { return "Lion"; }
};

class Wolf : public Carnivore
{
public:
	string name() const override { return "Wolf"; }
};

class Tiger : public Carnivore
{
public:
	string name() const override { return "Tiger"; }
};


class ContinentFactory
{
public:
	virtual Herbivore* CreateHerbivore() = 0;
	virtual Carnivore* CreateCarnivore() = 0;
	virtual ~ContinentFactory() {}
};


class AfricaFactory : public ContinentFactory
{
public:
	Herbivore* CreateHerbivore() override { return new Wildebeest(); }
	Carnivore* CreateCarnivore() override { return new Lion(); }
};

class NorthAmericaFactory : public ContinentFactory
{
public:
	Herbivore* CreateHerbivore() override { return new Bison(); }
	Carnivore* CreateCarnivore() override { return new Wolf(); }
};

class EurasiaFactory : public ContinentFactory
{
public:
	Herbivore* CreateHerbivore() override { return new Elk(); }
	Carnivore* CreateCarnivore() override { return new Tiger(); }
};


class AnimalWorld
{
	vector<Herbivore*> herbivores;
	vector<Carnivore*> carnivores;
public:
	AnimalWorld(ContinentFactory* factory, int hvCount, int cvCount)
	{
		for (int i = 0; i < hvCount; i++)
		{
			herbivores.push_back(factory->CreateHerbivore());
		}
		for (int i = 0; i < cvCount; i++)
		{
			carnivores.push_back(factory->CreateCarnivore());
		}
	}
	~AnimalWorld()
	{
		for (auto h : herbivores) delete h;
		for (auto c : carnivores) delete c;
	}
	void FeedHerbivores() {
		for (auto h : herbivores) h->EatGrass();
	}
	void FeedCarnivores() {
		for (int i = 0; i < herbivores.size() && i < carnivores.size(); i++)
		{
			carnivores[i]->Eat(herbivores[i]);
		}
	}
};

int main() {
	ContinentFactory* africa = new AfricaFactory();
	AnimalWorld world1(africa, 5, 3);
	world1.FeedHerbivores();
	world1.FeedCarnivores();
	delete africa;

	ContinentFactory* na = new NorthAmericaFactory();
	AnimalWorld world2(na, 3, 5);
	world2.FeedHerbivores();
	world2.FeedCarnivores();
	delete na;

	ContinentFactory* eur = new EurasiaFactory();
	AnimalWorld world3(eur, 5, 5);
	world3.FeedHerbivores();
	world3.FeedCarnivores();
	delete eur;

	return 0;
}
