#version 330 core

out vec4 fragColor;

#define MAX_DIST 10.
#define EPSILON .01

struct Ray {
    vec3 pos;
    vec3 dir;
    float dist;
};

struct Shape {
	vec3 pos;
    float radius;
};

struct RayHit {
	Ray ray;
    Shape shape;
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
    
float sdf(Shape s, vec3 pos) {
    return length(s.pos-pos) - s.radius;
}

float sdfScene(vec3 pos) {
    Shape s = Shape(vec3(0., 0., -5.), 1.);
    return sdf(s, pos);
}

vec3 normal(Shape s, vec3 pos) {
    return normalize(pos-s.pos);
}

vec3 normalScene(vec3 pos) {
    Shape s = Shape(vec3(0., 0., -5.), 1.);
    return normal(s, pos);
}

float rand(float n){return fract(sin(n) * 43758.5453123);}

float noise(float p){
	float fl = floor(p);
  float fc = fract(p);
	return mix(rand(fl), rand(fl + 1.0), fc);
}

vec3 rayMarch(Ray ray) {
    while(ray.dist <= MAX_DIST) {
        float dis = sdfScene(ray.pos);
        if(dis <= EPSILON) {
            vec3 lightPos = vec3(0., 5., 0.);
            vec3 lightDir =  normalize(lightPos - ray.pos);
            
            float doot = dot(lightDir, normalScene(ray.pos));
            doot /= 2.;
            doot += .5;
            return vec3(1., 1., 0.)*doot;
        }
        ray.dist += dis;
        ray.pos += dis * ray.dir;
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