#include"App.hpp"

Mesh mesh;
int MAIN()
{
	/*Material�̎g����
	Material material(L"Shader.hlsl");
	Drow�̑O��material.Attach();
	*/
	bool flag = true;
	float pos = 0.01f, pos2 = -0.01f;

	while (App::Refresh())
	{
		//ChangeSizeBox();
		mesh.bM.angles.y += 0.01f;

		mesh.bM.position.z = 1.0f;
		mesh.Draw();
		
		mesh.bM.position.z = -1.0f;
		mesh.Draw();

	}
	return 0;
}

