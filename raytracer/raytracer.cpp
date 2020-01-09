// raytracer.cpp : credits to Marcus Mathiassen for structure

#include <fstream>
#include <cmath>

class Vec3
{

private:


public:

	double x, y, z;

	inline Vec3()
	{
		x = y = z = 0;
	}

	inline Vec3(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	inline Vec3 operator-(Vec3 v)
	{
		return Vec3(x - v.x, y - v.y, z - v.z);
	}
};

inline double dot(const Vec3& a, const Vec3& b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline void clamp(Vec3& min, Vec3& max, Vec3& vec)
{
	vec.x = vec.x > max.x ? max.x : vec.x < min.x ? min.x : vec.x;
	vec.y = vec.y > max.y ? max.y : vec.y < min.y ? min.y : vec.y;
	vec.z = vec.z > max.z ? max.z : vec.z < min.z ? min.z : vec.z;
}


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

	inline Vec3 getOrigin() { return o; }
	inline	Vec3 getDirection() { return d; }
};


class Sphere
{
private:

	Vec3 c;
	double r;

public:

	inline Sphere(Vec3 center, double radius)
	{
		c = center;
		r = radius;
	}
	
	inline bool intersect(Ray ray, double& sol)
	{
		Vec3 oc = ray.getOrigin() - c;
		double b = 2 * dot(oc, ray.getDirection());
		double c = dot(oc, oc) - r * r;
		double discriminant = b * b - 4 * c;
		// no intersection
		if (discriminant < 1e-4) return false;
		double root = sqrt(discriminant);
		double sol0 = -b - root;
		double sol1 = -b + root;
		sol = sol0 < sol1 ? sol0 : sol1;
		return true;
	}
};

int main()
{
	const int width = 500;
	const int height = 500;

	const Vec3 white(255, 255, 255);
	const Vec3 black(0, 0, 0);
	const Vec3 blue(0, 255, 0);

	const Sphere sphere(Vec3(0.5 * width, 0.5 * height, 50), 50);
	const Sphere light(Vec3(0, 0, 50), 1);

	double sol;
	Vec3 pixel_color(black);

	std::ofstream out("out.ppm");
	out << "P3\n" << width << " " << height << " " << "255\n";

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// sending a ray through each pixel
			// from the pixel, at z = 0, in the +z direction.
			Ray ray(Vec3(x, y, 0), Vec3(0, 0, 1));

			// intersect
			if (sphere.intersect(ray, sol))
			{

			}
		}
	}
}
