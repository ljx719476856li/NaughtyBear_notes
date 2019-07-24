Shader"NaughtyBearShader学习/1.BaseColor"
{
	//子着色器
	SubShader
	{
		//pass通道
		Pass
		{
		//材质
		Material
		{
		//将漫反射和环境光设为一致
				Diffuse(0.9 ,0.5, 0.4, 1)
				Ambient(0.9, 0.5, 0.4, 1)
	}
	Lighting On
}
	}
}