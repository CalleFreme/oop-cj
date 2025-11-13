#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <random>

// ===============================
// En enkel sensorsimulering
// ===============================
class Sensor {
    std::string name;
    double minValue;
    double maxValue;

public:
    Sensor(std::string n, double minV, double maxV)
        : name(std::move(n)), minValue(minV), maxValue(maxV) {
    }

    std::string getName() const { return name; }

    // Simulerar en mätning med slumpvärde
    double read() const {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(minValue, maxValue);
        return dist(gen);
    }
};

// ===============================
// Central styrklass som lagrar mätvärden
// ===============================
class SystemController {
    std::vector<double> measurements; // Gemensam lista för alla trådar
    mutable std::mutex mtx;           // Mutex för trådsäker åtkomst

public:
    // Lägger till ett mätvärde i listan, trådsäkert
    void addMeasurement(double value) {
        std::lock_guard<std::mutex> lock(mtx); // Automatisk låsning
        measurements.push_back(value);
    }

    // Hämtar en kopia av alla mätvärden, trådsäkert
    std::vector<double> getMeasurements() const {
        std::lock_guard<std::mutex> lock(mtx);
        return measurements; // Returnerar kopia för säker läsning
    }

    // Räknar antalet registrerade mätvärden
    size_t count() const {
        std::lock_guard<std::mutex> lock(mtx);
        return measurements.size();
    }
};

// ===============================
// Funktion som körs i varje tråd
// ===============================
void sensorWorker(SystemController& controller, const Sensor& sensor) {
    for (int i = 0; i < 10; ++i) {
        double reading = sensor.read();
        controller.addMeasurement(reading);

        // Simulerar tidsintervall mellan mätningar
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// ===============================
// Huvudprogram
// ===============================
int main() {
    SystemController controller;

    // Skapar tre sensorer med olika intervall
    Sensor temp("TempSensor", -10.0, 40.0);
    Sensor hum("HumiditySensor", 0.0, 100.0);
    Sensor air("AirQualitySensor", 0.0, 500.0);

    // Startar en tråd per sensor
    std::thread t1(sensorWorker, std::ref(controller), std::ref(temp));
    std::thread t2(sensorWorker, std::ref(controller), std::ref(hum));
    std::thread t3(sensorWorker, std::ref(controller), std::ref(air));

    // Väntar tills alla trådar är klara
    t1.join();
    t2.join();
    t3.join();

    // Sammanställer resultat
    std::cout << "Totalt antal mätningar: " << controller.count() << "\n";

    auto allValues = controller.getMeasurements();
    std::cout << "Exempelvärden:\n";
    for (size_t i = 0; i < std::min(allValues.size(), size_t(5)); ++i) {
        std::cout << "  " << allValues[i] << "\n";
    }

    return 0;
}