On my device (RTX 3070) this renders the final scene from the book onto an 800x600 image in ~1.2s, using 1000 samples with a depth of 32.
![Scene](https://github.com/sc2046/RQIOW/blob/main/scenes/scene.jpg)



Some Notes:
- The work is all done in a compute shader.
- The acceleration structure setup consists of a BLAS representing a single AABB. Each sphere in the scene 
is represented as an instance in the TLAS.
- All refractive materials have an ior of 1.5 just to make the material API easier. An ior member could be added to the sphere structure,
then it would also have to be specified even for non-dielectric materials.


Some helpful resources:
- https://raytracing.github.io/
- https://nvpro-samples.github.io/vk_mini_path_tracer/
- https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/