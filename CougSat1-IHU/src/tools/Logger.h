#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger{

private:
    std::string filepath;


public:
    Logger(std::string logname);
    void write(std::string logMessage);
  
};

