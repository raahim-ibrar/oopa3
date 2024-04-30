#pragma once
/*
Name: Raahim Ibrar
Roll number: 23i-0612
Section: F
Instructor: Ma'am Marium Hida
TA: Ariyan Chaudhary
*/
#include<iostream>
using namespace std;
class ALU {
private:
	int NoOfAdders;
	int NoOfSubtractor;
	int NoOfRegisters;
	int sizeOfRegisters;
public:
	ALU() :NoOfAdders(0), NoOfSubtractor(0), NoOfRegisters(0), sizeOfRegisters(0) { };
	ALU(int w, int x, int y, int z): NoOfAdders(w), NoOfSubtractor(x), NoOfRegisters(y), sizeOfRegisters(z) { };

	int getAdder()
	{
		return NoOfAdders;
	}
	void setAdder(int d)
	{
		NoOfAdders = d;
	}
	int getSubtractor()
	{
		return NoOfSubtractor;
	}
	void setSubtractor(int d)
	{
		NoOfSubtractor = d;
	}
	int getRegister()
	{
		return NoOfRegisters;
	}
	void setRegister(int d)
	{
		NoOfRegisters = d;
	}
	int getSize()
	{
		return sizeOfRegisters;
	}
	void setSize(int d)
	{
		sizeOfRegisters = d;
	}
};

class ControlUnit {
private:
	float clock;
public:
	ControlUnit() : clock(0) {};
	ControlUnit(float x) : clock(x) {};
	float getClock()
	{
		return clock;
	}
	void setClock(float d)
	{
		clock = d;
	}
};

class CPU {
protected:
	ALU alu;
	ControlUnit cu;
public:
	CPU()
	{
		alu.setAdder(0);
		alu.setRegister(0);
		alu.setSubtractor(0);
		alu.setSize(0);
		cu.setClock(0);
	}
	CPU(int w, int x, int y, int z, float a)
	{
		alu.setAdder(w);
		alu.setRegister(x);
		alu.setSubtractor(y);
		alu.setSize(z);
		cu.setClock(a);
	}
	ALU getALU()
	{
		return alu;
	}
	ControlUnit getControlUnit()
	{
		return cu;
	}
	void setALU(const ALU& newALU)
	{
		alu = newALU;
	}
	void setControlUnit(const ControlUnit& newCU)
	{
		cu = newCU;
	}
};

class MainMemory {
private:
	int capacity;
	string technologyType;
public:
	MainMemory() : capacity(0), technologyType("") {};
	MainMemory(int initialCapacity, string initialTechnologyType) 
	{
		setCapacity(initialCapacity);
		setTechnologyType(initialTechnologyType);
	}

	int getCapacity() 
	{
		return capacity;
	}
	void setCapacity(int newCapacity) 
	{
		if (newCapacity >= 0) 
		{
			capacity = newCapacity;
		}
		else 
		{
			cout<<"Capacity cannot be negative!"<<endl;
		}
	}

	string getTechnologyType() 
	{
		return technologyType;
	}
	void setTechnologyType(string newTechnologyType) 
	{
		if (newTechnologyType == "Semiconductor" || newTechnologyType == "Silicon") 
		{
			technologyType = newTechnologyType;
		}
		else 
		{
			cout<<"Invalid technology type!"<<endl;
		}
	}
};

class Port {
private:
	string type;
	int baud_rate;
public:
	Port() :type(""), baud_rate(0) {};
	Port(string initialType, int initialBaudRate) 
	{
		setType(initialType);
		setBaudRate(initialBaudRate);
	}

	string getType() 
	{
		return type;
	}
	void setType(string newType) 
	{
		if (newType == "VGI" || newType == "I/O" || newType == "USB" || newType == "HDMI") 
		{
			type = newType;
		}
		else 
		{
			cout<<"Invalid port type!"<<endl;
		}
	}

	int getBaudRate() 
	{
		return baud_rate;
	}
	void setBaudRate(int newBaudRate)
	{
		if (newBaudRate >= 0) 
		{
			baud_rate = newBaudRate;
		}
		else 
		{
			cout << "Baud rate cannot be negative" << endl;
		}
	}
};

class MotherBoard {
private:
	MainMemory mm;
	Port ports[5];
	int numPorts;
public:
	MotherBoard() : mm(), numPorts(0) {};
	MotherBoard(const MainMemory& memory, const Port portsArray[], int numPorts) : mm(memory), numPorts(numPorts) 
	{
		for (int i = 0; i < numPorts; i++) 
		{
			ports[i] = portsArray[i];
		}
	}

	MainMemory getMainMemory() const
	{
		return mm;
	}

	void setMainMemory(const MainMemory& newmm)
	{
		mm = newmm;
	}

	const Port* getPorts() const {
		return ports;
	}
	int getNumPorts() const {
		return numPorts;
	}

	void setPorts(const Port portsArray[], int numPorts) 
	{
		if (numPorts <= 5) {
			for (int i = 0; i < numPorts; i++) 
			{
				ports[i] = portsArray[i];
			}
			this->numPorts = numPorts;
		}
		else 
		{
			cout<< "Exceeded maximum number of ports!" << endl;
		}
	}
};

class PhysicalMemory {
protected:
	int capacity;
public:
	PhysicalMemory() : capacity(0) {};
	PhysicalMemory(int x)
	{
		setCapacity(x);
	}
	int getCapacity()
	{
		return capacity;
	}
	void setCapacity(int x)
	{
		if (x >= 0)
			capacity = x;
		else
			cout << "Enter correct value for capacity!" << endl;
	}
};
class DDR4 : public PhysicalMemory {
public:
	DDR4() : PhysicalMemory() {}
	DDR4(int capacity) : PhysicalMemory(capacity) {}
};

class DDR5 : public PhysicalMemory {
public:
	DDR5() : PhysicalMemory() {}
	DDR5(int capacity) : PhysicalMemory(capacity) {}
};

class LPDDR4 : public PhysicalMemory {
public:
	LPDDR4() : PhysicalMemory() {}
	LPDDR4(int capacity) : PhysicalMemory(capacity) {}
};

class LPDDR5 : public PhysicalMemory {
public:
	LPDDR5() : PhysicalMemory() {}
	LPDDR5(int capacity) : PhysicalMemory(capacity) {}
};


class Computer {
protected:
	PhysicalMemory* pm;
	MotherBoard* mb;
	CPU* cpu;
public:
	Computer() :pm(nullptr), mb(nullptr), cpu(nullptr) {};
	Computer(PhysicalMemory* physicalMemory, MotherBoard* motherBoard, CPU* processor) : pm(physicalMemory), mb(motherBoard), cpu(processor) {};
	~Computer()
	{
		delete pm;
		delete mb;
		delete cpu;
	}

	PhysicalMemory* getPhysicalMemory()const
	{
		return pm;
	}
	MotherBoard* getMotherBoard()const
	{
		return mb;
	}
	CPU *getCPU()const
	{
		return cpu;
	}

	void setPhysicalMemory(PhysicalMemory* PM)
	{
		pm = PM;
	}
	void setMotherBoard(MotherBoard* MB)
	{
		mb = MB;
	}
	void setCPU(CPU* newCPU)
	{
		cpu = newCPU;
	}
};


class GraphicsCard {
protected:
	string brand;
	int memorySize;
	double price;
public:

	GraphicsCard() :brand(""), memorySize(0), price(0.0) {};
	GraphicsCard(string initialBrand, int size, double cost) :brand(initialBrand), memorySize(size), price(cost) {};

	string getBrand()const
	{
		return brand;
	}
	void setBrand(string initialBrand)
	{
		brand = initialBrand;
	}
	int getMemorySize() const {
		return memorySize;
	}

	void setMemorySize(int newMemorySize) {
		memorySize = newMemorySize;
	}

	double getPrice() const 
	{
		return price;
	}

	void setPrice(double newPrice) 
	{
		price = newPrice;
	}
};

class NvidiaGPU : public GraphicsCard {
public:
	NvidiaGPU() : GraphicsCard() {}
	NvidiaGPU(std::string brand, int memorySize, double price)
		: GraphicsCard(brand, memorySize, price) {}
};

class AMDGPU : public GraphicsCard {
public:
	AMDGPU() : GraphicsCard() {}
	AMDGPU(std::string brand, int memorySize, double price)
		: GraphicsCard(brand, memorySize, price) {}
};

class AppleGPU : public GraphicsCard {
public:
	AppleGPU() : GraphicsCard() {}
	AppleGPU(std::string brand, int memorySize, double price)
		: GraphicsCard(brand, memorySize, price) {}
};

class StorageDevice {
protected:
	string type;
	int capacity;
	double price;
public:
	StorageDevice() :type(""), capacity(0), price(0.0) {};
	StorageDevice(string s, int cap, double cost) :type(s), capacity(cap), price(cost) {};


	string getType()const
	{
		return type;
	}
	void setType(string s)
	{
		type = s;
	}
	int getCapacity()
	{
		return capacity;
	}
	void setCapacity(int x)
	{
		if (x >= 0)
			capacity = x;
		else
			cout << "Enter correct value for capacity!" << endl;
	}
	double getPrice() const 
	{
		return price;
	}

	void setPrice(double newPrice)
	{
		price = newPrice;
	}
};

class HDD : public StorageDevice {
public:
	HDD() : StorageDevice() {}
	HDD(std::string type, int capacity, double price)
		: StorageDevice(type, capacity, price) {}
};

class SSD : public StorageDevice {
public:
	SSD() : StorageDevice() {}
	SSD(std::string type, int capacity, double price)
		: StorageDevice(type, capacity, price) {}
};

class ConsumerHDD : public HDD {
public:
	ConsumerHDD() : HDD() {}
	ConsumerHDD(std::string type, int capacity, double price)
		: HDD(type, capacity, price) {}
};

class NASHDD : public HDD {
public:
	NASHDD() : HDD() {}
	NASHDD(std::string type, int capacity, double price)
		: HDD(type, capacity, price) {}
};

class NetworkCard {
protected:
	string type;
	int speed;
	double price;
public:
	NetworkCard():type(""), speed(0), price(0.0) {};
	NetworkCard(string s, int spd, double cost) :type(s), speed(spd), price(cost) {};
	string getType()const
	{
		return type;
	}
	void setType(string s)
	{
		type = s;
	}
	int getSpeed()
	{
		return speed;
	}
	void setSpeed(int x)
	{
		if (x >= 0)
			speed = x;
		else
			cout << "Enter correct value for speed!" << endl;
	}
	double getPrice() const
	{
		return price;
	}
	void setPrice(double newPrice)
	{
		price = newPrice;
	}
};

class EthernetCard : public NetworkCard {
public:
	EthernetCard() : NetworkCard() {}
	EthernetCard(std::string type, int speed, double price)
		: NetworkCard(type, speed, price) {}
};

class WiFiCard : public NetworkCard {
public:
	WiFiCard() : NetworkCard() {}
	WiFiCard(std::string type, int speed, double price)
		: NetworkCard(type, speed, price) {}
};

class PowerSupply {
private:
	int wattage;
	string efficiencyRating;
	double price;
public:
	PowerSupply() :wattage(0), efficiencyRating(""), price(0.0) {};
	PowerSupply(int x, string s, double p) :wattage(x), efficiencyRating(s), price(p) {};

	int getWattage()
	{
		return wattage;
	}
	void setWattage(int x)
	{
		if (x >= 0)
			wattage = x;
		else
			cout << "Enter correct value for wattage!" << endl;
	}
	string getEfficiencyRating()const
	{
		return efficiencyRating;
	}
	void setEfficiencyRating(string s)
	{
		efficiencyRating= s;
	}
	double getPrice() const
	{
		return price;
	}
	void setPrice(double newPrice)
	{
		price = newPrice;
	}
};

class Battery {
private:
	int capacity;
public:
	Battery() :capacity(0) {};
	Battery(int x) :capacity(x) {};
	int getCapacity()
	{
		return capacity;
	}
	void setCapacity(int x)
	{
		if (x >= 0)
			capacity = x;
		else
			cout << "Enter correct value for capacity!" << endl;
	}
};

class Case {
private:
	string formFactor;
	string color;
public:
	Case() :formFactor(""), color("") { };
	Case(string s, string d) :formFactor(s), color(d) {};

	string getFormFactor()const
	{
		return formFactor;
	}
	void setFormFactor(string s)
	{
		formFactor = s;
	}
	string getColor()const
	{
		return color;
	}
	void setColor(string d)
	{
		color = d;
	}
};

class ComputerAssembly{
private:
	Computer comp;
	GraphicsCard gpu;
	StorageDevice storage;
	NetworkCard network;
	PowerSupply power;
	Battery battery;
	Case pcCase;
	double totalPrice;
public:
	ComputerAssembly() : totalPrice(0.0) {}
	ComputerAssembly(const Computer& c, const GraphicsCard& g, const StorageDevice& s, const NetworkCard& n,
		const PowerSupply& p, const Battery& b, const Case& pc, double price) :
		comp(c), gpu(g), storage(s), network(n), power(p), battery(b), pcCase(pc), totalPrice(price) {}

	Computer getComputer() const { return comp; }
	GraphicsCard getGraphicsCard() const { return gpu; }
	StorageDevice getStorageDevice() const { return storage; }
	NetworkCard getNetworkCard() const { return network; }
	PowerSupply getPowerSupply() const { return power; }
	Battery getBattery() const { return battery; }
	Case getCase() const { return pcCase; }
	double getPrice()
	{
		return totalPrice;
	}
	void setComputer(const Computer& newComp) { comp = newComp; }
	void setGraphicsCard(const GraphicsCard& newGpu) { gpu = newGpu; }
	void setStorageDevice(const StorageDevice& newStg) { storage = newStg; }
	void setNetworkCard(const NetworkCard& newNtwrk) { network = newNtwrk; }
	void setPowerSupply(const PowerSupply& newPower) { power = newPower; }
	void setBattery(const Battery& newBattery) { battery = newBattery; }
	void setCase(const Case& newHousing) { pcCase = newHousing; }
	void setPrice(double p)
	{
		totalPrice = p;
	}
	double calculatePrice()
	{
		return gpu.getPrice() + storage.getPrice() + network.getPrice() + power.getPrice();
	}
};