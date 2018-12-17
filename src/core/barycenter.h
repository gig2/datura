#pragma once

#include <iterator>
#include <numeric>

template <typename InputIt1, typename InputIt2, typename T>
T barycenter( InputIt1 begin, InputIt2 end, T const& init )
{
    auto acc = std::accumulate( begin, end, init );
    acc /= std::distance( begin, end );
    return acc;
}
