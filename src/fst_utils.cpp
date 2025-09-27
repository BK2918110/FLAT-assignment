#include "fst_utils.h"
#include <fst/fstlib.h>
#include <fstream>
#include <iostream>
#include <cstdlib>

void saveFSTArtifacts(const fst::StdVectorFst &fst, const std::string &module_name) {
    // -------------------------------
    // Save FST
    // -------------------------------
    std::string fst_path = "build/" + module_name + ".fst";
    if (!fst.Write(fst_path)) {
        std::cerr << "Error writing FST file: " << fst_path << std::endl;
        return;
    }

    // -------------------------------
    // Generate diagram using fstdraw
    // -------------------------------
    std::string dot_path = "diagrams/" + module_name + ".dot";
    std::string cmd = "fstdraw " + fst_path + " > " + dot_path;
    int ret = system(cmd.c_str());
    if (ret != 0) {
        std::cerr << "Error generating diagram (ensure fstdraw is installed)" << std::endl;
        return;
    }

    // Convert .dot -> .png using Graphviz
    std::string png_path = "diagrams/" + module_name + ".png";
    cmd = "dot -Tpng " + dot_path + " -o " + png_path;
    ret = system(cmd.c_str());
    if (ret != 0) {
        std::cerr << "Error generating diagram PNG (ensure Graphviz is installed)" << std::endl;
    }

    std::cout << "✅ Saved artifacts for [" << module_name << "]:\n"
              << "   " << fst_path << "\n"
              << "   " << png_path << "\n";
}

