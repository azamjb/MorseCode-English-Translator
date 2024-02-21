#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include "message.h"

std::map<char, std::string> engDictionary;      /*! Map storing keys of English and values of Morse Code */
std::map<std::string, char> morseDictionary;    /*! Map storing keys of Morse Code and values of English */

/************************************************
 * \brief This function translates a string from English to Morse Code.
 * 
 * This function takes in a string of English and translates it to Morse Code. It does so by iterating through the string of characters and finding the corresponding
 * Morse Code character in the engDictionary map. It appends each value to a new string called translation which it then returns as the final, translated string.
 * 
 * @param message String representing the message to be translated.
 * @return translation - String representing the translation of the message.
 ***********************************************/
std::string Message::translateEng(std::string message) {
    std::string translation = "";   /*! string representing the translated message*/

    for (char &c : message) {   // for the characters in the message
        c = std::tolower(c);    // convert them to lowercase
    }

    for (int i = 0; i < message.length(); i++) {    // for each character in the message
        char current = message[i];  // variable storing the current character
        if (current == ' ') {       
            translation += "/ ";    // if the current character is a space, append '/' to the translation (space in morse code)
        }   
        else {
            translation += (engDictionary[current] + " ");  // else append the corresponding morse code to the translation based on the English key.
        }
    }

    return translation; // return the translated string
}

/************************************************
 * \brief This function translates a string from Morse Code to English.
 * 
 * This function takes in a string of morse code and translates it to English. It does so by splitting the string at every space to get each occurence of an English character
 * and finding the corresponding English character in the morseDictionary map. It appends each character to a new string called translation which it then returns as the final,
 * translated string.
 * 
 * @param message String representing the message to be translated.
 * @return translation - String representing the translation of the message.
 ***********************************************/
std::string Message::translateMorse(std::string message) {
    std::string translation = "";   /*! string representing the translated message*/

    std::istringstream iss(message);    
    std::vector<std::string> tokens;    // vector to store tokens of string

    std::string token;

    while (iss >> token) {  
        tokens.push_back(token);    // store token in vector
    }

    for (const std::string& t : tokens) {   // for each token
        if (t == "/") {     // if it is '/' (space in morse code) then append a space to translation string
            translation += " ";
        }
        else {  // else append the corresponding english value from the morseDictionary key.
            translation += morseDictionary[t];
        }
    }

    return translation;     // return the translated string
}

/************************************************
 * \brief This function creates the English dictionary.
 * 
 * When called, the following function maps key and value pairs to the engDictionary map to be used for translation.
 ***********************************************/
void Message::createEnglishDictionary() {
    engDictionary['a'] = ".-";
    engDictionary['b'] = "-...";
    engDictionary['c'] = "-.-.";
    engDictionary['d'] = "-..";
    engDictionary['e'] = ".";
    engDictionary['f'] = "..-.";
    engDictionary['g'] = "--.";
    engDictionary['h'] = "....";
    engDictionary['i'] = "..";
    engDictionary['j'] = ".---";
    engDictionary['k'] = "-.-";
    engDictionary['l'] = ".-..";
    engDictionary['m'] = "--";
    engDictionary['n'] = "-.";
    engDictionary['o'] = "---";
    engDictionary['p'] = ".--.";
    engDictionary['q'] = "--.-";
    engDictionary['r'] = ".-.";
    engDictionary['s'] = "...";
    engDictionary['t'] = "-";
    engDictionary['u'] = "..-";
    engDictionary['v'] = "...-";
    engDictionary['w'] = ".--";
    engDictionary['x'] = "-..-";
    engDictionary['y'] = "-.--";
    engDictionary['z'] = "--..";

    engDictionary[','] = "--..--";
    engDictionary['?'] = "..--..";
    engDictionary[':'] = "---...";
    engDictionary['-'] = "-....-";
    engDictionary['"'] = ".-..-.";
    engDictionary['('] = "-.--.";
    engDictionary[')'] = "-.--.-";
    engDictionary['='] = "-...-";
    engDictionary['.'] = ".-.-.-";
    engDictionary['/'] = "-..-.";
    engDictionary['\''] = ".----.";
    engDictionary['+'] = ".-.-.";
    engDictionary['@'] = ".--.-.";
    engDictionary['!'] = "-.-.--";

    engDictionary['1'] = ".----";
    engDictionary['2'] = "..---";
    engDictionary['3'] = "...--";
    engDictionary['4'] = "....-";
    engDictionary['5'] = ".....";
    engDictionary['6'] = "-....";
    engDictionary['7'] = "--...";
    engDictionary['8'] = "---..";
    engDictionary['9'] = "----.";
    engDictionary['0'] = "-----";
}

/************************************************
 * \brief This function creates the Morse Code dictionary.
 * 
 * When called, the following function maps key and value pairs to the morseDictionary map to be used for translation.
 ***********************************************/
void Message::createMorseDictionary() {
    morseDictionary[".-"] = 'a';
    morseDictionary["-..."] = 'b';
    morseDictionary["-.-."] = 'c';
    morseDictionary["-.."] = 'd';
    morseDictionary["."] = 'e';
    morseDictionary["..-."] = 'f';
    morseDictionary["--."] = 'g';
    morseDictionary["...."] = 'h';
    morseDictionary[".."] = 'i';
    morseDictionary[".---"] = 'j';
    morseDictionary["-.-"] = 'k';
    morseDictionary[".-.."] = 'l';
    morseDictionary["--"] = 'm';
    morseDictionary["-."] = 'n';
    morseDictionary["---"] = 'o';
    morseDictionary[".--."] = 'p';
    morseDictionary["--.-"] = 'q';
    morseDictionary[".-."] = 'r';
    morseDictionary["..."] = 's';
    morseDictionary["-"] = 't';
    morseDictionary["..-"] = 'u';
    morseDictionary["...-"] = 'v';
    morseDictionary[".--"] = 'w';
    morseDictionary["-..-"] = 'x';
    morseDictionary["-.--"] = 'y';
    morseDictionary["--.."] = 'z';

    morseDictionary["--..--"] = ',';
    morseDictionary["..--.."] = '?';
    morseDictionary["---..."] = ':';
    morseDictionary["-....-"] = '-';
    morseDictionary[".-..-."] = '"';
    morseDictionary["-.--."] = '(';
    morseDictionary["-.--.-"] = ')';
    morseDictionary["-...-"] = '=';
    morseDictionary[".-.-.-"] = '.';
    morseDictionary["-..-."] = '/';
    morseDictionary[".----."] = '\'';
    morseDictionary[".-.-."] = '+';
    morseDictionary[".--.-."] = '@';
    morseDictionary["-.-.--"] = '!';

    morseDictionary[".----"] = '1';
    morseDictionary["..---"] = '2';
    morseDictionary["...--"] = '3';
    morseDictionary["....-"] = '4';
    morseDictionary["....."] = '5';
    morseDictionary["-...."] = '6';
    morseDictionary["--..."] = '7';
    morseDictionary["---.."] = '8';
    morseDictionary["----."] = '9';
    morseDictionary["-----"] = '0';
}

/************************************************
 * \brief This function translates a User's message from English to Morse code or vice versa.
 * 
 * This function takes in a Message object as a parameter from the main.cpp file and uses the selection property to determine the translation method (i.e. english-morse),
 * then it prompts them for the message to be translated. Next it sets the translation property of the User's message to the translated value once it has called the appropriate
 * translation function. 
 * 
 * The translated message is then displayed to the User.
 * 
 * @param message Object of the class Message that represents the message to be translated.
 ***********************************************/
void Message::translateMessage(Message message) {
    if (message.selection == "english") {   // if the user chose to translate from English to Morse Code
        createEnglishDictionary();  // call the createEnglishDictionary function

        // prompt and read User input for the message to be translated
        std::cout << "What english sentence would you like to be translated to morse code? (Note: some special characters/punctuation may not work): ";
        std::getline(std::cin, message.inputMessage);
        
        // set the translation property of the message object to the User's input and call the translateEng function to translate it
        message.translation = translateEng(message.inputMessage);

        std::cout << "\n" << "Translated message is: " << message.translation << "\n\n";    // output the translated message
    }
    else if (message.selection == "morse") {    // else if the user chose to translate from Morse Code to English
        createMorseDictionary();    // call the createEnglishDictionary function

        // prompt and read User input for the message to be translated
        std::cout << "What morse code would you like to be translated to english? (Note: some special characters/punctuation may not work): ";
        std::getline(std::cin, message.inputMessage);

        // set the translation property of the message object to the User's input and call the translateEng function to translate it
        message.translation = translateMorse(message.inputMessage);

        // output the translated message
        std::cout << "\n" << "Translated message is: " << message.translation << "\n\n";
    }
    else {  // else the user did not enter "english" or "morse", restart
        std::cout << "You did not enter a valid option, restarting.\n\n";
        Message();
    }
}