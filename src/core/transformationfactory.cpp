#include "transformationfactory.h"

#include "manualtrans.h"

#include <stdexcept>

std::unique_ptr<TransformationImpl> createTransformation( Mode const& mode )
{
    switch ( mode )
    {
        case Mode::automatic:
            throw std::runtime_error( "Automatic mode not implemented in Transformation\n" );
            break;
        case Mode::manual: return std::make_unique<Manualtrans>(); break;
    }
}
