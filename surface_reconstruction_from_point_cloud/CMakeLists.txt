cmake_minimum_required(VERSION 3.20.0)
project(surface_reconstruction_from_point_cloud)

add_executable(surface_reconstruction_from_point_cloud "surface_reconstruction_from_point_cloud.cpp")

if(CGAL_Qt6_FOUND)
  target_link_libraries(surface_reconstruction_from_point_cloud PUBLIC CGAL ${Boost_LIBRARIES})
endif()