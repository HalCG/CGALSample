cmake_minimum_required(VERSION 3.20.0)
project(draw_surface_mesh)

#添加可执行程序
#create_single_source_cgal_program("draw_surface_mesh.cpp")
add_executable(draw_surface_mesh "draw_surface_mesh.cpp")

if(CGAL_Qt6_FOUND)
  #链接库
  target_link_libraries(draw_surface_mesh PUBLIC CGAL::CGAL_Basic_viewer ${Boost_LIBRARIES})
endif()