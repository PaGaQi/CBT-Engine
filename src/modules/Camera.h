#pragma once
#include <src/modules/Module.h>
#include <src/helpers/Globals.h>
#include <src/helpers/glmath.h>
#include <src/helpers/MathGeoLib/MathGeoLib.h>

class Camera : public Module
{
public:
	Camera(bool start_enabled = true);
	~Camera();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void Look(const vec3& Pos, const vec3& Reference, bool RotateAroundReference = false);
	void LookAt(const vec3& Spot);
	void Move(const vec3& Mov);
	float* GetViewMatrix();



	Frustum frustum;

private:

	void CalculateViewMatrix();

public:

	vec3 X, Y, Z, Position, Reference;

private:

	mat4x4 ViewMatrix, ViewMatrixInverse;
	LineSegment picking = LineSegment(vec::zero, vec::zero);
};