#include "../Public/Effect.h"

/* Comments from github:
add some private values, like 
-	"effectStrenght" 
-	"modifier" 
-	"duration" (maybe) 
ps: I guess they could be in the base class?
*/

Effect::Effect(const std::string& name) {
	name = name;
}

void Effect::apply() {
	if(duration > 0) {
		// apply effect logic here
	}

	if (effectStrength <= 0) {

	}

	//if (effectStrength < 0) {	// Duration condition vadå?
	//	
	//}

}

void Effect::remove() {
	
}

const std::string Effect::getName() const { 	
	return name; 
}