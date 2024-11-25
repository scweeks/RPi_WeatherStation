// WeatherStation.h : Include file for standard system include files,
// or project specific include files.

#pragma once
// File:  WeatherStation.h
#ifndef  WeatherStation.h
#define  WeatherStation.h

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>

// Interface for sensor data
class SensorDataIF {
public:
    virtual std::string GetData() const = 0;
    virtual bool SetData(const std::string& data) = 0;
    virtual ~SensorDataIF() = default;
};

// Concrete Sensor Data Types
class WindData : public SensorDataIF {
private:
    std::string data;
public:
    std::string GetData() const override { return data; }
    bool SetData(const std::string& data) override { this->data = data; return true; }
};

class TempData : public SensorDataIF {
private:
    std::string data;
public:
    std::string GetData() const override { return data; }
    bool SetData(const std::string& data) override { this->data = data; return true; }
};

class HumidityData : public SensorDataIF {
private:
    std::string data;
public:
    std::string GetData() const override { return data; }
    bool SetData(const std::string& data) override { this->data = data; return true; }
};

class BarometricData : public SensorDataIF {
private:
    std::string data;
public:
    std::string GetData() const override { return data; }
    bool SetData(const std::string& data) override { this->data = data; return true; }
};

// Sensor Interface
class SensorIF {
public:
    virtual std::shared_ptr<SensorDataIF> GetData() const = 0;
    virtual std::string GetSensorType() const = 0;
    virtual bool OpenConnection(const std::string& address) = 0;
    virtual bool WriteSensorData(const std::string& data) = 0;
    virtual ~SensorIF() = default;
};

// Concrete Sensors
class WindSensor : public SensorIF {
private:
    std::shared_ptr<SensorDataIF> data;
public:
    WindSensor() : data(std::make_shared<WindData>()) {}
    std::shared_ptr<SensorDataIF> GetData() const override { return data; }
    std::string GetSensorType() const override { return "Wind"; }
    bool OpenConnection(const std::string& address) override { return true; }
    bool WriteSensorData(const std::string& data) override { return this->data->SetData(data); }
};

class TemperatureSensor : public SensorIF {
private:
    std::shared_ptr<SensorDataIF> data;
public:
    TemperatureSensor() : data(std::make_shared<TempData>()) {}
    std::shared_ptr<SensorDataIF> GetData() const override { return data; }
    std::string GetSensorType() const override { return "Temperature"; }
    bool OpenConnection(const std::string& address) override { return true; }
    bool WriteSensorData(const std::string& data) override { return this->data->SetData(data); }
};

class HumiditySensor : public SensorIF {
private:
    std::shared_ptr<SensorDataIF> data;
public:
    HumiditySensor() : data(std::make_shared<HumidityData>()) {}
    std::shared_ptr<SensorDataIF> GetData() const override { return data; }
    std::string GetSensorType() const override { return "Humidity"; }
    bool OpenConnection(const std::string& address) override { return true; }
    bool WriteSensorData(const std::string& data) override { return this->data->SetData(data); }
};

class BarometricSensor : public SensorIF {
private:
    std::shared_ptr<SensorDataIF> data;
public:
    BarometricSensor() : data(std::make_shared<BarometricData>()) {}
    std::shared_ptr<SensorDataIF> GetData() const override { return data; }
    std::string GetSensorType() const override { return "Barometric"; }
    bool OpenConnection(const std::string& address) override { return true; }
    bool WriteSensorData(const std::string& data) override { return this->data->SetData(data); }
};

// Sensor Factory
class SensorFactory {
public:
    static std::shared_ptr<SensorIF> MakeSensor(const std::string& type) {
        if (type == "Wind") return std::make_shared<WindSensor>();
        if (type == "Temperature") return std::make_shared<TemperatureSensor>();
        if (type == "Humidity") return std::make_shared<HumiditySensor>();
        if (type == "Barometric") return std::make_shared<BarometricSensor>();
        return nullptr;
    }
};

// Sensor Manager
class SensorManager {
private:
    std::unordered_map<std::string, std::shared_ptr<SensorIF>> sensors;
public:
    bool AddSensor(const std::string& name, const std::string& type) {
        auto sensor = SensorFactory::MakeSensor(type);
        if (sensor) {
            sensors[name] = sensor;
            return true;
        }
        return false;
    }
    bool DelSensor(const std::string& name) {
        return sensors.erase(name) > 0;
    }
    std::shared_ptr<SensorIF> GetSensor(const std::string& name) const {
        auto it = sensors.find(name);
        return (it != sensors.end()) ? it->second : nullptr;
    }
};

// Connection Interface
class ConnectionIF {
public:
    virtual bool Open(int sockfd, int port) = 0;
    virtual bool Close() = 0;
    virtual ~ConnectionIF() = default;
};

// Concrete Connections
class Bluetooth : public ConnectionIF {
private:
    int sock = 0;
public:
    bool Open(int sockfd, int port) override { return true; }
    bool Close() override { return true; }
};

class Ethernet : public ConnectionIF {
private:
    int sock = 0;
public:
    bool Open(int sockfd, int port) override { return true; }
    bool Close() override { return true; }
};

// Connection Server
class ConnectionServer {
private:
    int server_id;
    int new_socket;
    struct sockaddr_in address;
    char buffer[1024] = { 0 };
    bool isETEnabled;
public:
    bool StartServer(int port) { return true; }
    bool EnableET(bool enable) { isETEnabled = enable; return true; }
};

// Weather Station
class WeatherStation {
private:
    ConnectionServer server;
    SensorManager manager;
    time_t time;
public:
    bool AddSensor(const std::string& name, const std::string& type) {
        return manager.AddSensor(name, type);
    }
    bool DelSensor(const std::string& name) {
        return manager.DelSensor(name);
    }
    bool UpdateDisplay() { return true; }
};

#endif // WEATHERSTATIONSYSTEM_H
