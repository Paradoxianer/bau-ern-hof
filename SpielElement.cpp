#include <File.h>
#include <BitmapStream.h>
#include <TranslatorRoster.h>

#include "SpielElement.h"
#include "BauernhofApp.h"

SpielElement::SpielElement(char *neuerName): BRect(0,0,2,2)
{
	name			= new BString(neuerName);
	meinBild		= HoleBild();
	unterElemente 	= new BList();
}

status_t SpielElement::Archive(BMessage* data, bool deep = true)
{
	data->AddString("name",*name);
	SpielElement	*element		= NULL;
	BMessage		*tmpMessage	= NULL;
	int32 			i;
	for (i=0;(element=(SpielElement *)unterElemente->ItemAt(i));i++)
	{
		tmpMessage=new BMessage();
		element->Archive(tmpMessage);
		data->AddMessage("unterElement", tmpMessage);
		delete tmpMessage;
	}
	
}


void SpielElement::FuegeHinzu(SpielElement * neuesElement)
{
	unterElemente->AddItem((void *)neuesElement);
}

void SpielElement::NimmsWeg(SpielElement * altesElement)
{
	unterElemente->RemoveItem((void *)altesElement);
	delete altesElement;
	altesElement=NULL;
}

void SpielElement::Zeige(BView *leinwand)
{
	int i = 0;
	if ((meinBild!=NULL) && (meinBild->IsValid()))
			leinwand->DrawBitmapAsync(meinBild,*this);
	SpielElement *element =NULL;
	for (i=0;(element=(SpielElement *)unterElemente->ItemAt(i));i++)
	{
		element->Zeige(leinwand);
	}
}


BBitmap *SpielElement::HoleBild()
{
	BPath path=((BauernhofApp*)be_app)->GetArtPath();
	path.Append(*name);
	BFile file(path.Path(),B_READ_ONLY);
	BTranslatorRoster *roster = BTranslatorRoster::Default();
	BBitmapStream stream;
	BBitmap *result = NULL;
	if (roster->Translate(&file, NULL, NULL, &stream,B_TRANSLATOR_BITMAP) < B_OK)
		return NULL;
	stream.DetachBitmap(&result);
	if (result->IsValid())
		Set(0,0,result->Bounds().Width(),result->Bounds().Height());
	return result;
}
