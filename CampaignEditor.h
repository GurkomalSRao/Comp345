
#ifndef CAMPAIGNEDITOR_H
#define CAMPAIGNEDITOR_H



#include <string>
#include "map.h"
#include "campaign.h"
using  namespace std;

//! Class implementing a campaign editor
class CampaignEditor
{
private:
	bool loadMap(string &fname);
	bool saveCampaign(Campaign* c, string fname);
	bool saveCampaign(Campaign* c);
	bool loadCampaign(Campaign* &c);
	Campaign* loadCampaign(string fname);
public:
	void runEditor();


};
#endif