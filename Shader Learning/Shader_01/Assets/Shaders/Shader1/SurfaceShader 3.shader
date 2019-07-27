Shader"NaughtyBearShader学习/3.简单的纹理载入Shader"
{
	//属性
	Properties
	{
		_MainTexture("基本纹理", 2D) = "White"{TexGen SphereMap}
	}
		//子着色器
		SubShader
	{
		//pass通道
		Pass
		{
			//设置纹理为属性中选择的纹理
			SetTexture[_MainTexture]{combine texture}

		}
	}
		//备胎回滚aaaaa
		//自带漫反射处理
		Fallback"Diffuse"
}