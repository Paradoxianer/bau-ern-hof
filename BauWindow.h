#ifndef BAUWINDOW_H
#define BAUWINDOW_H


#include <Window.h>
#include <View.h>
#include <GroupLayout.h>

#include "SpielElement.h"

class BauWindow : public BWindow
{
public:
							MainWindow(void);
			void			MessageReceived(BMessage *msg);
			bool			QuitRequested(void);
			
private:
			BaueBenutzerSchnittstelle();
			LadeSpielElemente();
			SpielElement Gewaehlt()
			
};

#endif
