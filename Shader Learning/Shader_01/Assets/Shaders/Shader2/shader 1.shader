Shader "NaughtyBearShader学习/6.纹理的Alpha通道与自发光相混合" 
{

		//-------------------------------【属性】-----------------------------------------
		Properties
		{
			_MainTex("基础纹理(RGB)-自发光(A)", 2D) = "white" {}
		}

			//--------------------------------【子着色器】--------------------------------
			SubShader
		{
			Pass
			{
				//设置白色的顶点光照
				Material
				{
					//漫反射光和环境光设置为默认值 (1,1, 1, 1)
					Diffuse(1, 1, 1, 1)
					Ambient(1, 1, 1, 1)
				}
				
			//开光照
			Lighting On

			// 【1】使用纹理的alpha通道来插值混合颜色(1, 1, 1, 1)
			SetTexture[_MainTex] 
			{
				constantColor(1,1,1,1)
				combine constant lerp(texture) previous
			}
			// 【2】使用相乘操作来进行Alpha纹理混合 
			SetTexture[_MainTex] {combine texture * previous}
			}
		}
}
