#include "Haus.h"
#include "stdio.h"

Haus::Haus(char *haus_name): SpielElement(haus_name)
{
	laenge=20;
	breite=3;
	hoehe=5;
	tuer_auf=true;
	fenster_auf=false;
}


void	Haus::MachFensterAuf()
{
	fenster_auf=true;
}

void	Haus::MachFensterZu()
{
	fenster_auf=false;
}
	
void	Haus::MachTuerAuf()
{
	tuer_auf=true;
}

void	Haus::MachTuerZu()
{
	tuer_auf=false;
}
	
void	Haus::Zeige()
{
	printf("Das %s ist %i Meter breit.\n",name->String(), breite);
	printf("Das %s ist %i Meter lang.\n",name->String(), laenge); 
	printf("Das %s ist %i Meter hoch.\n",name->String(), hoehe);
	if (tuer_auf==true)
		printf("Die Tür ist auf\n"); 
	else
		printf("Die Tür ist zu\n"); 
	if (fenster_auf==true)
		printf("Die Fenster sind auf\n"); 
	else
		printf("Die Fenster sind zu\n"); 

}
