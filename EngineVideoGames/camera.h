#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Viewport.h"
#include "MovableGLM.h"

class Camera : public MovableGLM
{
public:
	Camera(const glm::vec3& pos, const glm::vec3& forward, float fov, float zNear, float zFar, const Viewport &view);

	void SetProjection(float zNear, float zFar, Viewport &view);
	void Pitch(float angle);
	void RotateY(float angle);

	int GetWidth();
	int GetHeight();
	int GetLeft();
	int GetBottom();
	glm::vec3 GetPos(); //Added

	void SetPos(glm::vec3 position); //Added
	void SetView(const Viewport &view); //Added

	inline glm::mat4 GetViewProjection() const
	{
		return projection;
	}

	inline float GetAngle()
	{
		return fov;
	}

	inline float GetNear()
	{
		return near;
	}

	inline float GetFar()
	{
		return far;
	}

	inline float GetWHRelation()
	{
		return vp.GetWHRelation();
	}

protected:
private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
	float fov; 
	float far,near;
	Viewport vp;
};

#endif