#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

namespace bg = boost::geometry;

using SphericalPoint =
bg::model::d2::point_xy<double, bg::cs::spherical_equatorial<bg::degree>>;

using SphericalPolygon =
boost::geometry::model::polygon<SphericalPoint,
   false,  // clockwise if true
   true,   // closed
   std::vector, std::vector, std::allocator,
   std::allocator>;

auto main() -> int {
   SphericalPolygon quad{ {{0,0}, {0,1}, {1,1}, {1,0}, {0,0}} };
   SphericalPoint p{ 0.5,0.5 };

   std::cout << "within=" << bg::within(p, quad) << std::endl;
   std::cout << bg::wkt(quad) << std::endl;
   std::cout << "is valid=" << bg::is_valid(quad) << std::endl;
   std::cout << bg::area(quad) << std::endl;

   bg::correct(quad);

   std::cout << "within=" << bg::within(p, quad) << std::endl;
   std::cout << bg::wkt(quad) << std::endl;
   std::cout << "is valid=" << bg::is_valid(quad) << std::endl;
   std::cout << bg::area(quad) << std::endl;


   return 0;
}