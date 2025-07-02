#include <iostream>
#include <string>
using namespace std;

class AbstractCarPart {
protected:
    string producer;
public:
    string GetProducer() 
    {
        return producer;
    }
    void SetProducer(string producer)
    { 
        this->producer = producer; 
    }
    virtual AbstractCarPart* Clone() = NULL;
};

class Engine : public AbstractCarPart 
{
    double power;
public:
    double GetPower()
    { 
        return power; 
    }
    void SetPower(double power) 
    {
        this->power = power;
    }
    AbstractCarPart* Clone() override
    {
        Engine* e = new Engine;
        *e = *this;
        return e;
    }
};

class Wheels : public AbstractCarPart 
{
    int count;
    string type;
public:
    int GetCount() 
    {
        return count;
    }
    void SetCount(int count) 
    {
        this->count = count; 
    }
    string GetType()
    {
        return type;
    }
    void SetType(string type)
    {
        this->type = type;
    }
    AbstractCarPart* Clone() override 
    {
        Wheels* w = new Wheels;
        *w = *this;
        return w;
    }
};

class Body : public AbstractCarPart
{
    string color;
public:
    string GetColor() 
    { 
        return color; 
    }
    void SetColor(string color) 
    {
        this->color = color;
    }
    AbstractCarPart* Clone() override
    {
        Body* b = new Body;
        *b = *this;
        return b;
    }
};

class Transmission : public AbstractCarPart 
{
    string gearboxType;
public:
    string GetGearboxType() 
    {
        return gearboxType;
    }
    void SetGearboxType(string type) 
    {
        this->gearboxType = type; 
    }
    AbstractCarPart* Clone() override 
    {
        Transmission* t = new Transmission;
        *t = *this;
        return t;
    }
};

class Interior : public AbstractCarPart 
{
    string material;
public:
    string GetMaterial() 
    { 
        return material; 
    }
    void SetMaterial(string material) 
    { 
        this->material = material; 
    }
    AbstractCarPart* Clone() override
    {
        Interior* i = new Interior;
        *i = *this;
        return i;
    }
};

class Prototype 
{
public:
    virtual Prototype* Clone() = NULL;
};

class Car : public Prototype 
{
    Body* body;
    Engine* engine;
    Wheels* wheels;
    Transmission* transmission;
    Interior* interior;
public:
    Body* GetBody() 
    { 
        return body; 
    }
    void SetBody(Body* body) 
    { 
        this->body = body;
    }
    Engine* GetEngine()
    { 
        return engine;
    }
    void SetEngine(Engine* engine) 
    { 
        this->engine = engine; 
    }
    Wheels* GetWheels() 
    { 
        return wheels;
    }
    void SetWheels(Wheels* wheels) 
    {
        this->wheels = wheels;
    }
    Transmission* GetTransmission() 
    {
        return transmission; 
    }
    void SetTransmission(Transmission* t) 
    {
        this->transmission = t; 
    }
    Interior* GetInterior() 
    {
        return interior;
    }
    void SetInterior(Interior* i)
    { 
        this->interior = i;
    }

    Prototype* Clone() override 
    {
        Car* car = new Car;
        car->body = body ? static_cast<Body*>(body->Clone()) : nullptr;
        car->engine = engine ? static_cast<Engine*>(engine->Clone()) : nullptr;
        car->wheels = wheels ? static_cast<Wheels*>(wheels->Clone()) : nullptr;
        car->transmission = transmission ? static_cast<Transmission*>(transmission->Clone()) : nullptr;
        car->interior = interior ? static_cast<Interior*>(interior->Clone()) : nullptr;
        return car;
    }
};

class CarPrototypes
{
    Car* sport;
    Car* family;
    Car* truck;
public:
    CarPrototypes() 
    {
        sport = CreateSportCar();
        family = CreateFamilyCar();
        truck = CreateTruck();
    }

    Car* GetByIndex(int index) 
    {
        switch (index) 
        {
        case 0: return sport;
        case 1: return family;
        case 2: return truck;
        default: return nullptr;
        }
    }

    Car* CreateSportCar() 
    {
        Car* car = new Car();
        
        Body* b = new Body(); 
        b->SetColor("Red"); 
        car->SetBody(b);

        Engine* e = new Engine(); 
        e->SetProducer("Ferrari"); 
        e->SetPower(600); 
        car->SetEngine(e);

        Wheels* w = new Wheels(); 
        w->SetProducer("Pirelli");
        w->SetCount(4); 
        w->SetType("Sport"); 
        car->SetWheels(w);

        Transmission* t = new Transmission(); 
        t->SetGearboxType("Automatic");
        t->SetProducer("ZF");
        car->SetTransmission(t);

        Interior* i = new Interior(); 
        i->SetMaterial("Leather");
        i->SetProducer("Recaro"); 
        car->SetInterior(i);

        return car;
    }

    Car* CreateFamilyCar() 
    {
        Car* car = new Car();

        Body* b = new Body(); 
        b->SetColor("Blue"); 
        car->SetBody(b);

        Engine* e = new Engine(); 
        e->SetProducer("Toyota"); 
        e->SetPower(150); 
        car->SetEngine(e);

        Wheels* w = new Wheels(); 
        w->SetProducer("Michelin"); 
        w->SetCount(4); 
        w->SetType("All-season"); 
        car->SetWheels(w);

        Transmission* t = new Transmission(); 
        t->SetGearboxType("Automatic");
        t->SetProducer("Aisin"); 
        car->SetTransmission(t);

        Interior* i = new Interior();
        i->SetMaterial("Fabric");
        i->SetProducer("Toyota");
        car->SetInterior(i);

        return car;
    }

    Car* CreateTruck() 
    {
        Car* car = new Car();

        Body* b = new Body();
        b->SetColor("White"); 
        car->SetBody(b);

        Engine* e = new Engine(); 
        e->SetProducer("Volvo");
        e->SetPower(400); 
        car->SetEngine(e);

        Wheels* w = new Wheels();
        w->SetProducer("Bridgestone"); 
        w->SetCount(6);
        w->SetType("Heavy-duty");
        car->SetWheels(w);

        Transmission* t = new Transmission(); 
        t->SetGearboxType("Manual");
        t->SetProducer("Eaton");
        car->SetTransmission(t);

        Interior* i = new Interior();
        i->SetMaterial("Vinyl");
        i->SetProducer("Volvo"); 
        car->SetInterior(i);

        return car;
    }
};

void PrintCar(Car* car) 
{
    cout << "Car configuration:\n";
    cout << "Body: " << car->GetBody()->GetColor() << endl;
    cout << "Engine: " << car->GetEngine()->GetProducer() << " " << car->GetEngine()->GetPower() << " HP" << endl;
    cout << "Wheels: " << car->GetWheels()->GetProducer() << " " << car->GetWheels()->GetCount() << "x " << car->GetWheels()->GetType() << endl;
    cout << "Transmission: " << car->GetTransmission()->GetProducer() << " - " << car->GetTransmission()->GetGearboxType() << endl;
    cout << "Interior: " << car->GetInterior()->GetProducer() << " - " << car->GetInterior()->GetMaterial() << endl;
}

int main() 
{
    cout << "Select car type (1 - Sport, 2 - Family, 3 - Truck): ";
    int index;
    cin >> index;
    index--;

    CarPrototypes cp;
    Car* prototype = cp.GetByIndex(index);

    if (prototype != nullptr) 
    {
        Car* car = dynamic_cast<Car*>(prototype->Clone());
        PrintCar(car);
    }
    else 
    {
        cout << "Error: incorrect car type" << endl;
    }
    system("pause");
    return 0;
}
