#pragma once
#include <algorithm>
#include <functional>

template <typename InputIt, typename OutputIt, typename Barycentre>
OutputIt recenter( Barycentre const& barycentre, InputIt const& beginIt, InputIt const& endIt,
                   OutputIt const& outIt )
{
    return std::transform( beginIt, endIt, outIt,
                           [&barycentre]( auto const& point ) //
                           { return point - barycentre; } );
}
