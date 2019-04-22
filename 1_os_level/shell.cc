#include "shell.hh"
#include <unistd.h>
int main()
{ std::string input;

  // ToDo: Vervang onderstaande regel: Laad prompt uit bestand
  std::string prompt = "ToDo: Laad de prompt uit een bestand! ";

  while(true)
  { std::cout << prompt;                   // Print het prompt
    std::getline(std::cin, input);         // Lees een regel
    if (input == "new_file") new_file();   // Kies de functie
    else if (input == "ls") list();        //   op basis van
    else if (input == "src") src();        //   de invoer
    else if (input == "find") find();
    else if (input == "python") python();
    else if (input == "exit") return 0;
    else if (input == "quit") return 0;
    else if (input == "error") return 1;

    if (std::cin.eof()) return 0; } }      // EOF is een exit

void new_file() {
    char filename[255];
    std::string text;
    int fd;
    std::cout << "enter filename: ";
    std::cin >> filename;

    fd = creat(filename, 0644);
    std::cin.ignore(1000, '\n');
    std::cout << "enter text: ";
    std::getline(std::cin,text);

    char fileText[text.size()];

    for(unsigned int i = 0; i < text.size(); i++){

        fileText[i] = text[i];

    }


    if (fd == -1) {
        std::cout << "cannot create file\n";
        return;
    }

    write(fd, fileText, text.size());
    close(fd);
    std::cout << "file created\n";
    return;
}

void list(){
    system("ls");
}


void find() // ToDo: Implementeer volgens specificatie.
{ std::cout << "ToDo: Implementeer hier find()" << std::endl; }

void python() // ToDo: Implementeer volgens specificatie.
{ std::cout << "ToDo: Implementeer hier python()" << std::endl; }

void src() // Voorbeeld: Gebruikt SYS_open en SYS_read om de source van de shell (shell.cc) te printen.
{ int fd = syscall(SYS_open, "shell.cc", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                           // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                   // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte; }                                  //   zet de gelezen byte in "byte" zodat deze geschreven kan worden.
