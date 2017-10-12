// Boost.Geometry

// Copyright (c) 2017, Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_SRS_EPSG_HPP
#define BOOST_GEOMETRY_SRS_EPSG_HPP


#include <boost/geometry/srs/projection.hpp>
#include <boost/geometry/srs/projections/epsg.hpp>
#include <boost/geometry/srs/projections/epsg_params.hpp>
#include <boost/geometry/srs/projections/epsg_traits.hpp>


namespace boost { namespace geometry
{
    
namespace projections
{

template <typename CT>
struct dynamic_parameters<srs::epsg, CT>
{
    static inline projections::parameters<CT> apply(srs::epsg const& params)
    {
        return projections::detail::pj_init_plus<CT>(
                srs::dynamic(),
                projections::detail::epsg_to_string(params.code),
                false);
    }  
};

template <int Code, typename CT>
class proj_wrapper<srs::static_epsg<Code>, CT>
{
    typedef typename projections::detail::promote_to_double<CT>::type calc_t;

    typedef projections::detail::epsg_traits<Code> epsg_traits;

    typedef projections::parameters<calc_t> parameters_type;
    typedef typename projections::detail::static_projection_type
        <
            typename epsg_traits::type,
            typename epsg_traits::srs_tag,
            calc_t,
            parameters_type
        >::type projection_type;

public:
    proj_wrapper()
        : m_proj(projections::detail::pj_init_plus<calc_t>(
                        srs::static_epsg<Code>(),
                        epsg_traits::par(), false))
    {}

    projection_type const& proj() const { return m_proj; }
    projection_type & mutable_proj() { return m_proj; }

private:
    projection_type m_proj;
};


} // namespace projections


namespace srs
{


template <int Code, typename CT>
class projection<srs::static_epsg<Code>, CT>
    : public projections::projection<srs::static_epsg<Code>, CT>
{
    typedef projections::projection<srs::static_epsg<Code>, CT> base_t;

public:
    projection()
    {}
};


} // namespace srs


}} // namespace boost::geometry


#endif // BOOST_GEOMETRY_SRS_EPSG_HPP
