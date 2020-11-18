#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"

using namespace std;
using namespace Raytracer148;
using namespace Eigen;

int main() {
    Image im(400, 400);

    Scene scene;

    Vector3d center;
    center[0] = 0;
    center[1] = 0;
    center[2] = 4;
    scene.addShape(new Sphere(center, 2));

    center[0] = -.5;
    center[1] = 1;
    center[2] = 2.5;
    scene.addShape(new Sphere(center, .5));

    center[0] = .5;
    center[1] = 1.25;
    center[2] = 2.75;
    scene.addShape(new Sphere(center, .5));

    //i used this to put the triangle in the plane and reset x,y,z
    center[0] = 1.0;
    center[1] = 0.0;
    center[2] = 1.0;
    //used this to reposition the triangle
    Vector3d pV;
    pV[0] = -1.0;
    pV[1] = -1.0;
    pV[2] = 1.0;
    //used this to change the size of the triangle
    Vector3d dV;
    dV[0] = 0.25;
    dV[1] = 0.25;
    dV[2] = 1.0;
    //added the triangle into the space
    scene.addShape(new Triangle(center, dV, pV));

    scene.render(im);

    im.writePNG("test.png");

    return 0;
}
