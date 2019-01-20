#include "Logger.h"

Logger::Logger(){

}


Logger::Logger(std::string path){
    filepath = path;
}

void Logger::write(std::string filename, std::string logMsg){
    
    //writing to file
    std::ofstream log;
    log.open(filename.c_str(), std::fstream::app);

    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    log << asctime(timeinfo) << logMsg << std::endl << std::endl;
    log.close();
}


    

