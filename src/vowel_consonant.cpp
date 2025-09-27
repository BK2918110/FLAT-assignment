#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "fst_utils.h"

void vowelConsonant(const std::string &input) {
    // Define vowels
    std::unordered_set<char> vowels = {'a','e','i','o','u',
                                       'A','E','I','O','U'};

    fst::StdVectorFst fst;
    fst.AddState();  // start state 0
    fst.SetStart(0);
    int prev_state = 0, state_id = 1;

    // Build arcs
    for (char c : input) {
        fst.AddState();
        char label = vowels.count(c) ? 'V' : 'C';
        fst.AddArc(prev_state, fst::StdArc(
            static_cast<int>(c),
            static_cast<int>(label),
            0.0, state_id));
        prev_state = state_id;
        ++state_id;
    }

    fst.SetFinal(prev_state, 0.0);

    // Save FST diagram
    saveFSTArtifacts(fst, "vowel_consonant");

    // Build human-readable output
    std::string output;
    for (char c : input) {
        output += vowels.count(c) ? "V " : "C ";
    }

    std::cout << "🔁 Vowel-Consonant Output: " << output << std::endl;
}

