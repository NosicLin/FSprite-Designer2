#include <stdio.h>

#include "core/SdSprite.h"
#include "core/SdProject.h"
#include "core/SdAnimation.h"
static inline SdProject* createProject()
{
	SdProject* proj=new SdProject("proj/fsdf/","proj-01");


    for(int i=0;i<10;i++)
	{
		char buf[100];
		sprintf(buf,"sprite-0%d",i);

		SdSprite* sprite=new SdSprite;
        sprite->setName(buf);
        proj->addSprite(sprite);

        for(int j=0;j<20;j++)
        {
            sprintf(buf,"animation-%d-%d",i,j);
            SdAnimation* anim=new SdAnimation;
            anim->setName(buf);
            sprite->addAnimation(anim);
        }

	}
	return proj;
}
