#ifndef FST_UTILS_H
#define FST_UTILS_H

#include <string>
#include <fst/fstlib.h>

// Save FST and diagram for any module
void saveFSTArtifacts(const fst::StdVectorFst &fst,
                      const std::string &module_name);

#endif // FST_UTILS_H

