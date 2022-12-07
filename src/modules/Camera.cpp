#include <src/helpers/Globals.h>
#include <src/Application.h>
#include "Camera.h"
#include <imgui.h>


Camera::Camera(bool start_enabled) : Module("renderer")
{
	CalculateViewMatrix();

	X = vec3(1.0f, 0.0f, 0.0f);
	Y = vec3(0.0f, 1.0f, 0.0f);
	Z = vec3(0.0f, 0.0f, 1.0f);

	Position = vec3(10.0f, 0.0f, 50.0f);
	Reference = vec3(0.0f, 0.0f, 0.0f);
}

Camera::~Camera()
{

}

bool Camera::Start()
{
	PLOG("Setting camera");
	bool ret = true;

	return ret;
}

bool Camera::CleanUp()
{
	PLOG("Camera cleaning");

	return true;
}

update_status Camera::Update(float dt)
{
	CalculateViewMatrix();

	return UPDATE_CONTINUE;
}

void Camera::Look(const vec3& Pos, const vec3& Reference, bool RotateAroundReference)
{
	this->Position = Pos;
	this->Reference = Reference;

	Z = normalize(Pos - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	if (!RotateAroundReference)
	{
		this->Reference = this->Position;
		this->Position += Z * 0.05f;
	}

	CalculateViewMatrix();
}

void Camera::LookAt(const vec3& Spot)
{
	Reference = Spot;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	CalculateViewMatrix();
}

void Camera::Move(const vec3& Movement)
{
	Position += Movement;
	Reference += Movement;

	CalculateViewMatrix();
}

float* Camera::GetViewMatrix()
{
	return &ViewMatrix;
}

void Camera::CalculateViewMatrix()
{
	ViewMatrix = mat4x4(X.x, Y.x, Z.x, 0.0f, X.y, Y.y, Z.y, 0.0f, X.z, Y.z, Z.z, 0.0f, -dot(X, Position), -dot(Y, Position), -dot(Z, Position), 1.0f);
	ViewMatrixInverse = inverse(ViewMatrix);
}