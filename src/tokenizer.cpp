#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include "fst_utils.h"

void tokenizer(const std::string &input) {
    using namespace fst;

    StdVectorFst fst;

    int start_state = fst.AddState();
    fst.SetStart(start_state);

    int state = start_state;
    for (size_t i = 0; i < input.size(); ++i) {
        int next_state = fst.AddState();
        char c = input[i];

        if (std::isalnum(c)) {
            // Normal characters (letters/digits)
            fst.AddArc(state, StdArc(c, c, 0.0, next_state));
        } else if (std::ispunct(c)) {
            // Punctuation as separate token: add epsilon transition first
            int eps_state = fst.AddState();
            fst.AddArc(state, StdArc(0, 0, 0.0, eps_state));
            fst.AddArc(eps_state, StdArc(c, c, 0.0, next_state));
        } else {
            // Space: skip, just stay in the same state
            next_state = state;
        }

        state = next_state;
    }

    fst.SetFinal(state, 0.0);

    // Save FST diagram
    saveFSTArtifacts(fst, "tokenizer");

    // Print output tokens
    std::string token;
    for (char c : input) {
        if (std::isalnum(c)) {
            token += c;
        } else if (std::ispunct(c)) {
            if (!token.empty()) {
                std::cout << token << std::endl;
                token.clear();
            }
            std::cout << c << std::endl;
        } else if (std::isspace(c)) {
            if (!token.empty()) {
                std::cout << token << std::endl;
                token.clear();
            }
        }
    }
    if (!token.empty()) std::cout << token << std::endl;
}

