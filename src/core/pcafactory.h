#include "mode.h"
#include "pcaimpl.h"

#include <memory>


std::unique_ptr<PcaImpl> createPca( Mode const& mode );
