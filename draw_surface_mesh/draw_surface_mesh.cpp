#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/draw_surface_mesh.h>
#include <fstream>

typedef CGAL::Simple_cartesian<double>                       Kernel;
typedef Kernel::Point_3                                      Point;
typedef CGAL::Surface_mesh<Point>                            Mesh;

int main(int argc, char* argv[])
{
	std::string filename = "E:/opengl/HalCG/CGAL/CGALSample/datas/meshes/elephant.off";
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Cannot open file: " << filename << std::endl;
		return EXIT_FAILURE;
	}

	//const std::string filename = (argc>1) ? argv[1] : CGAL::data_file_path(filename);//CGAL::data_file_path用于获取可执行程序下相对路径文件的绝对路径
	//定义一个Mesh对象sm，用于存储读取的多边形网格。
	Mesh sm;
	if (!CGAL::IO::read_polygon_mesh(filename, sm))
	{
		std::cerr << "Invalid input file: " << filename << std::endl;
		return EXIT_FAILURE;
	}

	// 使用add_property_map方法为顶点、边和面添加颜色属性。v:color、e:color和f:color分别代表顶点、边和面的颜色属性。
	// 顶点的颜色属性使用CGAL::IO::Color类型，面属性的初始值被设置为白色。
	auto vcm = sm.add_property_map<Mesh::Vertex_index, CGAL::IO::Color>("v:color").first;
	auto ecm = sm.add_property_map<Mesh::Edge_index, CGAL::IO::Color>("e:color").first;
	auto fcm = sm.add_property_map<Mesh::Face_index>("f:color", CGAL::IO::white() /*default*/).first;

	//遍历所有顶点，并根据顶点的索引设置其颜色。如果索引是奇数则设置为黑色，偶数则设置为蓝色。
	for (auto v : vertices(sm))
	{
		if (v.idx() % 2)
		{
			put(vcm, v, CGAL::IO::black());
		}
		else
		{
			put(vcm, v, CGAL::IO::blue());
		}
	}

	//遍历所有边，并将它们的颜色设置为灰色。
	for (auto e : edges(sm))
	{
		put(ecm, e, CGAL::IO::gray());
	}

	//将第一个面的颜色设置为红色。
	put(fcm, *(sm.faces().begin()), CGAL::IO::red());

	//https://sider.ai/share/2575c3760aacaa7f6b46a2846df64482
	CGAL::draw(sm);

	return EXIT_SUCCESS;
}

/*
这段代码是使用 CGAL（Computational Geometry Algorithms Library）库定义的类型。其中包含了几个重要的类型定义，这些类型在计算几何中常用。下面是每个对象的具体含义：

1. **`Kernel`**:
   ```cpp
   typedef CGAL::Simple_cartesian<double> Kernel;
   ```
   - `Kernel` 是一个几何内核的类型。在这个例子中，`CGAL::Simple_cartesian<double>` 表示使用一个简单的笛卡尔坐标系内核，支持双精度浮点数（`double`）。几何内核负责定义几何对象（如点、向量、线等）的基本操作和属性。

2. **`Point`**:
   ```cpp
   typedef Kernel::Point_3 Point;
   ```
   - `Point` 是一个三维空间中的点类型。`Kernel::Point_3` 意味着这个点是由之前定义的 `Kernel`（即 `CGAL::Simple_cartesian<double>`）生成的，表示它具有三维坐标（x, y, z）。在 CGAL 中，`Point_3` 使你能够方便地操作三维空间中的点。

3. **`Mesh`**:
   ```cpp
   typedef CGAL::Surface_mesh<Point> Mesh;
   ```
   - `Mesh` 是一个表面网格（Surface Mesh）的类型，表示由三维点构成的网格结构。`CGAL::Surface_mesh<Point>` 使用 `Point` 作为顶点类型，允许你创建和操作一个表面网格，该网格可以用于各种应用，如三维建模、计算几何处理等。
*/