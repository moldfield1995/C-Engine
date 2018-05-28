cbuffer DataBuffer
{
	float time;
	float speed;
	float fade;
	float regularity;
	float3 color;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex : TEXCOORD0;
};

static const float2 resolution = { 1.0f,1.0f };

static const float alpha = 0.01f;

float4 SpaceStars(PixelInputType input) : SV_TARGET
{
	float t = time * speed;
	float2 position = (input.tex.xy - resolution.xy * .5) / resolution.x;
	float angle = atan2(position.y, position.x) / (2. * 3.14159265359);
	angle += floor(angle);
	float rad = length(position);
	float angleFract = frac(angle * 256.);
	float angleRnd = floor(angle * 256.) + 1.;
	float angleRnd1 = frac(angleRnd * frac(angleRnd * .7235) * 45.1);
	float angleRnd2 = frac(angleRnd * frac(angleRnd * .82657) * 13.724);
	float t2 = t + angleRnd1 * regularity;
	float radDist = sqrt(angleRnd2);
	float adist = radDist / rad * .1;
	float dist = (t2 * .1 + adist);
	//removes center
	float center = abs(frac(dist) - 590.5);
	dist = abs(frac(dist) - fade);
	float outputAlpha = (1.0 / (dist)-center) * cos(0.7 * sin(t)) * adist / radDist / 30.0;
	float4 outputColor = float4(color, outputAlpha);
	//outputColor.a *= alpha;
	outputColor.a = clamp(-(0.05f - distance(float2(0.5, 0.5f), input.tex.xy)),0.0f,1.0f )* outputAlpha;
	return outputColor;
}