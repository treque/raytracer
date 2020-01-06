// raytracer.cpp : credits to Marcus Mathiassen for structure

#include <fstream>


class Vec3
{

private:

	double x, y, z;

public:

	Vec3()
	{
		x = y = z = 0;
	}

	Vec3(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class Ray
{

private:

	Vec3 o;
	Vec3 d;

public:

	Ray(Vec3 origin, Vec3 direction)
	{
		o = origin;
		d = direction;
	}

	Vec3 getOrigin() { return o; }
	Vec3 getDirection() { return d; }
};

class Sphere
{
private:
	Vec3 c;
	double r;

public:
	Sphere(Vec3 center, double radius)
	{
		c = center;
		r = radius;
	}
	
	bool intersect(Ray ray, double& t)
	{
		Vec3 oc = ray.getOrigin - c;
	}
};

int main()
{
	const int width = 500;
	const int height = 500;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// sending a ray through each pixel
			// from the pixel, at z = 0, in the +z direction.
			Ray ray(Vec3(x, y, 0), Vec3(0, 0, 1));

			// intersect
			//if (sphere.intersect(ray))
		}
	}
}
