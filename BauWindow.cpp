#include "BauWindow.h"

#include <Application.h>
#include <LayoutBuilder.h>
#include <SpaceLayoutItem.h>
#include <View.h>
#include <StringView.h>
#include <stdio.h>
#include <string.h>



BauWindow::BauWindow(void)
	:	BWindow(BRect(100,100,550,400),"Bauernhof",B_BORDERED_WINDOW)
{


}


void
BauWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
	
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}

BauWindow::BaueBenutzerSchnittstelle()
{
}

BauWindow::LadeSpielElemente()
{
	
}


bool BauWindow::QuitRequested(void)
{
}
