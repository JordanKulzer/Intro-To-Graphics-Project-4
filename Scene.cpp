#include "Scene.h"
#include <cmath>
using namespace Raytracer148;
using namespace std;
using namespace Eigen;

HitRecord Scene::closestHit(const Ray &ray) {
    HitRecord result;
    result.t = -1;
    bool foundSomething = false;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        HitRecord r = shapes[i]->intersect(ray);
        if (r.t > std::numeric_limits<double>::epsilon() && (!foundSomething || r.t < result.t)) {
            result = r;
            foundSomething = true;
        }
    }

    return result;
}

Vector3d Scene::trace(const Ray& ray) {
    // For now we'll have diffuse shading with no shadows, so it's easy!
    HitRecord r = closestHit(ray);

    Vector3d result;
    result[0] = result[1] = result[2] = 0;

    if (r.t < numeric_limits<double>::epsilon()) return result;

    Vector3d lightDir = (lightPos - r.position).normalized();

    // Create reference ray to check for shadows
    Ray ref;
    ref.origin = r.position;
    ref.direction = lightDir;

    // Check for closest hit
    for (unsigned int i = 0; i < shapes.size(); i++) {
        HitRecord r = shapes[i]->intersect(ref);

        // If something is between the position and light source, then return result as black (shadow)
        if (r.t > 0.00000000000001)  return result;
    }

    double dot = lightDir.dot(r.normal);
    if (dot < 0) dot = 0;

    result = phong(r, lightDir, dot);

    return result;
}


Vector3d Scene::phong(HitRecord r, Vector3d lightDir, double dot) {
    
    //creating vector3d of the position of viewer, and setting them to 0
    Vector3d viewPosi;
    viewPosi[0] = viewPosi[1] = viewPosi[2] = 0;
    //creating vector3d of the color of the light from cube, and setting them to 1
    Vector3d lightColor;
    lightColor[0] = lightColor[1] = lightColor[2] = 1;
    //creating vector3d for what color the cube is, and setting it to an orange
    Vector3d cubeColor;
    cubeColor[0] = 1;
    cubeColor[1] = 0.5;
    cubeColor[2] = dot;

    //calculating ambient shade
    //how strong the fixed brightness of cube is 
    double ambStrength = 0.1;
    //combining brightness of cube with color to find total ambient shade
    Vector3d ambient = ambStrength * lightColor;

    //calculating diffuse shade 
    //using normal to find how even the reflection is
    Vector3d normFrag = r.normal;
    //calulate light reflection
    //combining those to a float
    double diff = max(lightDir.dot(normFrag), 0.0);
    //combining all those to find total diffuse shade
    Vector3d diffuse = diff * lightColor;

    //calculating specular shade
    //how strong the light is
    double specularStrength = 0.5;
    //calculate the direction of the light
    Vector3d viewDir = (viewPosi - r.position).normalized();
    //calculating how the reflection gets directed
    Vector3d reflectDir(-lightDir - 2.0 * -lightDir.dot(normFrag) * normFrag);
    //combining direction of light and reflection to a float
    double spec = pow(max(reflectDir.dot(viewDir), 0.0), 32);
    //combining calculations to find total specular shade
    Vector3d specular = specularStrength * spec * lightColor;

    //outputting ambient shading
    //Vector3d result = ambient * cubeColor;

    //outputting diffuse shading
    //Vector3d result = diffuse * cubeColor;

    //outputting specular shading
    //Vector3d result = specular * cubeColor;

    //outputting phong reflection
    return (ambient + diffuse + specular).cwiseProduct(cubeColor);
}

void Scene::render(Image &image) {
    // We make the assumption that the camera is located at (0,0,0)
    // and that the image plane happens in the square from (-1,-1,1)
    // to (1,1,1).

    assert(image.getWidth() == image.getHeight());

    int size = image.getWidth();
    double pixelSize = 2. / size;
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++) {
            Ray curRay;
            curRay.origin[0] = curRay.origin[1] = curRay.origin[2] = 0;

            curRay.direction[0] = (x + 0.5) * pixelSize - 1;
            curRay.direction[1] = 1 - (y + 0.5) * pixelSize;
            curRay.direction[2] = 1;

            Vector3d color = trace(curRay);
            image.setColor(x, y, color[0], color[1], color[2]);
        }
}
