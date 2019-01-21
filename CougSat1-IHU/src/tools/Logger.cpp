#include "Logger.h"

Logger::Logger(){

}

//Constructor with the filepath as an argument
//path is the filepath including the name of the file itself
Logger::Logger(std::string path){
    filepath = path;
}

//Writes to log file specified in constructor
void Logger::write(std::string logMessage){
    
    //opening stream to log file
    std::ofstream logStream;
    logStream.open(this->filepath.c_str(), std::fstream::app);

    //raw time is the time in seconds since the device was powered
    time_t rawtime;
    time (&rawtime);

    //localtime converts seconds to date format
    struct tm * timeinfo;
    timeinfo = localtime (&rawtime);

    //writing to file
    //asctime converts timeinfo into a string
    //if the time on the board has not been set then the time will start with the date Jan 1 1970
    logStream << asctime(timeinfo) << logMessage << std::endl;
    logStream.close();
}

//Static write function for use in the Event Queue
void Logger::write(std::string logMessage, std::string logFilePath){
    
    //opening stream to log file
    std::ofstream logStream;
    logStream.open(logFilePath.c_str(), std::fstream::app);

    //raw time is the time in seconds since the device was powered
    time_t rawtime;
    time (&rawtime);

    //localtime converts seconds to date format
    struct tm * timeinfo;
    timeinfo = localtime (&rawtime);

    //writing to file
    //asctime converts timeinfo into a string
    //if the time on the board has not been set then the time will start with the date Jan 1 1970
    logStream << asctime(timeinfo) << logMessage << std::endl;
    logStream.close();
}


    

