#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger{

private:
    std::string filepath;

public:
    Logger();
    Logger(std::string logname);
    void write(std::string logMessage);
    static void write(std::string logMessage, std::string logFilePath);
  
};

