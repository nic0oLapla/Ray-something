#version 420

uniform float fov;
uniform vec2 dim;
uniform vec3 cPos;
uniform vec3 cDir;

void main() {

	float rad = radians(fov);
	float d = dim.x / 2 * tan(rad / 2);
	vec3 centre = cPos + d / normalize(cDir);

//  Equation of the plane
//	cDir.x * x + cDir.y * y + cDir.z * y = cDir.x * centre.x + centre.y * centre.y + centre.z * cPos.z

	vec3 xVec = dim.x * normalize(vec3(cDir.x, 0, -cDir.x/cDir.z));
	vec3 yVec = dim.y * normalize(cross(cDir, xVec));

	mat3x2 clipPlane = mat3x2(xVec, yVec);

	gl_Position = 

}