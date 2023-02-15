#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <fstream>

int main(int argc, char **argv)
{
    char * myfifo = (char*)"/home/solmaz/Documents/intership c++ code/myfifo"; // Change to your desired pipe name
    const char* text_file = (char*)"/home/solmaz/Documents/intership c++ code/text_file.txt"; 
    
    // Open the named pipe for reading
    int read_fd = open(myfifo, O_RDONLY);

    // Read the string from the named pipe
    char buffer[1024];
    read(read_fd, buffer, sizeof(buffer));
    std::cout << "Received message: " << buffer << std::endl;
    std::cout << "message is writting in the text file ..." << std::endl;

 // Open the file for writing
    std::ofstream outfile;
    outfile.open(text_file);

    // Write the string to the file
    outfile << buffer;

    // Close the file
    outfile.close();


    // Close the named pipe for reading
    close(read_fd);

    return 0;
}