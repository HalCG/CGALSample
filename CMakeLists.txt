cmake_minimum_required(VERSION 3.20.0)
project(CGALSample)

# 设置 Boost 根目录  
set(Boost_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/modules/boost_1_87_0")  
set(Boost_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/boost_1_87_0/lib64-msvc-14.3")  

# 必须处理的 Boost 组件  
find_package(Boost REQUIRED COMPONENTS system filesystem)

if (Boost_FOUND)  
    include_directories(${Boost_INCLUDE_DIRS})  

    # 输出 Boost 库的路径  
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")  
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")  
else()  
    message(FATAL_ERROR "Could not find Boost")  
endif()  

#set(Qt6_DIR "C:/Qt6/6.7.3/msvc2022_64/lib/cmake/Qt6") #Qt6_DIR 环境变量设置
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
#CGAL_Qt6 is needed for the drawing.
#需要设置CGAL_DIR 的环境比变量为CGAL的根目录
find_package(CGAL REQUIRED OPTIONAL_COMPONENTS Qt6)

#..\CGAL-6.0.1\include\CGAL\jet_estimate_normals.h
#..\CGAL-6.0.1\include\CGAL\jet_smooth_point_set.h
#Error: no SVD traits   需要eigen 处理以上两个对象中svd（奇异值分解）
# 设置Eigen的路径
set(EIGEN3_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/eigen-3.4.0")

# 添加Eigen的头文件路径
include_directories(${EIGEN3_INCLUDE_DIR})

# 添加子项目  
add_subdirectory(draw_surface_mesh)  
add_subdirectory(surface_reconstruction_from_point_cloud)

