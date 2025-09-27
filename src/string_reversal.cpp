#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <algorithm>

#include "fst_utils.h"

void stringReversal(const std::string &input) {
    fst::StdVectorFst fst;
    fst.AddState();
    fst.SetStart(0);

    int prev_state = 0, state_id = 1;

    // Build FST in reversed order
    for (int i = input.size() - 1; i >= 0; --i) {
        fst.AddState();
        fst.AddArc(prev_state, fst::StdArc(
            static_cast<int>(input[i]),
            static_cast<int>(input[i]),
            0.0, state_id));
        prev_state = state_id;
        ++state_id;
    }

    fst.SetFinal(prev_state, 0.0);

    // Save FST and diagram
    saveFSTArtifacts(fst, "string_reversal");

    // Print reversed string
    std::string reversed(input.rbegin(), input.rend());
    std::cout << "🔁 Reversed string: " << reversed << std::endl;
}

