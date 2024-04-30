/*
Name: Raahim Ibrar
Roll number: 23i-0612
Section: F
Instructor: Ma'am Marium Hida
TA: Ariyan Chaudhary
*/
#include <iostream>
#include "C:\Users\Raahim\Documents\2nd Semester\Object Oriented Programming\a3\a3\Header.h"

using namespace std;

int main()
{
	int selection;
	cout << "1. PC\n2. Mac\n" << endl;
	cin >> selection;
	if (selection == 1)
	{
        int adders, subtractors, registers, size;
        cout << "Enter number of adders: ";
        cin >> adders;
        cout << "Enter number of subtractors: ";
        cin >> subtractors;
        cout << "Enter number of registers: ";
        cin >> registers;
        cout << "Enter size of registers: ";
        cin >> size;

        ALU alu(adders, subtractors, registers, size);

        // Input for ControlUnit
        float clock;
        cout << "Enter clock value: ";
        cin >> clock;

        ControlUnit cu(clock);

        CPU* cpu = new CPU(adders, subtractors, registers, size, clock);

        // Input for MainMemory
        int capacity;
        string technologyType;
        cout << "Enter MainMemory capacity: ";
        cin >> capacity;
        cout << "Enter technology type (Semiconductor/Silicon): ";
        cin >> technologyType;

        MainMemory mm(capacity, technologyType);

        // Input for Port
        string type;
        int baud_rate;
        cout << "Enter Port type (VGI/I/O/USB/HDMI): ";
        cin >> type;
        cout << "Enter baud rate: ";
        cin >> baud_rate;

        Port port(type, baud_rate);

        // Input for MotherBoard
        MainMemory memory = mm;
        Port ports[] = { port };
        int numPorts = 1;

        MotherBoard* mb = new MotherBoard(memory, ports, numPorts);


        // Input for PhysicalMemory (choose one type)
        int pm_capacity;
        cout << "Enter PhysicalMemory capacity: ";
        cin >> pm_capacity;

        PhysicalMemory* pm = new PhysicalMemory(pm_capacity);
        Computer comp(pm, mb, cpu);
        // Input for GraphicsCard
        string brand;
        int memorySize;
        double price;
        cout << "Enter GraphicsCard brand: ";
        cin >> brand;
        cout << "Enter GraphicsCard memory size: ";
        cin >> memorySize;
        cout << "Enter GraphicsCard price: ";
        cin >> price;

        GraphicsCard gpu(brand, memorySize, price);

        // Input for StorageDevice (choose one type)
        // For example, HDD
        string storageType;
        int storageCapacity;
        double storagePrice;
        cout << "Enter StorageDevice type: ";
        cin >> storageType;
        cout << "Enter StorageDevice capacity: ";
        cin >> storageCapacity;
        cout << "Enter StorageDevice price: ";
        cin >> storagePrice;

        HDD storage(storageType, storageCapacity, storagePrice);

        // Input for NetworkCard (choose one type)
        // For example, EthernetCard
        string networkType;
        int networkSpeed;
        double networkPrice;
        cout << "Enter NetworkCard type: ";
        cin >> networkType;
        cout << "Enter NetworkCard speed: ";
        cin >> networkSpeed;
        cout << "Enter NetworkCard price: ";
        cin >> networkPrice;

        EthernetCard network(networkType, networkSpeed, networkPrice);

        // Input for PowerSupply
        int wattage;
        string efficiencyRating;
        double powerPrice;
        cout << "Enter PowerSupply wattage: ";
        cin >> wattage;
        cout << "Enter PowerSupply efficiency rating: ";
        cin >> efficiencyRating;
        cout << "Enter PowerSupply price: ";
        cin >> powerPrice;

        PowerSupply power(wattage, efficiencyRating, powerPrice);

        // Input for Battery
        int batteryCapacity;
        cout << "Enter Battery capacity: ";
        cin >> batteryCapacity;

        Battery battery(batteryCapacity);

        // Input for Case
        string formFactor, color;
        cout << "Enter Case form factor: ";
        cin >> formFactor;
        cout << "Enter Case color: ";
        cin >> color;
        Case pcCase(formFactor, color);
        ComputerAssembly PC(comp, gpu, storage, network, power, battery, pcCase, 0.0);
        cout << "Assembled Computer Details:" << endl;
        cout << "ALU: Adders=" << alu.getAdder() << ", Subtractors=" << alu.getSubtractor() << ", Registers=" << alu.getRegister() << ", Size=" << alu.getSize() << endl;
        cout << "Control Unit: Clock=" << cu.getClock()<<" GHz" << endl;
        cout << "Main Memory: Capacity=" << mm.getCapacity() << " GB" << endl;
        cout << "Technology Type=" << mm.getTechnologyType() << endl;
        cout << "Motherboard: Memory Capacity=" << memory.getCapacity() << " GB" << endl;
        cout << "Number of Ports=" << numPorts << endl;
        cout << "Physical Memory: Capacity=" << pm->getCapacity()<< " GB" << endl;
        cout << "Graphics Card: Brand=" << gpu.getBrand() << ", Memory Size=" << gpu.getMemorySize() << ", Price=" << gpu.getPrice() << endl;
        cout << "Storage Device: Type=" << storage.getType() << ", Capacity=" << storage.getCapacity() << ", Price=" << storage.getPrice() << endl;
        cout << "Network Card: Type=" << network.getType() << ", Speed=" << network.getSpeed() << ", Price=" << network.getPrice() << endl;
        cout << "Power Supply: Wattage=" << power.getWattage() << ", Efficiency Rating=" << power.getEfficiencyRating() << ", Price=" << power.getPrice() << endl;
        cout << "Battery: Capacity=" << battery.getCapacity() << endl;
        cout << "Case: Form Factor=" << pcCase.getFormFactor() << ", Color=" << pcCase.getColor() << endl;
        cout << "Final Price: "<< PC.calculatePrice();
  
        delete cpu;
        delete mb;
        delete pm;
        
	}
	
    if (selection == 2)
    {
        int adders, subtractors, registers, size;
        cout << "Enter number of adders: ";
        cin >> adders;
        cout << "Enter number of subtractors: ";
        cin >> subtractors;
        cout << "Enter number of registers: ";
        cin >> registers;
        cout << "Enter size of registers: ";
        cin >> size;

        ALU alu(adders, subtractors, registers, size);

        // Input for ControlUnit
        float clock;
        cout << "Enter clock value: ";
        cin >> clock;

        ControlUnit cu(clock);

        CPU* cpu = new CPU(adders, subtractors, registers, size, clock);

        // Input for MainMemory
        int capacity;
        string technologyType;
        cout << "Enter MainMemory capacity: ";
        cin >> capacity;
        cout << "Enter technology type (Semiconductor/Silicon): ";
        cin >> technologyType;

        MainMemory mm(capacity, technologyType);

        // Input for Port
        string type;
        int baud_rate;
        cout << "Enter Port type (VGI/I/O/USB/HDMI): ";
        cin >> type;
        cout << "Enter baud rate: ";
        cin >> baud_rate;

        Port port(type, baud_rate);

        // Input for MotherBoard
        MainMemory memory = mm;
        Port ports[] = { port };
        int numPorts = 1;

        MotherBoard* mb = new MotherBoard(memory, ports, numPorts);


        // Input for PhysicalMemory (choose one type)
        int pm_capacity;
        cout << "Enter PhysicalMemory capacity: ";
        cin >> pm_capacity;

        PhysicalMemory* pm = new PhysicalMemory(pm_capacity);
        Computer comp(pm, mb, cpu);
        // Input for GraphicsCard
        string brand = "Apple Integrated GPU";
        int memorySize=8;
        double price=0;
       

        GraphicsCard gpu(brand, memorySize, price);

        // Input for StorageDevice (choose one type)
        // For example, HDD
        string storageType;
        int storageCapacity;
        double storagePrice;
        cout << "Enter StorageDevice type: ";
        cin >> storageType;
        cout << "Enter StorageDevice capacity: ";
        cin >> storageCapacity;
        cout << "Enter StorageDevice price: ";
        cin >> storagePrice;

        HDD storage(storageType, storageCapacity, storagePrice);

        // Input for NetworkCard (choose one type)
        // For example, EthernetCard
        string networkType;
        int networkSpeed;
        double networkPrice;
        cout << "Enter NetworkCard type: ";
        cin >> networkType;
        cout << "Enter NetworkCard speed: ";
        cin >> networkSpeed;
        cout << "Enter NetworkCard price: ";
        cin >> networkPrice;

        EthernetCard network(networkType, networkSpeed, networkPrice);

        // Input for PowerSupply
        int wattage;
        string efficiencyRating;
        double powerPrice;
        cout << "Enter PowerSupply wattage: ";
        cin >> wattage;
        cout << "Enter PowerSupply efficiency rating: ";
        cin >> efficiencyRating;
        cout << "Enter PowerSupply price: ";
        cin >> powerPrice;

        PowerSupply power(wattage, efficiencyRating, powerPrice);

        // Input for Battery
        int batteryCapacity=0;

        Battery battery(batteryCapacity);

        // Input for Case
        string formFactor="", color;
        cout << "Enter Case color: " << endl;
        cin >> color;
        Case pcCase(formFactor, color);
        ComputerAssembly PC(comp, gpu, storage, network, power, battery, pcCase, 0.0);
        cout << "Assembled Computer Details:" << endl;
        cout << "ALU: Adders=" << alu.getAdder() << ", Subtractors=" << alu.getSubtractor() << ", Registers=" << alu.getRegister() << ", Size=" << alu.getSize() << endl;
        cout << "Control Unit: Clock=" << cu.getClock() << " GHz" << endl;
        cout << "Main Memory: Capacity=" << mm.getCapacity() << " GB" << endl;
        cout << "Technology Type=" << mm.getTechnologyType() << endl;
        cout << "Motherboard: Memory Capacity=" << memory.getCapacity() << " GB" << endl;
        cout << "Number of Ports=" << numPorts << endl;
        cout << "Physical Memory: Capacity=" << pm->getCapacity() << " GB" << endl;
        cout << "Graphics Card: Brand=" << gpu.getBrand() << ", Memory Size=" << gpu.getMemorySize() << ", Price=" << gpu.getPrice() << endl;
        cout << "Storage Device: Type=" << storage.getType() << ", Capacity=" << storage.getCapacity() << ", Price=" << storage.getPrice() << endl;
        cout << "Network Card: Type=" << network.getType() << ", Speed=" << network.getSpeed() << ", Price=" << network.getPrice() << endl;
        cout << "Power Supply: Wattage=" << power.getWattage() << ", Efficiency Rating=" << power.getEfficiencyRating() << ", Price=" << power.getPrice() << endl;
        cout << "Color = " << pcCase.getColor() << endl;
        int finalPrice = PC.calculatePrice() + 20000.00;
        cout << "Final Price: " << finalPrice;

        delete cpu;
        delete mb;
        delete pm;
    }


	return 0;
}