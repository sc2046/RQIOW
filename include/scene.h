#pragma once
#include <vk_helpers.h>
#include <host_device_common.h>

#include <cstdlib>

inline float random_double() {
    // Returns a random real in [0,1).
    return std::rand() / (RAND_MAX + 1.0);
}

inline glm::vec3 random_vector() {
    return glm::vec3(random_double(), random_double(), random_double());
}


struct Scene
{
    Camera				mCamera;

    std::vector<Sphere> mSpheres;
    Buffer				mSphereBuffer;
};


inline Scene createBook1Ch9Scene()
{
    Scene scene;

    scene.mCamera = {
        .center = glm::vec3(0.f),
        .eye = glm::vec3(0.f,0.f,-1.f),
        .backgroundColor = glm::vec3(1.f),
        .fovY = 90.f,
        .focalDistance = 1.f
    };

    scene.mSpheres.emplace_back(glm::vec3(0.f, 0.f, -1.f), 0.5f, DIFFUSE, glm::vec3(0.5f));
    scene.mSpheres.emplace_back(glm::vec3(0.f, -100.5f, -1.f), 100.f, DIFFUSE, glm::vec3(0.5f));
    return scene;
}
 
inline Scene createBook1Ch10Scene()
{
    Scene scene;

    scene.mCamera = {
        .center = glm::vec3(0.f),
        .eye = glm::vec3(0.f,0.f,-1.f),
        .backgroundColor = glm::vec3(1.f),
        .fovY = 90.f,
        .focalDistance = 1.f
    };

    scene.mSpheres.emplace_back(glm::vec3(0.0, -100.5, -1.0), 100.0, DIFFUSE, glm::vec3(0.8f, 0.8f, 0.f));
    scene.mSpheres.emplace_back(glm::vec3(0.0, 0.0, -1.2), 0.5, DIFFUSE, glm::vec3(0.1f, 0.2f, 0.5f));
    scene.mSpheres.emplace_back(glm::vec3(-1.0, 0.0, -1.0), 0.5, METAL, glm::vec3(0.8f));
    scene.mSpheres.emplace_back(glm::vec3(1.0, 0.0, -1.0), 0.5, METAL, glm::vec3(0.8f, 0.6f, 0.2f));
    return scene;
}
 
inline Scene createBook1Ch11Scene()
{
    Scene scene;

    scene.mCamera = {
        .center = glm::vec3(0.f),
        .eye = glm::vec3(0.f,0.f,-1.f),
        .backgroundColor = glm::vec3(1.f),
        .fovY = 90.f,
        .focalDistance = 1.f
    };

    scene.mSpheres.emplace_back(glm::vec3(0.0, -100.5, -1.0), 100.0, DIFFUSE, glm::vec3(0.8f, 0.8f, 0.f));
    scene.mSpheres.emplace_back(glm::vec3(0.0, 0.0, -1.2), 0.5, DIFFUSE, glm::vec3(0.1f, 0.2f, 0.5f));
    scene.mSpheres.emplace_back(glm::vec3(-1.0, 0.0, -1.0), 0.5, DIELECTRIC, glm::vec3(1.f)); // note ior is fixed at 1.5 in shader.
    scene.mSpheres.emplace_back(glm::vec3(1.0, 0.0, -1.0), 0.5, METAL, glm::vec3(0.8f, 0.6f, 0.2f));
    return scene;
}
 
inline Scene createBook1Ch14Scene()
{
    Scene scene;

    scene.mCamera = {
        .center = glm::vec3(13.f, 2.f, 3.f),
        .eye = glm::vec3(0.f,0.f,0.f),
        .backgroundColor = glm::vec3(1.f),
        .fovY = 20.f,
        .focalDistance = 1.f
    };

    // Ground
    scene.mSpheres.emplace_back(glm::vec3(0, -1000, 0), 1000.f, DIFFUSE, glm::vec3(0.5f));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            const auto choose_mat = random_double();

            glm::vec3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

            if (glm::length(center - glm::vec3(4, 0.2, 0)) > 0.9) {

                if (choose_mat < 0.8) {
                    auto albedo = random_vector();
                    scene.mSpheres.emplace_back(center, 0.2f, DIFFUSE, albedo);
                }
                else if (choose_mat < 0.95) {
                    auto albedo = random_vector();
                    scene.mSpheres.emplace_back(center, 0.2f, METAL, albedo);
                }
                else {
                    scene.mSpheres.emplace_back(center, 0.2f, DIELECTRIC, glm::vec3(1.f));
                }
            }
        }
    }
    scene.mSpheres.emplace_back(glm::vec3(0, 1, 0), 1.f, DIELECTRIC, glm::vec3(1.f));
    scene.mSpheres.emplace_back(glm::vec3(-4, 1, 0), 1.f, DIFFUSE, glm::vec3(0.4f, 0.2f, 0.1f));
    scene.mSpheres.emplace_back(glm::vec3(4, 1, 0), 1.f, METAL, glm::vec3(0.7, 0.6, 0.5));

    return scene;
}