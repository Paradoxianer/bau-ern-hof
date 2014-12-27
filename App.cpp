#include <Entry.h>
#include <Alert.h>
#include <Roster.h>
#include <Directory.h>
#include <FindDirectory.h>

#include "App.h"
#include "MainWindow.h"
#include "constants.h"


App::App(void)
	:	BApplication("application/x-vnd.dw-TestApp")
{
	artPathAvailable = false;
	StartupCheck();
	MainWindow *mainwin = new MainWindow();
	mainwin->Show();

}

status_t App::StartupCheck(void)
{
	BEntry		entry;
	BPath		path;
	BDirectory	dir;
	status_t	err;
	
	//check if there is the directory containing all Art pictures if not there 
	if( find_directory(B_USER_NONPACKAGED_DATA_DIRECTORY, &path ) != B_OK )
		return B_ERROR;
	path.Append(BASE_PATH);
	//if base dir dosen exist then create it
	entry.SetTo(path.Path());
	if (!entry.Exists())
	{
		dir.CreateDirectory(path.Path(), &dir);
	}

	artPath.SetTo(path.Path());
	artPath.Append(ART_DIR);

	//if art dir dosen exist then create it	
	entry.SetTo(artPath.Path());
	if (!entry.Exists())
	{
		dir.CreateDirectory(artPath.Path(), &dir);
	}

	worldsPath.SetTo(path.Path());
	worldsPath.Append(WORLDS_DIR);

	//if world dir dosen exist then create it	
	entry.SetTo(worldsPath.Path());
	if (!entry.Exists())
	{
		dir.CreateDirectory(worldsPath.Path(), &dir);
	}
		
	// Get the path to the Game
	app_info ai;
	be_app->GetAppInfo(&ai);
	appPath.SetTo(&ai.ref);
	return B_OK;
}

int
main(void) {
	App *app = new App();
	app->Run();
	delete app;
	return 0;
}
