/*! \file message.h
    \brief The header file for message.cpp.
    
    This file is the header file for message.cpp and contains the function and variable definitions for the Message class.
*/

/*! \class Message
 *  \brief The class representing a message.
 * The class containing the User's input message (message to be translated) as well as it's translation and the selection of their translation method. 
 */

/*! \var string selection 
 *  String representing the selection of the User's method of translation.
 */

/*! \var string inputMessage 
 *  String representing the User's input message (message to be translated).
 */

/*! \var string translation 
 *  String representing the translation of the User's input message.
 */

/*! \var map<char, string> engDictionary
 *  Map of character keys (English) and string values (Morse Code).
 */

/*! \var map<string, char> morseDictionary
 *  Map of string keys (Morse Code) and character values (English).
 */

/*! \fn translateMessage
 * Translates the inputMessage of a Message object in the desired manner.
 *
 * @param message Message object to be translated.
 */

/*! \fn translateEng
 * Translates a string of English characters to Morse Code.
 *
 * @param message String representing the message to be processed
 * @return String of the translated message.
 */

/*! \fn translateEng
 * Translates a string from Morse Code to English
 *
 * @param message String representing the message to be processed
 * @return String of the translated message.
 */

/*! \fn createEnglishDictionary
 * Creates a dictionary or map of matched English keys and Morse Code values.
 */

/*! \fn createMorseDictionary
 * Creates a dictionary or map of matched Morse Code keys and English values.
 */
#ifndef MESSAGE_H
#define MESSAGE_H

#include <map>
#include <string.h>

class Message {

public:
    std::string selection;
    std::string inputMessage;
    std::string translation;

    void translateMessage(Message);
private:
    std::map<char, std::string> engDictionary;
    std::map<std::string, char> morseDictionary;

    std::string translateEng(std::string);
    std::string translateMorse(std::string);
    void createEnglishDictionary();
    void createMorseDictionary();
};
#endif 