#include "direct3d_setup.h"
#include "tree_Manager.h"

TREE m_trees[TREE_MAX];
D3DXVECTOR3 m_position[TREE_MAX] = {
	{ 344,168,0 },

	{ -128,256,0 },
	{ 0,256,0 },
	{ 128,256,0 },
	{ 256,256,0 },
	

	{ 512,384,0 },
	{ 512,512,0 },

	{ 640,512,0 },
	{ 640,640,0 },
	{ 640,768,0 },
	{ 640,896,0 },

	{ 756,168,0 },
	{ 840,84,0 },
	{ 924,0,0 },

	{ 1008,256,0 },
	{ 1008,384,0 },
	{ 1008,512,0 },
	{ 1008,640,0 },
	{ 1008,768,0 },
	{ 1008,896,0 },

	{ 1136,180,0 },
	{ 1264,180,0 },
	{ 1392,180,0 },

	{ 1520,96,0 },
	{ 1648,96,0 },
	
	{ 1664,512,0 },

	{ 1792,384,0 },
	{ 1920,384,0 },
	
	{ 1920,256,0 },
	{ 2048,256,0 },
	{ 2176,256,0 },
	{ 2304,256,0 },
	{ 2432,256,0 },
	{ 2560,256,0 }
};

RECT Tree_collision_rec[TREE_COLLSION_MAX] = {
	{-60,535,319,748 },//1
	{ 241,828,508,410 },//2
	{ 478,714,615,941 },//3
	{ 598,598,825,942 },//4
	{ 823,194,936,702 },//5
	{ 357,94,936,208 },//6
	{ 357,94,460,449 },//7
	{ 238,340,460,449 },//8
	{ 927,219,1288,328 },//9
	{ 1184,94,1288,249 },//10
	{ 1198,461,1659,694 },//11
	{ 1288,590,1450,694 },//12
	{ 1444,224,1550,694 },//13
	{ 1546,0,1665,328 },//14
	{ 1806,0,2578,82 },//15
	{ 2568,0,2688,235 },//16
	{ 1800,224,2264,454 },//17
	{ 2440,224,2688,454 },//18
	{ 1088,908,1588,1024 },//19
	{ 1800,431,1900,1024 },//20
	{ 1566,792,1806,1024 },//21
	{ 1685,554,1814,799 }//22
};

void Tree_Init(void) {
	for (int i = 0;i < TREE_MAX;i++) {
		m_trees[i].InitTREE(m_position[i]);
	}
}

void Tree_Draw(void) {
	for (int i = 0;i < TREE_MAX;i++) {
		m_trees[i].DrawTREE();
	}
}

void Tree_Uninit(void) {
	for (int i = 0;i < TREE_MAX;i++) {
		m_trees[i].UninitTREE();
	}
}

RECT *GetTree() {
	return Tree_collision_rec;
}