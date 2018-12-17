#include "transformationfactory.h"

#include "autotrans.h"
#include "manualtrans.h"

#include <stdexcept>

std::unique_ptr<TransformationImpl> createTransformation( Mode const& mode )
{
    switch ( mode )
    {
        case Mode::automatic: return std::make_unique<AutoTransformation>(); break;
        case Mode::manual: return std::make_unique<Manualtrans>(); break;
    }
}
