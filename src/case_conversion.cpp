#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "fst_utils.h"

void caseConversion(const std::string &input) {
    fst::StdVectorFst fst;

    // Start state
    fst.AddState();  // state 0
    fst.SetStart(0);

    int prev_state = 0, state_id = 1;

    // Build arcs
    for (char c : input) {
        fst.AddState();
        char out_char = c;

        // Convert lowercase a-z to uppercase A-Z
        if (c >= 'a' && c <= 'z') {
            out_char = c - 'a' + 'A';
        }

        fst.AddArc(prev_state, fst::StdArc(
            static_cast<int>(c),
            static_cast<int>(out_char),
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
    saveFSTArtifacts(fst, "case_conversion");

    // Build output string
    std::string output;
    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            output += (c - 'a' + 'A');
        } else {
            output += c;
        }
    }

    std::cout << "🔁 Case Conversion Output: " << output << std::endl;
}

