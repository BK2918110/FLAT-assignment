#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "fst_utils.h"

void binaryComplement(const std::string &input) {
    fst::StdVectorFst fst;
    fst.AddState();       // start state 0
    fst.SetStart(0);
    int prev_state = 0, state_id = 1;

    // Build arcs
    for (char c : input) {
        fst.AddState();
        char out_char = (c == '0') ? '1' : '0';
        fst.AddArc(prev_state, fst::StdArc(
            static_cast<int>(c),
            static_cast<int>(out_char),
            0.0, state_id));
        prev_state = state_id;
        ++state_id;
    }

    fst.SetFinal(prev_state, 0.0);

    // Save FST diagram
    saveFSTArtifacts(fst, "binary_complement");

    // Human-readable output
    std::string output;
    for (char c : input) {
        output += (c == '0') ? "1" : "0";
    }

    std::cout << "🔁 Binary Complement Output: " << output << std::endl;
}

