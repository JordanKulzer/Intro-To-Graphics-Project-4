#ifndef SHAPE_H
#define SHAPE_H

#include <Eigen/Dense>

namespace Raytracer148 {
struct Ray {
  Eigen::Vector3d origin, direction;
};

class Shape;

struct HitRecord {
	//i added the ability of changing the color of shapes into the struct
  Eigen::Vector3d position, normal, color;
  double t;
};

class Shape {
public:
  virtual ~Shape(){}
  virtual HitRecord intersect(const Ray &ray) = 0;
};

}

#endif
