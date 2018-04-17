
Texture2D shaderTexture;
SamplerState SampleType;

cbuffer ColourBuffer : register(b0)
{
	float4 colour;
	float2 UVClip;
};


struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
};


float4 SliderPixelShader(PixelInputType input) : SV_TARGET
{
	float4 textureColor;


    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor = shaderTexture.Sample(SampleType, input.tex);
	textureColor = textureColor * colour;
	if(input.tex.x > UVClip.x)
	{
		textureColor.a = 0.0;
	}

    return textureColor;
}
