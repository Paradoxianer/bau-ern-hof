#ifndef APP_H
#define APP_H

#include <Application.h>
#include <Path.h>


class App : public BApplication
{
public:
					App(void);
	status_t 		StartupCheck(void);
	
private:
	const char*		GetAppPath(void){return appPath.Path();};
	const char*		GetWorldsPath(void){return worldsPath.Path();};
	const char*		GetArtPath(void){return artPath.Path();};
	BPath			appPath;
	BPath			artPath;
	BPath			worldsPath;
	BPath			configPath;
	bool			artPathAvailable;
};

#endif
