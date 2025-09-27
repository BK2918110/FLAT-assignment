#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "fst_utils.h"

void digitToWord(const std::string &input) {
    // Map digits to words
    std::unordered_map<char, std::string> digit_map = {
        {'0', "zero"}, {'1', "one"},   {'2', "two"},
        {'3', "three"}, {'4', "four"}, {'5', "five"},
        {'6', "six"},   {'7', "seven"},{'8', "eight"},
        {'9', "nine"}
    };

    fst::StdVectorFst fst;
    fst.AddState();  // start state 0
    fst.SetStart(0);
    int prev_state = 0, state_id = 1;

    // Build arcs
    for (char c : input) {
        fst.AddState();
        std::string out_str = digit_map[c];

        // Output first character of word as label for FST
        fst.AddArc(prev_state, fst::StdArc(
            static_cast<int>(c),
            static_cast<int>(out_str[0]),
            0.0, state_id));

        prev_state = state_id;
        ++state_id;
    }

    fst.SetFinal(prev_state, 0.0);

    // Collect symbols
    std::vector<std::string> symbols;
    for (char c : input) {
        symbols.push_back(std::string(1, c));
    }

    // Save FST diagram
    saveFSTArtifacts(fst, "digit_to_word");

    // Build output string
    std::string output;
    for (char c : input) {
        output += digit_map[c] + " ";
    }

    std::cout << "🔁 Digit to Word Output: " << output << std::endl;
}

