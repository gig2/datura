#pragma once

#include "mode.h"
#include "transformationimpl.h"

#include <memory>

std::unique_ptr<TransformationImpl> createTransformation( Mode const& mode );
