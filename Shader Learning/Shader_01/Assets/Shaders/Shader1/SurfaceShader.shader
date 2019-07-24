Shader"NaughtyBearShader学习/1.可调漫反射光的Shader"
{
	//属性
	Properties
	{
		_Color("主颜色", Color) = (.0, .0, .5, 1)
	}
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
				//Diffuse(0.9 ,0.5, 0.4, 1)
				//Ambient(0.9, 0.5, 0.4, 1)
				Diffuse[_Color]
				Ambient[_Color]
	}
	Lighting On
}
	}
}