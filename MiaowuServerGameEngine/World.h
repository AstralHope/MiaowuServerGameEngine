#ifndef __WORLDCONTAINER
#define __WORLDCONTAINER

#include<vector>

#include"Transform.h"

typedef ClassTransform* Transform;

typedef std::vector<Transform> NodeTransformList;

struct WorldNode
{
	NodeTransformList transformList;
};

template<int AREA_SCALE>
class WorldContainer
{
public:
	WorldContainer();
	~WorldContainer();
	WorldNode* getNode(int x, int y);
	bool insertTransform(Transform transform);
	bool deleteTransform(Transform transform);
private:
	WorldNode* worldNodeList;
};

typedef WorldContainer<200> ViceWorld;
typedef WorldContainer<1000> NormalWorld;

template<int AREA_SCALE>
inline WorldContainer<AREA_SCALE>::WorldContainer()
{
	worldNodeList = new WorldNode[AREA_SCALE*AREA_SCALE];
}

template<int AREA_SCALE>
inline WorldContainer<AREA_SCALE>::~WorldContainer()
{
	delete[] worldNodeList;
}

template<int AREA_SCALE>
inline WorldNode* WorldContainer<AREA_SCALE>::getNode(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		if (x < AREA_SCALE &&y < AREA_SCALE)
		{
			return &worldNodeList[x*AREA_SCALE + y];
		}
	}
	return NULL;
}

template<int AREA_SCALE>
inline bool WorldContainer<AREA_SCALE>::insertTransform(Transform transform)
{
	if (transform == NULL)
	{
		return false;
	}
	int x = (int)transform->position.x;
	int y = (int)transform->position.y;
	WorldNode* node = getNode(x, y);
	if (node != NULL)
	{
		node->transformList.push_back(transform);
		return true;
	}
	return false;
}

template<int AREA_SCALE>
inline bool WorldContainer<AREA_SCALE>::deleteTransform(Transform transform)
{
	if (transform == NULL)
	{
		return false;
	}
	int x = (int)transform->position.x;
	int y = (int)transform->position.y;
	WorldNode* node = getNode(x, y);
	if (node != NULL)
	{
		NodeTransformList::iterator it = node->transformList.begin();
		while (it!= node->transformList.end())	
		{
			if (*it == transform)
			{
				node->transformList.erase(it);
				delete transform;
				return true;
			}
			else 
			{
				it++;
			}
		}
	}
	return false;
}

#endif // !__WORLDCONTAINER


