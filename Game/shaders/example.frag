#version 330 core
#define MAX_DIST 10.
#define EPSILON .01
#define MAX_SHAPES 128

#define sphere 0
#define rect 1

struct Ray {
    vec3 pos;
    vec3 dir;
    float dist;
};

struct Shape {
	mat4 transform;
	vec4 color;
    float radius;
	int type;
};

struct RayHit {
    Shape shape;
	float dist;
};

out vec4 fragColor;

layout (std140) uniform shape {
	Shape shapes[MAX_SHAPES];
	uint shapesSize;
};

vec3 transformVec(mat4 mat, vec3 vec) {
	vec4 v4 = vec4(vec, 1.);
	return (mat * v4).xyz;
}

Ray rayFromAngleEx(vec2 fragCoord, vec2 size, float fov) {
    vec2 xy = fragCoord - size / 2.0;
    float z = size.y / tan(radians(fov) / 2.0);
    return Ray(vec3(0.), normalize(vec3(xy, -z)), 0.);
}
   
float sdfRect(Shape s, vec3 pos) {
  vec3 q = abs(pos) - vec3(s.radius);
  return length(max(q,0.0)) + min(max(q.x,max(q.y,q.z)),0.0);
}
   
float sdfSphere(Shape s, vec3 pos) {
	return length(pos) - s.radius;
}
	
float sdf(Shape s, vec3 pos) {
	pos = transformVec(s.transform, pos);
	float sdf;
	if(s.type == rect) {
		sdf = sdfRect(s, pos);
	} else {
		sdf = sdfSphere(s, pos);
	}
	return sdf;
}

// float sdf(Shape s, vec3 pos) {
    // return length(s.pos-pos) - s.radius;
// }

RayHit sdfScene(vec3 pos) {
	float prevsdf = MAX_DIST;
	Shape s;
	for(uint i = 0u; i < shapesSize; i++) {
		float sdf = sdf(shapes[i], pos);
		if(sdf < prevsdf) {
			s = shapes[i];
			prevsdf = sdf;
		}
	}
    return RayHit(s, prevsdf);
}

// return the normal of the shape to the current position
vec3 normal(Shape s, vec3 pos) {
    return normalize(vec3(
        sdf(s, pos + vec3(EPSILON,0,0)) - sdf(s, pos - vec3(EPSILON,0,0)),
        sdf(s, pos + vec3(0,EPSILON,0)) - sdf(s, pos - vec3(0,EPSILON,0)),
        sdf(s, pos + vec3(0,0,EPSILON)) - sdf(s, pos - vec3(0,0,EPSILON))
   ));
}

vec3 rayMarch(Ray ray) {
    while(ray.dist <= MAX_DIST) {
        RayHit rayHit = sdfScene(ray.pos);
        if(rayHit.dist <= EPSILON) {
            vec3 lightPos = vec3(0., 5., 0.);
            vec3 lightDir =  normalize(lightPos - ray.pos);
            
            float doot = dot(lightDir, normal(rayHit.shape, ray.pos));
            doot /= 2.;
            doot += .5;
            return rayHit.shape.color.xyz*doot;
        }
        ray.dist += rayHit.dist;
        ray.pos += rayHit.dist * ray.dir;
    }
    return vec3(0.);
}
            
void main()
{
	vec2 fragCoord = gl_FragCoord.xy;
	vec2 iResolution = vec2(640, 480);

    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;
	uv -= .5;
    vec3 uv3d = vec3(uv.x, 0., uv.y);
    
    vec3 originPoint = vec3(0., 0., 0.);
    
    vec3 dir = normalize(uv3d/originPoint);
    
    //Ray ray = rayFromAngle(uv * fov);
    Ray ray = rayFromAngleEx(fragCoord, iResolution.xy, 45.);
    //Ray ray = Ray(vec3(0.), dir, 0.);
    
    // Time varying pixel color
    vec3 col = rayMarch(ray);
    //col = ray.dir;
	
    // Output to screen
    fragColor = vec4(col,1.0);
}