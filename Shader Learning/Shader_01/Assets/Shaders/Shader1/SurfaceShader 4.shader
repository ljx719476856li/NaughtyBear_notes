Shader"NaughtyBearShader学习/4. 光照材质完备正式版Shader"
{
	//属性
	Properties
	{
		_Color("颜色", Color) = (0.0, 0.0, 0.5, 1.0)
		_SpecColor("高光颜色", Color) = (1, 1, 1, 1)
		_EmissionColor("自发光颜色", Color) = (0, 0, 0, 0)
		_ShininessColor("光泽度", Range(0.01, 1)) = 0.7
		_MainTexture("基本纹理", 2D) = "White"{}
	}
		//子着色器
		SubShader
	{
		//pass通道
		Pass
		{
			Material
			{

				//可调节的漫反射光和环境光反射颜色
				Diffuse[_Color]
				Ambient[_Color]
				//光泽度
				Shininess[_Shininess]
				//高光颜色
				Specular[_SpecColor]
				//自发光颜色
				Emission[_Emission]
			}
			//开启光照
			Lighting On
			//开启独立镜面反射
			SeparateSpecular On
			//设置纹理为属性中选择的纹理
			//SetTexture[_MainTexture]{combine texture} 
			SetTexture[_MainTexture]{Combine texture * primary DOUBLE, texture * primary}
		}
	}
		//备胎回滚
		//自带漫反射处理
		Fallback"Diffuse"
}