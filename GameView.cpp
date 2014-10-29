#include "GameView.h"
#include "Haus.h"
#include <Alert.h>
#include <stdio.h>

GameView::GameView(BRect rect): BView(rect,"GameView",B_FOLLOW_ALL_SIDES,B_WILL_DRAW)
{
	player=new SpielElement("Maedchen");
	player->Set(200,50,300,200);
	gameBackground = new BList();
	gameForeground = new BList(); 
}

void GameView::Draw(BRect rect)
{
	gameBackground->DoForEach(ZeichneSpielElement,this);
	player->Zeige(this);
	gameForeground->DoForEach(ZeichneSpielElement,this);
}

void GameView::AttachedToWindow()
{
	SetEventMask(B_KEYBOARD_EVENTS);
	SetDrawingMode(B_OP_MIN);
}

void GameView::KeyDown(const char* bytes, int32 numBytes)
{
	switch(bytes[0])
 	{
		case B_LEFT_ARROW:
		{
			player->OffsetBy(-Step(),0);
			ScrollBy(-Step(),0);
			Invalidate();
			break;
		}
		case B_RIGHT_ARROW:
		{
			player->OffsetBy(Step(),0);
			ScrollBy(Step(),0);
			Invalidate();
			break;
		}
		case B_UP_ARROW:
		{
			player->OffsetBy(0,-Step());
			ScrollBy(0, -Step());
			Invalidate();
			break;
		}
		case B_DOWN_ARROW:
		{
			player->OffsetBy(0,Step());
			ScrollBy(0,Step());
			Invalidate();
			break;
		}
 	}
}

void GameView::AddSpielElement(SpielElement *element)
{
	if (element != NULL)
	{
		gameBackground->AddItem(element);
		Invalidate();
	}
}

void GameView::BuildSpielElement(char *item, int width, int heigth)
{
	SpielElement *element=new SpielElement(item);
	if ((element->meinBild!=NULL) && (element->meinBild->IsValid()))
	{
		element->Set(player->left,player->bottom-(heigth*100),player->left+(width*100),player->bottom);
		AddSpielElement(element);
	}
	else
	{
		char *errorMsg	= new char [255];
		sprintf(errorMsg,"%s kenne ich nicht, dass kann ich nicht bauen",item);
		BAlert *alert = new BAlert("Wie bitte?",errorMsg,";-(");
		alert->Go();
	}	

}

bool GameView::ZeichneSpielElement(void *arg, void *view)
{
	SpielElement *element=(SpielElement*)arg;
	element->Zeige((BView *)view);
	return false;
}