// Common file shared across C++ CPU code and GLSL GPU code.
#ifndef HOST_DEVICE_COMMON_H
#define HOST_DEVICE_COMMON_H

#ifdef __cplusplus
#include <cstdint>
#include <glm.hpp>
using uint = uint32_t;
using vec2 = glm::vec2;
using uvec2 = glm::uvec2;
using uvec3 = glm::uvec3;
using vec3 = glm::vec3;
#endif  // #ifdef __cplusplus


// ==============================================================
// Constants
// ==============================================================

#define RESOLUTION_WIDTH 800
#define RESOLUTION_HEIGHT  600

#define DIFFUSE		0
#define METAL		1
#define DIELECTRIC	2

#define M_PI         3.14159265358979323846f
#define INV_PI       0.31830988618379067154f
#define INV_TWOPI    0.15915494309189533577f
#define INV_FOURPI   0.07957747154594766788f
#define SQRT_TWO     1.41421356237309504880f
#define INV_SQRT_TWO 0.70710678118654752440f

struct Sphere
{
	vec3	center;
	float	radius;

	uint	material;
	vec3	color;
};

struct AABB
{
	vec3 min;
	vec3 max;
};

// Right-handed pinhole camera with (0,1,0) as up.
struct Camera
{
	vec3	center;
	vec3	eye;
	vec3	backgroundColor;  // Note a non-black background is equivalent to treating the background as a light source.
	float	fovY;
	float	focalDistance;
};

struct Ray
{
	vec3 origin;
	vec3 direction;
};



#endif // #ifndef COMMON_H