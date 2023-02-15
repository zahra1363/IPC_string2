#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
  #include <sys/stat.h>



int main(int argc, char **argv)
{
    char * myfifo = (char*)"/home/solmaz/Documents/intership c++ code/myfifo";// Change to your desired pipe name
    int ret = mkfifo(myfifo, 0666);

    // Get the user input
    std::string input;
    std::cout << "Enter a message to send: ";
    std::getline(std::cin, input);

    // Open the named pipe for writing
    int write_fd = open(myfifo, O_WRONLY);
    
    // Write the user input to the named pipe
    const char *message = input.c_str();
    write(write_fd, message, strlen(message) + 1);

    // Close the named pipe for writing
    close(write_fd);

    return 0;
}