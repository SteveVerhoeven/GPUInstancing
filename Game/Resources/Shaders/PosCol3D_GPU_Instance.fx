float4x4 gWorldViewProj : WorldViewProjection;

// ------------------------
// Input/Output structs
// ------------------------
struct VS_INPUT
{
	float3 Position : POSITION;
	float3 Color : COLOR;
	float2 Uv : TEXCOORD;
	float3 InstancePosition : INSTANCEPOS;
};
struct VS_OUTPUT
{
	float4 Position : SV_POSITION;			// SV = system variable
	float3 Color : COLOR;
	float2 Uv : TEXCOORD;
	float3 InstancePosition : INSTANCEPOS;
};

// ------------------------
// Vertex shader
// ------------------------
VS_OUTPUT VS(VS_INPUT input, float3 instancePos : INSTANCEPOS, uint instanceID : SV_InstanceID)
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	
	float4 newPos = mul(float4(input.Position, 1.0f), gWorldViewProj);
	newPos = newPos + float4(input.InstancePosition, 0);
	output.Position = newPos;
	output.InstancePosition = newPos;
	output.Color = input.Color;
		
	return output;
}

// ------------------------
// Pixel shader
// ------------------------
float4 PS(VS_OUTPUT input) : SV_TARGET
{
	return float4(input.Color, 1.f);
}

// ------------------------
// Technique
// ------------------------
technique11 DefaultTechnique
{
	pass P0
	{
		SetVertexShader( CompileShader(vs_5_0, VS()) );
		SetGeometryShader( NULL );
		SetPixelShader( CompileShader(ps_5_0, PS()) );
	}
}