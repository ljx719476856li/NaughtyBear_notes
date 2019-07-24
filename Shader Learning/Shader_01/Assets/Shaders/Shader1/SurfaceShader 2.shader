Shader"NaughtyBearShader学习/2.光照材质完备beta版Shader"
{
	//属性
	Properties
	{
		_Color("主颜色", Color) = (.0, .0, .5, 1)
		_SpecColor("反射高光颜色", Color) = (1, 1, 1, 1)
		_Emission("自发光颜色", Color) = (0, 0, 0, 0)
		_Shininess("光泽度", Range(.01, 1)) = 0.7
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

		//高光颜色
		Specular[_SpecColor]
		//自发光颜色
		Emission[_Emission]
		//光泽度
		Shininess[_Shininess]
}
Lighting On
}
	}
}