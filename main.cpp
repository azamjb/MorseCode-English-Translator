#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

#include "message.h"

int main() {
    char gptOrNot;  /*! character to represent the User's choice */
    bool quit = false; //Flag to indicate whether the user wants to quit

    do{
        std::cout << "Would you like to use ChatGPT to translate (Y/N/Q): ";  // prompt the User to choose between using ChatGPT or not
        std::cin >> gptOrNot;   // store their answer in the gptOrNot variable
        
        std::cout << "\n";  // line break

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the line break added when taking input

        if (gptOrNot == 'Y' || gptOrNot == 'y') {   // if the User chose TO use ChatGPT

            std::string selectionAI;  /*! string variable representing the User's selection of morse to english/english to morse translation */

            std::cout << "\n(Using AI) Type 'english' to translate from english to morse or 'morse' for the opposite: ";   //prompt User for their selection of translation method
            std::getline(std::cin, selectionAI);

            std::string combStr = "python gpt.py '"+ selectionAI + "'";
            const char* command = combStr.c_str();
            system(command);
        }
        else if (gptOrNot == 'N' || gptOrNot == 'n') {  // if the User chose NOT to use ChatGPT
            std::string selection;  /*! string variable representing the User's selection of morse to english/english to morse translation */
            Message message;        /*! message object representing the User's message */

            std::cout << "\nType 'english' to translate from english to morse or 'morse' for the opposite: ";   //prompt User for their selection of translation method
            std::getline(std::cin, selection);  // store their selection in the selection variable

            std::cout << "\n";  // line break
            
            message.selection = selection;      //  set the selection property of the message object to the User's selection
            message.translateMessage(message);  //  call the translateMessage() function on the message
        }
        else if (gptOrNot == 'Q' || gptOrNot == 'q'){
            quit = true; //Set quit flag to true to exit do while loop.
        }
        else {  // if the User did not enter 'Y/y' or 'N/n'
            std::cout << "Invalid input, restarting...\n\n";

            main(); // restart the application
        }
    } while (!quit);

    return 0;
}