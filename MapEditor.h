
#include <string>
#include "map.h"
using  namespace std;



//! Class implementing a map editor
class MapEditor
{
	private:
		bool saveMap(Map* m);
		bool loadMap(Map* &m);
		void printRules();
	public:
		void runEditor();
		

};