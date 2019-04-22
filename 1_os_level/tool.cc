#include <iostream>
#include <string>

std::string translate(std::string input, std::string variabele){
    std::string result = "";// implementeer dit
    for(unsigned int i =0; i < variabele.size(); i++){
        if(variabele[i] == 'e'){

            result += "3";


        }
        else if(variabele[i] == 'l'){

            result += "1";

        }
        else if(variabele[i] == 't'){

            result += "7";

        }
        else if(variabele[i] == 'o'){

            result += "0";

        }
        else if(96 < int(variabele[i]) and int(variabele[i]) < 123){

            result += variabele[i]-32;
        }
        else{

            result += variabele[i];

        }



    }

    return result;
}

int main(int argc, char *argv[]){
    std::string s;

    if(argc != 2){
      std::cerr << "Deze functie heeft exact 1 argument nodig";
      return -1;
  }

  while(true){

      std::cin >> s;
      if(std::cin.eof()){
          return 0;
      }

      std::cout << translate(argv[1], s) << std::endl; } }
