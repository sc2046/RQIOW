
Some Notes:
- The acceleration structure setup consists of a BLAS representing a single AABB. Each sphere in the scene 
is represented as an instance in the TLAS.
- All refractive materials have an ior of 1.5 just to make the material API easier. An ior member could be added to the sphere structure,
then it would also have to be specified even for non-dielectric materials.



- https://raytracing.github.io/
- https://nvpro-samples.github.io/vk_mini_path_tracer/
- https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/