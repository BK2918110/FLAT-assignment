#include <iostream>
#include <string>

// Include all module headers
#include "string_reversal.h"
#include "case_conversion.h"
#include "digit_to_word.h"
#include "vowel_consonant.h"
#include "binary_complement.h"
#include "tokenizer.h"

int main() {
    std::string input;
    std::string choice;

    std::cout << "=== FST Swiss Army Knife ===\n";
    std::cout << "Type 'q' to quit at any time.\n";

    while (true) {
        std::cout << "\nSelect FST Module:\n";
        std::cout << "1. String Reversal\n";
        std::cout << "2. Case Conversion\n";
        std::cout << "3. Digit to Word Converter\n";
        std::cout << "4. Vowel/Consonant Identifier\n";
        std::cout << "5. Binary Complement\n";
        std::cout << "6. Tokenizer\n";
        std::cout << "Enter your choice (1-6) or 'q' to quit: ";
        std::getline(std::cin, choice);

        if (choice == "q" || choice == "Q") {
            std::cout << "Exiting FST Swiss Army Knife. Goodbye!\n";
            break;
        }

        if (choice != "1" && choice != "2" && choice != "3" &&
            choice != "4" && choice != "5" && choice != "6") {
            std::cout << "Invalid response! Please enter 1-6 or 'q'.\n";
            continue;
        }

        std::cout << "Enter input string: ";
        std::getline(std::cin, input);

        if (choice == "1") stringReversal(input);
        else if (choice == "2") caseConversion(input);
        else if (choice == "3") digitToWord(input);
        else if (choice == "4") vowelConsonant(input);
        else if (choice == "5") binaryComplement(input);
        else if (choice == "6") tokenizer(input);

        std::cout << "=== Done ===\n";
    }

    return 0;
}

