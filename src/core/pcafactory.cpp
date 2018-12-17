#include "pcafactory.h"

#include "pcaauto.h"
#include "pcamanual.h"

std::unique_ptr<PcaImpl> createPca( Mode const& mode )
{
    switch ( mode )
    {
        case Mode::manual: return std::make_unique<PcaManual>(); break;
        case Mode::automatic: return std::make_unique<PcaAuto>(); break;
    }
}
