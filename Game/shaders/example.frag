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
	vec3 pos;
    float radius;
	vec3 color;
	int type;
};

struct RayHit {
    Shape shape;
	float dist;
};

out vec4 fragColor;

layout (std140) uniform shape {
	Shape shapes[MAX_SHAPES];
	int shapesSize;
};
    
Ray rayFromAngle(vec2 angles) {
    vec2 sinF = sin(angles);
    vec2 cosF = cos(angles);
    vec3 dir = vec3(
        sinF.y * cosF.x,
        sinF.y * sinF.x,
        cosF.y
    );
    
    //ray pos is where the camera is
    return Ray(vec3(0.), dir, 0.);
}

Ray rayFromAngleEx(vec2 fragCoord, vec2 size, float fov) {
    vec2 xy = fragCoord - size / 2.0;
    float z = size.y / tan(radians(fov) / 2.0);
    return Ray(vec3(0.), normalize(vec3(xy, -z)), 0.);
}
   
float sdfRect(Shape s, vec3 pos) {
  vec3 q = abs(s.pos - pos) - vec3(s.radius);
  return length(max(q,0.0)) + min(max(q.x,max(q.y,q.z)),0.0);
}
   
float sdfSphere(Shape s, vec3 pos) {
	return length(s.pos-pos) - s.radius;
}
	
float sdf(Shape s, vec3 pos) {
	float sdf = sdfSphere(s, pos);
	if(s.type == rect) {
		sdf = sdfRect(s, pos);
	}
	return sdf;
}

// float sdf(Shape s, vec3 pos) {
    // return length(s.pos-pos) - s.radius;
// }

RayHit sdfScene(vec3 pos) {
	float prevsdf = MAX_DIST;
	Shape s;
	for(int i = 0; i < shapesSize; i++) {
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
            return rayHit.shape.color*doot;
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