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
    static void write(std::string filename, std::string logMsg);
  
};

