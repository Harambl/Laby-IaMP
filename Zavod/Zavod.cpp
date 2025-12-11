#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>

using std::string;
using std::vector;


class PowerTool
{
private:

    string id;
    string type;
    string name;
    string power;
    string cost;

public:
    PowerTool() = default;
    PowerTool(string id, string type, string name, string power, string cost) : id(id), type(type), name(name), power(power), cost(cost) {}

    string toText() {
        return id + "|" + name + "|" + type + "|" + power + "|" + cost;
    }

    void verify() {
        if (id != "" && type != "" && name != "" && power != "" && cost != "") {
            if (std::stoi(id) > 0 && std::stoi(power) >= 0 && std::stoi(cost) >= 1000 && std::stoi(cost) <= 100000) {
                std::cout << "Correct" << "\n";
            }
            else {
                std::cout << "Incorrect" << "\n";
            }
        }
        else {
            std::cout << "Not enough info" << "\n";
        }
    }

    static PowerTool fromText(string& info) {
        int currIndex = 0;
        string id = "";
        string type = "";
        string name = "";
        string power = "";
        string cost = "";
        for (int i = 0; i < info.length(); i++) {
            if (info[i] != '|') {
                id += info[i];
            }
            else {
                currIndex = i + 1;
                break;
            }
        }

        for (int i = currIndex; i < info.length(); i++) {
            if (info[i] != '|') {
                name += info[i];
            }
            else {
                currIndex = i + 1;
                break;
            }
        }

        for (int i = currIndex; i < info.length(); i++) {
            if (info[i] != '|') {
                type += info[i];
            }
            else {
                currIndex = i + 1;
                break;
            }
        }

        for (int i = currIndex; i < info.length(); i++) {
            if (info[i] != '|') {
                power += info[i];
            }
            else {
                currIndex = i + 1;
                break;
            }
        }

        for (int i = currIndex; i < info.length(); i++) {
            cost += info[i];
        
        }
        return PowerTool(id, type, name, power, cost);
    }
};


class Workshop {
public:

    Workshop(const string& name, const string& date)
        : WorkshopName(name), InventoryDay(date) {
    }

    Workshop(const string& name, const string& date, vector<PowerTool>& tools)
        : WorkshopName(name), InventoryDay(date), Tools(tools) {
    }

    void addNewTool(PowerTool tool) {
        Tools.push_back(tool);
    }

    string toText() {
        string finalstr = WorkshopName + '|' + InventoryDay + '|';
        for (PowerTool tool : Tools) {
            finalstr += tool.toText() + " ";
        }
        
        return finalstr;
    }

    static Workshop fromText(string& info) {
        int currIndex = 0;
        string workshopName = "";
        string Date = "";
        vector<PowerTool> tools;
        string tool = "";

        for (int i = 0; i < info.length(); i++) {
            if (info[i] != '|') {
                workshopName += info[i];
            }
            else {
                currIndex = i + 1;
                break;
            }
        }

        for (int i = currIndex; i < info.length(); i++) {
            if (info[i] != '|') {
                Date += info[i];
            }
            else {
                currIndex = i + 1;
                break;
            }
        }
        for (int i = currIndex; i < info.length(); i++) {
            if (info[i] != ' ') {
                tool += info[i];
            }
            else {
                PowerTool Instrument = PowerTool::fromText(tool);
                tools.push_back(Instrument);
                tool = "";
            }
        }
        return Workshop(workshopName, Date, tools);
    }

    string getName() const { return WorkshopName; }
    string getDay() const { return InventoryDay; }
    vector<PowerTool> getTools() const { return Tools; }

    void saveWorkshopToFile(const string& filename) {
        std::ofstream file(filename);
        file << WorkshopName << "\n";
        file << InventoryDay << "\n";
        for (PowerTool& tool : Tools) {
            file << tool.toText() << "\n";
        }
        file.close();
    }

    Workshop loadWorkshopFromFile(const string& filename) {
        std::ifstream file(filename);

        string name, date;
        std::getline(file, name);
        std::getline(file, date);

        PowerTool tool;
        vector<PowerTool> tools;
        string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                tool = PowerTool::fromText(line);
                tools.push_back(tool);
            }
        }
        file.close();

        return Workshop(name, date, tools);
    }


private:

    string WorkshopName;
    vector<PowerTool> Tools;
    string InventoryDay;

};

int main()
{
    PowerTool Instrument1("1", "USM", "Bolgarka", "2200", "15000");
    string serializedI = Instrument1.toText();
    std::cout << Instrument1.toText() << "\n";
    PowerTool Instrument1dup = PowerTool::fromText(serializedI);
    std::cout << Instrument1dup.toText() << "\n";
    Instrument1.verify();

    PowerTool Instrument2("3", "CPY", "Stanok", "4000", "80000");
    PowerTool Instrument3("5", "OPO", "Laser", "3200", "60500");
    PowerTool Instrument4("9", "VAR", "Perforator", "2700", "50000");
    PowerTool Instrument5("2", "KOH", "Drel", "1000", "10000");
    PowerTool Instrument6("6", "FGT", "Svarka", "2500", "20000");

    Workshop Factory1("Gorkiy", "20.11.2024");
    Factory1.addNewTool(Instrument1);
    Factory1.addNewTool(Instrument2);
    Factory1.addNewTool(Instrument5);
    Factory1.addNewTool(Instrument6);
    std::cout << Factory1.toText() << "\n";
    string serializedF = Factory1.toText();
    Workshop Factory1dup = Workshop::fromText(serializedF);
    std::cout << Factory1dup.toText() << "\n";

    Workshop Factory2("ZAZ", "20.11.2020");
    Factory2.addNewTool(Instrument1dup);
    Factory2.addNewTool(Instrument3);
    Factory2.addNewTool(Instrument4);

    Factory1.saveWorkshopToFile("input.txt");
    Factory2.saveWorkshopToFile("input.txt");
    Workshop Factory1load = Factory1.loadWorkshopFromFile("input.txt");
    std::cout << Factory1load.toText() << "\n";
}
