#pragma once
#ifndef __TRANSFORM
#define __TRANSFORM

struct Vector2
{
	float x;
	float y;
};

class ClassTransform
{
public:
	Vector2 position;
	Vector2 scale;
	ClassTransform();
	ClassTransform(const Vector2 worldPosition);
	ClassTransform(float x,float y);
	ClassTransform(const Vector2 worldPosition, const Vector2 worldScale);
	~ClassTransform();

private:

};

ClassTransform::ClassTransform()
{
	position.x = 0;
	position.y = 0;
	scale.x = 1;
	scale.y = 1;
}
ClassTransform::ClassTransform(const Vector2 worldPosition)
{
	position = worldPosition;
	scale.x = 1;
	scale.y = 1;
}
ClassTransform::ClassTransform(float x, float y)
{
	position.x = x;
	position.y = y;
	scale.x = 1;
	scale.y = 1;
}
ClassTransform::ClassTransform(const Vector2 worldPosition, const Vector2 worldScale)
{
	position = worldPosition;
	scale = worldScale;
}
ClassTransform::~ClassTransform()
{

}
#endif // !__TRANSFORM
