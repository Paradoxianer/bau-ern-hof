#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <Window.h>
#include <View.h>
#include "GameView.h"
#include <GroupLayout.h>
#include <TextControl.h>

class MainWindow : public BWindow
{
public:
							MainWindow(void);
			void			MessageReceived(BMessage *msg);
			bool			QuitRequested(void);
			
private:
			GameView		*MakeGameView(){return new GameView(BRect(0,0,300,200));};
			BView			*MakeStatusView();
			BTextControl	*commandLine;
			GameView		*spielFeld;
};

#endif
