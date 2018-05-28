////////////////////////////////////////////////////////////////////////////////
// Filename: texture.ps
////////////////////////////////////////////////////////////////////////////////


/////////////
// GLOBALS //
/////////////
Texture2D colourShaderTexture : register(t0);
Texture2D maskShaderTexture : register(t1);
SamplerState SampleType;

cbuffer ColourBuffer
{
	float4 colour;
};

//////////////
// TYPEDEFS //
//////////////
struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
};


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 TexturePixelShader(PixelInputType input) : SV_TARGET
{
	float4 textSampleColour;
	float4 textureColor;
	float4 maskColor;
	float4 finalColor;
    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
	textSampleColour = colourShaderTexture.Sample(SampleType, input.tex);
	maskColor = maskShaderTexture.Sample(SampleType, input.tex);

	textureColor = textSampleColour *  maskColor.a;
	maskColor = maskColor * (1.0f - textSampleColour.a);
	maskColor *= colour;
	
	finalColor = textureColor + maskColor;
	return finalColor;
}
