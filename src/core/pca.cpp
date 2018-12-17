#include "pca.h"
#include "pcafactory.h"

Pca::Pca( Mode const& mode )
    : pimpl_{createPca( mode )}
{
}
