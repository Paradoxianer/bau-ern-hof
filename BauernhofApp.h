#ifndef APP_H
#define APP_H

#include <Application.h>
#include <Path.h>


class BauernhofApp : public BApplication
{
public:
					BauernhofApp(void);
	status_t 		StartupCheck(void);
	const char*		GetAppPath(void){return appPath.Path();};
	const char*		GetWorldsPath(void){return worldsPath.Path();};
	const char*		GetArtPath(void){return artPath.Path();};
	
private:
	BPath			appPath;
	BPath			artPath;
	BPath			worldsPath;
	BPath			configPath;
	bool			artPathAvailable;
};

#endif
