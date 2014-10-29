#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <View.h>
#include "SpielElement.h"

class GameView : public BView
{
public:
	GameView(BRect);
	void Draw(BRect updateRect);
	void AttachedToWindow();
	void GenerateWorld();
	void BuildSpielElement(char *item, int widht, int height);

	void AddSpielElement(SpielElement *element);
	static	bool			ZeichneSpielElement(void *arg,void *view);
	void KeyDown(const char* bytes, int32 numBytes);
	int Step(){return 5;};
protected:
	BList			*gameBackground;
	SpielElement	*player;
	BList			*gameForeground;

};	

#endif
