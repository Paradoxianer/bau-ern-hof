#include "MainWindow.h"

#include <Application.h>
#include <LayoutBuilder.h>
#include <SpaceLayoutItem.h>
#include <View.h>
#include <StringView.h>
#include <stdio.h>
#include <string.h>



MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,500,400),"Bauernhof",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
	BLayoutBuilder::Group<>(this,B_VERTICAL)
		.SetInsets(0,0,0,0)
		.Add(MakeStatusView())
		.Add(spielFeld=MakeGameView())
		.Add(commandLine=new BTextControl("Was soll ich machen:","",new BMessage('txt')));
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		case 'txt':
		{
			char *command = new char[100];
			char *item = new char[100];
			int  width = 1;
			int	 height = 1;	
			sscanf(commandLine->Text(),"%s %s %i %i",command,item,&width,&height );
			spielFeld->BuildSpielElement(item, width, height);
		}
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}

BView	*MainWindow::MakeStatusView()
{
	BGroupView *statusView=new BGroupView();
	statusView->GroupLayout()->SetInsets(10,2,10,2);
	statusView->GroupLayout()->AddView(new BStringView("status_labe1","Status"));
	statusView->GroupLayout()->AddView(new BStringView("status","Es ist Tag"));
	statusView->GroupLayout()->AddItem(BSpaceLayoutItem::CreateGlue());
	statusView->GroupLayout()->AddView(new BStringView("status_labe12","Status2"));
	statusView->GroupLayout()->AddView(new BStringView("status2","Zweiter Status"));
	return statusView;
}


bool MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
